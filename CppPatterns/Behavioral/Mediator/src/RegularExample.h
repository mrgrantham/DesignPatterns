#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class InterfaceElement {
protected:
  std::string name_;
  bool isVisible_;

public:
  InterfaceElement(const std::string &name, bool isVisible)
      : name_(name), isVisible_(isVisible) {}
  void setVisibility(bool isVisible) { this->isVisible_ = isVisible; }

  std::string getDescription() {
    return isVisible_ ? name_ + " is visible" : name_ + " is NOT visible";
  }
};
class ButtonElement : public InterfaceElement {
public:
  ButtonElement(const std::string &name, bool isVisible)
      : InterfaceElement(name, isVisible) {}
  virtual ~ButtonElement() {}
  virtual void click() = 0;
};

class TextBox : public InterfaceElement {
  std::string textValue_ = "";

public:
  TextBox(const std::string &name, bool isVisible)
      : InterfaceElement(name, isVisible) {}
  virtual ~TextBox() {}
  virtual void changeText(const std::string &newValue) {
    textValue_ = newValue;
  }
};

class CheckBox : public InterfaceElement {
private:
  bool isChecked_;

public:
  CheckBox(const std::string &name, bool isVisible)
      : InterfaceElement(name, isVisible) {}
  virtual ~CheckBox() {}
  virtual void setIsChecked(bool isChecked) { isChecked_ = isChecked; }
};

class SubmitButton : public ButtonElement {
public:
  SubmitButton() : ButtonElement("Submit Button", false) {}
  void click() override { std::cout << "Submitted!" << std::endl; }
};

class NameTextBox : public TextBox {
  SubmitButton *submitButton_;

public:
  NameTextBox(SubmitButton *submitButton)
      : TextBox("Name textbox", true), submitButton_(submitButton) {}
  void changeText(const std::string &newValue) override {
    if (newValue.empty()) {
      submitButton_->setVisibility(false);
    } else {
      submitButton_->setVisibility(true);
    }
    TextBox::changeText(newValue);
  }
};

class SpousesNameTextBox : public TextBox {
public:
  SpousesNameTextBox() : TextBox("Spouse's name textbox", false) {}
};

class IsMarriedCheckbox : public CheckBox {
private:
  SpousesNameTextBox *spousesNameTextBox_;

public:
  IsMarriedCheckbox(SpousesNameTextBox *spousesNameTextBox)
      : CheckBox("Is married checkbox", true),
        spousesNameTextBox_(spousesNameTextBox) {}
  void setIsChecked(bool isChecked) override {
    if (isChecked) {
      spousesNameTextBox_->setVisibility(true);
    } else {
      spousesNameTextBox_->setVisibility(false);
    }
    CheckBox::setIsChecked(isChecked);
  }
};
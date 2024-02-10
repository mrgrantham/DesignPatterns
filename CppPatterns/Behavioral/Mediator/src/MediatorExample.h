#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Refactor {
class Mediator {
public:
  virtual void mediate(const std::string &event) = 0;
  virtual ~Mediator(){};
};

class InterfaceElement {
protected:
  std::string name_;
  bool isVisible_;
  Mediator *mediator_;

public:
  InterfaceElement(const std::string &name, bool isVisible, Mediator *mediator)
      : name_(name), isVisible_(isVisible), mediator_(mediator) {}
  void setVisibility(bool isVisible) { this->isVisible_ = isVisible; }

  std::string getDescription() {
    return isVisible_ ? name_ + " is visible" : name_ + " is NOT visible";
  }
};
class ButtonElement : public InterfaceElement {
public:
  ButtonElement(const std::string &name, bool isVisible, Mediator *mediator)
      : InterfaceElement(name, isVisible, mediator) {}
  virtual ~ButtonElement() {}
  void click() { mediator_->mediate(name_ + " clicked"); };
};

class TextBox : public InterfaceElement {
  std::string textValue_ = "";

public:
  TextBox(const std::string &name, bool isVisible, Mediator *mediator)
      : InterfaceElement(name, isVisible, mediator) {}
  virtual ~TextBox() {}
  virtual void changeText(const std::string &newValue) {
    textValue_ = newValue;
    if (newValue.empty()) {
      mediator_->mediate(name_ + " empty");
    } else {
      mediator_->mediate(name_ + " not empty");
    }
  }
};

class CheckBox : public InterfaceElement {
private:
  bool isChecked_;

public:
  CheckBox(const std::string &name, bool isVisible, Mediator *mediator)
      : InterfaceElement(name, isVisible, mediator) {}
  virtual ~CheckBox() {}
  virtual void setIsChecked(bool isChecked) {
    isChecked_ = isChecked;
    if (isChecked) {
      mediator_->mediate(name_ + " is checked");
    } else {
      mediator_->mediate(name_ + " is unchecked");
    }
  }
};

class UserInterface : public Mediator {
private:
  TextBox *nameTextBox_;
  CheckBox *isMarriedCheckbox_;
  TextBox *spousesNameTextBox_;
  ButtonElement *submitButton_;

public:
  UserInterface() {
    nameTextBox_ = new TextBox("Name textbox", true, this);
    isMarriedCheckbox_ = new CheckBox("Is married checkbox", true, this);
    spousesNameTextBox_ = new TextBox("Spouse's name checkbox", false, this);
    submitButton_ = new ButtonElement("Submit button", false, this);
  }

  TextBox *getNameTextBox() { return nameTextBox_; }
  CheckBox *getIsMarriedCheckbox() { return isMarriedCheckbox_; }
  TextBox *getSpouseNameTextBox() { return spousesNameTextBox_; }
  ButtonElement *getSubmitButton() { return submitButton_; }

  ~UserInterface() {
    delete nameTextBox_;
    delete isMarriedCheckbox_;
    delete spousesNameTextBox_;
    delete submitButton_;
  }

  void mediate(const std::string &event) override {
    std::cout << "Mediating event: " << event << "...\n";

    if (event == "Name textbox is empty") {
      submitButton_->setVisibility(false);
    } else if (event == "Name textbox is not empty") {
      submitButton_->setVisibility(true);
    } else if (event == "Is married checkbox is checked") {
      spousesNameTextBox_->setVisibility(true);
    } else if (event == "Is married checkbox is unchecked") {
      spousesNameTextBox_->setVisibility(false);
    } else if (event == "Submit button clicked") {
      std::cout << "Submitted!\n";
    } else {
      std::cout << "unrecognized event\n";
    }
  }
};

} // namespace Refactor
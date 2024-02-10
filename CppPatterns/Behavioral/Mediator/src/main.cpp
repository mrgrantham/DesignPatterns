#include <filesystem>
#include <iostream>

#include "MediatorExample.h"
#include "RegularExample.h"

int main(int argc, char **argv) {

  std::cout << "Mediator Pattern Example" << std::endl;
  {
    /** Regular Unmediated Example
     * This is not a clear example it will need some work
     */

    SubmitButton *submitButton = new SubmitButton;
    NameTextBox *nameTextBox = new NameTextBox(submitButton);
    SpousesNameTextBox *spousesNameTextBox = new SpousesNameTextBox;
    IsMarriedCheckbox *isMarriedCheckBox =
        new IsMarriedCheckbox(spousesNameTextBox);

    InterfaceElement *elements[] = {nameTextBox, isMarriedCheckBox,
                                    spousesNameTextBox, submitButton};

    std::cout << "\n===== State =====\n";
    for (auto element : elements) {
      std::cout << element->getDescription() << "\n";
    }
  }

  /** Use the Mediator Example when you need to reduce coupling and organize
   * complex dependencies between a number of tightly coupled classes */
  {
    Refactor::UserInterface *ui = new Refactor::UserInterface;

    Refactor::InterfaceElement *elements[] = {
        ui->getNameTextBox(), ui->getIsMarriedCheckbox(),
        ui->getSpouseNameTextBox(), ui->getSubmitButton()};

    std::cout << "\n===== State =====\n";
    for (auto element : elements) {
      std::cout << element->getDescription() << "\n";
    }

    ui->getIsMarriedCheckbox()->setIsChecked(true);
    ui->getSpouseNameTextBox()->changeText("Spousita");
    ui->getSubmitButton()->click();

    std::cout << "\n===== Updated Married Checkbox State =====\n";
    for (auto element : elements) {
      std::cout << element->getDescription() << "\n";
    }

    delete ui;
  }
  return EXIT_SUCCESS;
}
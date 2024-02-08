#include <filesystem>
#include <iostream>

#include "ChainOfResponsibilityExample.h"

int main(int argc, char **argv) {

  std::cout << "Chain Of Responsibility Pattern Example" << std::endl;

  // In this exmample we create a linked list of obejcts that each act on the
  // data passed to it down the chain.
  StringValidator *emailValidator = new BaseValidator;

  emailValidator->setNext(new NotEmptyValidator)
      ->setNext(new RegexValidator(
          "email address",
          "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

  std::cout << "Checking emails...\n";
  std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
  std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
  std::cout << "Input: shaun@test.com\n"
            << emailValidator->validate("shaun@test.com") << "\n\n";

  delete emailValidator;

  return EXIT_SUCCESS;
}
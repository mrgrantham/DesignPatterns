#include <filesystem>
#include <iostream>

#include "TemplateMethodExample.h"

int main(int argc, char **argv) {

  std::cout << "Template Method Pattern Example" << std::endl;
  /** Template method is useful for preocesses that have similar structure of
   * steps to execute with potential varations in implementation for each
   * step.*/

  GreetingCardTemplate greetingCardTemplate;
  BirthdayCardTempate birthdayCardTempate;
  NewYearsCardTemplate newYearsCardTemplate;

  std::cout << "\nRegular Greeting Card:\n\n"
            << greetingCardTemplate.generate("James", "Sheye");
  std::cout << "\nBirthday Greeting Card:\n\n"
            << birthdayCardTempate.generate("James", "Sheye");
  std::cout << "\nNew Year Greeting Card:\n\n"
            << newYearsCardTemplate.generate("James", "Sheye");

  return EXIT_SUCCESS;
}
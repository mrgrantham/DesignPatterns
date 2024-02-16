#include <filesystem>
#include <iostream>

#include "RegularExample.h"
#include "StrategyExample.h"

int main(int argc, char **argv) {

  std::cout << "Strategy Pattern Example" << std::endl;

  /** Regular Example */
  {
    const std::string greetedPerson("Jerry");
    BusinessPerson *businessPerson = new BusinessPerson();
    businessPerson->greet(greetedPerson);

    NormalPerson *normalPerson = new NormalPerson();
    normalPerson->greet(greetedPerson);

    CoolPerson *coolPerson = new CoolPerson();
    coolPerson->greet(greetedPerson);

    Politician *politician = new Politician();
    politician->greet(greetedPerson);
  }

  /** Refactor with Strategy Pattern */
  {
    const std::string greetedPerson("Gary");
    Refactor::Person *businessPerson =
        new Refactor::Person(new Refactor::FormalGreetingStrategy());
    businessPerson->greet(greetedPerson);

    Refactor::Person *normalPerson =
        new Refactor::Person(new Refactor::NormalGreetingStrategy());
    normalPerson->greet(greetedPerson);

    Refactor::Person *coolPerson =
        new Refactor::Person(new Refactor::InformalGreetingStrategy());
    coolPerson->greet(greetedPerson);

    Refactor::Person *politician =
        new Refactor::Person(new Refactor::FormalGreetingStrategy());
    politician->greet(greetedPerson);
  }

  return EXIT_SUCCESS;
}
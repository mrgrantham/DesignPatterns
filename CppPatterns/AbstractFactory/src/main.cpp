#include <iostream>

#include "AbstractFactoryExample.h"

// This is useful when the various componenets of the object produced by the
// factory are not interchangable across different factories
// This allows you to keepp object that are of a particular familiy together
// when the ojects of that family are not compatible with the objects in another
// family

// Usually a natural progression from starting with the Factory Method

int main(int argc, char **argv) {

  int choice = 0;
  std::cout << "Abstract Factory Pattern Example" << std::endl;
  std::cout << "Select a car type: \n"
               "1: Gasoline\n"
               "2: Electric\n"
               "Selection: ";
  std::cin >> choice;

  CarFactory *carFactory = nullptr;

  switch (choice) {
  case 1:
    carFactory = new GasCarFactory;
    break;
  case 2:
    carFactory = new ElectricCarFactory;
    break;
  default:
    std::cout << "Invalid selection" << std::endl;
    return EXIT_FAILURE;
    break;
  }

  if (!carFactory) {
    return EXIT_FAILURE;
  }

  Door *door = carFactory->buildDoor();
  Engine *engine = carFactory->buildEngine();

  door->open();
  engine->run();

  return EXIT_SUCCESS;
}
#include <iostream>

// Create object based on parameters given at runtime

#include "FactoryMethodExample.h"

int main(int argc, char **argv) {
  std::cout << "Factory Method Pattern Example" << std::endl;

  CoffeeMakerFactory factory;
  Coffee *cup;

  cup = factory.getCoffee(1);
  std::cout << "Coffee Requested: " << cup->getType() << std::endl;

  cup = factory.getCoffee();

  std::cout << "Coffee User Requested: " << cup->getType() << std::endl;
  return 0;
}
#pragma once

#include <iostream>

class Coffee {
protected:
  char type_[15];

public:
  Coffee() {}
  char *getType() { return type_; }
};

// Concrete class
class Espresso : public Coffee {
public:
  Espresso() : Coffee() {
    strncpy(type_, "Espresso", sizeof(type_));
    std::cout << "\nMaking a cup of Espresso\n";
    std::cout << "Grind and brew one scoop of expresso beans" << std::endl;
  }
};
class Cappuccino : public Coffee {
public:
  Cappuccino() : Coffee() {
    strncpy(type_, "Cappuccino", sizeof(type_));

    std::cout << "\nMaking a cup of Cappuccino\n";
    std::cout << "Grind and brew one scoop of expresso beans\n";
    std::cout << "Heat and foam milk" << std::endl;
  }
};

class CoffeeMakerFactory {
private:
  // Coffee *coffee;
public:
  Coffee *getCoffee(int type) {
    switch (type) {
    case 1:
      return new Espresso;
    case 2:
      return new Cappuccino;
    default:
      std::cout << "Invalid Selection" << std::endl;
      return nullptr;
    }
  }
  Coffee *getCoffee() {
    int choice = 0;

    std::cout << "Select type of coffee to make: " << std::endl;
    std::cout << "1: Espresso" << std::endl;
    std::cout << "2: Cappuccino" << std::endl;
    std::cout << "Selection: " << std::endl;
    std::cin >> choice;

    return getCoffee(choice);
  }
};
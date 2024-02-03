#include <iostream>

#include "BuilderExample.h"

/** Focusing on the common steps for building an object
 * rather than the resulting object which could vary in
 * its type and interface between builders.
 * The retrival function for the final built object is
 * usually implemented in the concrete builder since the
 * resulting object maybe different depending on the builder
 */

int main(int argc, char **argv) {
  std::cout << "Builder Pattern Example" << std::endl;
  MealBuilder *lineCook = nullptr;
  MealCombo *meal;
  int choice = 0;

  std::cout << "Select a meal:\n"
               "1: Hamburger meal\n"
               "2: Hotdog meal\n"
               "Selection: ";
  std::cin >> choice;
  std::cout << std::endl;

  switch (choice) {
  case 1:
    lineCook = new BurgerMeal;
    break;
  case 2:
    lineCook = new HotDogMeal;
    break;
  default:
    std::cout << "Invalid meal selection" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Meaking meal" << std::endl;
  lineCook->cookEntree();
  lineCook->cookSide();
  lineCook->pourDrink();

  meal = lineCook->getMeal();
  std::cout << meal->openMealBag() << std::endl;
  return 0;
}
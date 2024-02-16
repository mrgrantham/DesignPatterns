#include <filesystem>
#include <iostream>

#include "VisitorExample.h"

int main(int argc, char **argv) {

  std::cout << "Visitor Pattern Example" << std::endl;
  /** Instead of adding the same extraneous methods to many different classes,
   * create a separate class that can visit these classes and handle that logic
   * itself */

  Person person("Jack", 41);
  Landmark landmark("Taj Mahal", "Mumbai");
  Car car("Chevy", "Bolt");

  DatabaseVisitor *databaseVisitor = new DatabaseVisitor();
  TextFileVisitor *testFileVisitor = new TextFileVisitor();

  person.accept(databaseVisitor);
  landmark.accept(databaseVisitor);
  car.accept(databaseVisitor);

  person.accept(testFileVisitor);
  landmark.accept(testFileVisitor);
  car.accept(testFileVisitor);
  return EXIT_SUCCESS;
}
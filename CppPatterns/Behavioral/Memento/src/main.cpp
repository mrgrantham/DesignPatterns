#include <filesystem>
#include <iostream>

#include "MementoExample.h"

int main(int argc, char **argv) {

  std::cout << "Memento Pattern Example" << std::endl;
  /** Memento pattern is useful when we want to freeze or save objects in such a
   * way that they can't be modified by any other part of our program until
   * the're unfrozen. */

  Canvas canvas;

  canvas.addShape("trapezoid");
  canvas.addShape("circle");
  canvas.addShape("ellipsis");
  canvas.addShape("square");

  std::cout << "Current State\n";
  for (auto shape : canvas.getShapes()) {
    std::cout << shape << ", ";
  }

  std::cout << "\n";

  canvas.undo();

  std::cout << "Current State after Undo\n";
  for (auto shape : canvas.getShapes()) {
    std::cout << shape << ", ";
  }
  std::cout << "\n";

  return EXIT_SUCCESS;
}
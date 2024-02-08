#include <filesystem>
#include <iostream>

#include "CommandExample.h"
#include "RegularExample.h"

static std::string VectorToString(auto items) {
  std::string toString;
  for (auto &item : items) {
    toString += item + ", ";
  }
  return toString;
}

int main(int argc, char **argv) {

  std::cout << "Command Pattern Example" << std::endl;
  {
    // Regular Example
    Canvas *canvas = new Canvas;

    AddTriangleButton *addTriangleButton = new AddTriangleButton(canvas);
    AddSquareButton *addSquareButton = new AddSquareButton(canvas);
    ClearButton *clearButton = new ClearButton(canvas);

    addTriangleButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";
    addSquareButton->click();
    addSquareButton->click();
    addTriangleButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";

    clearButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";
  }

  /** Command Pattern
   * Can help reduce coupling between classes in an application as well as make
   * functinoality more reusable between similar classes
   */

  {
    Refactor::Canvas *canvas = new Refactor::Canvas;

    Refactor::Button *addTriangleButton =
        new Refactor::Button(new Refactor::AddShapeCommand("triangle", canvas));
    Refactor::Button *addSquareButton =
        new Refactor::Button(new Refactor::AddShapeCommand("square", canvas));
    Refactor::Button *clearButton =
        new Refactor::Button(new Refactor::ClearCommand(canvas));

    addTriangleButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";
    addSquareButton->click();
    addSquareButton->click();
    addTriangleButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";

    clearButton->click();
    std::cout << "Current Canvas State: " << VectorToString(canvas->getShapes())
              << "\n";
  }

  return EXIT_SUCCESS;
}
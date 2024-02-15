#include <filesystem>
#include <iostream>

#include "InterpreterExample.h"

int main(int argc, char **argv) {

  std::cout << "Interpreter Pattern Example" << std::endl;

  NumberExpression *five = new NumberExpression("5");
  NumberExpression *seven = new NumberExpression("7");

  OperationExpression *fivePlusSeven =
      new OperationExpression("+", five, seven);

  std::cout << "Evaluate to " << fivePlusSeven->evaluate() << std::endl;

  NumberExpression *thirteen = new NumberExpression("13");

  OperationExpression *complexOp =
      new OperationExpression("-", thirteen, fivePlusSeven);
  std::cout << "Evaluate to " << complexOp->evaluate() << std::endl;

  return EXIT_SUCCESS;
}
#include <iostream>

class Expression {
public:
  virtual int evaluate() = 0;
};

class OperationExpression : public Expression {
  std::string operatorSymbol_;
  Expression *leftHandSide_;
  Expression *rightHandSide_;

public:
  OperationExpression(const std::string &operatorSymbol, Expression *lhs,
                      Expression *rhs)
      : operatorSymbol_(operatorSymbol), leftHandSide_(lhs),
        rightHandSide_(rhs) {}
  int evaluate() override {
    if (operatorSymbol_ == "+") {
      return leftHandSide_->evaluate() + rightHandSide_->evaluate();
    } else if (operatorSymbol_ == "-") {
      return leftHandSide_->evaluate() - rightHandSide_->evaluate();

    } else if (operatorSymbol_ == "/") {
      return leftHandSide_->evaluate() / rightHandSide_->evaluate();

    } else if (operatorSymbol_ == "*") {
      return leftHandSide_->evaluate() * rightHandSide_->evaluate();

    } else {
      std::cout << "Unrecognized operator [" << operatorSymbol_ << "]"
                << std::endl;
      return 0;
    }
  }
};

class NumberExpression : public Expression {
  std::string number_;

public:
  NumberExpression(const std::string &number) : number_(number) {}
  int evaluate() override { return std::stoi(number_); }
};
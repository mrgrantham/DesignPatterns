#pragma once

#include <iostream>

namespace Refactor {
class State {
public:
  virtual std::string getDescription() const = 0;
  virtual State *getNextState() = 0;
};

class PurchasedState : public State {
  State *nextState_ = nullptr;

public:
  PurchasedState(State *nextState) : nextState_(nextState) {}
  std::string getDescription() const override {
    return "Current State: PURCHASED";
  }
  State *getNextState() override { return nextState_; }
};

class InTransitState : public State {
  State *nextState_ = nullptr;

public:
  InTransitState(State *nextState) : nextState_(nextState) {}
  std::string getDescription() const override {
    return "Current State: IN_TRANSIT";
  }
  State *getNextState() override { return nextState_; }
};

class DeliveredState : public State {
  State *nextState_ = nullptr;

public:
  DeliveredState(State *nextState) : nextState_(nextState) {}
  std::string getDescription() const override {
    return "Current State: DELIVERED";
  }
  State *getNextState() override { return nextState_; }
};

class Purchase {
  std::string productName_;
  State *currentState_;

public:
  Purchase(const std::string &productName, State *initialState)
      : productName_(productName), currentState_(initialState) {}

  std::string getDescription() const {
    if (!currentState_) {
      return "no state available to describe";
    }
    return productName_ + " - " + currentState_->getDescription();
  }

  void goToNextState() {
    if (!currentState_)
      return;

    if (auto nextState = currentState_->getNextState()) {
      currentState_ = nextState;
    } else {
      currentState_ = nullptr;
      std::cout << "No more states!" << std::endl;
    }
  }
};

} // namespace Refactor
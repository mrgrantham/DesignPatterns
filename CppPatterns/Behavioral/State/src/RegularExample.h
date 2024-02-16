#pragma once

#include <iostream>

class Purchase {
  std::string productName_;
  std::string currentState_;

public:
  Purchase(const std::string &productName, const std::string &initialState)
      : productName_(productName), currentState_(initialState) {}

  std::string getDescription() const {
    std::string description = productName_ + " - " + currentState_ + "\n";

    if (currentState_ == "PURCHASED") {
      description += "Will be shipping soon\n";

    } else if (currentState_ == "IN_TRANSIT") {
      description += "Your item is on the way\n";
    } else if (currentState_ == "DELIVERED") {
      description += "Your item has arrrived\n";
    }
    return description;
  }

  void goToNextState() {
    if (currentState_ == "PURCHASED") {
      currentState_ = "IN_TRANSIT";
    } else if (currentState_ == "IN_TRANSIT") {
      currentState_ = "DELIVERED";
    } else if (currentState_ == "DELIVERED") {
      std::cout << "No more states!" << std::endl;
    }
  }
};
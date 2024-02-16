#include <filesystem>
#include <iostream>

#include "RegularExample.h"
#include "StateExample.h"

int main(int argc, char **argv) {

  std::cout << "State Pattern Example" << std::endl;

  /** Initial Example */
  {
    Purchase purchase("Shoes", "PURCHASED");
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
  }

  /** Refactor with State Pattern */
  {
    Refactor::DeliveredState *deliveredState =
        new Refactor::DeliveredState(nullptr);
    Refactor::InTransitState *inTransitState =
        new Refactor::InTransitState(deliveredState);
    Refactor::PurchasedState *purchasedState =
        new Refactor::PurchasedState(inTransitState);

    Refactor::Purchase purchase("Shoes", purchasedState);

    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
    purchase.goToNextState();
    std::cout << purchase.getDescription() << std::endl;
  }
  return EXIT_SUCCESS;
}
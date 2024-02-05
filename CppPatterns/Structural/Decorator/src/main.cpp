#include <iostream>

#include "DecoratorExample.h"
#include "RegularExample.h"

int main(int argc, char **argv) {
  std::cout << "Decorator Pattern Example" << std::endl;

  // Original Example
  {
    auto desktop = new Desktop();
    std::cout << desktop->description() << " costs $" << desktop->price()
              << std::endl;

    auto laptop = new Laptop();
    std::cout << laptop->description() << " costs $" << laptop->price()
              << std::endl;

    auto desktopGraphicsUpgrade = new DesktopWithGraphicsCard();
    std::cout << desktopGraphicsUpgrade->description() << " costs $"
              << desktopGraphicsUpgrade->price() << std::endl;

    auto laptopMemoryUpgrade = new LaptopWithMemoryUpgrade();
    std::cout << laptopMemoryUpgrade->description() << " costs $"
              << laptopMemoryUpgrade->price() << std::endl;
  }

  std::cout << "\n=======" << std::endl;

  // Refactored with Decorator
  {
    auto desktop = new Refactor::Desktop();
    std::cout << desktop->description() << " costs $" << desktop->price()
              << std::endl;

    auto laptop = new Refactor::Laptop();
    std::cout << laptop->description() << " costs $" << laptop->price()
              << std::endl;

    auto desktopMemoryUpgrade = new Refactor::MemoryUpgradeDecorator(desktop);
    std::cout << desktopMemoryUpgrade->description() << " costs $"
              << desktopMemoryUpgrade->price() << std::endl;

    auto laptopGraphicsUpgrade =
        new Refactor::GraphicsCardUpgradeDecorator(laptop);
    std::cout << laptopGraphicsUpgrade->description() << " costs $"
              << laptopGraphicsUpgrade->price() << std::endl;
  }

  return EXIT_SUCCESS;
}
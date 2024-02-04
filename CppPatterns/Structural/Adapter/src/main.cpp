#include <iostream>
#include <memory>

#include "AdapterExample.h"

/** Adapte allows two incompatible interfaces to work together
 * a shim of sorts
 */
int main(int argc, char **argv) {
  std::cout << "Adapter Pattern Example" << std::endl;

  const std::unique_ptr<Component> components[]{
      std::make_unique<ConcreteComponentA>(),
      std::make_unique<ConcreteComponentB>(),
      std::make_unique<LegacyAdapterInheritance>(),
      std::make_unique<LegacyAdapterComposition>()};

  for (const auto &component : components) {
    component->run();
  }

  return EXIT_SUCCESS;
}
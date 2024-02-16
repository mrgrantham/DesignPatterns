#include <filesystem>
#include <iostream>

#include "IteratorExample.h"

int main(int argc, char **argv) {

  std::cout << "Iterator Pattern Example" << std::endl;

  /** The Iterator Pattern allows for seuqnecal access to all elements in a data
   * structure. It is not uncommon to have different type of iterators for a
   * data structure that may traverse the structure in different ways. */

  NumberCollection collection({11, 22, 33, 44, 55, 66});

  auto forwardsIt = collection.getForwardsIterator();
  auto backwardsIt = collection.getBackwardsIterator();

  std::cout << "== Iterating Forwards == \n";
  while (!forwardsIt->isFinished()) {
    std::cout << "Val: " << forwardsIt->next() << "\n";
  }

  std::cout << "== Iterating Backwards == \n";
  while (!backwardsIt->isFinished()) {
    std::cout << "Val: " << backwardsIt->next() << "\n";
  }
  return EXIT_SUCCESS;
}
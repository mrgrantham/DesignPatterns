#include <iostream>

#include "CompositeExample.h"
#include "PreCompositeExample.h"

/** Composite pattern uses the concept of composite and leaf objects in a
 * tree like structure
 */

int main(int argc, char **argv) {
  std::cout << "Composite Pattern Example" << std::endl;

  {
    // Before refactor
    // Create Items
    Book book1{"Blink", 4.98};
    Book book2{"Stranger in a Strange Land", 19.99};
    Toy toy1{"Stretch Armstrong", 29.99};

    // Create Boxes

    Box smallBox{"Small Box"};
    smallBox.addBook(book1);
    smallBox.addBook(book2);

    Box bigBox{"Big Box"};
    bigBox.addToy(toy1);
    bigBox.addBox(smallBox);

    // Calculate price
    std::cout << "Calculating total price. \n"
              << bigBox.totalPrice() << std::endl;
  }

  {
    // Refactored with composite pattern
    // Before refactor
    // Create Items
    Refactor::Book book1{"Blink", 4.98};
    Refactor::Book book2{"Stranger in a Strange Land", 19.99};
    Refactor::Toy toy1{"Stretch Armstrong", 29.99};

    // Create Boxes

    Refactor::Box smallBox{"Small Box"};
    smallBox.addItem(book1);
    smallBox.addItem(book2);

    Refactor::Box bigBox{"Big Box"};
    bigBox.addItem(toy1);
    bigBox.addItem(smallBox);

    // Calculate price
    std::cout << "Calculating total price. \n" << bigBox.price() << std::endl;
  }
  return EXIT_SUCCESS;
}
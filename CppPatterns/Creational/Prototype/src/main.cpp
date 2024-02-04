#include <iostream>

#include "PrototypeExample.h"

/** Prototype pttern enbles making objects thata are
 * copies of other objects a much simpler process.
 *
 *
 */

int main(int argc, char **argv) {
  std::cout << "Prototype Pattern Example" << std::endl;

  Sheep *sheep0 = new Sheep;
  sheep0->setHairColor("white");
  sheep0->setTail(5);
  sheep0->setWeight(90);
  sheep0->setHeight(1);
  sheep0->setWeight(5);

  Cow *cow0 = new Cow;
  cow0->setHairColor("black");
  cow0->setTail(20);
  cow0->setWeight(999);
  cow0->setHeight(2);
  cow0->setAge(8);

  Animal *farm[3];

  farm[0] = sheep0->clone();
  farm[1] = cow0->clone();

  farm[1]->setWeight(2000);

  sheep0->shearing();

  farm[2] = sheep0->clone();

  return 0;
}
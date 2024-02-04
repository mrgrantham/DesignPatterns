#include <iostream>

#include "SingletonExample.h"

int main(int argc, char **argv) {
  std::cout << "Singleton Pattern Example" << std::endl;

  // // Will not compile
  // Leader *electedLeder = new Leader;

  // Correct use
  auto electedLeader = Leader::GetInstance();

  electedLeader->giveSpeech();

  return EXIT_SUCCESS;
}
#include <filesystem>
#include <iostream>

#include "ObserverExample.h"

int main(int argc, char **argv) {

  std::cout << "Observer Pattern Example" << std::endl;

  ChatUser *user1 = new ChatUser("James");
  ChatUser *user2 = new ChatUser("Jim");
  ChatUser *user3 = new ChatUser("Jimmy");
  ChatUser *user4 = new ChatUser("Josh");

  ChatGroup *group1 = new ChatGroup("LGBTQIA");
  ChatGroup *group2 = new ChatGroup("Plant Lovers");

  group1->subscribe(user1);
  group1->subscribe(user2);

  group2->subscribe(user2);
  group2->subscribe(user3);
  group2->subscribe(user4);

  group1->publish("Bearracuda this weekend!");
  group2->publish("Dont forget to water your babies!");

  return EXIT_SUCCESS;
}
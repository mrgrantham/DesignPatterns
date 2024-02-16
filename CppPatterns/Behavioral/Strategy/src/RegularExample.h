#pragma once

#include <iostream>

class Person {
public:
  virtual void greet(const std::string &name) = 0;
};

class BusinessPerson : public Person {
public:
  void greet(const std::string &name) override {
    std::cout << "Good Morning " << name << ", how do you do?\n";
  }
};

class NormalPerson : public Person {
public:
  void greet(const std::string &name) override {
    std::cout << "Hi " << name << ", how are you?\n";
  }
};

class CoolPerson : public Person {
public:
  void greet(const std::string &name) override {
    std::cout << "Hey " << name << ", what's up?\n";
  }
};

class Politician : public Person {
public:
  void greet(const std::string &name) override {
    std::cout << "Good Morning " << name << ", how do you do?\n";
  }
};
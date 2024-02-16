#pragma once

#include <iostream>

namespace Refactor {

class GreetingStrategy {
public:
  virtual void greet(const std::string &name) = 0;
  virtual ~GreetingStrategy() {}
};

class FormalGreetingStrategy : public GreetingStrategy {
public:
  void greet(const std::string &name) override {
    std::cout << "Good Morning " << name << ", how do you do?\n";
  }
};

class NormalGreetingStrategy : public GreetingStrategy {
public:
  void greet(const std::string &name) override {
    std::cout << "Hi " << name << ", how are you?\n";
  }
};

class InformalGreetingStrategy : public GreetingStrategy {
public:
  void greet(const std::string &name) override {
    std::cout << "Hey " << name << ", what's up?\n";
  }
};

class Person {
  GreetingStrategy *greetingStrategy_;

public:
  Person(GreetingStrategy *greetingStrategy)
      : greetingStrategy_(greetingStrategy) {}
  ~Person() { delete greetingStrategy_; }
  void greet(const std::string &name) { greetingStrategy_->greet(name); }
};

} // namespace Refactor
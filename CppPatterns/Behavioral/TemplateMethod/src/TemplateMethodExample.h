#include <iostream>

class GreetingCardTemplate {
protected:
  virtual std::string intro(const std::string &to) {
    return "Dear " + to + ",\n";
  }
  virtual std::string occasion() {
    return "Just writing to say hi! Hope all is well with you.\n";
  }

  virtual std::string closing(const std::string &from) {
    return "Sincerely,\n" + from + "\n";
  }

public:
  virtual std::string generate(const std::string &to, const std::string &from) {
    return intro(to) + occasion() + closing(from);
  }
};

class BirthdayCardTempate : public GreetingCardTemplate {
protected:
  std::string occasion() override {
    return "Happy Birthday! Hope you have a wonderful day and lots of cake.\n";
  }
};

class NewYearsCardTemplate : public GreetingCardTemplate {
protected:
  std::string intro(const std::string &to) override { return to + "!!!\n"; }
  std::string occasion() override {
    return "Happy Ney Years!! See you at the gym tomorrow!\n";
  }
};
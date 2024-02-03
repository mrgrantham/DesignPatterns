#include <iostream>

/** These examples rely on the implicitly defined
 * copy constructor that is generated for this trivial
 * implementation with simple member variables
 */

class Animal {
protected:
  char hairColor_[10];
  int hairLength_{0};
  int tail_{0};
  int weight_{0};
  int height_{0};
  int age_{0};

  int intelligence_{0};
  int stubbornness_{0};
  int aggressiveness_{0};

public:
  virtual Animal *clone() = 0;

  void setHairLength(int length) { hairLength_ = length; }

  void setHairColor(const char *color) { strcpy(hairColor_, color); }

  void setTail(int length) { tail_ = length; }

  void setWeight(int kg) { weight_ = kg; }

  void setHeight(int m) { height_ = m; }

  void setAge(int age) { age_ = age; }
};

class Sheep : public Animal {
public:
  Sheep() {
    hairLength_ = 5;
    stubbornness_ = 3;
    aggressiveness_ = 2;
    intelligence_ = 7;
  }
  Sheep *clone() override { return new Sheep(*this); }
  void shearing() { hairLength_ -= 2; }
};

class Cow : public Animal {
public:
  Cow() {
    stubbornness_ = 6;
    aggressiveness_ = 5;
    intelligence_ = 8;
  }

  Cow *clone() override { return new Cow(*this); }
};
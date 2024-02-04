#pragma once

#include <iostream>

#pragma region Entree
// base Entree class
class Entree {
protected:
  char entree_[10];

public:
  const char *getEntree() { return entree_; }
};

class Burger : public Entree {
public:
  Burger() : Entree() {
    std::cout << "\n Grill burger patty, add tomatoes bd pace them in a bun";
    strcpy(entree_, "burger");
  }
};

class HotDog : public Entree {
public:
  HotDog() : Entree() {
    std::cout << "\n Cook sausage and place it in a bun";
    strcpy(entree_, "hotdog");
  }
};

#pragma endregion Entree
#pragma region Sides

// Base Side class
class Side {
protected:
  char side_[10];

public:
  char *getSide() { return side_; }
};

class Fries : public Side {
public:
  Fries() : Side() {
    std::cout << "\n Fry and season potatoes";
    strcpy(side_, "fries");
  }
};

class Salad : public Side {
public:
  Salad() : Side() {
    std::cout << "\n Toss greens and dressing together";
    strcpy(side_, "salad");
  }
};
#pragma endregion Sides

class Drink {
protected:
  char drink_[10];

public:
  Drink() {
    std::cout << "\n Fill cup with soda" << std::endl;
    strcpy(drink_, "soda");
  }
  char *getDrink() { return drink_; }
};

class MealCombo {
private:
  Entree *entree_;
  Side *side_;
  Drink *drink_;
  char bag_[100];

public:
  MealCombo(const char *type) {
    snprintf(bag_, sizeof(bag_), "\n %s meal combo:", type);
  }
  void setEntree(Entree *e) { entree_ = e; }

  void setSide(Side *side) { side_ = side; }
  void setDrink(Drink *drink) { drink_ = drink; }

  const char *openMealBag() {
    if (!side_ || !entree_ || !drink_) {
      return "\n order incorrect, missing items";
    }
    snprintf(bag_, sizeof(bag_), "%s %s, %s, %s", bag_, entree_->getEntree(),
             side_->getSide(), drink_->getDrink());
    return bag_;
  }
};

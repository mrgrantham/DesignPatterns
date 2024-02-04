#pragma once

#include <Composition.h>

class MealBuilder {
protected:
  MealCombo *meal_;

public:
  virtual void cookEntree() = 0;
  virtual void cookSide() = 0;
  virtual void pourDrink() = 0;
  MealCombo *getMeal() { return meal_; }
};

class BurgerMeal : public MealBuilder {
public:
  BurgerMeal() { meal_ = new MealCombo("Burger"); }
  void cookEntree() override {
    Burger *burger = new Burger;
    meal_->setEntree(burger);
  }
  void cookSide() override {
    Fries *fries = new Fries;
    meal_->setSide(fries);
  }
  void pourDrink() override {
    Drink *drink = new Drink;
    meal_->setDrink(drink);
  }
};

class HotDogMeal : public MealBuilder {
public:
  HotDogMeal() { meal_ = new MealCombo("HotDog"); }
  void cookEntree() override {
    HotDog *hotdog = new HotDog;
    meal_->setEntree(hotdog);
  }
  void cookSide() override {
    Salad *salad = new Salad;
    meal_->setSide(salad);
  }
  void pourDrink() override {
    Drink *drink = new Drink;
    meal_->setDrink(drink);
  }
};
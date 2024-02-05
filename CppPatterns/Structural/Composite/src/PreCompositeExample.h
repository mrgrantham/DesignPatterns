#pragma once

#include <iostream>
#include <string>

// Concrete
class Book {
public:
  Book(const std::string &title, double price) : title_(title), price_(price) {}
  double price() const {
    std::cout << "Getting \"" << title_ << "\" book price" << std::endl;
    return price_;
  }

private:
  std::string title_;
  double price_;
};

class Toy {
public:
  Toy(const std::string &name, double price) : name_(name), priceTag_(price) {}
  double getPriceTag() const {
    std::cout << "Getting \"" << name_ << "\" toy price tag" << std::endl;
    return priceTag_;
  }

private:
  std::string name_;
  double priceTag_;
};

class Box {
private:
  std::string name_;
  std::vector<Book *> books_;
  std::vector<Toy *> toys_;
  std::vector<Box *> boxes_;

public:
  explicit Box(const std::string &name) : name_(name) {}

  void addBook(Book &book) { books_.push_back(&book); }

  void addToy(Toy &toy) { toys_.push_back(&toy); }

  void addBox(Box &box) { boxes_.push_back(&box); }

  double totalPrice() const {
    std::cout << "Opening " << name_ << std::endl;
    double totalPrice = 0;

    for (const auto &book : books_) {
      totalPrice += book->price();
    }

    for (const auto &toy : toys_) {
      totalPrice += toy->getPriceTag();
    }

    for (const auto &box : boxes_) {
      totalPrice += box->totalPrice();
    }
    return totalPrice;
  }
};
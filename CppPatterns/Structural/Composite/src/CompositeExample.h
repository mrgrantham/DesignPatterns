#pragma once

namespace Refactor {
  class BoxItem {
    public:
    virtual double price() const=0;
    virtual ~BoxItem() = default;
  };
// Concrete
class Book : public BoxItem{
public:
  Book(const std::string &title, double price) : title_(title), price_(price) {}
  double price() const override {
    std::cout << "Getting \"" << title_ << "\" book price" << std::endl;
    return price_;
  }

private:
  std::string title_;
  double price_;
};

class Toy : public BoxItem {
public:
  Toy(const std::string &name, double price) : name_(name), priceTag_(price) {}
  double price() const override {
    std::cout << "Getting \"" << name_ << "\" toy price tag" << std::endl;
    return priceTag_;
  }

private:
  std::string name_;
  double priceTag_;
};

class Box : public BoxItem {
private:
  std::string name_;
  std::vector<BoxItem *> items_;

public:
  explicit Box(const std::string &name) : name_(name) {}

  void addItem(BoxItem &item) { items_.push_back(&item); }

  double price() const override {
    std::cout << "Opening " << name_ << std::endl;
    double totalPrice = 0;

    for (const auto &item : items_) {
      totalPrice += item->price();
    }
    return totalPrice;
  }
};
}
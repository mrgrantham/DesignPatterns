#pragma once

class Computer {
public:
  virtual std::string description() const = 0;
  virtual double price() const = 0;
  virtual ~Computer() = default;
};

class Desktop : public Computer {
public:
  std::string description() const override { return "Desktop"; }
  double price() const override { return 1000.0; }
};

class Laptop : public Computer {
public:
  std::string description() const override { return "Laptop"; }
  double price() const override { return 2000.0; }
};

class DesktopWithGraphicsCard : public Computer {
public:
  std::string description() const override {
    return "Desktop With Graphics Card";
  }
  double price() const override { return 1500.0; }
};

class LaptopWithMemoryUpgrade : public Computer {
public:
  std::string description() const override {
    return "Laptop With Memory Upgrade";
  }
  double price() const override { return 2500.0; }
};
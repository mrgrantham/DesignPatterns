#pragma once

namespace Refactor {
class Computer {
public:
  virtual std::string description() const = 0;
  virtual double price() const = 0;
  virtual ~Computer() = default;
};

class ComputerDecorator : public Computer {
public:
  explicit ComputerDecorator(Computer *computer) : computer_(computer) {}
  std::string description() const override { return computer_->description(); }
  double price() const override { return computer_->price(); }

protected:
  const Computer *computer_;
};

class MemoryUpgradeDecorator : public ComputerDecorator {
public:
  explicit MemoryUpgradeDecorator(Computer *computer)
      : ComputerDecorator(computer) {}
  std::string description() const override {
    return ComputerDecorator::description() + " with memory upgrade";
  }
  double price() const override { return ComputerDecorator::price() + 500.0; }
};

class GraphicsCardUpgradeDecorator : public ComputerDecorator {
public:
  explicit GraphicsCardUpgradeDecorator(Computer *computer)
      : ComputerDecorator(computer) {}
  std::string description() const override {
    return ComputerDecorator::description() + " with graphics card upgrade";
  }
  double price() const override { return ComputerDecorator::price() + 500.0; }
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
} // namespace Refactor
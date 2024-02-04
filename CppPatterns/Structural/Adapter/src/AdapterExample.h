
class Component {
public:
  virtual void run() = 0;
  virtual ~Component() = default;
};

class ConcreteComponentA : public Component {
public:
  void run() override {
    std::cout << "Executing " << __PRETTY_FUNCTION__ << std::endl;
  }
};

class ConcreteComponentB : public Component {
public:
  void run() override {
    std::cout << "Executing " << __PRETTY_FUNCTION__ << std::endl;
  }
};

// Incompatible class

class LegacyComponent {
public:
  void go() { std::cout << "Executing " << __PRETTY_FUNCTION__ << std::endl; }
};

// Adapter Class with Inheritance (Class Adapter)
class LegacyAdapterInheritance : public LegacyComponent, public Component {
public:
  void run() override {
    std::cout << "Executing " << __PRETTY_FUNCTION__ << " -> ";
    go(); // adaptee method
  }
};

// Adapter Class with Composition (Object Adapter)
class LegacyAdapterComposition : public LegacyComponent, public Component {
private:
  std::unique_ptr<LegacyComponent> legacyComponent_; // adaptee
public:
  LegacyAdapterComposition()
      : legacyComponent_(std::make_unique<LegacyComponent>()) {}

  void run() override {
    std::cout << "Executing " << __PRETTY_FUNCTION__ << " -> ";
    legacyComponent_->go();
  }
};
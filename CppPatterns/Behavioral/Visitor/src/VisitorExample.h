#include <iostream>

class Visitor {
public:
  virtual void handlePerson(const std::string &name, int age) = 0;
  virtual void handleLandmark(const std::string &name,
                              const std::string &cityName) = 0;
  virtual void handleCar(const std::string &make, const std::string &model) = 0;
};

class DatabaseVisitor : public Visitor {
public:
  virtual void handlePerson(const std::string &name, int age) override {
    std::cout << "Writing person to database: " << name << " age: " << age
              << std::endl;
  }
  virtual void handleLandmark(const std::string &name,
                              const std::string &cityName) override {
    std::cout << "Writing landmark to database: " << name
              << " city name: " << cityName << std::endl;
  }
  virtual void handleCar(const std::string &make,
                         const std::string &model) override {
    std::cout << "Writing car to database make: " << make << " model: " << model
              << std::endl;
  }
};

class TextFileVisitor : public Visitor {
public:
  virtual void handlePerson(const std::string &name, int age) override {
    std::cout << "Writing person to file: " << name << " age: " << age
              << std::endl;
  }
  virtual void handleLandmark(const std::string &name,
                              const std::string &cityName) override {
    std::cout << "Writing landmark to file: " << name
              << " city name: " << cityName << std::endl;
  }
  virtual void handleCar(const std::string &make,
                         const std::string &model) override {
    std::cout << "Writing car to file make: " << make << " model: " << model
              << std::endl;
  }
};

class Person {
  std::string name_;
  int age_;

public:
  Person(const std::string &name, int age) : name_(name), age_(age) {}
  void accept(Visitor *visitor) { visitor->handlePerson(name_, age_); }
};

class Landmark {
  std::string name_;
  std::string cityName_;

public:
  Landmark(const std::string &name, const std::string &cityName)
      : name_(name), cityName_(cityName) {}

  void accept(Visitor *visitor) { visitor->handleLandmark(name_, cityName_); }
};

class Car {
  std::string make_;
  std::string model_;

public:
  Car(const std::string &make, const std::string &model)
      : make_(make), model_(model) {}

  void accept(Visitor *visitor) { visitor->handleCar(make_, model_); }
};
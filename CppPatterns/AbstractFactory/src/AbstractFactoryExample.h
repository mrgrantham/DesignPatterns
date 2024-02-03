#pragma once

class Door {
public:
  Door() {}
  virtual void open() = 0;
};

class Engine {
protected:
  char sound_[15];

public:
  Engine() { strncpy(sound_, "", sizeof(sound_)); }
  virtual void run() = 0;
};

class CarFactory {
public:
  virtual Door *buildDoor() = 0;
  virtual Engine *buildEngine() = 0;
};

class GasCarDoor : public Door {
public:
  GasCarDoor() { std::cout << "Making a door for a gas car" << std::endl; }
  void open() override { std::cout << "click" << std::endl; }
};

class GasEngine : public Engine {
public:
  GasEngine() : Engine() {
    strncpy(sound_, "vroom", sizeof(sound_));
    std::cout << "Making a gas engine" << std::endl;
  }
  void run() { std::cout << sound_ << std::endl; }
};

class GasCarFactory : public CarFactory {
public:
  Door *buildDoor() override { return new GasCarDoor; }

  Engine *buildEngine() override { return new GasEngine; }
};

class ElectricCarDoor : public Door {
public:
  ElectricCarDoor() : Door() {
    std::cout << "Making a door for an electric car." << std::endl;
  }
  void open() override { std::cout << "shhhhhh" << std::endl; }
};

class ElectricEngine : public Engine {
public:
  ElectricEngine() : Engine() {
    strncpy(sound_, "bzzzzzz", sizeof(sound_));
    std::cout << "Making an electric engine" << std::endl;
  }
  void run() override { std::cout << sound_ << std::endl; }
};

class ElectricCarFactory : public CarFactory {
public:
  Door *buildDoor() override { return new ElectricCarDoor; }

  Engine *buildEngine() override { return new ElectricEngine; }
};
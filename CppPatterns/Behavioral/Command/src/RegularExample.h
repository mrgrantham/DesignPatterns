#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Canvas {
  private:
  std::vector<std::string> shapes_;
  public:
  void addShape(const std::string &newShape) {
    shapes_.push_back(newShape);
  }
  void clearAll() {
    shapes_.clear();
  }
  std::vector<std::string> getShapes() {return shapes_;}
};

class Button {
  public:
  virtual ~Button() {};
  virtual void click()=0;

};

class AddTriangleButton : public Button {
  private:
  Canvas *canvas_;
  public:
  AddTriangleButton(Canvas *canvas) : canvas_(canvas) {}
  void click() override {
    canvas_->addShape("triangle");
  }
};

class AddSquareButton : public Button {
  private:
  Canvas *canvas_;
  public:
  AddSquareButton(Canvas *canvas) : canvas_(canvas) {}
  void click() override {
    canvas_->addShape("square");
  }
};

class ClearButton : public Button {
  private:
  Canvas *canvas_;
  public:
  ClearButton(Canvas *canvas) : canvas_(canvas) {}
  void click() override {
    canvas_->clearAll();
  }
};

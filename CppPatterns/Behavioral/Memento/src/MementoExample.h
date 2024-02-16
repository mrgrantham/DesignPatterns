#include <iostream>

class Canvas;

class CanvasMemento {
  friend class Canvas;
  const std::vector<std::string> shapes_;

public:
  CanvasMemento(std::vector<std::string> &shapes) : shapes_(shapes) {}
};

class Canvas {
  std::vector<std::string> shapes_;
  std::vector<CanvasMemento *> oldStates_;

public:
  ~Canvas() {
    for (auto statePointer : oldStates_) {
      delete statePointer;
    }
    oldStates_.clear();
  }
  void addShape(const std::string &newShape) {
    oldStates_.push_back(new CanvasMemento(shapes_));
    shapes_.push_back(newShape);
  }

  void undo() {
    auto previousState = oldStates_.back();
    shapes_ = previousState->shapes_;
    oldStates_.pop_back();
    delete previousState;
  }

  void clearAll() { shapes_.clear(); }
  std::vector<std::string> getShapes() { return shapes_; }
};
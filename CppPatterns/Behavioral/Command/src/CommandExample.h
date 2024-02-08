#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Refactor {
class Canvas {
private:
  std::vector<std::string> shapes_;

public:
  void addShape(const std::string &newShape) { shapes_.push_back(newShape); }
  void clearAll() { shapes_.clear(); }
  std::vector<std::string> getShapes() { return shapes_; }
};

class Command {
public:
  virtual ~Command(){};
  virtual void execute() = 0;
};

class AddShapeCommand : public Command {
private:
  std::string shapeName_;
  Canvas *canvas_;

public:
  AddShapeCommand(const std::string &shapeName, Canvas *canvas)
      : shapeName_(shapeName), canvas_(canvas) {}
  void execute() { canvas_->addShape(shapeName_); }
};

class ClearCommand : public Command {
private:
  Canvas *canvas_;

public:
  ClearCommand(Canvas *canvas) : canvas_(canvas) {}
  void execute() override { canvas_->clearAll(); }
};

class Button {
private:
  Command *command_;

public:
  Button(Command *command) : command_(command) {}
  virtual ~Button(){};
  void click() { command_->execute(); }
};

} // namespace Refactor
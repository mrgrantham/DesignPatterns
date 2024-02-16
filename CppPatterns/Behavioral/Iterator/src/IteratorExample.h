#include <iostream>

class NumberIterator {
public:
  virtual ~NumberIterator() {}
  virtual int next() = 0;
  virtual bool isFinished() = 0;
};

class ForwardsIterator : public NumberIterator {
  std::vector<int> &numbers_;
  int currentPosition_;

public:
  ForwardsIterator(std::vector<int> &numbers)
      : numbers_(numbers), currentPosition_(0) {}
  int next() override {
    int current = numbers_.at(currentPosition_);
    currentPosition_ += 1;
    return current;
  }
  bool isFinished() override { return currentPosition_ >= numbers_.size(); }
};

class BackwardsIterator : public NumberIterator {
  std::vector<int> &numbers_;
  int currentPosition_;

public:
  BackwardsIterator(std::vector<int> &numbers)
      : numbers_(numbers), currentPosition_(numbers_.size() - 1) {}
  int next() override {
    int current = numbers_.at(currentPosition_);
    currentPosition_ -= 1;
    return current;
  }
  bool isFinished() override { return currentPosition_ < 0; }
};

class NumberCollection {
  std::vector<int> numbers_;

public:
  NumberCollection(const std::vector<int> &numbers) : numbers_(numbers) {}
  NumberIterator *getForwardsIterator() {
    return new ForwardsIterator(numbers_);
  }
  NumberIterator *getBackwardsIterator() {
    return new BackwardsIterator(numbers_);
  }
};
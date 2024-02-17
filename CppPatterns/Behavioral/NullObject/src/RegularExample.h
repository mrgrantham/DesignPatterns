#include <iostream>

class Logger {
public:
  virtual ~Logger() {}
  virtual void log(const std::string &message) = 0;
};

class ConsoleLogger : public Logger {
public:
  void log(const std::string &message) override {
    std::cout << "Console: " << message << std::endl;
  }
};

class FileLogger : public Logger {
  std::string filePath_;

public:
  FileLogger(const std::string &filePath) : filePath_(filePath) {}

  void log(const std::string &message) override {
    std::cout << "Logging message to file: " << filePath_ << ": " << message
              << "\n";
  }
};

class ApiLogger : public Logger {
  std::string url_;

public:
  ApiLogger(const std::string &url) : url_(url) {}
  void log(const std::string &message) {
    std::cout << "Logging message to API: " << url_ << ": " << message << "\n";
  }
};

class SomeTask {
  Logger *logger_;

public:
  SomeTask(Logger *logger) : logger_(logger) {}
  ~SomeTask() { delete logger_; }
  void execute() {
    // do tasks

    if (logger_) {
      logger_->log("Did tasks");
    }

    // do other tasks
    if (logger_) {
      logger_->log("Did other tasks");
    }

    // one last thing
    if (logger_) {
      logger_->log("Did one last thing");
    }
  }
};
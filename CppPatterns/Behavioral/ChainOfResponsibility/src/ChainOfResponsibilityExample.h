#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

class StringValidator {
public:
  virtual ~StringValidator() {}
  virtual StringValidator *setNext(StringValidator *nextValidator) = 0;
  virtual std::string validate(std::string) = 0;
};

// Defines functionality that all validators will have in common
class BaseValidator : public StringValidator {
protected:
  StringValidator *next = nullptr;

public:
  virtual ~BaseValidator() { delete next; }
  StringValidator *setNext(StringValidator *nextValidator) override {
    next = nextValidator;
    return nextValidator;
  }
  std::string validate(std::string testString) override {
    if (this->next) {
      return this->next->validate(testString);
    }
    return "Success!";
  }
};

class NotEmptyValidator : public BaseValidator {
public:
  NotEmptyValidator() {}
  std::string validate(std::string testString) override {
    puts("Checking if empty...");

    if (testString.empty()) {
      return "Please enter a value.";
    }
    return BaseValidator::validate(testString);
  }
};

class LengthValidator : public BaseValidator {
private:
  int minLength_;

public:
  LengthValidator(int minLength) : minLength_(minLength) {}
  std::string validate(std::string testString) override {
    puts("Checking string length...");

    if (testString.length() < minLength_) {
      return "Please enter a value longer than " + std::to_string(minLength_);
    }
    return BaseValidator::validate(testString);
  }
};

class RegexValidator : public BaseValidator {
private:
  std::string patternName_;
  std::string regexString_;

public:
  RegexValidator(std::string patternName, std::string regexString)
      : patternName_(patternName), regexString_(regexString) {}
  std::string validate(std::string testString) override {
    puts("Checking regex match...");

    if (!std::regex_match(testString, std::regex(regexString_))) {
      return "The value entered does not match the proper format for a " +
             patternName_;
    }
    return BaseValidator::validate(testString);
  }
};

template <typename CollectionType, typename ItemType>
static bool CollectionDoesContainItem(CollectionType collection,
                                      ItemType item) {
  return std::find(collection.begin(), collection.end(), item) !=
         collection.end();
}

class HistoryValidator : public BaseValidator {
private:
  std::vector<std::string> historyItems_;

public:
  HistoryValidator(std::vector<std::string> historyItems)
      : historyItems_(historyItems) {}
  std::string validate(std::string testString) override {
    puts("Checking if string has been used before...");

    if (CollectionDoesContainItem(historyItems_, testString)) {
      return "Please enter a value that you haven't entered before";
    }
    return BaseValidator::validate(testString);
  }
};
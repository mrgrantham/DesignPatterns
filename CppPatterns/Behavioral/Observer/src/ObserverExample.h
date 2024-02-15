#pragma once

#include <iostream>

class Subscriber {
public:
  virtual ~Subscriber() {}
  virtual void notify(const std::string &publisherName,
                      const std::string &message) = 0;
  virtual std::string getName() = 0;
};

class Publisher {
public:
  virtual ~Publisher() {}
  virtual void subscribe(Subscriber *subscriber) = 0;
  virtual void unsubscribe(Subscriber *subscriber) = 0;
  virtual void publish(const std::string &message) = 0;
};

class ChatGroup : public Publisher {
private:
  std::string groupName_;
  std::vector<Subscriber *> subscribers;

public:
  ChatGroup(const std::string &name) : groupName_(name) {}
  void subscribe(Subscriber *subscriber) override {
    this->subscribers.push_back(subscriber);
  }

  void unsubscribe(Subscriber *subscriber) override {

    this->subscribers.erase(
        std::remove_if(subscribers.begin(), subscribers.end(),
                       [subscriber](Subscriber *s) -> bool {
                         return subscriber->getName() == s->getName();
                       }),
        subscribers.end());
  }

  void publish(const std::string &messge) override {
    for (auto subscriber : subscribers) {
      subscriber->notify(groupName_, messge);
    }
  }
};

class ChatUser : public Subscriber {
private:
  std::string userName_;

public:
  ChatUser(const std::string &userName) : userName_(userName) {}
  void notify(const std::string &publisherName,
              const std::string &message) override {
    std::cout << userName_ << " received a new message from " << publisherName
              << ": " << message << std::endl;
  }

  std::string getName() override { return userName_; }
};
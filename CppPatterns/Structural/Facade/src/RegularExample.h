#pragma once

#include <iostream>
#include <memory>
#include <string>

// Mock class for a database library
class Database {
public:
  void storeReservation(const std::string &reservation) {
    std::cout << "Database: Storing reservation: " << reservation << std::endl;
  }
};

// Mock class for a payment gateway
class PaymentGateway {
public:
  void processPayment(const std::string &paymentInfo) {
    std::cout << "Processing payment with info: " << paymentInfo << std::endl;
  }
};

// Mock class for a messaging service
class MessagingService {
public:
  void sendConfirmation(const std::string &message) {
    std::cout << "Messaging Service: Sending confirmation message: " << message
              << std::endl;
  }
};
#pragma once

#include "RegularExample.h"

class ReservationSystemFacade {
private:
  Database database_;
  PaymentGateway paymentGateway_;
  MessagingService messagingService_;

public:
  ReservationSystemFacade()
      : database_(), paymentGateway_(), messagingService_() {}

  void makeReservation(const std::string &reservationInfo,
                       const std::string &paymentInfo) {
    database_.storeReservation(reservationInfo);
    paymentGateway_.processPayment(paymentInfo);
    messagingService_.sendConfirmation("Reservation Confirmed");
  }
};
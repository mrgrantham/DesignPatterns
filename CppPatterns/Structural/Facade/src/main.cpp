#include <iostream>

#include "FacadeExample.h"
#include "RegularExample.h"

/** Facade pattern provides a simplified interface to complex subsystems of
 * multiple objects through one interface
 */

int main(int argc, char **argv) {
  std::cout << "Facade Pattern Example" << std::endl;

  /** Complex Example */
  Database db;
  PaymentGateway paymentGateway;
  MessagingService messagingService;

  const std::string reservation = "Room reservation info";
  db.storeReservation(reservation);

  const std::string paymentInfo = "Payment info";
  paymentGateway.processPayment(paymentInfo);

  messagingService.sendConfirmation("Reservation confirmed");

  /** Facade Example, hides the complex underlying components and presents a
   * simpler interface to use
   */

  ReservationSystemFacade reservationSystem;

  reservationSystem.makeReservation("Room reservation info", "Payment info");

  return EXIT_SUCCESS;
}
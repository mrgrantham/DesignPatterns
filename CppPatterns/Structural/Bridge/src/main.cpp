#include <iostream>

#include "BridgeExample.h"

/** Bridge pattern helps solve the exploding class heirarchy problem
 * by switching from inheritance to object composition
 */
int main(int argc, char **argv) {
  std::cout << "Bridge Pattern Example" << std::endl;

  PlainTextHandler handler = PlainTextHandler();
  EncryptedTextHandler encryptedHandler = EncryptedTextHandler();

  const std::unique_ptr<TextSharerInterface> sharingServices[]{
      std::make_unique<EmailShare>(handler),
      std::make_unique<EmailShareEncrypted>(encryptedHandler)};

  const std::string message = "Beam me up scotty!!";
  for (const auto &service : sharingServices) {
    service->shareText(message);
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
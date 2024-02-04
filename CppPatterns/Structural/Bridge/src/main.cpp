#include <iostream>

#include "BridgeExample.h"

/** Bridge pattern helps solve the exploding class heirarchy problem
 * by switching from inheritance to object composition
 * 
 * This example is still a little confusion the solution still
 * seems similarly complex to the original but perhaps
 * there is more opportunity for slower growth when adding additional
 * share and text mechanisms
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
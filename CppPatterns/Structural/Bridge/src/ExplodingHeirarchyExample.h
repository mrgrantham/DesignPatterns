
namespace Explode {
/** Example of Exploding Heirarchy of classes
 *
 *
 * */

class TextShareInterface {
public:
  virtual bool shareText(const std::string &text) = 0;
  virtual ~TextShareInterface() = default;
};

class EmailShare : public TextShareInterface {
public:
  bool shareText(const std::string &text) override {
    std::cout << "Sharing with " << __PRETTY_FUNCTION__ << std::endl;
    return true;
  }
};

class SMSShare : public TextShareInterface {
public:
  bool shareText(const std::string &text) override {
    std::cout << "Sharing with " << __PRETTY_FUNCTION__ << std::endl;
    return true;
  }
};

class EmailShareEncrypted : public EmailShare {
public:
  bool shareText(const std::string &text) override {
    std::cout << "Encrypting text with " << __PRETTY_FUNCTION__ << std::endl;
    std::string encryptedText = xorEncrypt(text);
    return EmailShare::shareText(encryptedText);
  }

private:
  std::string xorEncrypt(const std::string &input) {
    constexpr char key = 64;
    std::string output = input;

    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] ^ key;
    }
    return output;
  }
};

class SMSShareEncrypted : public SMSShare {
public:
  bool shareText(const std::string &text) override {
    std::cout << "Encrypting text with " << __PRETTY_FUNCTION__ << std::endl;
    std::string encryptedText = xorEncrypt(text);
    return SMSShare::shareText(encryptedText);
  }

private:
  std::string xorEncrypt(const std::string &input) {
    constexpr char key = 64;
    std::string output = input;

    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] ^ key;
    }
    return output;
  }
};

// More classes become more cumbersome and it becomes easier to redesign with
// bridge pattern

class EmailShareAutoExpiring : public EmailShare {
  //...
};

class SMSShareAutoExpiring : public SMSShare {
  //...
};

} // namespace Explode
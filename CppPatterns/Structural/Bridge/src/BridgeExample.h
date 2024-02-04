

/**
 * Hear we will reimplement using the bridge pattern
 */

class TextHandlerInterface {
public:
  virtual std::string prepareMessage(const std::string &text) const = 0;
  virtual ~TextHandlerInterface() = default;
};

class TextSharerInterface {
public:
  explicit TextSharerInterface(const TextHandlerInterface &textHandler)
      : textHandler_(textHandler) {}
  virtual bool shareText(const std::string &text) {
    const std::string preparedText = textHandler_.prepareMessage(text);
    return sharePreparedText(preparedText);
  }
  virtual ~TextSharerInterface() = default;

protected:
  virtual bool sharePreparedText(const std::string &text) = 0;

private:
  const TextHandlerInterface &textHandler_;
};

class PlainTextHandler : public TextHandlerInterface {
public:
  std::string prepareMessage(const std::string &text) const override {
    std::cout << "returning original text in " << __PRETTY_FUNCTION__
              << std::endl;
    return text;
  }
};

class EmailShare : public TextSharerInterface {
public:
  explicit EmailShare(const PlainTextHandler &handler)
      : TextSharerInterface(handler) {}

  bool sharePreparedText(const std::string &text) override {
    std::cout << "Sharing text with " << __PRETTY_FUNCTION__ << std::endl;
    return true;
  }
};

class EncryptedTextHandler : public TextHandlerInterface {
public:
  std::string prepareMessage(const std::string &text) const override {
    std::cout << "encrypting text in " << __PRETTY_FUNCTION__ << std::endl;
    return xorEncrypt(text);
  }

private:
  std::string xorEncrypt(const std::string &input) const {
    constexpr char key = 64;
    std::string output = input;

    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] ^ key;
    }
    return output;
  }
};

class EmailShareEncrypted : public TextSharerInterface {
public:
  explicit EmailShareEncrypted(const EncryptedTextHandler &handler)
      : TextSharerInterface(handler) {}

protected:
  bool sharePreparedText(const std::string &text) override {
    std::cout << "Sharing text with " << __PRETTY_FUNCTION__ << std::endl;
    return true;
  }
};
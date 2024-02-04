class Leader {
private:
  static Leader *Instance_;
  Leader() { std::cout << "New Leader Elected" << std::endl; }

public:
  static Leader *GetInstance() {
    // Not necessarily thread safe
    // Calling this once at start of program would
    // avoid the instantiation race condition
    if (!Instance_) {
      Instance_ = new Leader;
    }
    return Instance_;
  }
  void giveSpeech() { std::cout << "Addresss the public" << std::endl; }
};

Leader *Leader::Instance_ = nullptr;
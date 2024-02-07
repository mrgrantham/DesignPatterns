#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ConfigFile {
public:
  virtual std::vector<std::string> getSettings() = 0;
  virtual ~ConfigFile() = default;
};

class RealConfigFile : public ConfigFile {
public:
  explicit RealConfigFile(const std::string &filename) {
    std::cout << "RealConfigFile created" << std::endl;

    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
      settings_.push_back(line);
    }
    std::cout << settings_.size() << " settings loaded" << std::endl;
  }
  std::vector<std::string> getSettings() { return settings_; }

private:
  std::vector<std::string> settings_;
};

// ConfigFile Proxy only implements the RealConfigFile the first time it is
// accessed.
class ConfigFileProxy : public ConfigFile {
private:
  std::string filename_;
  std::unique_ptr<RealConfigFile> realConfigFile_;

public:
  explicit ConfigFileProxy(const std::string &filename)
      : filename_(filename), realConfigFile_(nullptr) {
    std::cout << "ConfigFileProxy created" << std::endl;
  }
  std::vector<std::string> getSettings() override {
    if (!realConfigFile_) {
      realConfigFile_ = std::make_unique<RealConfigFile>(filename_);
    }
    return realConfigFile_->getSettings();
  }
};

// Protective Proxy Example
class Storage {
  public:
  virtual const std::string getContents()=0;
  virtual ~Storage() = default;

};

class SecureStorage : public Storage {
  public:
  explicit SecureStorage(const std::string &data) : contents_(data) {
    std::cout << "Creating secure storage" << std::endl;
  }

  const std::string getContents() {return contents_;}
  private:
  std::string contents_;
};

class SecureStorageProxy : public Storage {
  private: 
  const std::string passcode_ = "1234";
  std::unique_ptr<SecureStorage> secureStorage_;
  public:
  explicit SecureStorageProxy(const std::string &passcode, const std::string &data) : secureStorage_(passcode_ == passcode? new SecureStorage(data) : nullptr) {

  }

  const std::string getContents() {
    if (secureStorage_) {
      return secureStorage_->getContents();
    }
    return "invalid passcode";
  }

};
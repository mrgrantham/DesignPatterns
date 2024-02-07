#include <filesystem>
#include <iostream>

#include "ProxyExample.h"

static void GenerateSampleFile(const std::string &filename) {
  std::cout << "file: " << filename << std::endl;

  std::ofstream samplefile;
  samplefile.open(filename);
  samplefile << "procedural: true\n"
                "flat_shading: false\n"
                "field_of_view: 75";
  samplefile.close();
}

int main(int argc, char **argv) {

  const char *exampleFileName = "proxy_config.txt";
  const std::filesystem::path exampleFilePath =
      std::filesystem::current_path() / exampleFileName;
  GenerateSampleFile(exampleFilePath);

  std::cout << "Proxy Pattern Example" << std::endl;

  /** No Proxy Example */
  RealConfigFile configFile(exampleFilePath);

  bool useSettings = true;

  if (useSettings) {
    std::vector<std::string> settings = configFile.getSettings();
    for (const auto &setting : settings) {
      std::cout << "Setting: " << setting << std::endl;
    }
  } else {
    std::cout << "configuration not used" << std::endl;
  }

  /** Virtual Proxy Example
   * This can be used to delay the creating of a potentially
   * expensive object until it is actually needed.
   */

  ConfigFileProxy configFileProxy(exampleFilePath);
  if (useSettings) {
    std::vector<std::string> settings = configFileProxy.getSettings();
    for (const auto &setting : settings) {
      std::cout << "Setting: " << setting << std::endl;
    }
  } else {
    std::cout << "configuration not used" << std::endl;
  }

  // Clean up sample file
  // std::remove(exampleFilePath.c_str());

  /** Protective Proxy Example
   * This example hides a secure storage instance
   * and its data behind a proxy that requires validation with the
   * correct passcode first
   */

  SecureStorageProxy brokenProxy("1233", "This is the secure data");
  std::cout << "Contents: " << brokenProxy.getContents() << std::endl;

  SecureStorageProxy workingProtectiveProxy("1234", "This is the secure data");
  std::cout << "Contents: " << workingProtectiveProxy.getContents()
            << std::endl;

  return EXIT_SUCCESS;
}
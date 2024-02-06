#include <iostream>
#include <vector>

class Texture {
public:
  explicit Texture(const std::string &fileName)
      : filename_(fileName), id_(arc4random_uniform(INT_MAX)) {
    std::cout << "Creating texture with file: " << filename_ << std::endl;
  }
  const std::string description() const {
    return "<" + filename_ + " id" + std::to_string(id_) + ">";
  }

private:
  const std::string filename_;
  const int id_;
};

class Sprite {
public:
  Sprite(int width, int height, int x, int y,
         const std::string &textureFileName)
      : width_(width), height_(height), x_(x), y_(y),
        texture_(new Texture(textureFileName)) {
    std::cout << "Creating sprite with texture file: "
              << texture_->description() << std::endl;
  }

  void render() {
    std::cout << "Rendering sprite of size [" << width_ << ", " << height_
              << "] with texture: " << texture_->description()
              << " at location [" << x_ << ", " << y_ << "]" << std::endl;
  }

private:
  const int width_;
  const int height_;
  const int x_;
  const int y_;
  const Texture *texture_;
};
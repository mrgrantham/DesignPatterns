#include <iostream>
#include <vector>

namespace Refactor {

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
  Sprite(const Texture *texture) : texture_(texture) {
    std::cout << "Creating sprite with texture file: "
              << texture_->description() << std::endl;
  }

  void setPositionSize(int width, int height, int x, int y) {
    width_ = width;
    height_ = height;
    x_ = x;
    y_ = y;
  }
  void render() {

    std::cout << "Rendering sprite of size [" << width_ << ", " << height_
              << "] with texture: " << texture_->description()
              << " at location [" << x_ << ", " << y_ << "]" << std::endl;
  }

private:
  int width_;
  int height_;
  int x_;
  int y_;
  const Texture *texture_;
};

class SpriteFactory {
public:
  Sprite *makeSprite(const std::string &filename) {
    auto it = spritePool_.find(filename);
    if (it != spritePool_.end()) {
      return it->second;
    }
    const auto texture = getTexture(filename);
    auto [newIt, _] = spritePool_.emplace(filename, new Sprite(texture));
    return newIt->second;
  }

  ~SpriteFactory() {
    for (auto &[filename, sprite] : spritePool_) {
      delete sprite;
    }

    for (auto &[filename, texture] : texturePool_) {
      delete texture;
    }
  }

private:
  const Texture *getTexture(const std::string &filename) {
    auto it = texturePool_.find(filename);
    if (it != texturePool_.end()) {
      return it->second;
    }
    auto [newIt, _] = texturePool_.emplace(filename, new Texture(filename));
    return newIt->second;
  }
  std::unordered_map<std::string, Sprite *> spritePool_;
  std::unordered_map<std::string, Texture *> texturePool_;
};
} // namespace Refactor
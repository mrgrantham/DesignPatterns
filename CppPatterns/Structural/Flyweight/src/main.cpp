#include <iostream>

#include "FlyweightExample.h"
#include "RegularExample.h"

int main(int argc, char **argv) {
  std::cout << "Flyweight Pattern Example" << std::endl;

  /** Unoptimized version */
  std::vector<Sprite *> sprites;
  const int numSprites = 10;
  const std::string textureFile = "Spaceship.png";

  for (int i = 0; i < numSprites; i++) {
    auto sprite = new Sprite(10, 10, i * 10, i * 10, textureFile);
    sprites.push_back(sprite);
  }

  /** Draw all sprites */
  for (auto &sprite : sprites) {
    sprite->render();
  }

  /** cleanup */
  for (auto &sprite : sprites) {
    delete (sprite);
  }

  /** Refactored with Flyweight pattern
   * This example is flawed in that the extrinsic
   * traits are overridden with each makeSprite call where
   * the sprite is useing hte same texture file. So all the
   * sprites are the same object with the last position and size
   * that was set in the for loop.
   *
   * A new sprite should be made for each makeSprite call while reusing the
   * texture object as that does not change for any of the sprites
   */
  {
    std::vector<Refactor::Sprite *> sprites;

    Refactor::SpriteFactory spriteFactory;
    for (int i = 0; i < numSprites; i++) {
      auto sprite = spriteFactory.makeSprite(textureFile);
      sprite->setPositionSize(10, 10, i * 10, i * 10);
      sprites.push_back(sprite);
    }

    for (auto &sprite : sprites) {
      sprite->render();
    }
  }
  return EXIT_SUCCESS;
}
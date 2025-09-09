#pragma once
#include <SFML/Graphics.hpp>

namespace ly {
class Application {
 public:
  Application();
  void run();
  void internal_tick(float delta_time);
  void internal_render();
  // this function will be called by this class users (the child classes)
  virtual void render();
  virtual void tick(float delta_time);

 private:
  sf::RenderWindow _window;
  float _target_framerate;
  sf::Clock _tick_clock;
};
}  // namespace ly
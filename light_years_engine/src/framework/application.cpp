

#include <framework/application.h>

#include <iostream>

ly::Application::Application()
    : _window{sf::VideoMode({500u, 500u}), "Light Years"},
      _target_framerate{60.f},
      _tick_clock{} {
  _window.setFramerateLimit(144);
}

void ly::Application::run() {
  _tick_clock.reset();
  float accumulated_time = 0.f;
  float target_delta_time = 1.f / _target_framerate;
  while (_window.isOpen()) {
    while (const std::optional event = _window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        _window.close();
      }
    }

    // accumulate the time with each while loop
    accumulated_time += _tick_clock.restart().asSeconds();

    // only update when the accumulated time reach the required
    // framerate
    while (accumulated_time > target_delta_time) {
      accumulated_time -= target_delta_time;
      internal_tick(target_delta_time);
      internal_render();
    }
  }
}

void ly::Application::internal_tick(float delta_time) {
  // every child class will be responsible for
  // what to do with their tick
  tick(delta_time);
  std::cout << "ticking at framerate: " << 1.f / delta_time << std::endl;
}

void ly::Application::internal_render() {
  _window.clear(sf::Color(10, 55, 150));

  render();

  _window.display();
}

void ly::Application::render() {
  sf::RectangleShape rect{sf::Vector2f{50, 50}};
  rect.setFillColor(sf::Color(50, 30, 10));
  rect.setPosition(sf::Vector2f{20, 20});
  _window.draw(rect);
}

void ly::Application::tick(float delta_time) {}
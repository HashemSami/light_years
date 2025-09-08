
#include <framework/Application.h>

#include <iostream>

ly::Application::Application()
    : _window{sf::VideoMode({500u, 500u}), "Light Years"} {
  _window.setFramerateLimit(144);
}

void ly::Application::Run() {
  while (_window.isOpen()) {
    while (const std::optional event = _window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        _window.close();
      }
    }

    _window.clear(sf::Color(10, 55, 150));
    _window.display();
  }
  std::cout << "Hello worlds" << std::endl;
}

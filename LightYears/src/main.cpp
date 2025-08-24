#include <SFML/Graphics.hpp>
#include <iostream>

class Product {
 public:
  std::string name;
  double price;

  void display() const {
    std::cout << "Product: " << name << ", Price: $" << price << std::endl;
  }
  bool hasName() { return name != ""; }
};

int main() {
  auto window =
      sf::RenderWindow(sf::VideoMode({500u, 500u}), "CMake SFML Project");
  window.setFramerateLimit(144);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(sf::Color(10, 55, 150));
    window.display();
  }
  std::cout << "Hello worlds" << std::endl;

  return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "framework/Application.h"

int main() {
  std::unique_ptr application = std::make_unique<ly::Application>();
  application->Run();

  return 0;
}
#include "entry_point.h"

#include <memory>

#include "framework/application.h"

int main() {
  ly::Application* app = get_application();
  app->run();
  return 0;
}
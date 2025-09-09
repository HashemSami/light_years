#include "framework/game_application.h"

ly::Application* get_application() { return new ly::GameApplication{}; }

namespace ly {}
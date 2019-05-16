#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"
constexpr uint16_t gameWidth = 1600;
constexpr uint16_t gameHeight = 800;
constexpr uint16_t invaders_rows = 1;
constexpr uint16_t invaders_columns = 6;

extern sf::Texture spritesheet;
extern std::vector<Ship*> ships;
extern Ship* railGun;
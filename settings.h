#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1200;
const float WINDOW_HEIGHT = 900;
const std::string WINDOW_TITLE = "SFML Asteroids P53122";
const size_t FPS = 60;

const double PI = 3.141592653589793;

const std::string IMAGES_FOLDER = "images\\";
const std::string PLAYER_FILE_NAME = "images\\spaceShips_008.png";
const int CHAR_SIZE = 48;
const std::string FONT_FILE_NAME = "ds-digib.ttf";
sf::Vector2f HP_TEXT_POS(0.f, 0.f);

const float TOP_BORDER = -300.f;
const float BOTTOM_BORDER = 1200.f;
const float LEFT_BORDER = -300.f;
const float RIGHT_BORDER = 1500.f;

const float LASER_SPEED = 15.f;
const std::string LASER_FILE_NAME = "laserRed03.png";
const int FIRE_COOLDOWN = 200;
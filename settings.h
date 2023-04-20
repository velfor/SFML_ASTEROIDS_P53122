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
const int MAX_PLAYER_LIVES = 3;
const int MAX_PLAYER_HP = 100;

const float TOP_BORDER = -300.f;
const float BOTTOM_BORDER = 1200.f;
const float LEFT_BORDER = -300.f;
const float RIGHT_BORDER = 1500.f;

const float LASER_SPEED = 15.f;
const std::string LASER_FILE_NAME = "laserRed03.png";
const int FIRE_COOLDOWN = 200;

const float FRAME_WIDTH = 150.f;
const float FRAME_HEIGHT = 30.f;

const std::string LIFE_ICON_FILE_NAME{ "star_gold.png" };
const std::string BONUS_MEDKIT_FILE_NAME{ "pill_yellow.png" };
const std::string BONUS_SPEED_BOOST_FILE_NAME{ "bolt_gold.png" };
const std::string BONUS_KABOOM_FILE_NAME{ "icon-explosion.png" };
const int BONUS_OPERATING_TIME{ 5000 };
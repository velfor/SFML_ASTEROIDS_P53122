#pragma once
#include "settings.h"

class Player;

class Bonus {
public:
	enum BonusType { MEDKIT, SPEED_BOOST, KABOOM, MAX_BONUS_TYPE};
	Bonus(sf::Vector2f meteorPos, size_t bonusType);
	void update();
	void draw(sf::RenderWindow& window);
	void act(Player& player);
	bool isToDel();
	auto getHitBox();
	void setDel();

private:
	BonusType type;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock timer;
	bool del = false;
};

Bonus::Bonus(sf::Vector2f meteorPos, size_t bonusType) {
	type = (BonusType)bonusType;
	switch (type) {
	case MEDKIT:
		texture.loadFromFile(IMAGES_FOLDER + BONUS_MEDKIT_FILE_NAME);
		break;
	case SPEED_BOOST:
		texture.loadFromFile(IMAGES_FOLDER + BONUS_SPEED_BOOST_FILE_NAME);
		break;
	case KABOOM:
		texture.loadFromFile(IMAGES_FOLDER + BONUS_KABOOM_FILE_NAME);
		break;
	}
	sprite.setTexture(texture);
	sprite.setPosition(meteorPos);
	timer.restart();
}

void Bonus::update() {
	int now = timer.getElapsedTime().asMilliseconds();
	if (now > 5000) {
		del = true;
	}
}

void Bonus::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

bool Bonus::isToDel() { return del; }

auto  Bonus::getHitBox() { return sprite.getGlobalBounds(); }

void Bonus::setDel() { del = true; }

void Bonus::act(Player& player) {
	switch (type) {
	case MEDKIT:
		player.addHp(50);
		break;
	case SPEED_BOOST:
		
		break;
	case KABOOM:
		
		break;
	}
}
#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
public:
	enum MeteorSize {SMALL, AVERAGE, BIG};
	Meteor(std::string fileName, MeteorSize size, sf::Vector2f pos, sf::Vector2f fspeed) {
		texture.loadFromFile(fileName);
		sprite.setTexture(texture);
		if (size == BIG) {
			sprite.setScale(0.5f, 0.5f);
		}
		else if (size == AVERAGE) {
			sprite.setScale(0.25f, 0.25f);
		}
		else if (size == SMALL) {
			sprite.setScale(0.125f, 0.125f);
		}
		sprite.setPosition(pos);
		speed = fspeed;
	}

	void update() {
		sprite.move(speed);
	}

	sf::Sprite getSprite() { return sprite; }
};
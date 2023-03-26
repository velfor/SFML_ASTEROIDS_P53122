#pragma once
#include "settings.h"

class Laser {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
public:
	Laser(sf::Vector2f playerPos, int playerAngle) {
		texture.loadFromFile(IMAGES_FOLDER + LASER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setRotation(playerAngle);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(playerPos);
		speedx = LASER_SPEED * sin(playerAngle * PI / 180);
		speedy = -LASER_SPEED * cos(playerAngle * PI / 180);
	}
	void update() {
		sprite.move(speedx, speedy);
	}

	sf::Sprite& getSprite() { return sprite; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};
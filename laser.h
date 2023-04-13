#pragma once
#include "settings.h"

class Laser {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	bool m_hit;

public:
	Laser(sf::Vector2f playerPos, int playerAngle) {
		texture.loadFromFile(IMAGES_FOLDER + LASER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setRotation((float)playerAngle);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(playerPos);
		speedx = LASER_SPEED * (float)sin(playerAngle * PI / 180);
		speedy = -LASER_SPEED * (float)cos(playerAngle * PI / 180);
		m_hit = false;
	}

	void update() {	sprite.move(speedx, speedy); }

	sf::Sprite& getSprite() { return sprite; }

	auto getHitBox() { return sprite.getGlobalBounds(); }

	void hit() { m_hit = true; }

	bool getHit() { return m_hit; }

	auto getPosition() { return sprite.getPosition(); }

	bool offScreen(){
		auto laserPos = getPosition();
		auto laserBounds = getHitBox();
		if (laserPos.x < -laserBounds.width ||
			laserPos.x > WINDOW_WIDTH + laserBounds.width ||
			laserPos.y > WINDOW_HEIGHT + laserBounds.height ||
			laserPos.y < -laserBounds.height)
		{
			return true;
		}
		return false;
	}
	
};
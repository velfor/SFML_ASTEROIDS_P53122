#pragma once
#include "settings.h"
#include "cmath"
#include <list>
#include "laser.h"
#include "textobj.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int angle;
	float speed, speedx, speedy;
	std::list<Laser*> lasers;
	sf::Clock timer;
	int hp = 100;
	int lives = MAX_PLAYER_LIVES;

public:
	Player(){
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
		angle = 0;
		speed = 0.f;
		timer.restart();
	}

	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//влево
			angle -= 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		sprite.setRotation((float)angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//вперед
			speed += 0.5f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//назад
			speed -= 0.25f;
		}
		if (speed < 0) speed = 0.f;
		else if (speed > 10.f) speed = 10.f;

		speedx = speed * (float)sin(angle * PI / 180);
		speedy = -speed * (float)cos(angle * PI / 180);
		sprite.move(speedx,speedy);
		fire();
		for (auto laser : lasers) {
			laser->update();
		}
		
	}

	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > FIRE_COOLDOWN) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				auto laser = new Laser(sprite.getPosition(), angle);
				lasers.push_back(laser);
				timer.restart();
			}
		}
	}

	void draw(sf::RenderWindow& window) {
		for (auto laser : lasers) {
			window.draw(laser->getSprite());
		}
		window.draw(sprite);
	}

	void decreaseHp(int damage) { hp -= damage; }

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	
	std::list<Laser*>* getLasers() { return &lasers; }

	int getHp() { return hp; }

	void restoreHp() { hp = MAX_PLAYER_HP; }

	void playerAddLife() { lives++; }

	void playerMinusLife() { lives--; }

	int getLives() { return lives; }
};
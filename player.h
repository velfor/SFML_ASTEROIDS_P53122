#pragma once
#include "settings.h"
#include "cmath"
#include <list>
#include "laser.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int angle;
	float speed, speedx, speedy;
	std::list<Laser*> lasers;

public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
		angle = 0;
		speed = 0.f;
	}

	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//влево
			angle -= 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		sprite.setRotation(angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//вперед
			speed += 0.5f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//назад
			speed -= 0.25f;
		}
		if (speed < 0) speed = 0.f;
		else if (speed > 10.f) speed = 10.f;

		speedx = speed * sin(angle * PI / 180);
		speedy = -speed * cos(angle * PI / 180);
		sprite.move(speedx,speedy);
		fire();
		for (auto laser : lasers) {
			laser->update();
		}
	}

	void fire() {
		//если нажал кнопку Выстрел
		//то создать Лазер
		//добавить Лазер в СписокЛазеров
	}

	//sf::Sprite& getSprite() { return sprite; }

	void draw(sf::RenderWindow& window) {
		//нарисовать свой спрайт
		//нарисовать все лазеры
	}
};
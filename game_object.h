#pragma once
#include "settings.h"
#include <iostream>

class GameObject {
public:
	GameObject() {
		std::cout << "GameObject constuctor" << std::endl;
	}
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

protected:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::Texture texture;
	sf::Sprite sprite;
};
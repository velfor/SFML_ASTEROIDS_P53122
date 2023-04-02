#pragma once
#include "settings.h"

class HpBar {
private:
	sf::RectangleShape frame;
	sf::RectangleShape hpBar;
	float hpBarWidth;
public:

	HpBar() {
		hpBar.setSize(sf::Vector2f{ FRAME_WIDTH, FRAME_HEIGHT });
		hpBar.setFillColor(sf::Color{sf::Color::Green});
		hpBar.setPosition(sf::Vector2f{ 7.f, 7.f });
		frame.setSize(sf::Vector2f{FRAME_WIDTH + 4, FRAME_HEIGHT + 4});
		frame.setOutlineColor(sf::Color::White);
		frame.setOutlineThickness(2);
		frame.setFillColor(sf::Color::Black);
		frame.setPosition(sf::Vector2f{ 5.f, 5.f });
	}

	void update(int playerHp) {
		if (playerHp < 0) {
			hpBarWidth = 0;
		}
		else{
			hpBarWidth = playerHp / 100.f * FRAME_WIDTH;
		}

		hpBar.setSize(sf::Vector2f{ hpBarWidth, FRAME_HEIGHT });
	}

	void draw(sf::RenderWindow& window) {
		window.draw(frame);
		window.draw(hpBar);
	}
};
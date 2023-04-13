#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <vector>
#include "meteor.h"
#include "player.h"
#include <list>
#include "laser.h"
#include "hp_bar.h"
#include "lives_indicator.h"

class Game {
private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteors;
	Player player;
	HpBar hpBar;
	std::list<LivesIndicator*> livesIndicator;

public:
	void spawnMeteors(size_t n) {
		for (int i = 0; i < n; i++) {
			int num = rand() % 4 + 1;
			std::string fileName = "images\\spaceMeteors_00" + std::to_string(num) + ".png";
			Meteor::MeteorSize size = (Meteor::MeteorSize)(rand() % 3);
			float x = rand() % 1801 - 300.f;
			float y = rand() % 1501 - 300.f;
			float speedx = rand() % 11 - 5.f;
			float speedy = rand() % 11 - 5.f;
			Meteor* m = new Meteor(fileName, size, sf::Vector2f{ x,y }, sf::Vector2f{speedx, speedy});
			meteors.push_back(m);
		}
	}
	Game() {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT}, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		spawnMeteors(20);
		for (size_t i = 0; i < MAX_PLAYER_LIVES; i++) {
			float xPos = WINDOW_WIDTH / 2 - 64.f;
			float yPos = 10.f;
			LivesIndicator* life = new LivesIndicator(sf::Vector2f{xPos + i*48.f, yPos});
			livesIndicator.push_back(life);
		}
	}

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		for (int i = 0; i < meteors.size(); i++) {
			meteors.at(i)->update();
		}
		player.update();
		hpBar.update(player.getHp());
	}

	void checkCollisions() {
		//метеоры c игроком
		sf::FloatRect playerBounds = player.getHitBox();
		for (auto& meteor : meteors) {
			sf::FloatRect meteorBounds = meteor->getHitBox();
			if (meteorBounds.intersects(playerBounds)) {
				meteor->setRandomPosition();
				player.decreaseHp(meteor->getDamage());
				if (player.getHp() < 0) {
					player.playerMinusLife();
					//если жизни == 0  - конец игры
					player.restoreHp();
					livesIndicator.pop_back();
				}
			}
		}

		auto laserSprites = player.getLasers();
		for (auto& meteor : meteors) {
			sf::FloatRect meteorBounds = meteor->getHitBox();
			for (auto laser : (* laserSprites)) {
				sf::FloatRect laserBounds = laser->getHitBox();
				if (meteorBounds.intersects(laserBounds)) {
					//добавить к счету столько очков, сколько стоит сбитый метеор
					meteor->setRandomPosition();
					laser->hit();
				}
			}
		}
		(*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
		(*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
	}

	void draw() {
		window.clear();
		for (int i = 0; i < meteors.size(); i++) {
			window.draw(meteors.at(i)->getSprite());
		}
		//window.draw(player.getSprite());
		player.draw(window);
		hpBar.draw(window);
		for (auto& life : livesIndicator) {
			life->draw(window);
		}
		window.display();
	}

	void play() {
		while (window.isOpen())	{
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
};
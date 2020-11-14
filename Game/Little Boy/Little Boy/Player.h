#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"


class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::Sprite body;
	bool canjump;
	sf::Vector2f velocity;
	bool status;

private:

	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	float jumpHeight;
	
};

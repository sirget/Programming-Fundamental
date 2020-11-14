#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Fire
{
public:
	Fire(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float position, float time, int statusitem, float scale, float itemy);
	~Fire();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Sprite body;
	float position;
	float timefire;
	int statusitem;
	
private:
	Animation animation;
	unsigned int row;
	bool faceRight = true;
};


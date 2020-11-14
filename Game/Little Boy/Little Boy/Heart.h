#pragma once
#include <SFML/Graphics.hpp>

class Heart
{
public:
	Heart(sf::Texture* texture, float position);
	~Heart();

	void Draw(sf::RenderWindow& window);

	sf::Sprite body;
	float position;
};


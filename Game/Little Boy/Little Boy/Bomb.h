#pragma once
#include <SFML/Graphics.hpp>

class Bomb
{
public:
	Bomb(sf::Texture* texture, float speed, float positionx, float positiony, float scale);
	~Bomb();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Sprite body;
	float positionx;
	float positiony;

private:
	
	float speed;
};


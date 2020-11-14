#include "Bomb.h"


Bomb::Bomb(sf::Texture* texture, float speed, float positionx, float positiony, float scale)
{
	this->positionx = positionx;
	this->positiony = positiony;
	this->speed = speed;
	body.setScale(scale,scale);
	body.setPosition(positionx, positiony);
	body.setTexture(*texture);
}

Bomb::~Bomb()
{
}

void Bomb::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y += speed;
	body.move(movement * deltaTime);
}

void Bomb::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
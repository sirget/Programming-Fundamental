#include "Fire.h"

Fire::Fire(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float position, float timefire, int statusitem, float scale, float itemy):
	animation(texture,imageCount,switchTime)
{
	this->timefire = timefire;
	this->position = position;
	this->statusitem = statusitem;
	row = 0;
	body.setScale(scale, scale);
	body.setPosition(position+50, itemy);
	body.setTexture(*texture);
}

Fire::~Fire()
{
}

void Fire::Update(float deltaTime)
{
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
}

void Fire::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
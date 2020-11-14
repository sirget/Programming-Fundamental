#include "Heart.h"



Heart::Heart(sf::Texture* texture, float position)
{
	this->position = position;
	body.setScale(2.0f, 2.0f);
	body.setPosition(position, 20);
	body.setTexture(*texture);
}

Heart::~Heart()
{
}

void Heart::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

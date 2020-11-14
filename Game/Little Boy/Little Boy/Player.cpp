#include "Player.h"
#include "Collission.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setScale(0.75f, 0.75f);
	body.setPosition(500.0f, 500.0f);
	body.setTexture(*texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime) //animation ตัวละคร
{
	if(status)
	{
		velocity.x = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x -= speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x += speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canjump)
		{
			canjump = false;
			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}

		if (velocity.x == 0.0f)
		{
			row = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				row = 3;
			}
			
		}
		else
		{
			row = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				row = 3;
			}
			if (velocity.x > 0.0f)
			{
				faceRight = true;
			}
			else
			{
				faceRight = false;
			}
		}

		if (canjump == false)
		{
			row = 2;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				row = 3;
				velocity.y = 800;
			}
		}
	}
	else
	{
		row = 4;
	}
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window) //วาดตัวละคร
{
	window.draw(body);
}
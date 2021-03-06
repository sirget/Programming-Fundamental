#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <string> 
#include <sstream>
#include "Player.h"
#include "Collission.h"
#include "Bomb.h"
#include <time.h>
#include "Fire.h"
#include "Heart.h"
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(NULL));

	int point = 0, positionx, positiony, positionheart = 20, life = 0, positionchx, positionchy, cnt = 0;;
	
	sf::String name;

	sf::RenderWindow window(sf::VideoMode(1800, 1000), "Little Boy", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

	window.setFramerateLimit(250);

	sf::Texture background, playertexture, floor1, bombtexture, firetexture, maintoplay, maintohowto, maintoscore, maintoexit, overtoplay, overtomain, loading, itemtexture, hearttexture, cointexture, daimond, maintoname, top5, howto, potiontex, potiontex2;
	
	sf::Sprite bgsprite1, bgsprite2, bgsprite3, floorsprite1, floorsprite2, floorsprite3, mt[10];
	
	loading.loadFromFile("Slide7.jpg");
	mt[6].setTexture(loading);
	mt[6].setPosition(250, 150);
	window.clear(sf::Color(76, 76, 76));
	window.draw(mt[6]);
	window.display();

	sf::Music music;
	music.openFromFile("longsound.ogg");
	music.setPitch(1);
	music.setVolume(20);
	music.setLoop(true);
	music.play();

	vector<pair<int, string>> scoreboard;

	background.loadFromFile("01bg.jpg");
	background.setSmooth(true);

	playertexture.loadFromFile("02player.png");

	floor1.loadFromFile("05floor.png");
	floor1.setSmooth(true);

	bombtexture.loadFromFile("03normalmiss.png");

	firetexture.loadFromFile("06fire.png");

	potiontex.loadFromFile("11potion.png");
	potiontex2.loadFromFile("12potion.png");

	maintoplay.loadFromFile("Slide1.jpg");
	maintoscore.loadFromFile("Slide2.jpg");
	maintohowto.loadFromFile("Slide3.jpg");
	maintoexit.loadFromFile("Slide4.jpg");
	overtoplay.loadFromFile("Slide5.jpg");
	overtomain.loadFromFile("Slide6.jpg");
	maintoname.loadFromFile("Slide8.jpg");
	top5.loadFromFile("Slide9.jpg");
	howto.loadFromFile("Slide10.jpg");

	hearttexture.loadFromFile("07heart.png");

	itemtexture.loadFromFile("08chest.png");

	cointexture.loadFromFile("09coin.png");

	daimond.loadFromFile("10daimond.png");

	bgsprite1.setTexture(background);
	bgsprite2.setTexture(background);
	bgsprite3.setTexture(background);
	
	bgsprite1.setPosition(bgsprite1.getPosition().x, 300);
	bgsprite2.setPosition(bgsprite1.getPosition().x + 600, 300);
	bgsprite3.setPosition(bgsprite1.getPosition().x + 1200, 300);

	floorsprite1.setTexture(floor1);
	floorsprite2.setTexture(floor1);
	floorsprite3.setTexture(floor1);

	floorsprite1.setPosition(bgsprite1.getPosition().x, 300);
	floorsprite2.setPosition(bgsprite1.getPosition().x + 600, 300);
	floorsprite3.setPosition(bgsprite1.getPosition().x + 1200, 300);

	mt[0].setTexture(maintoplay);
	mt[1].setTexture(maintoscore);
	mt[2].setTexture(maintohowto);
	mt[3].setTexture(maintoexit);
	mt[4].setTexture(overtoplay);
	mt[5].setTexture(overtomain);
	mt[7].setTexture(maintoname);
	mt[8].setTexture(top5);
	mt[9].setTexture(howto);

	mt[0].setPosition(250, 150);
	mt[1].setPosition(250, 150);
	mt[2].setPosition(250, 150);
	mt[3].setPosition(250, 150);
	mt[4].setPosition(250, 150);
	mt[5].setPosition(250, 150);
	mt[7].setPosition(250, 150);
	mt[8].setPosition(250, 150);
	mt[9].setPosition(250, 150);

	sf::SoundBuffer bufferjump, bufferitem, bufferbomb, bufferchan;
	sf::Sound jump, sitem, explo, chan;
	bufferjump.loadFromFile("jump.wav");
	bufferitem.loadFromFile("item.wav");
	bufferbomb.loadFromFile("explosion.wav");
	bufferchan.loadFromFile("chan.wav");
	jump.setBuffer(bufferjump);
	sitem.setBuffer(bufferitem);
	explo.setBuffer(bufferbomb);
	chan.setBuffer(bufferchan);

	float deltaTime = 0.0f;

	sf::Clock clock, fireclock, itemclock;

	sf::Font font;
	font.loadFromFile("GALS.ttf");

	sf::Text text,score,yourname,myname;
	text.setFont(font);
	score.setFont(font);
	myname.setFont(font);
	myname.setPosition(600, 900);
	myname.setString("Nachawanon Phetcharaporn 61010280");
	text.setPosition(135, 100);
	score.setPosition(20, 100);

	bool press;

	string name1;
	
	ifstream loadFile;

Main :
	int i = 0;
	int j;
	press = false;

	while (window.isOpen())
	{

		window.clear(sf::Color(76, 76, 76));

		sf::Vector2i MousePos = sf::Mouse::getPosition(window);

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				press = true;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				press = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && press)
		{
			i++;
			press = false;
			if (i == 4)
			{
				i = 0;
			}
			chan.play();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && press)
		{
			i--;
			press = false;
			if (i == -1)
			{
				i = 3;
			}
			chan.play();
		}
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) && press)
		{
			press = false;
			chan.play();
			if (i == 1)
				goto SeeScore;
			else if (i == 0)
				goto YourName;
			else if (i == 3)
				window.close();
			else if (i == 2)
				goto Howto;
		}

		if (MousePos.x > 772 && MousePos.x < 1218 )
		{
			if (MousePos.y > 426 && MousePos.y < 509)
				i = 0;
			if (MousePos.y > 530 && MousePos.y < 614)
				i = 1;
			if (MousePos.y > 635 && MousePos.y < 718)
				i = 2;
			if (MousePos.y > 739 && MousePos.y < 823)
				i = 3;
		}

		window.draw(mt[i]);

		window.draw(myname);

		window.display();
	}

YourName :

	press = false;

	while (window.isOpen())
	{

		window.clear(sf::Color(76, 76, 76));

		sf::Event event;
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) && press)
		{
			press = false;
			chan.play();
			goto Game;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && press)
		{
			press = false;
			chan.play();
			goto Main;
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
				press = true;

			if (event.type == sf::Event::MouseButtonPressed)
				press = true;

			if (event.type == sf::Event::TextEntered) 
			{
				if (event.text.unicode == '\b' && (name.getSize() > 0))
				{
					name1.erase(name.getSize() - 1, 1);
					name.erase(name.getSize() - 1, 1);
				}
				else 
				{
					if ((event.text.unicode < 128) && (name.getSize() < 8) && (event.text.unicode != '\b'))
					{
						name += static_cast<char>(event.text.unicode);
						name1 += static_cast<char>(event.text.unicode);
					}
				}
				yourname.setFont(font);
				yourname.setString(name);
				yourname.setFillColor(sf::Color::Black);
				yourname.setCharacterSize(100);   
				yourname.setPosition(630.0f, 440.0f);
				chan.play();
			}
		}

		window.draw(mt[7]);
		window.draw(yourname);
		window.draw(myname);
		window.display();
	}


SeeScore :

	press = false;

	scoreboard.clear();

	loadFile.open("HS.txt");
	while (!loadFile.eof()) {
		string tempName;
		int tempScore;
		loadFile >> tempName >> tempScore;
		scoreboard.push_back({ tempScore,tempName });
	}
	loadFile.close();

	sort(scoreboard.begin(), scoreboard.end(), greater<pair<int, string>>());
	
	while (window.isOpen())
	{	
		cnt = 0;
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				press = true;
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && press)
		{
			press = false;
			chan.play();
			goto Main;
		}

		window.clear(sf::Color(76, 76, 76));

		window.draw(mt[8]);

		for (vector<pair<int, string>>::iterator k = scoreboard.begin(); k != scoreboard.end(); ++k) 
		{
			++cnt;
			if (cnt > 5) 
				break;                       
			    
			sf::Text hname, hscore;
			hscore.setString(to_string(k->first));    
			hscore.setFont(font);                        
			hscore.setCharacterSize(40);                   
			hscore.setPosition(1200, 300 + (80 * cnt));     
			hscore.setFillColor(sf::Color::Black);
			window.draw(hscore);                           
			hname.setString(k->second);          
			hname.setFont(font);                        
			hname.setCharacterSize(40);                   
			hname.setPosition(600, 300 + (80 * cnt));    
			hname.setFillColor(sf::Color::Black);
			window.draw(hname); 		                   
		}

		window.draw(myname);

		window.display();  
	}

Over :
	press = false;
	j = 4;
	positionheart = 50;
	life = 0;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				press = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && press)
		{
			j++;
			press = false;
			chan.play();
			if (j == 6)
			{
				j = 4;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && press)
		{
			j--;
			press = false;
			chan.play();
			if (j == 3)
			{
				j = 5;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && press)
		{
			chan.play();
			if (j == 4)
			{
				goto Game;
			}
			else if (j == 5)
			{
				goto Main;
			}
		
			press = false;
		}

		window.draw(mt[j]);

		window.display();

	}

Howto :
	press = false;

	while (window.isOpen())
	{
		cnt = 0;
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				press = true;
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && press)
		{
			press = false;
			chan.play();
			goto Main;
		}

		window.clear(sf::Color(76, 76, 76));

		window.draw(mt[9]);

		window.draw(myname);

		window.display();
	}

Game :
	bool candam = true, canplay = true;
	press = false;
	point = 0;
	int ranbomb = 200, ranitem = 400;
	bool pauseGame = false;

	Player player(&playertexture, sf::Vector2u(4, 5), 0.2f, 500.0f, 200.0f);
	player.status = true;

	std::vector <Bomb> bombs;
	std::vector <Bomb> chests;
	std::vector <Fire> fires;
	std::vector <Heart> hearts;
	std::vector <Fire> items;

	hearts.push_back(Heart(&hearttexture, positionheart));
	life++;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Time timeonfire = fireclock.getElapsedTime();
		sf::Time timeonitem = itemclock.getElapsedTime();

		sf::Event event;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) 
		{
			pauseGame = true;
		}
		while (pauseGame == true) 
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::LShift) 
				{
					pauseGame = false;
					clock.restart();
					fireclock.restart();
					itemclock.restart();
				}
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
				music.stop();
			}

		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				music.stop();
			}

			if (event.type == sf::Event::KeyReleased)
			{
				press = true;
			}
		}

		if (life == 0)
		{
			ofstream highscore;
			highscore.open("HS.txt", ios::out | ios::app);
			highscore << "\n" << name1 << " " << point ;
			highscore.close();

			goto Over;
		}
		else if (life != 0 && (!candam) )
		{
			candam = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && press)
		{
			ofstream highscore;
			highscore.open("HS.txt", ios::out | ios::app);
			highscore << "\n" << name1 << " " << point;
			highscore.close();
			chan.play();
			press = false;
			goto Main;
		}
		
		if (rand()%ranbomb == 1)
		{
			positionx = rand() % 1700;
			positiony = 0; 

			bombs.push_back(Bomb(&bombtexture, 500.0f, positionx, positiony, 1.0f));
		}

		if (rand()%ranitem == 1)
		{
			positionchx = rand() % 1700;
			positionchy = 0; 

			chests.push_back(Bomb(&itemtexture, 500.0f, positionchx, positionchy, 2.0f));
		}

		if (Collission::PixelPerfectTest(player.body, floorsprite1) || Collission::PixelPerfectTest(player.body, floorsprite2) || Collission::PixelPerfectTest(player.body, floorsprite3))
		{
			player.canjump = true;

			canplay = true;

			player.velocity.y = 0;

			player.Update(deltaTime);
		}
		else
		{
			player.velocity.y += 981.0f * deltaTime;

			if (canplay && !player.canjump)
			{
				jump.play();
				canplay = false;
			}

			player.Update(deltaTime);
		}

		int b = 0;

		for (Bomb& bomb : bombs)
		{

			bomb.Update(deltaTime);

			if (Collission::PixelPerfectTest(bomb.body, floorsprite1) || Collission::PixelPerfectTest(bomb.body, floorsprite2) || Collission::PixelPerfectTest(bomb.body, floorsprite3))
			{
				fires.push_back(Fire(&firetexture, sf::Vector2u(11, 1), 0.1f, bomb.positionx, timeonfire.asSeconds(), 0, 0.5f, 800));
				bombs.erase(bombs.begin());
				if (ranbomb > 30)
				{
					ranbomb-=2;
				}
				explo.play();
				
			}

			if (Collission::PixelPerfectTest(player.body, bomb.body) && candam)
			{
				life--;
				hearts.erase(hearts.begin() + life);
				bombs.erase(bombs.begin() + b);
				positionheart -= 20;
				candam = false;
				explo.play();
			}

			b++;

		}

		int che = 0;

		for (Bomb& chest : chests)
		{
			chest.Update(deltaTime);

			if (Collission::PixelPerfectTest(chest.body, floorsprite1) || Collission::PixelPerfectTest(chest.body, floorsprite2) || Collission::PixelPerfectTest(chest.body, floorsprite3))
			{
				int ran = rand() % 2;
				{
					if (rand()%10 == 1)
					{
						items.push_back(Fire(&hearttexture, sf::Vector2u(1, 1), 0.1f, chest.positionx-40, timeonitem.asSeconds(), 1, 2.0f, 870));
					}
					else if (rand() % 10 == 1)
					{
						items.push_back(Fire(&potiontex, sf::Vector2u(1, 1), 0.1f, chest.positionx - 40, timeonitem.asSeconds(), 4, 2.0f, 870));
					}
					else if (rand() % 10 == 1)
					{
						items.push_back(Fire(&potiontex2, sf::Vector2u(1, 1), 0.1f, chest.positionx - 40, timeonitem.asSeconds(), 5, 2.0f, 870));
					}
					else if (ran == 0)
					{
						items.push_back(Fire(&cointexture, sf::Vector2u(1, 1), 0.1f, chest.positionx-40, timeonitem.asSeconds(), 2, 2.0f, 870));
					}
					else if (ran == 1)
					{
						items.push_back(Fire(&daimond, sf::Vector2u(1, 1), 0.1f, chest.positionx-40, timeonitem.asSeconds(), 3, 2.0f, 870));
					}
					
				}

				chests.erase(chests.begin() + che);
			}
			che++;
		}

		int f = 0;

		for (Fire& fire : fires)
		{
			
			fire.Update(deltaTime);

			if (timeonfire.asSeconds() - fire.timefire >= 3.00000f)
			{
				fires.erase(fires.begin());
			}

			if(Collission::PixelPerfectTest(player.body, fire.body) && candam)
			{
				life--;
				hearts.erase(hearts.begin() + life);
				fires.erase(fires.begin() + f);
				positionheart -= 20;
				candam = false;
			}

			f++;

		}

		int itom = 0;

		for (Fire& item : items)
		{
			item.Update(deltaTime);

			if (timeonitem.asSeconds() - item.timefire >= 10.00000f)
			{
				items.erase(items.begin() + itom);
			}

			else if(Collission::PixelPerfectTest(player.body, item.body) && candam)
			{
				sitem.play();

				if (item.statusitem == 1)
				{
					positionheart += 20;
					hearts.push_back(Heart(&hearttexture, positionheart));
					life++;
					items.erase(items.begin() + itom);
				}
				
				else if (item.statusitem == 2)
				{
					point += 1;
					items.erase(items.begin() + itom);
				}

				else if (item.statusitem == 3)
				{
					point += 10;
					items.erase(items.begin() + itom);
				}

				else if (item.statusitem == 4)
				{
					bombs.clear();
					fires.clear();
					items.erase(items.begin() + itom);
				}

				else if (item.statusitem == 5)
				{
					point *= 2;
					items.erase(items.begin() + itom);
				}

				candam = false;
			}

			itom++;
		}
			
		window.clear(sf::Color(76, 76, 76));

		window.draw(bgsprite1);
		window.draw(bgsprite2);
		window.draw(bgsprite3);

		window.draw(floorsprite1);
		window.draw(floorsprite2);
		window.draw(floorsprite3);

		for (Bomb& bomb : bombs)
			bomb.Draw(window);

		for (Fire& fire : fires)
			fire.Draw(window);

		for (Heart& heart : hearts)
			heart.Draw(window);

		for (Bomb& chest : chests)
			chest.Draw(window);

		for (Fire& item : items)
			item.Draw(window);

		std::ostringstream sc;
		sc << point;
		text.setString(sc.str());
		score.setString("score : ");
		window.draw(score);
		window.draw(text);

		player.Draw(window);

		window.display();

	}
	return 0;
}
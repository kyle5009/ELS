//main.cpp
#include "ship.h"
#include "game.h"

std::vector<Ship *> ships;
Ship* railGun;

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;



void Reset() {
	// Reset Invaders movement
	Invader::direction = true;
	Invader::speed = 30.f;
	Invader::speed = 160.f;
}

void Load() {
  if (!spritesheet.loadFromFile("res/img/earthlaststand_sheet.png")) {
    cerr << "Failed to load spritesheet!" << std::endl;
  }
  invader.setTexture(spritesheet);
  //invader.setTextureRect(sf::IntRect(260, 80, 90, 35));
  invader.setTextureRect(sf::IntRect(0, 0, 200, 100));

  Invader* inv = new Invader(sf::IntRect(260, 80, 90, 35), {300,250});
  ships.push_back(inv);

    auto rect = IntRect(260, 80, 90, 35);
    for (int c = 0; c < invaders_columns; ++c) {
		float leftMargin = gameWidth / 2 - 32 * invaders_columns / 2;
		float topMargin = 300.f;

        Vector2f position = { leftMargin + 100.f * c, topMargin + 100.f };
        auto inv = new Invader(rect, position);
        ships.push_back(inv);
    }

	// Spawn railgun
	auto player = new Player();
	railGun = player;
	ships.push_back(player);

	Reset();


}


void Update(RenderWindow &window)
{

	static Clock clock;
	float dt = clock.restart().asSeconds();
	// check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	// quit via esc key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
  for (auto &s : ships) {
    s->Update(dt);
  };
}

void Render(RenderWindow &window)
{
	window.draw(invader);
	for (const auto s : ships)
	{
		window.draw(*s);
	}
}


int main()
{
  RenderWindow window(VideoMode(gameWidth, gameHeight), "Earths Last Stand");
  Load();
  while(window.isOpen()){
    window.clear();
    Update(window);
    Render(window);
    window.display();
  }
  return 0;
}

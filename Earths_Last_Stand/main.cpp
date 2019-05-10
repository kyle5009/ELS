#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

int gameWidth = 1000;
int gameHeight = 750;

void Load() {
  if (!spritesheet.loadFromFile("res/img/earthlaststand_sheet.png")) {
    cerr << "Failed to load spritesheet!" << std::endl;
  }
  invader.setTexture(spritesheet);
  invader.setTextureRect(sf::IntRect(0, 0, 200, 100));
}

void Update(RenderWindow &window)
{

}

void Render(RenderWindow &window) {
  window.draw(invader);
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

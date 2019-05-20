#include "bullet.h"
#include "game.h"

using namespace sf;
using namespace std;

unsigned char Bullet::bulletPointer = '0';
Bullet Bullet::bullets[256];

Bullet::Bullet(const sf::Vector2f &pos, const bool mode) {
  setPosition(pos);
  _mode = mode;
  setTexture(spritesheet);

  if (_mode) {
    setTextureRect(IntRect(260, 115, 30, 30));
  } else{
    setTextureRect(IntRect(280, 115, 30, 30));
  }
}

Bullet::Bullet() : Sprite()
{
	setOrigin(50, 50);
	setTexture(spritesheet);
}
void Bullet::Fire(const sf::Vector2f & pos, const bool mode)
{
	bulletPointer++;
	bullets[bulletPointer].setPosition(pos);
	bullets[bulletPointer]._mode = mode;

	if (mode) {
		bullets[bulletPointer].setPosition(bullets[bulletPointer].getPosition() - Vector2f(0, 32));
		bullets[bulletPointer].setTextureRect(IntRect(300, 115, 70, 40));
	}
	else {
		bullets[bulletPointer].setTextureRect(IntRect(300, 115, 70, 40));
	}
}

void Bullet::Render(sf::RenderWindow &window) {
  for (auto b : bullets) {
    window.draw(b);
  }
}


void Bullet::Update(const float &dt) {
    //move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}

void Bullet::_Update(const float &dt) {
    if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
        //off screen - do nothing
        return;
    } else {
        move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
        const FloatRect boundingBox = getGlobalBounds();

        for (auto s : ships) {
            if (!_mode && s == railGun) {
                //player bulelts don't collide with player
                continue;
            }
            if (_mode && s != railGun) {
                //invader bullets don't collide with other invaders
                continue;
            }
            if (!s->is_exploded() &&
                s->getGlobalBounds().intersects(boundingBox)) {
                  //Explode the ship
                  s->Explode();
                  //warp bullet off-screen
                  setPosition(-100, -100);
                  return;
            }
        }
    }
};

#include "ship.h"
#include "game.h"
#include "bullet.h"
using namespace sf;
using namespace std;

bool Invader::direction;
float Invader::speed;

Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
    setOrigin(100, 100);
    setPosition(pos);
}

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
  _exploded = false;
};


void Invader::Update(const float &dt) {
	Ship::Update(dt);

	move(dt *(direction ? 1.0f : -1.0f) * speed, 0);
	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size() - 1; ++i) {
			ships[i]->move(0, 24);
		}
	}

	static float firetime = 0.f;
	firetime -= dt;
	if (firetime <= 0 && rand() % 100 == 0 && !_exploded) {
		Bullet::Fire(getPosition(), true);
		firetime = 4.f + (rand() % 60);
	}

}
void Invader::Explode()
{
	Ship::Explode();
	setTextureRect(IntRect(215, 80, 40, 45));
}
void Ship::Update(const float &dt) {
// removes exploded enemy
if (_exploded) {
	_explosiontime -= dt;
}
if (_explosiontime <= 0.f) {
	setColor(Color(0, 0, 0, 0));
}
}

Ship::~Ship() = default;

Player::Player() : Ship(IntRect(200, 0, 130, 75)) {
	setPosition({ gameHeight * .5f, gameHeight - 302.f });
}

void Player::Update(const float &dt) {
	Ship::Update(dt);
		// Move Left
		if (Keyboard::isKeyPressed(Keyboard::Left) && (getPosition().x - 16 > 0)) {

			move(-500 * dt, 0);
		}
		// Move Right
		if (Keyboard::isKeyPressed(Keyboard::Right) && (getPosition().x + 16 < gameWidth)) {

			move(500 * dt, 0);
		}
		// Move up
		if (Keyboard::isKeyPressed(Keyboard::Up) && (getPosition().y + 16 > 0)) {

			move(0, -500 * dt);
		}
		// Move down
		if (Keyboard::isKeyPressed(Keyboard::Down) && (getPosition().y + 16 < gameHeight)) {

			move(0, 500 * dt);
		}
		static float firetime = 0.0f;
		firetime -= dt;

		if (firetime <= 0 && Keyboard::isKeyPressed(Keyboard::Space)) {
			Bullet::Fire(getPosition(), false);
			firetime = 0.7f;
		}


	}

void Player::Explode()
{
	setTextureRect(IntRect(128, 32, 32, 32));
	_exploded = true;
}

bool Ship::is_exploded() const
{
	return _exploded;
}

void Ship::Explode() {
	//setTextureRect(IntRect(128, 32, 32, 32));
	_exploded = true;
}


 

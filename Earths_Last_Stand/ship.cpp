#include "ship.h"
#include "game.h"
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
}
void Ship::Update(const float &dt) {}


Ship::~Ship() = default;

//Player::Player() : Ship(IntRect(200, 0, 130, 75)) {
Player::Player() : Ship(IntRect(260, 80, 90, 35)) {
	setPosition({ gameHeight * .5f, gameHeight - 32.f });
}

void Player::Update(const float &dt) {
    Ship::Update(dt);

	float direction = 0.0f;
	// Move Left
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		if (getPosition().x - 16 > 0)
			direction--; //Deincrements the direction/position of ship
	}
	// Move Right
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (getPosition().x + 16 < gameWidth)
			direction++; //Increments the direction/position of ship
	}
}

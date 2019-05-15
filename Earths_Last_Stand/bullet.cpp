#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;

//Create definition for the constructor
//...

void Bullet::Update(const float &dt) {
    move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}

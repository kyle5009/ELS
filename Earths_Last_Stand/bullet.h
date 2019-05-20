#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	static void Update(const float &dt);
	Bullet(const sf::Vector2f &pos, const bool mode);

	//Renders All bullets
	static void Render(sf::RenderWindow &window);

	//Choose an inactive bullet and use it.
	static void Fire(const sf::Vector2f &pos, const bool mode);
	//void Update(const float &dt); maybe a this back in later?
	
	~Bullet()=default;



protected:
	bool _mode;

	static unsigned char bulletPointer;
	static Bullet bullets[256];

	Bullet();

	void _Update(const float &dt);

};

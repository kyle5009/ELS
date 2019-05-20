#pragma once
#include <SFML/Graphics.hpp>


class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    //Default constructor is hidden
    Ship();

	//explosions
	bool _exploded;
	float _explosiontime = 0.2f;

public:
   
    explicit Ship(sf::IntRect ir);
    
    virtual ~Ship() = 0;
 
    virtual void Update(const float &dt);

	//explosions
	bool is_exploded() const;
	virtual void Explode();
};

class Invader : public Ship {
public:
	Invader(sf::IntRect ir, sf::Vector2f pos);
	Invader();
	void Update(const float &dt) override;
	static bool direction; 
	static float speed; 
	void Explode();
};

class Player : public Ship {
public:
	Player();
	void Update(const float &dt) override;
	static float speed; 
	void Explode(); 
};



#pragma once

#include "Projectile.h"

class Cannonball : public Projectile {
public:

	explicit Cannonball();
	explicit Cannonball(const COORD position, const eColor color);
	~Cannonball() = default;

	virtual VOID explosion(std::list<std::shared_ptr<FireworkObject>>& list) override;
protected:


};




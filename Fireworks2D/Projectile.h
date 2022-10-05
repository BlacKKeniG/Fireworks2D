#pragma once

#include<iostream>

#include "FireworkObject.h"
#include "RandomGenerators.h"

#define DEFAUT_PROJECTALE_WIDTH 7
#define DEFAUT_PROJECTALE_HEIGHT 7

class Projectile : public FireworkObject {

public:

	explicit Projectile();
	explicit Projectile(const COORD position, const eColor color);
	virtual ~Projectile() = default;

	virtual VOID explosion(std::list<std::shared_ptr<FireworkObject>>& list) override;
};


#pragma once
#include "../unit.h"
#include"../DS/ArrayStack.h"
class EarthGun : public unit
{
	EarthGun()
	{
		ArrayStack<EarthGun*>gunList(200);
	}
	void add(EarthGun* gun)
	{
		
	}
};


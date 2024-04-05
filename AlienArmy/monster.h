#pragma once
#include "../unit.h"
class monster : public unit
{
public:
	monster() {
		set_type("monster");
	}
	
	void attack() {}
};


#pragma once
#include "../ADTs/QueueList.h"
#include"../ADTs/PriQueueList.h"

class UML
{
	PriQueueList soldiersToHeal;
	QueueList tanksToHeal;
	int healed_count, curr_count;
public:
	~UML();
	UML(); 
	int get_healed_count();
	void set_healed_count(int a);
	int get_curr_count();
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
};


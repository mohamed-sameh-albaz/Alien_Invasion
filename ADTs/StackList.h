#pragma once
#include<iostream>
#include"../unit.h"
#include"../DS/ArrayStack.h"

class StackList :public ArrayStack<unit*>
{
	int count;
public:
	StackList();
	~StackList();
	int getCount();
	bool insert(unit* newUnit);
	bool peek(unit*& frontUnit);
	bool remove(unit*& removedUnit);
	void print(type unitType);
};
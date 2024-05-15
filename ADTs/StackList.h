#pragma once
#include<iostream>
#include"../unit.h"
#include"../DS/ArrayStack.h"

class StackList :public ArrayStack<unit*>
{
	int count;
public:
	StackList() :count(0) {};
	~StackList()
	{
		StackList::~StackList();
	}
	int getCount()
	{
		return count;
	}
	bool insert(unit* newUnit)
	{
		count++;
		return push(newUnit);
	}
	bool peek(unit*& frontUnit)
	{
		return ArrayStack::peek(frontUnit);
	}
	bool remove(unit*& removedUnit)
	{
		if (pop(removedUnit))
		{
			count--;
			return true;
		}
		return false;
	}
	void print(type unitType)
	{
		int topUnit = count-1;
		cout <<" " << count;
		switch (unitType)
		{
		case ET:cout << " ET [";
			break;
		case EH:cout << " EH [";
			break;
		}
		for (int i = topUnit; i >= 0; i--)
		{
			cout << items[i]->get_id();
			if (i > 0)
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;
		cout << "_____________________________________________________\n";
	}

};
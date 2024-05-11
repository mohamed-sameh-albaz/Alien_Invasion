#pragma once
#include"LinkedQueue.h"
#include"Node.h"
template<class T>
class double_endedQueue :public LinkedQueue<T>

{

public:
	bool peekBack(T& u) {
		if (LinkedQueue<T>::isEmpty())
			return false;

		u = LinkedQueue<T>::backPtr->getItem();
		return true;
	}
	bool peekFront(T& u) {
		return LinkedQueue<T>::peek(u);
	}
	bool dequeueBack(T& u) {
		if (LinkedQueue<T>::isEmpty())
			return false;
		if (LinkedQueue<T>::frontPtr == LinkedQueue<T>::backPtr)
			LinkedQueue<T>::dequeue(u);
		else {
			Node<T>* temp = LinkedQueue<T>::frontPtr;
			while (temp->getNext() != LinkedQueue<T>::backPtr)
				temp = temp->getNext();
			u = LinkedQueue<T>::backPtr->getItem();
			Node<T>* temp1 = LinkedQueue<T>::backPtr;
			LinkedQueue<T>::backPtr = temp;
			LinkedQueue<T>::backPtr->setNext(nullptr);
			delete temp1;
			temp1 = nullptr;
		}
		return true;

	}

	bool enqueueFront(T u) {
		Node<T>* t = new Node<T>(u);
		if (!t)
			return 0;
		t->setNext(LinkedQueue<T>::frontPtr);
		LinkedQueue<T>::frontPtr = t;
		return 1;
	}
};


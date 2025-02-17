
#ifndef _NODE
#define _NODE
template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
public:
	//	Node();
	//	Node(const T& r_Item);
	//	Node(const T& r_Item, Node<T>* nextNodePtr);
	//	void setItem(const T& r_Item);
	//	void setNext(Node<T>* nextNodePtr);
	//	T getItem() const;
	//	Node<T>* getNext() const;
	//}; // end Node
	//#endif

	template < typename T>
	Node()
	{
		next = nullptr;
	}

	//template < typename T>
	Node(const T& r_Item)
	{
		item = r_Item;
		next = nullptr;
	}

	//template < typename T>
	Node(const T& r_Item, Node<T>* nextNodePtr)
	{
		item = r_Item;
		next = nextNodePtr;
	}
	//template < typename T>
	void setItem(const T& r_Item)
	{
		item = r_Item;
	}

	//template < typename T>
	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	//template < typename T>
	T getItem() const
	{
		return item;
	}

	//template < typename T>
	Node<T>*getNext() const
	{
		return next;
	}
};
#endif
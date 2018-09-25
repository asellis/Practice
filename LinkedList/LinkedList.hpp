/*
Implementation of a Linked List with pointers at the head and tail.
Implemented everything into .hpp file to avoid issues with using template
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// Declarations
template <typename Type>
class LinkedList
{
private:
	struct Node
	{
		// The base component of the linked list.
		// Contains a value and points to the next
		// linked list in the series
		Type value;
		Node* next;
	};

	// Pointers to the beginning and end of the linked list
	Node* head;
	Node* tail;

public:
	// Empty initializer
	LinkedList();

	// Copy Constructor
	LinkedList(const LinkedList& list);

	// Destructor
	~LinkedList();

	// Adds value to start
	void addToStart(const Type& value);

	// Adds value to end
	void addToEnd(const Type& value);

	// Removes value from start
	void removeFromStart();

	// Removes value from end
	void removeFromEnd();

	// Returns the first element in the linked list
	const Type& first() const;
	Type& first();

	// Returns the last element in the linked list
	const Type& end() const;
	Type& end();

	// Returns element at index
	const Type& valueAt(int index) const;

	// Adds value at index
	void addAt(int index, Type value);

	// Removes value at index
	void removeAt(int index);

	// Returns true if empty
	bool isEmpty() const;
	
	// Returns the size, 0 if empty
	int size() const;
};

// Definitions
template <typename Type>
LinkedList<Type>::LinkedList()
{
	// No nodes yet
	head = nullptr;
	tail = nullptr;
}

template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList& list)
{
	// check if empty
	if(list.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		// Initial node setup
		Node* temp = list.head;
		head = new Node;
		head->value = temp->value;
		tail = head;
		temp = temp->next;

		// All other nodes
		while(temp!=nullptr)
		{
			tail->next = new Node;
			tail = tail->next;
			tail->value = temp->value;
			temp = temp->next;
		}
		tail->next = nullptr;
	}
}

template <typename Type>
LinkedList<Type>::~LinkedList()
{
	while(head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename Type>
void LinkedList<Type>::addToStart(const Type& value)
{
	// case if empty
	if(head == nullptr)
	{
		head = new Node;
		head->value = value;
		head->next = nullptr;
		tail = head;
	}

	// non empty case
	else
	{
		Node* newStart = new Node;
		newStart->value = value;
		newStart->next = head;
		head = newStart;
	}
}

template <typename Type>
void LinkedList<Type>::addToEnd(const Type& value)
{
	// case if empty
	if(head == nullptr)
	{
		head = new Node;
		head->value = value;
		head->next = nullptr;
		tail = head;
	}

	// non empty case
	else
	{
		Node* newEnd = new Node;
		newEnd->value = value;
		newEnd->next = nullptr;
		tail->next = newEnd;
		tail = newEnd;
	}
}

template <typename Type>
void LinkedList<Type>::removeFromStart()
{
	if(head == nullptr)
		throw "Empty";

	Node* temp = head;
	head = head->next;
	delete temp;
}

template <typename Type>
void LinkedList<Type>::removeFromEnd()
{
	if(head == nullptr)
		throw "Empty";

	// Get to the node before tail
	Node* temp = head;
	while(temp->next != tail)
		temp=temp->next;
	tail = temp;
	temp = temp->next;
	tail->next = nullptr;
	delete temp;
}

template <typename Type>
const Type& LinkedList<Type>::first() const
{
	if(head == nullptr)
		throw "Empty";
	return head->value;
}

template <typename Type>
Type& LinkedList<Type>::first()
{
	if(head == nullptr)
		throw "Empty";
	return head->value;
}

template <typename Type>
const Type& LinkedList<Type>::end() const
{
	if(tail == nullptr)
		throw "Empty";
	return tail->value;
}

template <typename Type>
Type& LinkedList<Type>::end()
{
	if(tail == nullptr)
		throw "Empty";
	return tail->value;
}

template <typename Type>
const Type& LinkedList<Type>::valueAt(int index) const
{
	if(index < 0)
		throw "Negative Index";
	if(head == nullptr)
		throw "Empty";
	int count = index;
	Node* node = head;

	while(count > 0)
	{
		node = node->next;
		if(node == nullptr)
			throw "Out of Range";
		--count;
	}
	return node->value;
}

template <typename Type>
void LinkedList<Type>::addAt(int index, Type value)
{
	if(index < 0)
		throw "Negative Index";
	if(head == nullptr)
	{
		head = new Node;
		tail = head;
		head->value = value;
		head->next = nullptr;
	}
	int count = index;
	Node* node = head;
	Node* prev = nullptr;
	bool isTail = false;
	while(count > 0)
	{
		prev = node;
		node = node->next;
		if(node == nullptr)
		{
			isTail = true;
			count = 0;
		}
		--count;
	}

	Node* temp = new Node;
	temp->value = value;
	if(prev == nullptr)
	{
		// Head Position
		temp->next = head;
		head = temp;
	}
	else if(isTail)
	{
		// Tail position
		temp->next = nullptr;
		prev->next = temp;
		tail = temp;
	}
	else
	{
		prev->next = temp;
		temp->next = node;
	}
}

template <typename Type>
void LinkedList<Type>::removeAt(int index)
{
	if(index < 0)
		throw "Negative Index";
	if(head == nullptr)
	{
		throw "Empty";
	}
	int count = index;
	Node* node = head;
	Node* prev = nullptr;
	bool isTail = false;
	while(count > 0)
	{
		prev = node;
		node = node->next;
		if(node == nullptr)
		{
			isTail = true;
			count = 0;
		}
		--count;
	}
	
	if(prev == nullptr)
	{
		// Head Position
		head = head->next;
	}
	else if(isTail)
	{
		// Tail position
		tail = prev;
		prev->next = nullptr;
	}
	else
	{
		prev->next = node->next;
	}
	delete node;
}

template <typename Type>
bool LinkedList<Type>::isEmpty() const
{
	return bool(head == nullptr);
}

template <typename Type>
int LinkedList<Type>::size() const
{
	int count = 0;
	Node* temp = head;
	while(temp != nullptr)
	{
		++count;
		temp = temp->next;
	}
	return count;
}
#endif
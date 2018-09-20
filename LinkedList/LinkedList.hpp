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

	// Destructor
	~LinkedList();

	// Adds value to start
	void addToStart(const Type& value);

	// Adds value to end
	void addToEnd(const Type& value);

	// Returns the first element in the linked list
	const Type& first() const;
	Type& first();

	// Returns the last element in the linked list
	const Type& end() const;
	Type& end();

	
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

#endif
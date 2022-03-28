#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_back(array[i]);
	}
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::push_back(int data)
{
	if (head == nullptr)
	{
		head = new LinkedNode;
		tail = head;
		head->data = data;
		tail->data = data;
		head->prev = nullptr;
		head->next = nullptr;
		tail->prev = nullptr;
		tail->next = nullptr;
	}
	else
	{
		LinkedNode* current;
		current = new LinkedNode;
		if (head->next == nullptr) head->next = current;
		current->prev = tail;
		tail->next = current;
		tail = current;
		tail->prev = current->prev;
		tail->data = data;
		tail->next = nullptr;
	}
}

void LinkedList::push_back(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_back(array[i]);
	}
}

void LinkedList::push_front(int data)
{
	if (head == nullptr)
	{
		head = new LinkedNode;
		tail = head;
		head->data = data;
		tail->data = data;
		head->prev = nullptr;
		head->next = nullptr;
		tail->prev = nullptr;
		tail->next = nullptr;
	}
	else
	{
		LinkedNode* current;
		current = new LinkedNode;
		if (tail->prev == nullptr) tail->prev = current;
		current->next = head;
		head->prev = current;
		head = current;
		head->next = current->next;
		head->data = data;
		head->prev = nullptr;
	}
}

void LinkedList::push_front(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_front(array[i]);
	}
}

void LinkedList::pop_back()
{
	if (head->next == nullptr || tail->prev == nullptr || head == nullptr || tail == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
}

void LinkedList::pop_front()
{
	if (head->next == nullptr || tail->prev == nullptr || head == nullptr || tail == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		head->prev = nullptr;
	}
}

LinkedNode* LinkedList::end()
{
	return tail;
}

LinkedNode* LinkedList::begin()
{
	return head;
}

LinkedNode* LinkedList::next(LinkedNode* position)
{
	if (position == nullptr || position->next == nullptr)
	{
		return nullptr;
	}
	return position->next;
}

LinkedNode* LinkedList::prev(LinkedNode* position)
{
	if (position == nullptr || position->prev == nullptr)
	{
		return nullptr;
	}
	return position->prev;
}

int LinkedList::front()
{
	if (head == nullptr)
	{
		return 0;
	}
	return head->data;
}

int LinkedList::back()
{
	if (tail == nullptr)
	{
		return 0;
	}
	return tail->data;
}

LinkedNode* LinkedList::position(int data)
{
	LinkedNode* tmp = head;
	while (tmp != tail->next)
	{
		if (tmp->data == data)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

int LinkedList::retrieve(LinkedNode* current)
{
	if (current == nullptr)
	{
		return 0;
	}
	else
	{
		return current->data;
	}
}

void LinkedList::insert(int data, LinkedNode* position)
{
	if (position == nullptr)
	{
		cout << "there is no current position in list" << endl;
	}
	else if (position == begin() || (position == nullptr && position->next == head))
	{
		push_front(data);
	}
	else
	{
		LinkedNode* temp = new LinkedNode;
		temp->prev = position->prev;
		position->prev->next = temp;
		position->prev = temp;
		temp->next = position;
		temp->data = data;
	}
}

LinkedNode* LinkedList::erase(LinkedNode* position)
{
	if (position == nullptr)
	{
		return nullptr;
	}
	else if (position == begin())
	{
		pop_front();
		return head;
	}
	else if (position == end())
	{
		pop_back();
		return tail;
	}
	else
	{
		(position->prev != nullptr) ? position->prev->next = position->next : position->prev = nullptr;
		(position->next != nullptr) ? position->next->prev = position->prev : position->next = nullptr;
		return position = position->next;
	}
}

void LinkedList::clear()
{
	if (head != nullptr)
	{
		while (head->next != nullptr)
		{
			head = head->next;
		}
		head = nullptr;
	}
}

void LinkedList::print()
{
	LinkedNode* iterator = head;
	while (iterator != nullptr)
	{
		cout << "\t" << iterator->data;
		iterator = iterator->next;
	}
	cout << endl;
}

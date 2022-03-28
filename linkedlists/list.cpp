#include "list.h"

List::List(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_back(array[i]);
	}
}

List::List()
{
	head = nullptr;
}

List::~List()
{
	clear();
}

void List::push_front(int data)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		Node* current;
		current = new Node;
		current->data = data;
		current->next = head;
		head = current;
	}
}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		Node* current;
		current = new Node;
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = current;
		current->data = data;
		current->next = nullptr;
	}
}

void List::push_back(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_back(array[i]);
	}
}

void List::push_front(int* array, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		push_front(array[i]);
	}
}

void List::pop_back()
{
	if (head->next == nullptr)
	{
		head = nullptr;
	}
	else
	{
		Node* tmp = head;
		while (tmp->next != end())
		{
			tmp = tmp->next;
		}
		tmp->next = nullptr;
	}

}

void List::pop_front()
{
	if (head->next == nullptr || head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		head = head->next;
	}
}

void List::clear()
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

Node* List::end()
{
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	return tmp;
}

Node* List::begin()
{
	return head;
}

Node* List::position(int data)
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

int List::retrieve(Node* current)
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

int List::front()
{
	if (head == nullptr)
	{
		return 0;
	}
	return head->data;
}

int List::back()
{
	if (end() == nullptr)
	{
		return 0;
	}
	return end()->data;
}

Node* List::next(Node* position)
{
	if (position == nullptr || position->next == nullptr)
	{
		return nullptr;
	}
	return position->next;
}

Node* List::erase(Node* position)
{
	if (position == nullptr)
	{
		return nullptr;
	}
	else if (position == begin())
	{
		Node* iterator = position->next;
		pop_front();
		return position = iterator;
	}
	else if (position == end())
	{
		pop_back();
		return position = nullptr;
	}
	else
	{
		Node* tmp = head;
		while (tmp->next != position)
		{
			tmp = tmp->next;
		}
		tmp->next = position->next;
		position = position->next;
		return position;
	}
}

void List::insert(int data, Node* position)
{
	if (position == nullptr)
	{
		push_back(data);
	}
	else if (position == begin())
	{
		push_front(data);
	}
	else
	{
		Node* iterator = head;
		while (iterator->next != position)
		{
			iterator = iterator->next;
		}
		Node* tmp = iterator->next;
		position = new Node;
		iterator->next = position;
		position->data = data;
		position->next = tmp;
	}
}

void List::print()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		cout << "\t" << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}
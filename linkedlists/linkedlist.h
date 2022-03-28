#pragma once
#include <iostream>
using namespace std;

struct LinkedNode
{
	int data;
	LinkedNode* next;
	LinkedNode* prev;
};

class LinkedList
{
	LinkedNode* head;
	LinkedNode* tail;
public:
	LinkedList();
	LinkedList(int* array, int size);
	~LinkedList();

	void push_back(int data);
	void push_back(int* array, int size);
	void push_front(int data);
	void push_front(int* array, int size);
	void pop_back();
	void pop_front();

	LinkedNode* end();
	LinkedNode* begin();

	LinkedNode* next(LinkedNode* position);
	LinkedNode* prev(LinkedNode* position);

	int front();
	int back();

	LinkedNode* position(int data);
	int retrieve(LinkedNode* current);

	void insert(int data, LinkedNode* position);
	LinkedNode* erase(LinkedNode* position);

	void clear();

	void print();
};
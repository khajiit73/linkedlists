#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List
{
	Node* head;
public:

	List(int* array, int size);
	List();
	~List();

	void push_front(int data);
	void push_back(int data);
	void push_back(int* array, int size);
	void push_front(int* array, int size);
	void pop_back();
	void pop_front();

	void clear();

	Node* end();
	Node* begin();

	int front();
	int back();

	Node* position(int data);
	int retrieve(Node* current);

	Node* next(Node* position);

	Node* erase(Node* position);
	void insert(int data, Node* position);

	void print();
};
#include "list.h"
#include "linkedlist.h"

int main()
{
	int array[] = { 5, 44, 7, 14 };
	List list(array, 4);

	cout << "list of numbers" << endl;
	list.print();

	int array_1[] = { 4, 16, 1, 55, 63 };
	list.push_front(array_1, 5);

	cout << "list of numbers after adding an array of numbers in front" << endl;
	list.print();

	auto iter = list.begin();
	iter = list.next(iter);
	list.insert(31, iter);
	list.insert(77, iter);
	cout << "list of numbers after inserting two numbers" << endl;
	list.print();

	list.push_back(33);
	cout << "list of numbers after adding a number at the end of list" << endl;
	list.print();

	list.pop_front();
	list.pop_back();
	cout << "list of numbers after removing a number from the beginning and the ending of list" << endl;
	list.print();

	iter = list.position(16);
	iter = list.erase(iter);
	cout << "list of numbers after removing a number at the position of iterator" << endl;
	list.print();

	cout << "number in list, that is at the position of iterator" << endl;
	cout << list.retrieve(iter) << endl;

	cout << "number in list, that is at the end of the list" << endl;
	iter = list.end();
	cout << list.retrieve(iter) << endl;

	list.clear();
	cout << "list of numbers after removing all numbers" << endl;
	list.print();

	cout << "\n\n-------------------------------------------------------------------\n\n";

	LinkedList l_list(array, 4);

	cout << "list of numbers" << endl;
	l_list.print();

	int array_2[] = { 3, 7, 10, 47, 24 };
	l_list.push_front(array_2, 5);

	cout << "list of numbers after adding an array of numbers in front" << endl;
	l_list.print();

	auto iterator = l_list.begin();
	iterator = l_list.next(iterator);
	l_list.insert(31, iterator);
	l_list.insert(77, iterator);
	cout << "list of numbers after inserting two numbers" << endl;
	l_list.print();

	l_list.push_back(33);
	cout << "list of numbers after adding a number at the end of list" << endl;
	l_list.print();

	l_list.pop_front();
	l_list.pop_back();
	cout << "list of numbers after removing a number from the beginning and the ending of list" << endl;
	l_list.print();

	iterator = l_list.position(7);
	iterator = l_list.erase(iterator);
	cout << "list of numbers after removing a number at the position of iterator" << endl;
	l_list.print();

	cout << "number in list, that is at the position of iterator" << endl;
	cout << l_list.retrieve(iterator) << endl;

	cout << "number in list, that is at the end of the list" << endl;
	iterator = l_list.end();
	cout << l_list.retrieve(iterator) << endl;

	l_list.clear();
	cout << "list of numbers after removing all numbers" << endl;
	l_list.print();

	return 0;
}
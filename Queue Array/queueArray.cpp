#include <iostream>
#include <string>
#include "queueArray.h"

using namespace std;

// initialize
queueArray::queueArray() {
	list = nullptr;
	maxQueueSize = 10;
	queueFront = 0;
	queueRear = -1;
	count = 0;
}

// create Queue
void queueArray::createQueue() {
	if (list != nullptr) {
		delete[] list;
		list = nullptr;
	}

	list = new string[maxQueueSize];

	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;

	// print
	cout << " Starbucks queue created ☕!!" << endl;
}

// initialize Queue
void queueArray::initializeQueue() {
	if (list == nullptr) {
		cout << " Create Starbucks Queue First Please 😼" << endl;
	}


	queueFront = 0;
	queueRear = -1;
	count = 0;

	// print
	cout << " Starbucks Queue Initialized 😼" << endl;
}

// check if queue is empty
bool queueArray::isEmptyQueue() {
	return (count == 0);
}

// check if queue is full
bool queueArray::isFullQueue() {
	return (count == maxQueueSize);
}

// add custoimer to top
void queueArray::addQueue(const string& customerName) {
	if (list == nullptr) {
		cout << " Create Queue First" << endl;
		return;
	}

	queueRear = (queueRear + 1) % maxQueueSize;

	list[queueRear] = customerName;
	cout << " Starbucks Customer 🩷" << customerName << "🩷 has been added" << endl;
	count++;


}

// view top element
string queueArray::top() {
	if (list == nullptr || isEmptyQueue()) {
		return " Starbucks Queue Empty 😥";
	}

	return list[queueFront];
}

// view last element
string queueArray::last() {
	if (list == nullptr || isEmptyQueue()) {
		return " Starbucks Queue Empty 😥";
	}

	return list[queueRear];
}

// remove top element and display a message of action
void queueArray::next() {
	if (list == nullptr) {
		cout << " Create Starbucks Queue First" << endl;
		return;
	}

	if (isEmptyQueue()) {
		cout << " Queue is Empty" << endl;
		return;
	}

	cout << "🩷" << list[queueFront] << "🩷 your order is ready!" << endl;
	queueFront = (queueFront + 1) % maxQueueSize;
	count--;

	if (count == 0) {
		queueFront = 0;
		queueRear = -1;
	}
}

// display current size
int queueArray::queueSize() {
	return count;
}

// search for user/name
bool queueArray::searchQueue(const string& customerName) {
	if (list == nullptr || isEmptyQueue()) {
		return false;
	}

	int current = queueFront;

	for (int i = 0; i < count; i++) {
		if (list[current] == customerName) {
			return true;
		}

		current = (current + 1) % maxQueueSize;
	}

	return false;
}

// display for user visually
void queueArray::printQueue() {
	if (list == nullptr) {
		cout << "Create queue first" << endl;
		return;
	}

	if (isEmptyQueue()) {
		cout << " No customers waiting at Starbies" << endl;
		return;
	}

	cout << " 🥤STARBIES QUEUE🥤: ";

	int current = queueFront;

	for (int i = 0; i < count; i++) {
		cout << list[current] << " ";

		if (i < count - 1) {
			cout << " -> ";
		}

		current = (current + 1) % maxQueueSize;
	}

	cout << endl;
}

// delete queue
void queueArray::deleteQueue() {
	if (list == nullptr) {
		cout << "Create queue first" << endl;
		return;
	}

	delete[] list;

	list = nullptr;
	queueFront = 0;
	queueRear = -1;
	count = 0;
	cout << " No Starbies Queue 🥤😿" << endl;
}

// destroy dynamic memory
queueArray::~queueArray() {
	delete[] list;
	list = nullptr;
}
#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>
#include <string>

using namespace std;

//  queueArray class

class queueArray {
private:
    // declare
    string* list;
    int queueFront;
    int queueRear;
    int maxQueueSize;
    int count;

public:
    queueArray();
    void createQueue();
    void initializeQueue();
    bool isEmptyQueue();
    bool isFullQueue();
    void addQueue(const string& customerName);
    string top();
    string last();
    void next();
    int queueSize();
    bool searchQueue(const string& customerName);
    void printQueue();
    void deleteQueue();
    ~queueArray();
};



#endif
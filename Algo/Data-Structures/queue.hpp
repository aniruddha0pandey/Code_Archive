// Array implementation of queue

#include <iostream>

class Queue {
private:
	int siz;
protected:
	int frontIndex, rearIndex;
	static int count;
	int* arr;
public:
	Queue(auto);
	~Queue();
	enQueue(auto);
	deQueue();
};

Queue::Queue(auto e = 0): siz(e) {
	frontIndex = rearIndex = 0;
	arr = new int[siz];
}

virtual Queue::~Queue() {
	delete arr;
}

void Queue::enQueue(auto x) {
	if ( full() ) std::cerr << "Overflow";
	else arr[rearIndex++] = x;
}

template <class T>
T Queue::deQueue(void) {
	if ( empty() ) std::cerr << "Underflow";
	else return arr[frontIndex++];
}

class Status: public Queue {
public:
	full(int, auto);
	empty(int, int);
	size(int, int);
};

bool Status::full(int frontIndex, int rearIndex) {
	return (frontIndex == rearIndex);
}

bool Status::empty(int frontIndex, int rearIndex) {
	return (frontIndex == rearIndex);
}

int Status::size(int frontIndex, int rearIndex) {
	return (rearIndex - frontIndex);
}

int main (void) {
	Queue q(5);
	return 0;
}

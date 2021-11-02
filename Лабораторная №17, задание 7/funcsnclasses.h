#ifndef _FUNCSNCLASSES_H_

#include <iostream>
#include <exception>
#include <cstdio>

typedef struct point { int x, y, z;} point_s;

template <typename T>
class Node{
private:
	T value;
	Node* next;
public:
	Node();
	~Node();
};

template <typename T>
class List {
private:
	Node<T>* head;
	size_t size;
public:
	List();
	~List();
	void push_back();
	void pop_front();
};

template <typename T>
class Queue {
private:
	T* set;
	int setsize;
	int tail;
	int top;
public:
	Queue(int a= 3);
	Queue(const Queue<T>&);
	~Queue();
	void enque(T);
	T deque();
	int size();
	void clear();
	Queue<T>& operator=(const Queue<T>&);
};

template <typename T>
Queue<T>::Queue(int a) {
	if (a <= 0) a = 3;
	setsize = a;
	set = new T[setsize];
	top = 0;
	tail = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& a) {
	setsize = a.setsize;
	set = new T[setsize];
	tail = a.tail;
	top = a.top;
	for (int i = top; i < tail; i++) { set[i] = a.set[i]; }
}

template <typename T>
Queue<T>::~Queue() {delete[] set;}

template <typename T>
void Queue<T>::enque(T a) {
	int i = (tail + 1) % setsize;
	if (i == top) return;
	set[tail] = a;
	tail = (tail + 1) % setsize;
}

template <typename T>
T Queue<T>::deque() {
	if (top == tail) throw std::exception("Queue is empty");
	T tmp = set[top];
	top = (top + 1) % setsize;
	return tmp;
}

template <typename T>
int Queue<T>::size() { return this->setsize; }

template <typename T>
void Queue<T>::clear() { 
	while (top != tail) this->deque();
	top = tail = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& a) {
	if (this == &a) { return *this; }
	delete[] set;
	setsize = a.setsize;
	set = new T[setsize];
	tail = a.tail;
	top = a.top;
	for (int i = top; i < tail; i++) { set[i] = a.set[i]; }
	return *this;
}


std::ostream& operator<<(std::ostream& b, point_s a) {
	std::cout << "{" << a.x << ", ";
	std::cout << a.y << ", ";
	std::cout << a.z << "} ";
	return b;
}

#endif
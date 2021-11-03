#ifndef _FUNCSNCLASSES_H_

#include <iostream>
#include <exception>
#include <cstdio>

typedef struct point { int x, y, z;} point_s;

template <typename T>
class Node{
public:
	T value;
	Node<T>* next;
};

template <typename T>
class List {
public:
	Node<T>* head;
	List() {
		head = NULL;
	}
	~List() {
		Node<T>* tmp;
		while (head != NULL) {
			tmp = head;
			head = head->next;
		}
	}

	void push_back(const T& a) {
		if (head == NULL) {
			head = new Node<T>;
			head->value = a;
			head->next = NULL;
		}
		else {
			Node<T>* tmp = head;
			while (tmp->next != NULL) {tmp = tmp->next;}
			tmp->next = new Node<T>;
			tmp = tmp->next;
			tmp->value = a;
			tmp->next = NULL;
		}
	}

	T pop_front() {
		Node<T>* tmp;
		T value;
		tmp = head;
		head = head->next;
		value = tmp->value;
		delete tmp;
		return value;
	}
};

template <typename T>
class Queue {
private:
	List<T> a;
public:
	void enque(const T& b) {
		a.push_back(b);
	}
	T deque() {
		if (size() == 0) throw std::exception("Queue is empty");
		T tmp = a.pop_front();
		return tmp;
	}
	int size() {
		int counter = 0;
		Node<T>* tmp;
		tmp = a.head;
		while (tmp != NULL) {
			counter++;
			tmp = tmp->next;
		}
		return counter;
	}
	void clear() {
		while (a.head != NULL) { deque(); }
	}
};


std::ostream& operator<<(std::ostream& b, point_s a) {
	std::cout << "{" << a.x << ", ";
	std::cout << a.y << ", ";
	std::cout << a.z << "} ";
	return b;
}

#endif
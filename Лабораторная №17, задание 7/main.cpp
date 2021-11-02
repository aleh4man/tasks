#include "funcsnclasses.h"

int main() {
	point_s b = { 1, 1, 1 }, c = { 2, 1, 1 }, d = {43, 43, 11};
	Queue<point_s> e;
	Queue<int> aa;
	e.enque(b);
	e.enque(c);
	aa.enque(12);
	aa.enque(41);
	try {
		std::cout << e.deque() << " has been deleted from the queue" << std::endl;
		std::cout << aa.deque();
		std::cout << " has been deleted from the queue" << std::endl;
		std::cout << e.deque();
		std::cout << " has been deleted from the queue" << std::endl;
	}
	catch (std::exception&) {
		std::cout << "The queue is empty. Deleting isn't possible" << std::endl;
	}
	return 0;
}
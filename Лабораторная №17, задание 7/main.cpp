#include "funcsnclasses.h"

int main() {
	point_s b = { 1, 1, 1 }, c = { 2, 1, 1 }, d = {43, 43, 11};
	Queue<point_s> a;
	a.enque(b);
	a.enque(c); 
	a.enque(b);
	try {
		a.deque();
		a.deque();
	}
	catch (std::exception&) {
		std::cout << "WARNING: Queue is empty. Deleting isn't possible";
	}
	return 0;
}
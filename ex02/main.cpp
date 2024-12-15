#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main () {
	Base *p;

	p = generate();

	std::cout << "\033[33m----------type identification using pointer----------\033[0m" << std::endl;
	identify(p);

	std::cout << "\033[33m----------type identification using reference----------\033[0m" << std::endl;
	identify(*p);
	
	delete(p);
	return 0;
}

Base * generate(void) {
	Base *p;
	std::srand(std::time(0));
	int random_number = std::rand() % 3;

	switch(random_number)
	{
		case 0:
			p = new A();
			break;
		case 1:
			p = new B();
			break;
		case 2:
			p = new C();
			break;
	}
	return p;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "type : A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "type : B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "type : C" << std::endl;
}

void identify(Base &p) {
	A a;
	B b;
	C c;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << "type : A" << std::endl;
	} catch (std::exception & e) {
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "type : B" << std::endl;
	} catch (std::exception & e) {
	try {
		c = dynamic_cast<C&>(p);
		std::cout << "type : C" << std::endl;
	} catch (std::exception & e){

	}}}
}
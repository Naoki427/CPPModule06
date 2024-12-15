#include "Serializer.hpp"

int main() {
	Data data;
	
	data.horse = "Do deuce";
	data.jockey = "Yutaka Take";
	std::cout << "\033[33m[ orinal data ]\033[0m" << std::endl;
	std::cout << "Horse: " << data.horse << std::endl;
	std::cout << "Jockey: " << data.jockey << std::endl;
	std::cout << "data address: " << &data << std::endl;
	std::cout << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "\033[33m[ data -> serialize ptr ]\033[0m" << std::endl;
	std::cout << ptr << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m[ data -> serialize ptr -> deserialize ptr ]\033[0m" << std::endl;
	std::cout << Serializer::deserialize(ptr) << std::endl;
	std::cout << std::endl;

	return 0;
}
#pragma once
#include "Data.hpp"
#include <stdint.h>
class Serializer
{
private:
public:
	Serializer();
	Serializer(const Serializer &origin);
	virtual ~Serializer() = 0;
	Serializer& operator = (const Serializer &origin);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
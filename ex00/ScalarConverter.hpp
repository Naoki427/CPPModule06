#pragma once
#include <iostream>
#include "SupportConvert.hpp"

class ScalarConverter
{
private:
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &origin);
	virtual ~ScalarConverter() = 0;
	ScalarConverter& operator = (const ScalarConverter &origin);
	static void convert(const std::string input);
};

void putCharLiteral(const std::string input);
void putIntLiteral(SupportConvert & sup);
void putFloatLiteral(SupportConvert & sup);
void putDoubleLiteral(SupportConvert & sup);
void putPseudoFloat(const std::string input);
void putPseudoDouble(const std::string input);
void putErrorLiteral(SupportConvert & sup);
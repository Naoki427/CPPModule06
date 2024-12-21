#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &origin) {
	*this = origin;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter &origin){
	if(this == &origin)
		return *this;
	
	return *this;
}

void ScalarConverter::convert(const std::string input) {
	SupportConvert sup;
	int type = sup.getType(input);
	if (type == CHAR)
		putCharLiteral(input);
	if (type == INT)
		putIntLiteral(sup);
	if (type == FLOAT)
		putFloatLiteral(sup);
	if (type == DOUBLE)
		putDoubleLiteral(sup);
	if (type == P_FLOAT)
		putPseudoFloat(input);
	if (type == P_DOUBLE)
		putPseudoDouble(input);
	if (type == ERROR)
		putErrorLiteral(sup);
}

void putCharLiteral(const std::string input) {
	char c =  static_cast<char>(input[0]);
	std::cout << "char: ";
	if (input[0] >= 32 && input[0] <= 126)
		std::cout << c << std::endl;
	else {
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void putIntLiteral(SupportConvert & sup) {
	int n = sup.getIntValue();

	std::cout << "char: ";
	if (n >= 32 && n <= 126)
		std::cout << static_cast<char>(n) << std::endl;
	else if (n >= -128 && n <= 31) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "Out of range" << std::endl;
	}
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void putFloatLiteral(SupportConvert & sup) {
	float n = sup.getFloatValue();

	std::cout << "char: ";
	if (n >= 32 && n <= 126)
		std::cout << static_cast<char>(n) << std::endl;
	else if (n >= -128 && n <= 31) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "Out of range" << std::endl;
	}
	if (sup.getIsOverflow() == INT_OVER)
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (sup.getIsDecimal() == 0) {
		std::cout << "float: " << n << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << n << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
	}
}

void putDoubleLiteral(SupportConvert & sup) {
	double n = sup.getDoubleValue();

	std::cout << "char: ";
	if (n >= 32 && n <= 126)
		std::cout << static_cast<char>(n) << std::endl;
	else if (n >= -128 && n <= 31) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "Out of range" << std::endl;
	}
	if (sup.getIsOverflow() == INT_OVER || sup.getIsOverflow() == FLOAT_OVER)
		std::cout << "int: Out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (sup.getIsOverflow() == FLOAT_UNDER || sup.getIsOverflow() == FLOAT_OVER)
		std::cout << "float: Out of range" << std::endl;
	else if (sup.getIsDecimal() == 0)
		std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	else 
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	if (sup.getIsDecimal() == 0)
		std::cout << "double: " << n << ".0" << std::endl;
	else 
		std::cout << "double: " << n << std::endl;
}

void putPseudoFloat(const std::string input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << input.substr(0,input.length() -1) << std::endl;
}

void putPseudoDouble(const std::string input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void putErrorLiteral(SupportConvert & sup) {
	if(sup.getIsOverflow() == 0) {
	std::cout << "char: invalid input" << std::endl;
	std::cout << "int: invalid input" << std::endl;
	std::cout << "float: invalid input" << std::endl;
	std::cout << "double: invalid input" << std::endl;
	}
	else if (sup.getIsOverflow() == INT_OVER) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: Out of range" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (sup.getIsOverflow() == FLOAT_OVER || sup.getIsOverflow() == FLOAT_UNDER) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: Out of range" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else if (sup.getIsOverflow() == DOUBLE_OVER || sup.getIsOverflow() == DOUBLE_UNDER) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: Out of range" << std::endl;
	}
}
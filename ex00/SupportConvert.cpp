#include "SupportConvert.hpp"

SupportConvert::SupportConvert() :_intValue(0),_floatValue(0),_doubleValue(0),_isOverflow(0), _isDecimal(0) {}

SupportConvert::SupportConvert(const SupportConvert &origin) {
	*this = origin;
}

SupportConvert::~SupportConvert() {}

SupportConvert& SupportConvert::operator= (const SupportConvert &origin){
	if(this == &origin)
		return *this;
	_isOverflow = origin.getIsOverflow();
	_intValue = origin.getIntValue();
	_floatValue = origin.getFloatValue();
	_doubleValue = origin.getDoubleValue();
	_isDecimal = origin.getIsDecimal();
	return *this;
}

void SupportConvert::setIntValue(int n) {
	_intValue = n;
}

void SupportConvert::setFloatValue(float n) {
	_floatValue = n;
}

void SupportConvert::setDoubleValue(double n){
	_doubleValue = n;
}

void SupportConvert::setIsOverflow(int n) {
	_isOverflow = n;
}

void SupportConvert::setIsDecimal(int n) {
	_isDecimal = n;
}

int		SupportConvert::getIntValue() const {
	return _intValue;
}

float	SupportConvert::getFloatValue() const {
	return _floatValue;
}

double	SupportConvert::getDoubleValue() const {
	return _doubleValue;
}

int SupportConvert::getIsOverflow() const {
	return _isOverflow;
}

int SupportConvert::getIsDecimal() const {
	return _isDecimal;
}

bool SupportConvert::isDigit(const char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool SupportConvert::isChar(const std::string input) {
	if (input.length() != 1 || isDigit(input[0]))
		return false;
	return true;
}

bool SupportConvert::isInt(const std::string input) {
	long num = 0;
	int sign = (input[0] == '-') ? -1 : 1;
	for (size_t i = (input[0] == '-') ? 1 : 0; i < input.length(); i++)
	{
		if(!isDigit(input[i]))
			return false;
		if(getIsOverflow() == 0)
			num = num*10 + (input[i] - '0');
		if(sign == 1 && num > 2147483647)
			setIsOverflow(INT_OVER);
		if(sign == -1 && num > 2147483648)
			setIsOverflow(INT_OVER);
	}
	if(getIsOverflow())
		return false;
	setIntValue(static_cast<int>(sign*num));
	return true;
}

bool SupportConvert::isFloat(const std::string input) {
	int dot_flg = 0;
	long num = 0;
	int digit = 0;
	int decimal_digit = 0;
	float scale = 1;
	if (input[0] == '.' || input[input.length() - 2] == '.')
		return false;
	if (input[0] == '-' && input[1] == '.')
		return false;
	for (size_t i = (input[0] == '-') ? 1 : 0; i < input.length(); i++)
	{
		if(!isDigit(input[i]) && input[i] != '.')
		{
			if(i == input.length() - 1 && input[i] == 'f')
				break;
			setIsOverflow(0);
			return false;
		}
		if(dot_flg == 1 && input[i] == '.')
		{
			setIsOverflow(0);
			return false;
		}
		if(dot_flg == 0 && input[i] == '.') {
			dot_flg = 1;
			continue;
		}
		if(dot_flg == 0)
			digit++;
		else {
			decimal_digit++;
			scale *= 10;
			if (input[i] != '0')
				setIsDecimal(1);
		}
		if(digit <= 8)
			num = num * 10 + (input[i] - '0');
		if(digit > 39 || (digit == 39 && num > FLT_MAX_VV))
			setIsOverflow(FLOAT_OVER);
		if(decimal_digit > 38 && getFloatValue() == 0)
			setIsOverflow(FLOAT_UNDER);
		if(getIsOverflow() != FLOAT_OVER || getIsOverflow() != FLOAT_UNDER)
		{
			if(dot_flg == 0)
				setFloatValue(getFloatValue()* static_cast<float>(10) + static_cast<float>(input[i] - '0'));
			else
				setFloatValue(getFloatValue() + static_cast<float>(input[i] - '0') / scale);
		}
	}
	if(getIsOverflow() == FLOAT_OVER || getIsOverflow() == FLOAT_UNDER || input[input.length() - 1] != 'f')
		return false;
	if (input[0] == '-')
		setFloatValue(-getFloatValue());
	if (digit > 6 || decimal_digit > 6)
		setIsDecimal(1);
	return true;
}

bool SupportConvert::isDouble(const std::string input) {
	int dot_flg = 0;
	long num = 0;
	int digit = 0;
	int decimal_digit = 0;
	double scale = 1;
	if (input[0] == '.' || input[input.length() - 1] == '.')
		return false;
	if (input[0] == '-' && input[1] == '.')
		return false;
	for (size_t i = (input[0] == '-') ? 1 : 0; i < input.length(); i++)
	{
		if(!isDigit(input[i]) && input[i] != '.')
		{
			if(i == input.length() - 1 && input[i] == 'f')
				return false;
			setIsOverflow(0);
			return false;
		}
		if(dot_flg == 1 && input[i] == '.')
		{
			setIsOverflow(0);
			return false;
		}
		if(dot_flg == 0 && input[i] == '.') {
			dot_flg = 1;
			continue;
		}
		if(dot_flg == 0)
			digit++;
		else {
			decimal_digit++;
			scale *= 10;
			if (input[i] != '0')
				setIsDecimal(1);
		}
		if(digit <= 16)
			num = num * 10 + (input[i] - '0');
		if(digit > 309 || (digit == 309 && num > DBL_MAX_VV))
			setIsOverflow(DOUBLE_OVER);
		if(decimal_digit > 308 && getDoubleValue() == 0)
			setIsOverflow(DOUBLE_UNDER);
		if(getIsOverflow() != DOUBLE_OVER || getIsOverflow() != DOUBLE_UNDER)
		{
			if(dot_flg == 0)
				setDoubleValue(getDoubleValue()* static_cast<double>(10) + static_cast<double>(input[i] - '0'));
			else
				setDoubleValue(getDoubleValue() + static_cast<double>(input[i] - '0') / scale);
		}
	}
	if(getIsOverflow() == DOUBLE_OVER || getIsOverflow() == DOUBLE_UNDER || decimal_digit == 0)
		return false;
	if (input[0] == '-')
		setDoubleValue(-getDoubleValue());
	if (digit > 6 || decimal_digit > 6)
		setIsDecimal(1);
	return true;
}

bool SupportConvert::isPseudoFloat(const std::string input) {
	if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	return false;
}

bool SupportConvert::isPseudoDouble(const std::string input) {
	if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
		return true;
	return false;
}

int SupportConvert::getType(const std::string input) {
	if (isChar(input))
		return CHAR;
	if (isInt(input))
		return INT;
	if (isFloat(input))
		return FLOAT;
	if (isDouble(input))
		return DOUBLE;
	if (isPseudoFloat(input))
		return P_FLOAT;
	if (isPseudoDouble(input))
		return P_DOUBLE;
	return ERROR;
}

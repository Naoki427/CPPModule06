#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

#define FLT_MAX_VV 34028234
#define DBL_MAX_VV 1797693134862315
enum e_type {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	P_FLOAT,
	P_DOUBLE,
	ERROR
};

enum e_overflow {
	INT_OVER = 10,
	FLOAT_OVER,
	FLOAT_UNDER,
	DOUBLE_OVER,
	DOUBLE_UNDER
};

class SupportConvert
{
private:
	int		_intValue;
	float	_floatValue;
	double	_doubleValue;
	int		_isOverflow;
	int		_isDecimal;
public:
	SupportConvert();
	SupportConvert(const SupportConvert &origin);
	virtual ~SupportConvert();
	SupportConvert& operator = (const SupportConvert &origin);

	void setIntValue(int n);
	void setFloatValue(float n);
	void setDoubleValue(double n);
	void setIsOverflow(int n);
	void setIsDecimal(int n);
	int getIntValue() const;
	float getFloatValue() const;
	double getDoubleValue() const;
	int getIsOverflow() const;
	int getIsDecimal() const;

	bool isDigit(const char c);
	bool isChar(const std::string input);
	bool isInt(const std::string input);
	bool isFloat(const std::string input);
	bool isDouble(const std::string input);
	bool isPseudoFloat(const std::string input);
	bool isPseudoDouble(const std::string input);
	int getType(const std::string input);
};
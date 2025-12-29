#pragma once

#include "Token.hpp"

#include <string>

namespace Calc
{
	Token GetToken(void);
	void Init(void);
	double Error(const std::string&);
	double Expression(bool);
	double Primary(bool);
	double Term(bool);
}

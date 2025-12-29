#pragma once

#include "Token.hpp"
#include "Type.hpp"

namespace Global
{
	extern Calc::Token CurrentToken;
	extern double NumberValue;
	extern std::string StringValue;
	extern Type::Table TableName;
}

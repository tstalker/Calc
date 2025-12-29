#include "Calc.hpp"
#include "Global.hpp"

#include <numbers>

void Calc::Init(void)
{
	Global::TableName["pi"] = std::numbers::pi;
	Global::TableName["e"] = std::numbers::e;
}

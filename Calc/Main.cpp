#include "Calc.hpp"

#include <iostream>
#include <numbers>

int main(void)
{
	Global::TableName["pi"] = std::numbers::pi;
	Global::TableName["e"] = std::numbers::e;

	for(auto NeedPrompt(true); std::cin && Global::CurrentToken != Calc::Token::END;)
	{
		if(NeedPrompt)
		{
			NeedPrompt = false;
			std::cout << "> ";
		}

		Calc::GetToken();

		switch(Global::CurrentToken)
		{
		default:
			break;
		case Calc::Token::END:
		case Calc::Token::PRINT:
			continue;
		}

		std::cout << Calc::Expression(false) << std::endl;
		NeedPrompt = true;
	}

	return EXIT_SUCCESS;
}

double Global::NumberValue{};
std::string Global::StringValue;
Calc::Token Global::CurrentToken(Calc::Token::PRINT);
Type::Table Global::TableName;

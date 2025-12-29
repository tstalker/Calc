#include "Calc.hpp"
#include "Global.hpp"

#include <iostream>

int main(void)
{
	Calc::Init();

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

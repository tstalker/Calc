#include "CalcTestHelpers.hpp"
#include "Calc.hpp"

#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcTests
{
    TEST_CLASS(ExpressionTests)
    {
    public:

        TEST_METHOD(Addition)
        {
            CinRedirect in("2+3;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(5.0, result);
        }

        TEST_METHOD(OperatorPrecedence)
        {
            CinRedirect in("2+3*4;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(14.0, result);
        }

        TEST_METHOD(Parentheses)
        {
            CinRedirect in("(2+3)*4;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(20.0, result);
        }

        TEST_METHOD(SubAndDiv)
        {
            CinRedirect in("20-10/2;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(15.0, result);
        }

        TEST_METHOD(Power)
        {
            CinRedirect in("2^3;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(8.0, result);
        }

        TEST_METHOD(NestedExpression)
        {
            CinRedirect in("2*(3+4*(1+1));");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(22.0, result);
        }

        TEST_METHOD(SyntaxError)
        {
            CinRedirect in("2+;");
            const auto result(Calc::Expression(false));
            Assert::AreEqual(0.0, result);
        }
    };
}

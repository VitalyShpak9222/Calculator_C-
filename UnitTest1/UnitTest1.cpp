#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Functions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NumberTest)
		{
			std::string str = "1283.45";
			Calculator calc{str};
			unsigned int idx = 0;
			double result = calc.Number(str, idx);
			Assert::IsTrue(result == 1283.45);
		}

		TEST_METHOD(ExprTest1)
		{
			std::string str = "2+3";
			Calculator calc{ str };
			unsigned int idx = 0;
			double result = calc.Expr(str, idx);
			Assert::IsTrue(result == 5);
		}

		TEST_METHOD(ExprTest2)
		{
			std::string str = "2+3-4+12-4+2+3";
			Calculator calc{ str };
			unsigned int idx = 0;
			double result = calc.Expr(str, idx);
			Assert::IsTrue(result == 14);
		}

		TEST_METHOD(TermTest1)
		{
			std::string str = "6*4";
			Calculator calc{str};
			unsigned int idx = 0;
			double result = calc.Term(str, idx);
			Assert::IsTrue(result == 24);
		}

		TEST_METHOD(TermTest2)
		{
			std::string str = "6*6/4*232/2/4";
			Calculator calc{ str };
			unsigned int idx = 0;
			double result = calc.Term(str, idx);
			Assert::IsTrue(result == 261);
		}

 		TEST_METHOD(FactorTTest)
		{
			std::string str = "2*(3-2)";;
			Calculator calc{str};
			unsigned int idx = 0;
			double result = calc.Factor(str, idx);
			Assert::IsTrue(result == 2);
		}
	};
}

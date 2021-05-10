#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.4/Matrix.cpp"
#include "../lab2.4/Matrix.h"
#include "../lab2.4/Row.cpp"
#include "../lab2.4/Row.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Matrix A(4), B(4);
			Assert::AreEqual(A == B, true);
		}
	};
}

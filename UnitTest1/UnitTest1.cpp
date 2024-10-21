#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-7.2 REC/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 2;
			int n = 2;
			int minmax;
			int** a = new int* [k];
			rowmem(a, k, n,0);
			a[0][0] = 1;
			a[0][1] = 3;
			a[1][0] = 6;
			a[1][1] = 5;
			Calc(a, k, n, minmax,1);
			Assert::AreEqual(minmax, 3);
		}
	};
}

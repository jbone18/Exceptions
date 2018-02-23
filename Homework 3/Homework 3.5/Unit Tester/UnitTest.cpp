#include"stdafx.h"
#include"CppUnitTest.h"
#include"readint.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std; //Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{
	TEST_CLASS(readint)
	{
	public:
		Test case 1: If read_int(“My prompt : ”, -3, 3) AND input is “Hello\n0”
				Expect 0 will be returned by the function

			Test case 2: If read_int(“My prompt : ”, 5, 1)
				Expect invalid_argument exception will be thrown

			Test case 3: If read_int(“My prompt : ”, 0, 4) AND input is “ - 3\n5\n10\n - 2\n3”
				Expect 3 will be returned by the function

			Test case 4: If read_int(“My prompt : ”, 0, 0)
				Expect invalid_argument exception will be thrown

	}

}

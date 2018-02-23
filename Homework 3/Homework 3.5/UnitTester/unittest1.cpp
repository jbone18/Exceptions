#include "stdafx.h"
#include "CppUnitTest.h"
#include"readint.h"
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTester
{	
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(case1) // Test case 1: invalid input
		{
			ifstream ss("C:\\Users\\jbone\\OneDrive\\Desktop\\CS-273-1\\Homework\\Homework 3\\Homework 3.5\\UnitTester\\zeroinput.txt");

			// Check if we opened the file stream successfully
			if (ss.fail())
			{
				throw int(-1); // throw an integer with value -1
			}
			
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);

			// Close the file stream
			ss.close();
		}

		TEST_METHOD(case2) // Test case 2: for invalid argument
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(case3)
		{
			ifstream ss("C:\\Users\\jbone\\OneDrive\\Desktop\\CS-273-1\\Homework\\Homework 3\\Homework 3.5\\UnitTester\\threeinput.txt");

			// Check if we opened the file stream successfully
			if (ss.fail())
				throw int(-1); // throw an integer with value -1

			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// We expect the correct value returned is 3.
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);

			// Close the file stream
			ss.close();
		}

		TEST_METHOD(case4)
		{
			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}
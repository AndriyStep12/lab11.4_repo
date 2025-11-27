#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include <cstdio>
#include "../lab11_4.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest11_4)
	{
	public:

		TEST_METHOD(TestProcessFiles_ReverseOrderAndRemoveChar)
		{
			string inFile = "test_in.txt";
			string outFile = "test_out.txt";
			char excludeChar = 'o';

			ofstream fout(inFile);
			fout << "Hello" << endl;
			fout << "World" << endl;
			fout.close();

			ProcessFiles(inFile, outFile, excludeChar);

			ifstream fin(outFile);
			string line;

			getline(fin, line);
			Assert::AreEqual(string("Wrld"), line, L"First line mismatch (should be reversed last line)");

			getline(fin, line);
			Assert::AreEqual(string("Hell"), line, L"Second line mismatch (should be reversed first line)");

			fin.close();

			remove(inFile.c_str());
			remove(outFile.c_str());
		}
	};
}
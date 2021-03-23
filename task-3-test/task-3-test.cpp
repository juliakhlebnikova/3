#include "pch.h"
#include "CppUnitTest.h"
#include "main.cpp"
#include <vector>
#include "../task-3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace task3test
{
	TEST_CLASS(task3test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int m = 4, n = 4;
			vector<vector<int>> matrix = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} };
			vector<int> result = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4 };
			vector<int> vec(m* n);

			change_matrix(matrix, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod2)
		{
			const int m = 1, n = 4;
			vector<vector<int>> matrix = { { 1, 1, 1, 1 } };
			vector<int> result = { 1, 1, 1, 1 };
			vector<int> vec(m * n);

			change_matrix(matrix, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod3)
		{
			const int m = 4, n = 1;
			vector<vector<int>> matrix = { { 1 }, { 1 }, { 1 }, { 1 } };
	        vector<int> result = { 1, 1, 1, 1 };
			vector<int> vec(m * n);

			change_matrix(matrix, vec, m, n);

			Assert::IsTrue(vec == result);
		}

		TEST_METHOD(TestMethod4)
		{
			const int m = 1, n = 4;
			vector<vector<int>> matrix(m, vector<int>(n));
			vector<vector<int>> result = { { 1, 1, 1, 1 } };
			vector<int> vec = { 1, 1, 1, 1 };

			change_vector(matrix, vec, m, n);

			Assert::IsTrue(matrix == result);
		}

		TEST_METHOD(TestMethod5)
		{
			const int m = 4, n = 1;
			vector<vector<int>> matrix(m, vector<int>(n));
			vector<vector<int>> result = { { 1 }, { 1 }, { 1 }, { 1 } };
			vector<int> vec = { 1, 1, 1, 1 };

			change_vector(matrix, vec, m, n);

			Assert::IsTrue(matrix == result);
		}

		TEST_METHOD(TestMethod6)
		{
			const int m = 1, n = 1;
			vector<vector<int>> matrix(m, vector<int>(n));
			vector<vector<int>> result = { { 1 } };
			vector<int> vec = { 1 };

			change_vector(matrix, vec, m, n);

			Assert::IsTrue(matrix == result);
		}

		TEST_METHOD(TestMethod7)
		{
			const int m = 0, n = 0;
			vector<vector<int>> matrix(m, vector<int>(n));
			vector<vector<int>> result = { };
			vector<int> vec = { };

			change_vector(matrix, vec, m, n);

			Assert::IsTrue(matrix == result);
		}
	};
}

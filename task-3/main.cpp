#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void random_vector(vector<int>& v)
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		*i = rand() % 10;
	}
}

void random_matrix(vector<vector<int>>& matrix)
{
	for (vector<vector<int>>::iterator row = matrix.begin(); row != matrix.end(); ++row)
	{
		for (vector<int>::iterator col = row->begin(); col != row->end(); ++col)
		{
			*col = rand() % 10;
		}
	}
}

void print_vector(std::vector<int> v)
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

void print_matrix(vector<vector<int>> matrix)
{
	for (vector<vector<int>>::iterator row = matrix.begin(); row != matrix.end(); ++row)
	{
		for (vector<int>::iterator col = row->begin(); col != row->end(); ++col)
		{
			cout << *col << ' ';
		}
		cout << endl;
	}
}

void change_matrix(vector<vector<int>>& matrix, vector<int>& v, int m, int n)
{
	for (vector<vector<int>>::iterator row = matrix.begin(); row != matrix.end(); ++row)
	{
		for (vector<int>::iterator col = row->begin(); col != row->end(); ++col)
		{
			vector<int>::iterator it = v.begin() + ((row - matrix.begin()) * n + (col - row->begin()));
			*it = *col;
		}
	}
}

void change_vector(vector<vector<int>>& matrix, vector<int>& v, int m, int n)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		vector<vector<int>>::iterator row = matrix.begin() + (it - v.begin()) / n;
		vector<int>::iterator col = row->begin() + (it - v.begin()) % n;
		*col = *it;
	}
}


int main(int argc, char* argv[])
{
	int m, n;
	srand(time(0));
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	cout << "\n";

	vector<vector<int>> matrix(m, vector<int>(n));
	vector<int> vec(m * n);

	random_matrix(matrix);
	cout << "Random matrix: ";
	cout << "\n";
	print_matrix(matrix);
	change_matrix(matrix, vec, m, n);
	cout << "Vector: ";
	print_vector(vec);
	cout << "\n";

	random_vector(vec);
	cout << "Random vector: ";
	print_vector(vec);
	change_vector(matrix, vec, m, n);
	cout << "Matrix: ";
	cout << "\n";
	print_matrix(matrix);
	cout << "\n";

	return 0;
}

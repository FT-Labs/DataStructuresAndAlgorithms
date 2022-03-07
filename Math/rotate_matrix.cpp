#include <iostream>
#include <vector>
using namespace std;



void rotateMatrix(vector<vector<int>>& mat)
{
	// First get transpose
	for(int i=0; i<mat.size(); i++)
		for(int j=i; j<mat.size(); j++)
			swap(mat[i][j], mat[j][i]);

	// Swap first half and last half
	for(int i=0; i<mat.size(); i++)
		for(int j=0; j<mat[i].size()/2; j++)
			swap(mat[i][j], mat[i][mat[i].size()-j-1]);
}




int main()
{
	// 1 2 3	7 4 1
	// 4 5 6 -> 8 5 2
	// 7 8 9 	9 6 3

	// 1 4 7	7 4 1
	// 2 5 8 -> 8 5 2
	// 3 6 9    9 6 3

	vector<vector<int>> mat = {{1,2,3},
							   {4,5,6},
							   {7,8,9}};

	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[i].size(); j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

	rotateMatrix(mat);


	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[i].size(); j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}





	return 0;
}

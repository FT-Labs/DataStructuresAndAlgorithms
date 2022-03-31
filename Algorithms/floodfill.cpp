#include <iostream>
using namespace std;

#define M 8
#define N 8

void ffUtil(int* screen, int x, int y, int prevC, int newC, int width)
{
	int cur = y*width + x;
	//cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (screen[cur] != prevC || screen[cur] == newC)
		return;

	screen[cur] = newC;

	ffUtil(screen, x+1, y, prevC, newC, width);
	ffUtil(screen, x-1, y, prevC, newC, width);
	ffUtil(screen, x, y+1, prevC, newC, width);
	ffUtil(screen, x, y-1, prevC, newC, width);
}


void floodFill(int* screen, int x, int y, int newC, int width)
{
	int prevC = screen[y * width + x];
	if (prevC == newC) return;

	ffUtil(screen, x, y, prevC, newC, width);
}

int main()
{
	int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
				  {1, 1, 1, 1, 1, 1, 0, 0},
				  {1, 0, 0, 1, 1, 0, 1, 1},
				  {1, 2, 2, 2, 2, 0, 1, 0},
				  {1, 1, 1, 2, 2, 0, 1, 0},
				  {1, 1, 1, 2, 2, 2, 2, 0},
				  {1, 1, 1, 1, 1, 2, 1, 1},
				  {1, 1, 1, 1, 1, 2, 2, 1},
				 };

	int x = M/2, y = N/2;
	floodFill(*screen, x, y, 3, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << screen[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

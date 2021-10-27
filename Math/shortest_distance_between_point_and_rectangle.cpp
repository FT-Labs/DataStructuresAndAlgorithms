#include <iostream>
#include <cmath>
#define sqr(x) ((x) * (x))
#define HYPOT(x, y) sqrt(sqr(x) + sqr(y))


using namespace std;


// x and y are coordinates of dot
// other parameters are min and max coordinates of rectangle
// note that if you know opposite diagonal coordinates of the rectangle it is enough to get min and max points
double distancePointRectangle2D(double x, double y, double xMin, double yMin, double xMax, double yMax)
{
	if(x < xMin)
	{
		if(y < yMin)
			return HYPOT(xMin - x, yMin - y);
		else if(y <= yMax)
			return xMin - x;
		else
			return HYPOT(xMin - x, yMax - y);
	}
	else if(x <= xMax)
	{
		if(y < yMin)
			return yMin - y;
		else if(y <= yMax)
			return 0;
		else
			return y - yMax;
	}
	else
	{
		if(y < yMin)
			return HYPOT(x - xMax, yMin - y);
		else if(y <= yMax)
			return x - xMax;
		else
			return HYPOT(x - xMax, y - yMax);
	}
}


int main()
{
	cout << "Enter nums: x, y, xmin, ymin, xmax, ymax" << endl;
	int x, y, xMin, yMin, xMax, yMax; cin >> x >> y >> xMin >> yMin >> xMax >> yMax;

	cout << distancePointRectangle2D(x, y, xMin, yMin, xMax, yMax) << endl;


	return 0;
}

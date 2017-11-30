#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <deque>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Point
{
	int x, y;
};
float dist(Point& p1, Point& p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
float stripPoints(vector<Point> strip, float d)
{
	int size = strip.size();
	float min = d;

	sort(strip.begin(), strip.end(), [](Point& a, Point& b)
	{
		if (a.y > b.y)
			return true;
		else return false;
	});
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
	return min;
}
float closestUtil(vector<Point> P)
{
	int n = P.size();
	if (n <= 3)
	{
		float min = FLT_MAX;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (dist(P[i], P[j]) < min)
					min = dist(P[i], P[j]);
		return min;
	}
	int mid = n / 2;
	Point midPoint = P[mid];
	float dl = closestUtil(vector<Point>(P.begin(),P.begin() + mid) );
	float dr = closestUtil(vector<Point>(P.begin() + mid, P.end()));
	float d = min(dl, dr);
	vector<Point> strip;
	for (int i = 0; i < n; i++)
			if (abs(P[i].x - midPoint.x) < d)
			strip.push_back(P[i]);

	return min(d, stripPoints(strip, d));
}

int main()
{
	ifstream fin("date.in");
	int n;
	fin >> n;
	vector<Point> points;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		fin >> x >> y;
		points.push_back( Point{ x,y } );
	}
	sort(points.begin(), points.end(), [](Point& a, Point& b)
	{
		if (a.x > b.x)
			return true;
		return false;
	});
	cout << closestUtil(points) << endl;

	int ch;
	cin>>ch;
	return 0;
}




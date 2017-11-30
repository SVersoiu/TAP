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
#include <cstdlib>
#include <ctime>
using namespace std;


int nr = 1;

void const_mat(vector<vector<int>>& mat, int i, int j, int n, int x, int y)
    {
	int gol_nr = mat[x][y];

	if (n == 2) {
		mat[i][j] = mat[i][j + 1] = mat[i + 1][j] = mat[i + 1][j + 1] = nr;
		nr++;
		mat[x][y] = gol_nr;
		return;
	}

	int case_;

	if (x < i + n / 2) {
		if (y < j + n / 2)
			case_ = 1;
		else
			case_ = 2;
	}
	else {
		if (y < j + n / 2)
			case_ = 3;
		else
			case_ = 4;
	}
	if(case_ == 1){
		mat[i + n / 2 - 1][j + n / 2] = mat[i + n / 2][j + n / 2 - 1] = mat[i + n / 2][j + n / 2] = nr;
		nr++;
		const_mat(mat, i, j, n / 2, x, y);
		const_mat(mat, i, j + n / 2, n / 2, i + n / 2 - 1, j + n / 2);
		const_mat(mat, i + n / 2, j, n / 2, i + n / 2, j + n / 2 - 1);
		const_mat(mat, i + n / 2, j + n / 2, n / 2, i + n / 2, j + n / 2);
		return;
	}
	else if(case_ == 2){
		mat[i + n / 2 - 1][j + n / 2 - 1] = mat[i + n / 2][j + n / 2 - 1] = mat[i + n / 2][j + n / 2] = nr;
		nr++;
		const_mat(mat, i, j, n / 2, i + n / 2 - 1, j + n / 2 - 1);
		const_mat(mat, i, j + n / 2, n / 2, x, y);
		const_mat(mat, i + n / 2, j, n / 2, i + n / 2, j + n / 2 - 1);
		const_mat(mat, i + n / 2, j + n / 2, n / 2, i + n / 2, j + n / 2);
		return;
	}else if(case_ == 3){
		mat[i + n / 2 - 1][j + n / 2 - 1] = mat[i + n / 2 - 1][j + n / 2] = mat[i + n / 2][j + n / 2] = nr;
		nr++;
		const_mat(mat, i, j, n / 2, i + n / 2 - 1, j + n / 2 - 1);
		const_mat(mat, i, j + n / 2, n / 2, i + n / 2 - 1, j + n / 2);
		const_mat(mat, i + n / 2, j, n / 2, x, y);
		const_mat(mat, i + n / 2, j + n / 2, n / 2, i + n / 2, j + n / 2);
		return;
	}else if(case_ == 4){
		mat[i + n / 2 - 1][j + n / 2 - 1] = mat[i + n / 2 - 1][j + n / 2] = mat[i + n / 2][j + n / 2 - 1] = nr;
		nr++;
		const_mat(mat, i, j, n / 2, i + n / 2 - 1, j + n / 2 - 1);
		const_mat(mat, i, j + n / 2, n / 2, i + n / 2 - 1, j + n / 2);
		const_mat(mat, i + n / 2, j, n / 2, i + n / 2, j + n / 2 - 1);
		const_mat(mat, i + n / 2, j + n / 2, n / 2, x, y);
		return;
	}

}


int main()
{
	ifstream f("date.in");
	int p;
	f >> p;
	int gol_i, gol_j;
	f >> gol_i >> gol_j;
	int n = pow(2, p);
	vector<vector<int>> mat(n+1);

	for (int i = 0; i <= n; i++){
		for (int j = 1; j <= n + 1; j++)
			mat[i].push_back(-1);
	}
	mat[gol_i][gol_j] = 0;

	const_mat(mat, 1, 1, n, gol_i, gol_j);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;


	int ch;
	cin>>ch;
	return 0;
}

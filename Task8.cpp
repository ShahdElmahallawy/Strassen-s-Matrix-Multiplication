/*
Name: Shahd Khaled Elmahallawy
ID: 900194441
Lab 8
*/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matrix_add(vector<vector<int>> mx1, vector<vector<int>> mx2)
{
	vector<vector<int>> result(mx1.size());
	for (int i = 0; i < mx1.size(); i++)
	{
		for (int j = 0; j < mx2.size(); j++)
		{
			result[i].push_back(mx1[i][j] + mx2[i][j]);
		}
	}
	return result;
}
vector<vector<int>> matrix_subtract(vector<vector<int>> mx1, vector<vector<int>> mx2)
{
	vector<vector<int>> result(mx1.size());
	for (int i = 0; i < mx1.size(); i++)
	{
		for (int j = 0; j < mx2.size(); j++)
		{
			result[i].push_back (mx1[i][j] - mx2[i][j]);
		}
	}
	return result;
}
vector<vector<int>> matrix_mult(vector<vector<int>> mx1, vector<vector<int>> mx2)
{
	int n = mx1.size();
	//Base Case (1x1 matrices)
	if (n == 1)
	{
		vector<vector<int>> Z(1);
		Z[0].push_back(mx1[0][0] * mx2[0][0]);
		return Z;
	}
	vector<vector<int>> a(n / 2);
	vector<vector<int>>b(n / 2);
	vector<vector<int>>c(n / 2);
	vector<vector<int>>d(n / 2);
	vector<vector<int>>e(n / 2);
	vector<vector<int>>f(n / 2);
	vector<vector<int>>g(n / 2);
	vector<vector<int>>h(n / 2);
	vector<vector<int>>p[8];
	vector<vector<int>>temp1(n / 2);
	vector<vector<int>>temp2(n / 2);
	
	vector<vector<int>> Z(n);
	//Divide the matrix into 4 sub-matrices
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			a[i].push_back(mx1[i][j]);
			b[i].push_back(mx1[i][n / 2 + j]);
			c[i].push_back(mx1[n / 2 + i][j]);
			d[i].push_back(mx1[n / 2 + i][n / 2 + j]);

			e[i].push_back(mx2[i][j]);
			f[i].push_back(mx2[i][n / 2 + j]);
			g[i].push_back(mx2[n / 2 + i][j]);
			h[i].push_back(mx2[n / 2 + i][n / 2 + j]);
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		temp1[i].resize(n / 2);
		temp2[i].resize(n / 2);
	}
	temp1 = matrix_subtract(f, h);
	p[1] = matrix_mult(a, temp1);

	temp1 = matrix_add(a, b);
	p[2] = matrix_mult(temp1, h);

	temp1 = matrix_add(c, d);
	p[3] = matrix_mult(temp1, e);

	temp1 = matrix_subtract(g, e);
	p[4] = matrix_mult(d, temp1);

	temp1 = matrix_add(a, d);
	temp2 = matrix_add(e, h);
	p[5] = matrix_mult(temp1, temp2);

	temp1 = matrix_subtract(b, d);
	temp2 = matrix_add(g, h);
	p[6] = matrix_mult(temp1, temp2);

	temp1 = matrix_subtract(a, c);
	temp2 = matrix_add(e, f);
	p[7] = matrix_mult(temp1, temp2);

	//Fill the result marix(Z)
	for (int i = 0; i < n; i++)
	{
		Z[i].resize(n);
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			Z[i][j] = p[5][i][j] + p[4][i][j] - p[2][i][j] + p[6][i][j];
			Z[i][n / 2 + j] = p[1][i][j] + p[2][i][j];
			Z[n / 2 + i][j] = p[3][i][j] + p[4][i][j];
			Z[n / 2 + i][n / 2 + j] = p[1][i][j] + p[5][i][j] - p[3][i][j] - p[7][i][j];
		}
	}
	return Z;
}
void matrix_display(vector<vector<int>> result)
{
	int n = result.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j] << '\t';
		}
		cout << '\n';
	}
}
int main()
{
	int n;
	n = 4;
	vector<vector<int>> mx1(n), mx2(n);
	mx1 = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	mx2 = { {-1, -2, -3, -4}, {-5, -6, -7, -8}, {-9, -10, -11, -12}, {-13, -14, -15, -16} };
	matrix_display(matrix_mult(mx1, mx2));
	return 0;
}

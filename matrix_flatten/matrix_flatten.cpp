#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#define AboNasser ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
using namespace std;
typedef pair<int, int> pr;
#define ll long long
ll n, m, p;
vector<vector<vector<ll>>>matrix3d;
vector<ll>vector1d;
//return (x * m * p) + (y * p) + z;
void to1D() {
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			for (int k = 0;k < p;k++)
			{
				int eq_indx = (i * m * p) + (j * p) + k;
				vector1d[eq_indx] = matrix3d[i][j][k];
			}
		}
	}
}


/*
 int[] to3D(int idx) {
	final int z = idx / (xMax * yMax);
	idx -= (z * xMax * yMax);
	final int y = idx / xMax;
	final int x = idx % xMax;
	return new int[] { x, y, z };
}
*/
void solve() {
	cout << "enter the the dimentions of the matrix must be positive integers :";
	cin >> n >> m >> p;
	while (n < 0 || m < 0 || p < 0)
	{
		cout << endl << "invalid dimentions" << endl;
		cin >> n >> m >> p;
	}


	// intialize the size of the 1d vector with value zero
	matrix3d.resize(n, vector<vector<ll>>(m, vector<ll>(p)));
	ll y = n * m * p;
	vector1d.resize(y);

	cout << "Enter the 3d matrix: " << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			for (int k = 0;k < p;k++)
			{

				cin >> matrix3d[i][j][k];

			}
		}
	}
	cout << endl;
	to1D();
	// to print vector1d
	for (int i = 0;i < y;i++)
		cout << vector1d[i] << ' ';
}
int main()
{
	solve();
	return 0;

}

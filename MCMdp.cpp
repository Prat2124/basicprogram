// C++ program using memoization
#include <climits>
#include <iostream>
using namespace std;

// function
int MatrixChainOrder(int* p, int n)
{
	n++;
	int m[n][n];
	int i, j, k, L, q;

	// initialize dp array with zero
	for (i = 0; i < n; i++)
		m[i][i] = 0;

	// from L = 3 to L = n-1
	for (L = 2; L < n; L++) 
	{
		for (i = 1; i < n - L + 1; i++) 
		{
			j = i + L - 1;
		
			// make m[i][j] = INT_MAX
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) 
			{
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
			
				// if q is less than m[i][j]
				// make m[i][j] = q;
				if (q < m[i][j]) {
					m[i][j] = q;
				}
			}
		}
	}

	// return ans as m[1][n-1]
	return m[1][n - 1];
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n - 1);
}


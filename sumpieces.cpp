#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long powers[1000003];
const int MOD = 1000000007;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	powers[0] = 1;
	for (int i = 1; i<1000003; i++)
	{
		powers[i] = (2 * powers[i - 1]) % MOD;
	}
	int N;
	cin >> N;
	long long result = 0;
	for (int i = 0; i<N; i++)
	{
		long long num;
		cin >> num;
		long long mult = ((powers[i + 1] + powers[i] - 1)*powers[N - 1 - i] - powers[i] + MOD) % MOD;
		result += num*(mult) % MOD;
        result = result % MOD;
	}
	cout << result;
	return 0;
}

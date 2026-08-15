#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
const int N = 1e5 + 9;
const ll p = 1e9 + 7;

//´ø±¸ÍüÂ¼µÄµÝ¹é
ll dp[N];

ll fib(int n) 
{
	if(dp[n])return dp[n];
	if(n<=2)return 1;
	return dp[n] = (fib(n-1) + fib(n-2))%p;
}
int main()
{
  int n;
  cin >> n;
  cout << fib(n);
}

#define ll long long

class Solution {
public:
	ll tribonacciRec(ll n, ll n1, ll n2, ll n3)
	{
		return n == 0 ? n1 : tribonacciRec(n - 1, n2, n3, n1 + n2 + n3);
	}

	ll tribonacci(ll n)
	{
		return tribonacciRec(n, 0, 1, 1);
	}
};
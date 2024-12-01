class Solution {
public:
	int fibbRec(int n, int n1, int n2) {
		return n == 0 ? n1 : fibbRec(n - 1, n2, n1 + n2);
	}

	int fib(int n) {
		return fibbRec(n, 0, 1);
	}
};
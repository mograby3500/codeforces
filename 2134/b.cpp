#include <bits/stdc++.h>
using namespace std;

#define int long long

int primes[30] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113
};

int power(int a, int b, int MOD) {
	int res = 1;
	while(b) {
		if (b & 1) res = res * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return res;
}

int modInv(int x, int MOD) {
	return power(x, MOD - 2, MOD);
}


void solve() {
	// a, b
	// gcd = g
	// r1 * g = (a + x * k)
	// r2 * g = (b + y * k)
	// choose a prime number = 2
	// k = 4
	// 1, 8
	// 9, 12
	//
	//
	
	int n, k;
	cin>>n>>k;
	
	int a[n];
	for(int i= 0; i < n; i++) {
		cin>>a[i];
	}

	int p = -1;
	for(int i = 0; i < 30; i++) {
		if (k % primes[i]) {
			p = primes[i];
			break;
		}
	}
	assert(p != -1);
	int inv = modInv(k, p);
	for(int i = 0; i < n; i++) {
		int x = a[i];
		// x + f * k = 0 (MOD p)
		// (p-x) = f*k (MOD p)
		// f = (p-x) * k^(-1) (MOD p)
		int f = (p - x%p) * inv % p;
		cout<<x + f * k<<" ";
	}
	cout<<"\n";
}
int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    	
	int T; cin>>T;
	while(T--) solve();
}



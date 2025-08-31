#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	// 1 2 3 4 5 6 7
	// 2 >= 1
	// 4 >= 3
	// 6 >= 5
	// [1, 2, 3] ==> 2 >= 1 + 3
	// [1, 2, 3, 4, 5] ==> 2 + 4 >= 1 + 3 + 5
	// [1, 2, 3, 4, 5, 6, 7] ==> 2 + 4 + 6 >= 1 + 3 + 5 + 7

	
	int n; cin>>n;
	int a[n + 1];
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}

	int ans = 0;
	for(int i = 2; i <= n; i+=2) {
		if (a[i - 1] > a[i]) {
			ans += a[i - 1] - a[i];
			a[i - 1] = a[i];
		}

		if (i + 1 <= n && a[i] < a[i - 1] + a[i + 1]) {
			int x = (a[i - 1] + a[i + 1]) - a[i];
			a[i + 1] -= x;
			ans += x;
		}
	}

	cout<<ans<<"\n";
}
int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    	
	int T; cin>>T;
	while(T--) solve();
}



#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin>>n>>m;
	int a[n + 1], b[n + 1];
	a[0] = b[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin>>a[i] >> b[i];
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int d = a[i] - a[i - 1];
		if ((d & 1) == (b[i] ^ b[i - 1])) {
			ans += d;
		} else {
			ans += d - 1;
		}
	}

	ans += m - a[n];
	cout<<ans<<"\n";
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T; cin>>T;
	while(T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin>>n;
	vector<int> odd;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x; cin>>x;
		ans += x;
		if (x & 1) odd.push_back(x);
	}

	if (odd.size() == 0) {
		cout<<"0\n";
		return;
	}

	sort(odd.begin(), odd.end());
	int sz = odd.size();
	for(int i = 0; i < sz / 2; i++) {
		ans -= odd[i];
	}

	cout<<ans<<"\n";
}

int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T; cin>>T;
	while(T--) solve();
}


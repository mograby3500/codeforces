#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, x, y;
	cin>>n>>m>>x>>y;

	for(int i = 0; i < n + m; i++) {
		cin>>x;
	}

	cout<<n + m<<"\n";
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T; cin>>T;
	while(T--) solve();
}

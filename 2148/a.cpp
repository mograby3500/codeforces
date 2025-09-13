#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, n;
	cin>>x >> n;
	cout<<x * (n & 1) <<"\n";

}
int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T; cin>>T;
	while(T--) solve();
}

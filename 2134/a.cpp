#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
	int n, a, b;
	cin>> n >> a >> b;

	if (a > b) {
		int a_parity = a & 1;
		int b_parity = b & 1;
		int n_parity = n & 1;

		if (a_parity == b_parity && b_parity == n_parity) {
			cout<<"YES\n";
		}else {
			cout<<"NO\n";
		}
	} else {
		if ((b & 1) == (n & 1)) {
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}	
}
int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    	
	int T; cin>>T;
	while(T--) solve();
}



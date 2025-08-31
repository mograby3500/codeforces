#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> adj;
vector<int> d, is_diameter, parent;
int a, b, c;

pair<int,int> dfs(int node, int p, int depth) {
	pair<int,int> res = {depth, node};
	for(int ch : adj[node]) {
		if (ch == p) continue;
		res = max(res, dfs(ch, node, depth + 1));
	}
	d[node] = res.first;
	return res;
}

void mark_diameter(int node, int p) {
	parent[node] = p;
	is_diameter[node] = 1;
	
	pair<int,int> to = {-1, -1};
	for(int ch : adj[node]) {
		if (ch != p) {
			to = max(to, {d[ch], ch});
		}
	}

	if (to.second != -1) {
		mark_diameter(to.second, node);
	}
}

void solve() {
	int n; cin>>n;
	adj = vector<vector<int>> (n);
	d = vector<int> (n, 0);
	is_diameter = vector<int> (n, 0);
	parent = vector<int> (n, -1);

	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin>>u>>v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	auto [_, ed] = dfs(0, 0, 0);
	auto [l, __] = dfs(ed, -1, 0);


	if (l == n - 1) {
		cout<<"-1\n";
		return;
	}

	mark_diameter(ed, -1);
	// for(int node = 0; node < n; node++) {
	//	if (is_diameter[node]) {
	//		cout<<node + 1 <<"\n";
	//	}
	//}
	for(int node = 0; node < n; node++) {
		if (parent[node] == -1) 
			continue;
		
		if (is_diameter[node] && is_diameter[parent[node]]) {
			for(int ch : adj[node]) {
				if (!is_diameter[ch]) {
					cout<<parent[node] + 1 <<" "<<node + 1 <<" "<<ch + 1 <<"\n";
					return;
				}
			}
		}

	}

}
int32_t main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    	
	int T; cin>>T;
	while(T--) solve();
}

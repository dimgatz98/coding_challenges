#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 100005

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility> 

using namespace std;

vector<int> adj[MAXN];
vector<int> visited(MAXN, -1)

pii furthest_node(int u) {
	pii ans = {0, u};
	visited[u] = 1;

	for(int v: adj[u]){
		if(visited[v] == 1)continue;
		pii furthrest_from_child = furthest_node(v);

		if(ans.X < furthrest_from_child.X + 1)
			ans = {furthrest_from_child.X + 1, furthrest_from_child.Y}
	}

	return ans;
}

int n, x, y;

int main() {
	// ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int furthestLeaf = furthest_node(1).Y;

	for(int i = 0 ; i < n ; i++)
		visited[i] = false;
	
	cout << furthest_node(furthestLeaf).X << endl; 

	return 0;
}
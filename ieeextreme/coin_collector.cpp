#include <utility>
#include <vector>
#include <stdio.h>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#define MAXN 10005
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;

vector<int> adj[MAXN], coins, meta_coins;
unordered_map<int, int> sccs;
int V, E, scc_count = 0, start;

void print_vector(vector<int> vec){
    for (auto i: vec) {
        cout << i << "  ";
    }
    cout << endl;
}

void print_map(unordered_map<int, int> m){
    for (auto it: m) {
        cout << it.X << "->" << it.Y << endl;
    }
}

void print_vector_vector(vector<vector<int> > vec){
    for (int i = 0; i < vec.size() ; ++i)
    {
        cout << i << ": ";
        for (auto j: vec[i] ) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

int find_start(vector<vector<int> > metagraph){
    vector<int> edge_num(metagraph.size() );
    int start;

    for (int i = 0; i < metagraph.size() ; ++i)
    {
        for (auto j: metagraph[i] )
        {
            edge_num[j]++;
        }
    }

    for (int i = 0; i < edge_num.size() ; ++i)
    {
        if(edge_num[i] == 0)
            start = i;
    }

    return start;
}

int find_max_coins_path(vector<vector<int> > metagraph, int u){
    int max = meta_coins[u];

    for(auto i: metagraph[u] )
        if(max < meta_coins[u] + find_max_coins_path(metagraph, i) )
            max = meta_coins[u] + find_max_coins_path(metagraph, i);

    return max;
}

vector<vector<int> > make_metagraph(){
    
    vector<int> temp;
    vector<vector<int> > metagraph;
    
    for (int i = 0; i < scc_count ; ++i)
    {
        meta_coins.push_back(0);
        metagraph.push_back(temp);
    }

    for (auto it: sccs)
        meta_coins[it.Y] += coins[it.X];
    
    for (int i = 0; i < V ; ++i)
    {
        for (auto j: adj[i])
        {
            if(sccs[i] != sccs[j] ){
                metagraph[sccs[i] ].push_back(sccs[j] );
            }
        }
    }

    return metagraph;
}

void DFSUtil(vector<vector<int> > gr, int v, vector<int> &visited)
{
    visited[v] = 1;
    sccs.insert({v, scc_count});

    for(auto i: gr[v])
        if(visited[i] == 0)
            DFSUtil(gr, i, visited);
}

vector<vector<int> > getTranspose()
{
    vector<vector<int> > g;
    vector<int> temp;
    for (int i = 0; i < V ; ++i)
    {
        g.push_back(temp);
    }

    for (int v = 0; v < V; v++)
    {
        for(auto i: adj[v])
        {
            g[i].push_back(v);
        }
    }
    return g;
}

void fillOrder(int v, vector<int> &visited, stack<int> &Stack)
{
    visited[v] = 1;
  
    for(auto i: adj[v])
        if(visited[i] == 0)
            fillOrder(i, visited, Stack);
  
    Stack.push(v);
}

void findSCCs()
{
    stack<int> Stack;
  
    vector<int> visited(V);
    
    for(int i = 0; i < V; i++)
        if(visited[i] == 0)
            fillOrder(i, visited, Stack);
  
    vector<vector<int> > gr = getTranspose();
  
    for(int i = 0; i < V; i++)
        visited[i] = 0;
  
    vector<int> temp;
    
    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();
  
        if (visited[v] == 0)
        {
            DFSUtil(gr, v, visited);
            scc_count++;
        }
    }
}
  
int main(int argc, char const *argv[])
{
	vector<vector<int> > metagraph;
    int a, b, res;
	scanf("%d%d", &V, &E);

	for (int i = 0; i < E; ++i)
	{
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

    for (int i = 0; i < V; ++i)
    {
        scanf("%d", &a);
        coins.push_back(a);
    }
    
    findSCCs();

	metagraph = make_metagraph();
	start = find_start(metagraph);

    cout << "sccs:" << endl;
    print_map(sccs);
    cout << "metagraph:" << endl;
    print_vector_vector(metagraph);
    cout << "meta coins:" << endl;
    print_vector(meta_coins);
    
    res = find_max_coins_path(metagraph, start);
    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int query(vector<int> q){
	printf("Q");
	for(int it : q)
		printf(" %d", it);
	printf('\n');
	fflush(stdout);
	
	int res;
	scanf("%d", &res);
	return res;
}

int main(){
	int n;
	scanf("%d", &n);
		
	vector<int> q(n);
	int cnt_zeros = query(q);
	
	vector<int> ans(n);
	for(int i = 0 ; i < q.size() ; i++){
		q[i] = 1;
		if(query(q) > cnt_zeros)
			ans[i] = 1;
		else
			ans[i] = 0;
		q[i] = 0;
	}

	printf("A");
	for(int it: ans)
		printf(" %d", it);
	return 0;
}
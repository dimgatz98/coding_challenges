#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void print_vector(vector<int> vec){
    for(auto i: vec){
        cout << i << " ";
    }
    cout << endl;
}

int shuffle_and_get_sum(vector<int> &a, int W){
    int sum = 0;
    random_shuffle(a.begin(), a.end() );
    print_vector(a);
    for(auto i: a){
        if(W - i >= 0){
            W -= i;
            sum += i;
        }
    }
    cout << sum << endl;
    return sum;
}

int main(int argc, char const *argv[])
{
	int W, n;
	scanf("%d%d", &W, &n);
	vector<int> a(n);
	for(int &x :a){
		scanf("%d", &x);
	}
    int temp_max = 0;
    for (int i = 0; i < 100; ++i)
    {
       temp_max = max(shuffle_and_get_sum(a, W), temp_max);
    }

	cout << temp_max << endl;
}
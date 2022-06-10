/*
Randomized algorithm to compute the largest subset of points that belong in the same line
*/

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;

void print_vector(vector<pii> v){
	for (auto x: v)
		cout << x.X << "=>" << x.Y << " ";
	cout << endl;
}

int count_points_in_line(pii a, pii b, vector<pii> &x){
	int res = 0, m = (b.Y - a.Y) / (b.X - a.X), c = a.Y - m * a.X; // a.Y = m * a.X + c;
	//line is y = m * x + c;
	
	for(auto i: x){
		if(i.Y == m * i.X + c){
			res++;
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	unordered_set<string> searched_points;
	srand (time(NULL) );
	int n, a, b ;
	scanf("%d", &n);
	vector<pii> points(n);
	for (auto &x: points)
	{
		scanf("%d%d", &x.X, &x.Y);
	}

	int temp_max = 0;
	for (int i = 0; i < 40 ; ++i)
	{
		a = rand() % n;
		b = rand() % n;
		if(searched_points.find(to_string(a)+to_string(b) ) == searched_points.end() ) { // in this case the string
																						 // a + b is not in the set
			searched_points.insert(to_string(a)+to_string(b) );
			temp_max = max(temp_max, count_points_in_line(points[a], points[b], points) );
		}
		else{
			i--;
		}
	}
	cout << temp_max << endl;
	return 0;
}
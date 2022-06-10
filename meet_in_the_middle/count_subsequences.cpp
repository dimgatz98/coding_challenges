#include <iostream>

using namespace std;
 
int main(int argc, char *argv[]) {
    int n, smaller = 0, greater = 0, res = 0;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
    }
    for (int j = 1 ; j < n - 1 ; ++j)
    {
        smaller = 0, greater = 0;
        for (int i = 0; i < j; ++i)
        {
            if(a[i] < a[j]){
                smaller++;
            }
        }
        for (int i = j + 1; i < n; ++i)
        {
            if(a[i] > a[j])
                greater++;
        }
        res += smaller * greater;
    }
    cout << res << endl;
    return 0;
}
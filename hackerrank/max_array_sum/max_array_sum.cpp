#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    // res.first is the best result up until now and 
    // res.second indicates whether or not arr[i]
    // is included in this result
    vector<pair<int,int> > res;
    
    for (int i = 0 ; i < arr.size() ; i++) {
        // If arr[i] is negative it should not be included
        // so we copy previous result if it exists
        if (arr[i] <= 0) {
            if (i == 0) {
                res.push_back({0, 0});
            } else {
                res.push_back({res[i - 1].first, 0});
            }
            continue;
        }

        // First element should be included unless it's negative
        if (i == 0) {
            res.push_back({arr[i + 1], 1});
            continue;
        }
        // Second element should be checked with the previous one
        else if (i == 1) {
            if(arr[i] > res[i - 1].first) {
                res.push_back({arr[i], 1});
                res[i - 1].second = 0;
            } else {
                res.push_back({res[i - 1].first, 0});
            }
            continue;
        }

        // If the last element wasn't included and 
        // arr[i] is not negative then it is always
        // included
        if (!res[i - 1].second) {
            res.push_back({res[i - 1].first + arr[i], 1});
            continue;
        }

        // If result's better without arr[i] then keep the same result
        if (res[i - 1].first >= res[i - 2].first + arr[i]) { 
            res.push_back({res[i - 1].first, 0});
        } else {
            // Else add arr[i] and delete arr[i - 1]
            res.push_back({res[i - 2].first + arr[i], 1});
            res[i - 1].second = 0;
        }
    }

    return res[res.size() - 1].first;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    cout << res << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

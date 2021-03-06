#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

bool compare2D (vector<int> v1, vector<int> v2) {
    if(v1[0] > v2[0]) {
        return true;
    }
    else {
        return false;
    }
}

void printVector (vector<vector<int>> v) {
    for(vector<int> x: v) {
        cout << "[" << x[0] << ", " << x[1] << "]" << " ";
    }
    cout << endl;
}

int luckBalance(int k, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end(), compare2D);
    printVector(contests);
    int counter = 0, luck = 0;
    for(vector<int> v: contests) {
        if (v[1] == 0) {
            cout << "Just added: [" << v[0] << ", " << v[1] << "]" << endl;
            luck += v[0];
        }
        else if (counter < k){
            cout << "Just added: [" << v[0] << ", " << v[1] << "]" << endl;
            counter++;
            luck += v[0];
        }
        else {
            luck -= v[0];
        }
    }
    return luck;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> contests(n);

    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        string contests_row_temp_temp;
        getline(cin, contests_row_temp_temp);

        vector<string> contests_row_temp = split(rtrim(contests_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int contests_row_item = stoi(contests_row_temp[j]);

            contests[i][j] = contests_row_item;
        }
    }

    int result = luckBalance(k, contests);

    cout << result << "\n";
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

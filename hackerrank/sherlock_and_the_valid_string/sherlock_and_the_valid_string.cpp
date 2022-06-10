#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

void printMap (unordered_map<char, int> m) {
    for (pair<char, int> p: m) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << endl;
}

string isValid(string s) {
    unordered_map<char, int> m;
    int occurencies1 = -1, occurencies2 = -1, occurencies3 = -1, count = 0, dif = 0, count1 = 0;

    for (char c: s) {
        if (m.find(c) == m.end()) {
            m.insert({c, 1});
            continue;
        }
        m.at(c)++;
    }

    for (pair<char, int> p: m) {
      
        if (count == 0) {
            count++;
            count1++;
            occurencies1 = p.second;
            continue;
        }

        if (count == 2) {
            if (count1 == 2) { 
                if (occurencies1 != p.second && occurencies2 != p.second) {
                    return "NO";
                }
            }
            else {
                if (occurencies1 != p.second) {
                    return "NO";
                }
            }
            occurencies3 = occurencies1;
            occurencies1 = p.second;
            count--;
            count1++;
            continue;
        }

        count1++;

        if (p.second != occurencies1) {
            if (p.second > occurencies1 + 1) { 
                if (occurencies1 != 1 || count1 > 2) { 
                    return "NO";
                }
                occurencies2 = p.second;
                count++;
            }
            
            else if (p.second < occurencies1 - 1) { 
                if (p.second != 1) { 
                    return "NO";
                }
                occurencies2 = p.second;
                count++;
            }

            else if (p.second == occurencies1 - 1) { 
                dif++;
                if (dif == 2) { 
                    return "NO";
                }
                occurencies2 = p.second;
                count++;
            }

            else if (p.second == occurencies1 + 1) { 
                dif++;
                if (dif == 2) { 
                    return "NO";
                }
                occurencies2 = p.second;
                count++;
            }        
        }
    }
    
    if (occurencies1 == 1 && (occurencies2 > 2 || occurencies3 > 2)) {
        return "NO";
    }

    if (occurencies2 == -1 && occurencies3 == -1) {
        return "YES";
    }

    return (occurencies1 == occurencies2 || occurencies1 == occurencies3) ? "YES" : "NO";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}

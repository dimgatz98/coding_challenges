#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.size() == 0) { 
            return 0;
        }
        // I             1
        // V             5
        // X             10
        // L             50
        // C             100
        // D             500
        // M             1000
        unordered_map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        
        int res = m.at((char)s[s.size() - 1]);
        
        for (int i = s.size() - 2 ; i >= 0 ; i--) {
            if (m.at((char)s[i]) >= m.at((char)s[i + 1])) { 
                res += m.at((char)s[i]);
                continue;
            }
            res -= m.at((char)s[i]);
        }      

        return res;
    }   
};

int main() {
    cout << Solution().romanToInt("III") << endl;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> split(string num) {
        int tmp1, tmp2, count, checkpoint, num1, num2;
        for (int i = 0 ; i < num.size() - 1 ; i++) {
            tmp1 = stoi(num.substr(num.size() - 1 - i, num.size() ) );

            count = num.size() - i - 2;
            tmp2 = stoi(num.substr(count, num.size() - i - 1) );
            while (tmp2 < tmp1) {
                count--;
                tmp2 = stoi(num.substr(count, num.size() - i - 1) );
            }
            checkpoint = count + 1;
            tmp2 = stoi(num.substr(count, checkpoint) );
            while (tmp2 < tmp1) {
                count--;
                tmp2 = stoi(num.substr(count, checkpoint) );
            }
            count++;

            for (int j = num.size() - i ; j >= count ; j--) {
                num1 = stoi(num.substr(count, num.size() - i - 1 - j) );
                num2 = stoi(num.substr(num.size() - i - 1 - j, num.size() - i - 1) );
                if (num1 + num2 == tmp1) {
                    return vector<pair<int, int> > ({{count, num.size() - i - 2 - j}, {num.size() - i - 2 - j, num.size() - i - 2}});
                }
            }
        } 
        return vector<pair<int,int> > ({{-1, -1}, {-1, -1}});
    }

    bool isAdditiveNumber(string num) {
        vector<pair<int, int> > tmp;
        while (num.size() > 0) {
            tmp = split(num);
            if (tmp[0].first == -1) {
                return false;
            }
            num = num.substr(0, tmp[1].second);
        }
        return true;
    }
};

int main() {
    if (Solution().isAdditiveNumber("123") ) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}
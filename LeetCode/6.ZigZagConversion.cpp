#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> arr(numRows);
        int direction = -1;
        int j = 0;

        for (int i = 0; i < s.size(); ++i) {
            arr[j] += s[i];
            if (j == 0 || j == numRows - 1) {
                direction *= -1;
            }
            j += direction;
        }
        
        string res;
        for (const auto& str : arr) {
            res += str;
        }

        return res;
    }
};

int main() {
    Solution a;
    cout << a.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}
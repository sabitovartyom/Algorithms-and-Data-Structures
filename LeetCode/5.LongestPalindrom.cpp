#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int res_len = 1;    // Длина самого длинного палиндрома
        int center = 0;     // Центр палиндрома
        bool pair = false;  // Флаг четного палиндрома
        int length = s.size();

        for (int i = 0; i < length; ++i) {
            int cur_len = 1;
            int max_radius = min(i, length - 1 - i);
            
            for (int j = 1; j <= max_radius; ++j) {
                if (s[i-j] == s[i+j]) {
                    cur_len += 2;
                } else {
                    break;
                }
            }
            
            if (cur_len > res_len) {
                center = i;
                res_len = cur_len;
                pair = false;
            }
        }

        for (int i = 0; i < length - 1; ++i) {
            if (s[i] != s[i+1]) continue;
            
            int cur_len = 2;
            int max_radius = min(i, length - 2 - i);
            
            for (int j = 1; j <= max_radius; ++j) {
                if (s[i-j] == s[i+1+j]) {
                    cur_len += 2;
                } else {
                    break;
                }
            }
            
            if (cur_len > res_len) {
                center = i;
                res_len = cur_len;
                pair = true;
            }
        }

        if (pair) {
            return s.substr(center - res_len/2 + 1, res_len);
        } else {
            return s.substr(center - res_len/2, res_len);
        }
    }
};

int main() {
    Solution a;
    cout << a.longestPalindrome("abaab");  // Выведет "baab"
    return 0;
}
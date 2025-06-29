#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;
        unordered_map<char, int> lastSeen;
        for(int right = 0; right < s.size(); ++right){
            char curToken = s[right];

            if (lastSeen.find(curToken) != lastSeen.end() && lastSeen[curToken] >= left){
                left = lastSeen[curToken] + 1;
            }
            res = max(res, right - left + 1);

            lastSeen[curToken] = right;
        }
        return res;
    }
};

int main() {
    Solution a;
    cout << a.lengthOfLongestSubstring("a") << endl;  // Должно быть 1
    cout << a.lengthOfLongestSubstring("abcabcbb") << endl;  // Ожидается 3 ("abc")
    cout << a.lengthOfLongestSubstring("bbbbb") << endl;  // Ожидается 1 ("b")
    cout << a.lengthOfLongestSubstring("pwwkew") << endl;  // Ожидается 3 ("wke")
    return 0;
}
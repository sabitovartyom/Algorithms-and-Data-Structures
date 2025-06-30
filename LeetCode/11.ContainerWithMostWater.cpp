#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        int curRes = 0;
        while (left < right){
            curRes = (right - left) * min(height[left], height[right]);
            res = max(curRes, res);
            if (height[left] < height[right]) { ++left; }
            else { --right; }
        }
        return res;
    }
};

int main(){
    Solution a;
    vector<int> ms = {1,8,6,2,5,4,8,3,7};
    cout << a.maxArea(ms) << endl;
}
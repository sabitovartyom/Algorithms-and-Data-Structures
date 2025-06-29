class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> valueToIndex;
        for(int i = 0; i < nums.size(); ++i){
            int p = target - nums[i];
            if (valueToIndex.count(p) == 1) {return {valueToIndex[p], i};}
            valueToIndex[nums[i]] = i;
        }
        return {};
    }
};

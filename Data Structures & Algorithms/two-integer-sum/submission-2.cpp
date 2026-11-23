class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for(int i=0;i<nums.size();i++){
            auto iter=map.find(target-nums[i]);
            if(iter!=map.end())
                return std::vector<int>{iter->second, i};
            else
                map.insert({nums[i], i});
        }

        return std::vector<int>{0,0};
    }
};

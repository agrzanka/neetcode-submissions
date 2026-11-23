class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::vector<std::vector<int>>output;

        std::sort(nums.begin(), nums.end()); //O(nlogn)

        for(int i=0;i<nums.size()-1;i++){ //O(n)

            int goal=0-nums[i];
            int left=i+1;
            int right = nums.size()-1;

            while(left<right){
                if(nums[left]+nums[right]==goal){
                    output.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                        left++;
                }
                else if(nums[left]+nums[right]>goal){
                    right--;
                }
                else{
                    left++;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
        }

        return output;
    }
};

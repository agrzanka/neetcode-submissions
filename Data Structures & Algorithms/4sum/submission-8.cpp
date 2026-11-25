class Solution {

    std::vector<std::vector<int>> result;
    std::vector<int> nn;
    
public:
    void KSum(int k, std::vector<int> & nums, int start, long long target){
        if(k>2){
            for(int i=start;i<nums.size();i++){
                if(i>start && nums[i]==nums[i-1])
                    continue;
                nn.push_back(nums[i]);
                KSum(k-1, nums, i+1, target-nums[i]);
                nn.pop_back();
            } 
        }
        else{
            int left=start, right=nums.size()-1;
            while(left<right){
                long long sum = (long long) nums[left] + (long long) nums[right];
                if(sum>target){
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    nn.push_back(nums[left]);
                    nn.push_back(nums[right]);
                    result.push_back(nn);
                    nn.pop_back();
                    nn.pop_back();
                    left++;
                    right--;
                    while (left<right && nums[left]==nums[left-1])
                        left++;
                    while (left<right && nums[right]==nums[right+1])
                        right--;
                }
            }
            return;
        }
    }   
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        KSum(4, nums, 0, (long long)target);
        return result;
    }
};

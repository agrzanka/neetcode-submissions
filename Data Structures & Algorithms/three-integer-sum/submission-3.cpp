class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::vector<std::vector<int>>output;

        std::sort(nums.begin(), nums.end()); //O(nlogn)

        for(int i=0;i<nums.size()-1;i++){ //O(n)
            if(nums[i]>0)   
                break;      //because we are looking for sum=0. If, after sorting ascending, first element is bigger than 0 - we know that no three numbers can possibly sum up to 0';
            int goal=0-nums[i];
            int left=i+1;
            int right = nums.size()-1;

            while(left<right){          //going through by using left and rifght 'pointer', so this loop is O(n)
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
}; //alltogrther: O(n^2) time and O(1) auxiliary space

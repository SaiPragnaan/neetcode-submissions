class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;

        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                auto itr=lower_bound(temp.begin(), temp.end(), nums[i]);
                *itr=nums[i];
            }
        }

        return len;
    }
};

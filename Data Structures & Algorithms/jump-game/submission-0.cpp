class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        if(nums.size()==2) return nums[0]!=0;

        vector<int> maxi(nums.size());
        maxi[0]=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            maxi[i]=max(maxi[i-1]-1, nums[i]);
            if(maxi[i]==0){
                return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int& num:nums){
            s+=num;
        }
        if(s%2==1) return false;
        bitset<10001> dp;
        dp[0]=1;
        for(int& num:nums){
            dp|=dp<<num;
        }
        return dp[s/2];
    }
};
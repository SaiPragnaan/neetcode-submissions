class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int current=0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            current+=gas[i]-cost[i];
            if(current<0){
                current=0;
                idx=i+1;
            }
        }
        if(total<0) return -1;
        return idx;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();

        vector<int> start(n), end(n);

        for(int i = 0; i < n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        // First interval whose end >= newInterval[0]
        int left = lower_bound(
            end.begin(),
            end.end(),
            newInterval[0]
        ) - end.begin();

        // Last interval whose start <= newInterval[1]
        int right = upper_bound(
            start.begin(),
            start.end(),
            newInterval[1]
        ) - start.begin() - 1;


        if(left > right){
            vector<vector<int>> ans;

            for(int i = 0; i < left; i++)
                ans.push_back(intervals[i]);

            ans.push_back(newInterval);

            for(int i = left; i < n; i++)
                ans.push_back(intervals[i]);

            return ans;
        }

        newInterval[0] = min(newInterval[0], intervals[left][0]);
        newInterval[1] = max(newInterval[1], intervals[right][1]);

        vector<vector<int>> ans;

        for(int i = 0; i < left; i++)
            ans.push_back(intervals[i]);

        ans.push_back(newInterval);

        for(int i = right + 1; i < n; i++)
            ans.push_back(intervals[i]);

        return ans;
    }
};
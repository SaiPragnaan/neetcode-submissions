class Solution {
private:
    vector<int> ans;
    bool hasCycle=false;
public:
    void dfs(vector<vector<int>>& adj_list, vector<int>& state, int x){
        state[x]=1;
        for(auto& neighbor:adj_list[x]){
            if(state[neighbor]==1){
                hasCycle=true;
                return;
            }
            if(state[neighbor]==0){
                dfs(adj_list, state, neighbor);
                if(hasCycle) return;
            }
        }
        state[x]=2;
        ans.push_back(x);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> state(numCourses,0);
        for(auto& vec:prerequisites){
            adj_list[vec[0]].push_back(vec[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                dfs(adj_list, state, i);
            }
        }
        if(hasCycle) return {};
        return ans;
    }
};
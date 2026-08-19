class Solution {
public:
    void dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int node){
        visited[node]=true;
        for(int& neighbor : adj_list[node]){
            if(!visited[neighbor]){
                dfs(adj_list, visited, neighbor);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<bool> visited(n, false);
        for(auto& edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj_list, visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};

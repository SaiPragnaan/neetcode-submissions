class Solution {
public:
    bool dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int node, int parent){
        visited[node]=true;
        for(int& neighbor:adj_list[node]){
            if(visited[neighbor]){
                if(neighbor!=parent) return true;
                continue;
            }
            
            bool child=dfs(adj_list, visited, neighbor, node);
            if(child) return true;
        }
        return false;
    }
    bool validTree(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(V);
        vector<bool> visited(V, false);
        for(int i=0;i<edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        bool check=dfs(adj_list, visited, 0, -1);
        if(check) return false;

        for(int i=0;i<V;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};

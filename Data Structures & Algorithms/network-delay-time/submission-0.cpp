class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
        vector<vector<pair<int,int>>> adj_list(V+1);
        vector<int> dist(V+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        
        for(auto& edge : edges){
            adj_list[edge[0]].push_back({edge[1], edge[2]});
            // adj_list[edge[1]].push_back({edge[0], edge[2]});
        }
        
        dist[src]=0;
        min_heap.push({0,src});
        while(!min_heap.empty()){
            auto top=min_heap.top();
            min_heap.pop();
            if(top.first > dist[top.second]){
                continue;
            }
            for(auto& neighbor : adj_list[top.second]){
                int new_dist=top.first + neighbor.second;
                if(dist[neighbor.first] > new_dist){
                    min_heap.push({new_dist, neighbor.first});
                    dist[neighbor.first]=new_dist;
                }
            }
        }
        int min_time=INT_MIN;
        for(int i=1;i<=V;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            min_time=max(min_time, dist[i]);
        }
        return min_time;
    }
};
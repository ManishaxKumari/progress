class Solution {
public:
    bool solve(vector<vector<int>>& graph,vector<int> &color, int node,int fill){
        color[node]=fill;
        for(auto it : graph[node]){
            if(color[it]==-1){
                if(solve(graph,color,it,!fill)==false) return false;
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(); // total no. nodes
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(solve(graph,color,i,0)==false) return false;
            }
        }
        return true;
    }
};
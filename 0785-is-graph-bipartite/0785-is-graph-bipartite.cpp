class Solution {
public:
    bool solve(vector<vector<int>> &graph,vector<int> &col,int node,int fill){
        col[node]=fill;
        for(auto it : graph[node]){
            if(col[it]==-1){
                if(solve(graph,col,it,!fill)==false) return false;
            }
            else if(col[it]==col[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(solve(graph,col,i,0)==false) return false;
            }
        }
        return true;
    }
};
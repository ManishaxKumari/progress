class Solution {
    //if given graph is acyclic - true
    //if graph is cyclic- false
    //kahn algorithm for check this
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto it : prerequisites ){
            int a=it[0];
            int b=it[1];
            adj[b].push_back(a); //b->a
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return cnt==numCourses;
    }
};
class disJointSet{
public:
    vector<int>rank,parent,size;
    //construtor
    disJointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    //find ultimate parent
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    // belongs to same or not func
    bool belong(int u,int v){
        return findParent(u)==findParent(v);
    }
    // union by rank
    void unionbyrank(int u,int v){
        int parentofU=findParent(u);
        int parentofV=findParent(v);
        if(parentofU==parentofV) return ;
        if(rank[parentofV]>rank[parentofU]){
            parent[parentofU]=parentofV;
        }
        else if(rank[parentofV]<rank[parentofU]){
            parent[parentofV]=parentofU;
        }
        else{
            parent[parentofV]=parentofU;
            rank[parentofU]++;
        }
        return;
    }
    //union by size
    void unionbysize(int u , int v){
        int parentofU=findParent(u);
        int parentofV=findParent(v);
        if(parentofU==parentofV) return ;
         if(size[parentofV]>size[parentofU]){
            parent[parentofU]=parentofV;
            size[parentofV]+=size[parentofU];
        }
        else{
            parent[parentofV]=parentofU;
           size[parentofU]+=size[parentofV];
        }
        return;
    }
}; //mistake

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disJointSet ds(n); //mistake
        unordered_map<string,int> mailmap;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailmap.find(mail)==mailmap.end()){
                    mailmap[mail]=i;
                }
                else{
                  ds.unionbysize(i,mailmap[mail]); 
                }
            }
        }

        vector<string> mergedmail[n];
        for(auto it : mailmap ){
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergedmail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmail[i].size()==0) continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedmail[i] ){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
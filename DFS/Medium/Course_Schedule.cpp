class Solution {
private:
    int time=0;
    bool res=true;
    //Starting time, Ending Time and parent is just for complete algo and not used here!
    vector<int> s,f,parent,color;
    void dfs_sub(vector<vector<int>>& adj,int src){
        //Marking it gray, and start time as time + 1;
        color[src]=1;
        s[src] = time + 1;
        for(int i=0;i<adj[src].size();i++){
            if(color[adj[src][i]] == 0){
                parent[adj[src][i]] = src;
                dfs_sub(adj,adj[src][i]);
            }
            //Else if we find a gray vertex again we have a cycle
            else if(color[adj[src][i]]==1)
                res = false;
        }
        //marking it black and setting finishing time
        color[src] = 2;
        f[src] = time + 1;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //We will first add adjacency list of the directed edge!
        vector<vector<int>> adj(numCourses,vector<int>(0,0));
        for(pair<int,int > p:prerequisites)
            adj[p.first].push_back(p.second);
        
        //We need to find if there is a cycle or not
        //We will do it by DFS as there could be disconnected nodes
        
        s.resize(numCourses); f.resize(numCourses); parent.resize(numCourses); color.resize(numCourses);
        
        for(int i=0;i<numCourses;i++){
            if(color[i]==0){
                dfs_sub(adj,i);
            }
            if(res==false)
                break;
        }
        return res;
    }
};
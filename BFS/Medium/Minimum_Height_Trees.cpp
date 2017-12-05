//It is a rooted tree so could only have 1 or 2 roots. Think!
//Basically this question is finding a root of the tree!!
//We could delete the end nodes until we reach the roots/roots

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //Firstly we construct an adj. list
        vector<unordered_set<int>> adj(n);
        for(pair<int,int > e:edges){
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        
        //Corner case
        vector<int> current;
        if(n==1){
            current.push_back(0);
            return current;
        }
        
        //Adding the 1st layer of end nodes
        for(int i=0;i<n;i++){
            //If only 1 neighbour push it to current
            if(adj[i].size()==1)
                current.push_back(i);
        }
        
        while(1){
            //This will keep the size of the present ennd node list
            vector<int> next;
            for(int node: current){
                //Going through adj list of end node
                for(int neigh: adj[node]){
                    //Removing that node from its neighbour
                    adj[neigh].erase(node);
                    if(adj[neigh].size()==1)
                        next.push_back(neigh);
                }
            }
            //Made by just adjusting the code for special cases!
            if(next.empty())
                return current;
            current = next;
        }
        
    }
};
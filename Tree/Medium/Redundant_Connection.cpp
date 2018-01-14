//We could have done it by simple dfs and seen for the vertices which are gray i.e. that forms cycle
//But as the input is given in edge format we tend to use Union-Find
//And also we have an advantage that while doing union if we find false as our result we output that edge

class Solution {
private:
    vector<int> uf,nn;
    int find(int a){
        while(a!=uf[a]){
            uf[a] = uf[uf[a]];
            a = uf[a];
        }
        return a;
    }
    bool do_union(int a,int b){
        int a_par = find(a), b_par = find(b);
        if(a_par == b_par)
            return false;
        if(nn[a_par]>nn[b_par]){
            uf[b_par] = a_par;
            nn[a_par] += nn[b_par];
            return true;
        }
        else{
            uf[a_par] = b_par;
            nn[b_par] += nn[a_par];
            return true;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> res(2,0);
        
        uf.resize(n+1);
        nn.resize(n+1);
        //Initializing for union-find algo
        for(int i=0;i<=n;i++){
            uf[i] = i;
            nn[i] = 1;
        }
        
        //Now doing the edge traversal and checking the edge whhich causes union to return false
        for(int i=0;i<edges.size();i++){
            //If union is successful
            if( do_union( edges[i][0], edges[i][1]) ){
                //do nothing
            }
            else{
                res[0] = edges[i][0];
                res[1] = edges[i][1];
                return res;
            }
        }
    }
};
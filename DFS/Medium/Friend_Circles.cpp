//As we are asked to find the number of sdisjoint set of friends,we use simple Union-Find!

class Solution {
private:
    int uf[201],nn[201];     //here 'nn' keeps the number of nodes below that node
    //This finds the parent of 'a' with path compression
    int find(int a){
        while(uf[a]!=a){
            uf[a] = uf[uf[a]];
            a = uf[a];
        }
        return a;
    }
    void do_union(int a,int b){
        int par_a = find(a),par_b = find(b);
        if(par_a == par_b)
            return;
        else if(nn[par_a]>nn[par_b]){
            uf[par_b] = par_a;
            nn[par_a] += nn[par_b];
        }
        else{
            uf[par_a] = par_b;
            nn[par_b] += nn[par_a];
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        
        for(int i=0;i<n;i++){
            uf[i] = i;
            nn[i] = 1;
        }
        //Now we will traverse the matrix and assign disjoint groups using union-find
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(M[i][j]==1){
                    do_union(i,j);
                }
            }
        }
        
        //Answer would be number of leaders in the uf array!
        int res=0;
        for(int i=0;i<n;i++){
            if(uf[i]==i)
                res++;
        }
        return res;
    }
};
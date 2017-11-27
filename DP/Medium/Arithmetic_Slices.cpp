class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(),count=0;
        //First index is the start of array!
        //Second index saves the size of the array!
        int dp[n+1],temp[n+1];
        for(int i=0;i<=n-3;i++){
            if(A[i+1]-A[i] == A[i+2]-A[i+1]){
                dp[i]=1;
                count++;
            }
            else
                dp[i]=0;
        }
        for(int size=4;size<=n;size++){
            if(size%2==0){
            for(int i=0;i<=n-size;i++){
                if(A[i+size-1]-A[i+size-2]==A[i+size-2]-A[i+size-3] && dp[i]){
                    temp[i] = 1;
                    count++;
                }
                else
                    temp[i]=0;
            }
            }
            else{
            for(int i=0;i<=n-size;i++){
                if(A[i+size-1]-A[i+size-2]==A[i+size-2]-A[i+size-3] && temp[i]){
                    dp[i] = 1;
                    count++;
                }
                else
                    dp[i]=0;
            }
            }
        }
        return count;
    }
};
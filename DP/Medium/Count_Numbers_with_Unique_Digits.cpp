class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res=0;
        for(int i=n;i>0;i--){
            int temp=9,p=1,j=i-1;
            while(j--){
                p = p*temp;
                temp--;
            }
            res += 9*p;
        }
        return res+1;
    }
};
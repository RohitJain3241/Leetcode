class Solution {
public:
    int minSteps(int n) {
        if(n==1)
            return 0;
        //This is for finding the max. divisor
        int maxd=1;
        for(int i=n/2;i>0;i--){
            if(n%i==0){
                maxd = i;
                break;
            }
        }
        //n/maxd is added for the last pasting
        return n/maxd + minSteps(maxd);
    }
};
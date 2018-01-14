class Solution {
private:
    bool solve(vector<double>& n){
        if(n.size()==1) return abs(n[0]-24) < 1e-6;
        //We will change 2 numbers by 4 operators and see further
        //This is for choosing the 1st digit
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size();j++){
                if(i==j) continue;
                vector<double> temp = n;
                double a = n[i],b = n[j];
                temp.erase( find(temp.begin(),temp.end(),a) ); temp.erase( find(temp.begin(),temp.end(),b) );
                //Seeing for the 4 operators now
                temp.push_back(a+b);
                if(solve(temp)) return true;
                temp.pop_back();
                temp.push_back(a*b);
                if(solve(temp)) return true;
                temp.pop_back();
                temp.push_back(a-b);
                if(solve(temp)) return true;
                temp.pop_back();
                if(b!=0){
                    temp.push_back(a/b);
                    if(solve(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> n;
        for(int i=0;i<nums.size();i++) n.push_back(nums[i]);
        return solve(n);
    }
};
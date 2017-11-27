class NumArray {
private: int sm[100000];
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        sm[0] = 0;
        for(int i=1;i<n+1;i++){
            sm[i] = sm[i-1] + nums[i-1];
        }
        
    }
    
    int sumRange(int i, int j) {
        return sm[j+1] - sm[i];
    }
};
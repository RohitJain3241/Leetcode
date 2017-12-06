//Not good question
//Uses simple hashing technique

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //This gives us O(1) lookup
        unordered_set<int> hash(nums.begin(),nums.end());
        //We will traverse through the hash and update the 'longest'
        int longest=0;
        for(int i:hash){
            //See if previous element is present in hash or not
            //If previous element is present we don't need to run this loop
            if( hash.find(i-1) == hash.end() ){
                //initial size of the longest is 0
                int curr = 0;
                int curr_ele = i;
                //This loop counts the size of the longest consecutive sequence starting from 'i'
                while( hash.find(curr_ele) != hash.end() ){
                    curr++; curr_ele++;
                }
                longest = max( longest,curr );
            }
        }
        return longest;
    }
};
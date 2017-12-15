class Solution{
    //1st is that word ,second string is its parent
    unordered_map<string,string> stringset;
    //This returns the parent string for that element
    string finder(string a){
        if(stringset[a]==a)
            return a;
        return finder(stringset[a]);
    }
    bool do_union(string a,string b){
        string par1 = finder(a),par2 = finder(b);
        if(par1==par2)
            return true;
        stringset[par1] = par2;
        return false;
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n = words1.size(),m = pairs.size();
        //This handles the case of different length sentences
        if(words1.size()!=words2.size())
            return false;
        //Now we need to make union-find set for all the words in the pairs vector
        
        //This is for inserting all the unique values of the strings 
        //and making a hash table with its own parent at first
        for(int i=0;i<n;i++){
            stringset[words1[i]] = words1[i];
            stringset[words2[i]] = words2[i];
        }
        
        //this is for inserting all elements of pairs into hash table with thier own values as parents
        for(int i=0;i<m;i++){
            stringset[pairs[i].first] = pairs[i].first;
            stringset[pairs[i].second] = pairs[i].second;
        }
        
        //Now we make unions for the pairs vector
        for(int i=0;i<m;i++)
            //We do union of all pairs
            bool temp = do_union(pairs[i].first , pairs[i].second);
        
        for(int i=0;i<n;i++){
            if(!do_union( words1[i] , words2[i] ))
                return false;
        }
        return true;
    }
};
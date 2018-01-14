class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        //We have to search the kth smallest element in a grid of m*n
        //We could do it by binary search only if we are able to find the rank of each element
        //We could do that by observing that rank = sum( min( no/1, n ) + min( no/2, n ) + ......uptil no/m )
        long long left = 1,right = m*n;
        while(left<right){
            long long mid = left + (right-left)/2,cnt=0;
            for(int i=1;i<=m;i++)
                cnt += min( mid/i,(long long )n );
            //If the rank is greater than mid's rank
            if(k>cnt) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

//Priority_queue solution gave TLE after 59/69 Test Cases

// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//         int kx=0;
//         //We will make a priority_queue for keeping the values
//         //priority_queue<int, std::vector<int>, std::greater<int> > q2;
//         priority_queue<pair<int, pair<int,int >>,vector<pair<int, pair<int,int >> >, greater<pair<int, pair<int,int >> > > pq;
//         //This is to check the presence
//         unordered_set<int> uset;
//         pq.push( make_pair( 1*1 , make_pair(1,1) ) );  uset.emplace(n*0+0);
//         while(!pq.empty()){
//             auto temp = pq.top(); pq.pop(); kx++;
//             if(kx>=k) return temp.first;
//             //Seeing the right and down and adding them if in range and not added yet
//             int x = temp.second.first,y = temp.second.second;
//             //cout << x << " --- " << y << endl;
//             //We see for right
//             if(y+1<=n && uset.find( n*(x-1)+(y-1+1) ) == uset.end() ){
//                 pq.push(make_pair( x*(y+1) , make_pair(x,y+1) ) );
//                 uset.emplace( n*(x-1)+(y-1+1) );
//             }
//             //This is for down
//             if(x+1<=m && uset.find( n*(x-1+1)+(y-1) ) == uset.end() ){
//                 pq.push(make_pair( (x+1)*y , make_pair(x+1,y) ) );
//                 uset.emplace( n*(x-1+1)+(y-1) );
//             }
//         }
//         return m*n;
//     }
// };
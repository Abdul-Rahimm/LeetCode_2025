class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contained, vector<int>& initial) {
            int n = candies.size();
            int ans = 0;
    
            queue<int> q;
            for(int i: initial)
                q.push(i);
    
            vector<int> keyPresent(n, 0);  // no keys initially
            int count = 0;
    
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                bool openStatus = false;
    
                if(count >= n){
                    // means you are circling round and round. no key
                    break;
                }
    
                // check if you have the key and open the box
                if(keyPresent[curr])
                    status[curr] = 1;
    
                // if status is 1 then add candies
                if(status[curr] == 1){
                    ans += candies[curr];
                    openStatus = true;
                    count = 0;      // reset count
                }
                else{
                // box can not be opened right now
                    q.push(curr);   // re-push, maybe you will discover the key later. 
                    count++;
                }
    
                // mark the keys present
                if(openStatus)
                    for(int key: keys[curr])
                        keyPresent[key] = 1;
    
                // add the newly discovered boxes into the queue
                if(openStatus)
                    for(int box: contained[curr]){
                        q.push(box);
                    }
            }
    
            return ans;
        }
    };
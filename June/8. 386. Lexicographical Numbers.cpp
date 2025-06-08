class Solution {
    public:
        int n;
        void solve(int num, vector<int> &ans){
    
            if(num <= n){
                ans.push_back(num);
            }
            else{
                return;
            }
    
            string str = to_string(num);
            for(int i = 0 ; i <= 9 ; i++){
                string temp = str + to_string(i);
                int newNumber = stoi(temp);
                solve(newNumber, ans);
            }
        }
    
        vector<int> lexicalOrder(int a) {
            n = a;
            vector<int> ans;
    
            for(int i = 1 ; i < 10 ; i++){
                solve(i, ans);
            }
    
            return ans;
        }
    };
class Solution {
    public:
    
        void rec(unordered_map<int,int>& m, vector<int>& temp, vector<vector<int>>& ans, int n){
            if(temp.size()==n){
                ans.push_back(temp);
                return;
            }
    
            for(auto it: m){
                int num = it.first;
                int val = it.second;
    
                if(val==0) continue;
                temp.push_back(num); m[num] -=1;
                rec(m,temp,ans,n);
                temp.pop_back(); m[num]+=1;
            }
            return;
        }
    
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ans;
            unordered_map<int,int> m;
            vector<int> temp;
            int n = nums.size();
            for(auto it : nums) m[it]++;
            rec(m,temp,ans,n);
            return ans;
        }
    };
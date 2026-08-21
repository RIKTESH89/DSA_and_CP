class Solution {
    public:
    
        void rec(int i, int sum, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int target){
            if(sum>target || i==candidates.size()) return;
            if(sum==target){
                ans.push_back(temp); return;
            }
    
            if(sum+candidates[i]<=target){
                temp.push_back(candidates[i]);
                rec(i,sum+candidates[i],temp,ans,candidates, target);
                temp.pop_back();
            }
            rec(i+1,sum,temp,ans,candidates, target);
            return;
    
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> temp;
            rec(0,0,temp,ans,candidates, target);
            return ans;
        }
    };
class Solution {
    public:
    
        void rec(int ind, int sum, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int target){
            if(sum > target) return;
            if(sum == target){
                ans.push_back(temp);
            }
    
            for(int i=ind;i<candidates.size();i++){
                if(i!=ind && candidates[i]==candidates[i-1]) continue;
    
                temp.push_back(candidates[i]);
                rec(i+1,sum+candidates[i],temp,ans,candidates, target);
                temp.pop_back();
            }
            return;
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>> ans;
            vector<int> temp;
            rec(0,0,temp,ans,candidates,target);
            return ans;
        }
    };
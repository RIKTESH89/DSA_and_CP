class Solution {
    public:
    
        void rec(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vis, vector<int>& temp){
            if(temp.size() == nums.size()) {
                ans.push_back(temp);
                return;
            }
    
            for(int i=0;i<nums.size();i++){
                if(vis[i] != -1) continue;
                vis[i]=1;
                temp.push_back(nums[i]);
                rec(nums,ans,vis,temp);
                temp.pop_back();vis[i]=-1;
            }
            return;
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> vis(nums.size()+1,-1);
            vector<vector<int>> ans;
            vector<int> temp;
            rec(nums,ans,vis,temp);
            return ans;
        }
    };
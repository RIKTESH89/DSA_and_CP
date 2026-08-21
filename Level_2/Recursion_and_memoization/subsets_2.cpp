class Solution {
    public:
    
        void rec(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
            // if(ind == nums.size()){
            //     ans.push_back(temp);
            //     return;
            // }
            ans.push_back(temp);
            
            for(int i=ind;i<nums.size();i++){
                if(i!=ind && nums[i]==nums[i-1]) continue;
                temp.push_back(nums[i]);
                rec(i+1,nums,ans,temp);
                temp.pop_back();
            }
            return;
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            rec(0, nums, ans, temp);
            return ans;
        }
    };
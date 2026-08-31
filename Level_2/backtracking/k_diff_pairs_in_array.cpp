class Solution {
    public:
        int ans;
        void rec(vector<int>& nums,int i, int k){
            if(i>=nums.size()-1) return;
    
            for(int j=i+1;j<nums.size();j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                if(nums[j]-nums[i] == k) ans+=1;
            }
            while(i!=nums.size()-2 && nums[i]==nums[i+1]) ++i;
            rec(nums,i+1,k);
            return;
        }
    
        int findPairs(vector<int>& nums, int k) {
            ans = 0;
            sort(nums.begin(),nums.end());
            rec(nums,0,k);
            return ans;
        }
    };
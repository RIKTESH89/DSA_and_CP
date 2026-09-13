class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> ans2;
            vector<int> nums2;
            nums2=nums;
            for(int i=0;i<nums.size()-1;i++){
                nums2.push_back(nums[i]);
            }
            stack<int> s;
            vector<int> ans(nums2.size());
            for(int i=nums2.size()-1;i>=0;i--){
                if(s.empty()) {
                    s.push(nums2[i]);
                    ans[i]=-1;
                }
                else{
                    while(!s.empty() && s.top()<=nums2[i]) s.pop();
                    if(s.empty()) ans[i]=-1;
                    else ans[i]=s.top();
                    s.push(nums2[i]);
                }
    
            }
            for(int i=0;i<nums.size();i++) ans2.push_back(ans[i]);
            return ans2;
        }
    };
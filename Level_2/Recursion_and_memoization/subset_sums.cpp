class Solution {
    public:
    
      void rec(int sum, vector<int>& ans,int i, vector<int>& arr){
          if(i==arr.size()) {
           ans.push_back(sum); return;
          }
          
          rec(sum+arr[i],ans, i+1, arr);
          rec(sum,ans,i+1,arr);
          return;
      }
      
      vector<int> subsetSums(vector<int>& arr) {
          // code here
          vector<int> ans;
          rec(0,ans,0,arr);
          return ans;
      }
  };
class Solution {
    public:
    
      string addStrings(string a, string b) {
      int i = a.size() - 1;
      int j = b.size() - 1;
  
      int carry = 0;
      string ans = "";
  
      while (i >= 0 || j >= 0 || carry) {
  
          int sum = carry;
  
          if (i >= 0)
              sum += a[i--] - '0';
  
          if (j >= 0)
              sum += b[j--] - '0';
  
          ans.push_back((sum % 10) + '0');
          carry = sum / 10;
      }
  
      reverse(ans.begin(), ans.end());
  
      return ans;
  }
      
      bool isValid(string str, vector<string>& v1){
          string str1 = addStrings(v1[v1.size()-1], v1[v1.size()-2]);
          if(str==str1) return true;
          else return false;
      }
      
      bool rec(int ind, string& s, vector<string>& v1){
          if(ind == s.length()) return v1.size()>=3;
          if(s[ind]=='0') return false;
          for(int i=ind;i<s.length();i++){
              string str = s.substr(ind,i-ind+1);
              
              if(v1.size()<2){
                  v1.push_back(str);
                  if(rec(i+1,s,v1)) return true;
                  v1.pop_back();
              }
              else if(isValid(str,v1)){
                  v1.push_back(str);
                  if(rec(i+1,s,v1)) return true;
                  v1.pop_back();
              }
          }
          return false;
      }
      
      bool isSumString(string &s) {
          // code here
          if(s.length()<3) return false;
          vector<string> v1;
          return rec(0,s,v1);
      }
  };
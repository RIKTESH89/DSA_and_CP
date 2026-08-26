class Solution {
    public:
    
      
      bool isvalid(int n, int x, int y, vector<vector<int>>& vis){
          if(x<0 || y<0 || x>=n || y>=n || vis[x][y]!=-1) return false;
          return true;
      }
      
      int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
          // Code here
          int ans;
          if(knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;
          
          vector x_p = {1,1,2,2,-1,-1,-2,-2};
          vector y_p = {2,-2,1,-1,2,-2,1,-1};
          vector<vector<int>> vis(n,vector<int>(n,-1));
          
          queue<pair<int,int>> q;
          q.push({knightPos[0]-1,knightPos[1]-1});
          vis[knightPos[0]-1][knightPos[1]-1] = 0;
          
          
          while(!q.empty()){
              pair<int,int> top = q.front();
              q.pop();
              
              for(int i=0;i<8;i++){
                  int x = top.first + x_p[i];
                  int y = top.second + y_p[i];
                  
                  if(isvalid(n,x,y,vis)){
                      if(x==targetPos[0]-1 && y==targetPos[1]-1) {
                          ans = vis[top.first][top.second] + 1;
                          return ans;
                      }
                      q.push({x,y});
                      vis[x][y] = vis[top.first][top.second] + 1;
                  }
              }
          }
          return -1;
      }
  };
class Solution {
    public:
    
      bool isvalid(vector<vector<int>>& graph, vector<int>& vis, int i, int ind){
          for(auto child : graph[ind]){
              if(vis[child] == i) return false;
          }
          return true;
      }
      
      bool rec(int v, vector<vector<int>>& graph, vector<int>& vis, int ind, int m){
          
          if(ind == v) return true;
          
          for(int i=1;i<=m;i++){
              if(isvalid(graph, vis, i, ind)){
                  vis[ind] = i;
                  if(rec(v,graph,vis,ind+1,m)) return true;
                  vis[ind] = -1;
              }
          }
          return false;
      }
      
      bool graphColoring(int v, vector<vector<int>> &edges, int m) {
          // code here
          vector<vector<int>> graph(v);
          for(int i=0;i<edges.size();i++){
              int x = edges[i][0];
              int y = edges[i][1];
              graph[x].push_back(y);
              graph[y].push_back(x);
          }
          vector<int> vis(v+1,-1);
          return rec(v,graph,vis,0,m);
      }
  };
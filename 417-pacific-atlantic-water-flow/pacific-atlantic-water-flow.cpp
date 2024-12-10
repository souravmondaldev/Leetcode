class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> vis_pac(m,vector<bool>(n,false));
        vector<vector<bool>> vis_atl(m,vector<bool>(n,false));
        vector<vector<int>> ans;
        queue<pair<int,int>> q_pac,q_atl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(i==0 || j==0)
                {
                    q_pac.push({i,j});
                }
                if(i==m-1 || j==n-1)
                {
                    q_atl.push({i,j});
                }
            }
                   
        }
        //bfs on pacific q
        while(!q_pac.empty())
        {
            pair<int,int> temp=q_pac.front();
            q_pac.pop();
            int x=temp.first;
            int y=temp.second;
            vis_pac[x][y]=true;
            for(int i=0;i<4;i++)
            {
                int nx=x+row[i];
                int ny=y+col[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis_pac[nx][ny] && heights[nx][ny]>=heights[x][y])
                    q_pac.push({nx,ny});
            }
        }
        
        // bfs on atlantic q
        while(!q_atl.empty())
        {
            pair<int,int> temp=q_atl.front();
            q_atl.pop();
            int x=temp.first;
            int y=temp.second;
            vis_atl[x][y]=true;
            for(int i=0;i<4;i++)
            {
                int nx=x+row[i];
                int ny=y+col[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis_atl[nx][ny] && heights[nx][ny]>=heights[x][y])
                    q_atl.push({nx,ny});
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis_pac[i][j] && vis_atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid,int color) {
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 || j < 0 || i >= n || j >= m)//invalid case
         return 0;
    
    if(grid[i][j] == 0 || grid[i][j] ==  color)//invalid case
         return 0;
    
    grid[i][j] = color;//just assign the value of color to all adjacent 1's of grid and increment the count everytime
    
    int count = 1;
    count += dfs(i + 1, j, grid,color);
    count += dfs(i - 1, j , grid,color);
    count += dfs(i, j + 1, grid,color);
    count += dfs(i, j - 1, grid,color);
    
    return count;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    unordered_map<int,int>mp;

    int color=2;

    for(int i = 0; i < n; i++)
     {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
            {
                int count = dfs(i, j, grid,color);//insert the value of particular area in map with its 1's count
                    mp[color] = count;
                    color++;
                 
            }
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            {
                set<int> st;//here i use set because we want to store connected values of different color counts,checking all the adjacent values
                
                if(i-1>=0 && grid[i-1][j]!=0)
                {
                    st.insert(grid[i-1][j]);
                }
                if(i+1<n && grid[i+1][j]!=0) 
                {
                    st.insert(grid[i+1][j]);
                }
                if(j-1>=0 && grid[i][j-1]!=0) 
                {
                    st.insert(grid[i][j-1]);
                }
                if(j+1<m && grid[i][j+1]!=0) 
                {
                    st.insert(grid[i][j+1]);
                }
                
                int sum = 1;
                for(auto i:st)
                    sum += mp[i];
                
                result = max(result, sum);
                
            }

        }
    }
    if(result==0)
    {
        return n*m;
    }
    else{
        return result;
    }

}

};
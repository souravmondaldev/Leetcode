/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
bool sameValue(vector<vector<int>>& grid, int x1, int y1, int length) {
        for (int i = x1; i < x1 + length; i++) {
            for (int j = y1; j < y1 + length; j++)
                if (grid[i][j] != grid[x1][y1])
                    return false;
        }
        return true;
    }
Node* solve(vector<vector<int>> &grid, int x1, int x2, int len){
    if(sameValue(grid, x1, x2, len)){
        return new Node(grid[x1][x2], true);
    }
    else{
        Node* root = new Node(false, false);

        root->topLeft = solve(grid,x1, x2, len/2);
        root->topRight = solve(grid, x1, x2 + len/2, len/2);
        root->bottomLeft = solve(grid, x1 + len/2, x2, len/2);
        root->bottomRight = solve(grid, x1 + len/2, x2 +len/2, len/2);

        return root;
    }
}
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        // Check if all elements in the current subgrid are the same
        bool allSame = true;
        int value = grid[r][c];  // Initial value to compare
        for (int i = r; i < r + n; ++i) {
            for (int j = c; j < c + n; ++j) {
                if (grid[i][j] != value) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break;
        }

        // If all values are the same, create a leaf node
        if (allSame) {
            return new Node(value, true);
        }

        // Divide the grid into 4 quadrants and recursively construct the tree
        int half = n / 2;
        Node* topLeft = dfs(grid, half, r, c);
        Node* topRight = dfs(grid, half, r, c + half);
        Node* bottomLeft = dfs(grid, half, r + half, c);
        Node* bottomRight = dfs(grid, half, r + half, c + half);

        // Return the parent node with the four quadrants as children
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        // return solve(grid, 0, 0, grid.size());
        return dfs(grid, grid.size(), 0, 0);
    }
};
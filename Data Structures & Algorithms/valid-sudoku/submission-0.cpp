class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a;
        for(auto line : board) for(auto x : line) {
            if(x=='.') continue;
            a = x - '0';
            if(check[a]) 
        }
    }
};

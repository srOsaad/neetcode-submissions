class Solution {

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0, end = matrix.size() * matrix[0].size()-1, mid,
        rsz = matrix[0].size(), x,
        r,c;
        while(begin<=end) {
            mid = (begin+end)>>1;
            x = matrix[mid/rsz][mid%rsz];
            if(target==x) return true;
            else if(target>x) begin = mid+1;
            else if(target<x) end = mid-1;
            else break;
        }
        return false;
    }
};

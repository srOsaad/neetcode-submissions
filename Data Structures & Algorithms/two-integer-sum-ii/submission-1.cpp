class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j, x;
        while(i<numbers.size()-1) {
            x = target - numbers[i];
            j = i+1;
            while(j<numbers.size() && numbers[j]<=x) {
                if(numbers[j]==x) {
                    return {i+1,j+1};
                }
                j+=1;
            }
            i+=1;
        }
        return {0,0};
    }
};

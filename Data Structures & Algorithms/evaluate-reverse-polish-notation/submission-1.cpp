class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int calc;
        bool valNotSet = true;
        for(auto x : tokens) {
            if (x=="+" || x=="-" || x=="*" || x=="/") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(x=="+" ? n1+n2 : x=="-" ? n2-n1 : x=="*" ? n1*n2 : x=="/" ? n2/n1 : -1);
            }
            else {
                nums.push(stoi(x));
            }
        }
        return nums.top();
    }
};

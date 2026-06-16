class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        queue<int> nums;
        int calc;
        bool valNotSet = true;
        for(auto x : tokens) {
            if (x=="+" || x=="-" || x=="*" || x=="/") {
                while(!nums.empty()) {
                    
                    int n = nums.front();
                    //cout<<"staclsize "<<n<<'\n';
                    nums.pop();
                    if(valNotSet) {
                        calc = n;
                        valNotSet = false;
                        continue;
                    }
                    if(x=="+") calc+=n;
                    else if(x=="-") calc-=n;
                    else if(x=="*") calc*=n;
                    else calc/=n;
                }
                //cout<<(calc)<<'\n';
                nums.push(calc);
                valNotSet = true;
            }
            else {
                nums.push(stoi(x));
            }
        }
        return nums.front();
    }
};

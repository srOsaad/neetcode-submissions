class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<int> left_to_calculate;
        left_to_calculate.push(0);

        for(int i = 1; i < temperatures.size(); i++) {
            while(!left_to_calculate.empty() && temperatures[left_to_calculate.top()] < temperatures[i]) 
            {
                answer[left_to_calculate.top()] = (i - left_to_calculate.top());
                left_to_calculate.pop();
            }
            left_to_calculate.push(i);
        }
        return answer;
    }
};
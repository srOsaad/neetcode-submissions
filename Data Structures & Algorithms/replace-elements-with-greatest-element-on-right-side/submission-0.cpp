class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current_element, max_element = -1;
        for(int i = arr.size()-1; i>-1; i--) {
            current_element = arr[i];
            arr[i] = max_element;
            max_element = max(max_element, current_element);
        }
        return arr;
    }
};
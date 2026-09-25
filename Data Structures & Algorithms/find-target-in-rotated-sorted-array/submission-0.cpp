class Solution {
public:
    int search(vector<int>& arr, int target) {
        // finding pivot
        int lo = 0, hi = arr.size()-1, mid = 0, pivot = 0;
        while(pivot < hi) {
            mid = (pivot + hi) >> 1; // dividing by 2
            if(arr[mid] > arr[hi]) pivot = mid + 1;
            else hi = mid;
        }

        if(arr[pivot] <= target && target <= arr[arr.size()-1]) {
            lo = pivot;
            hi = arr.size()-1;
            while(lo<=hi) {
                mid = (lo + hi) >> 1;
                if(arr[mid] == target) return mid;
                if(arr[mid]<target) lo =  mid + 1;
                else hi = mid - 1;
            }
        }
        else if(pivot-1 > -1) {
            lo = 0;
            hi = pivot - 1;
            while(lo<=hi) {
                mid = (lo + hi) >> 1;
                if(arr[mid] == target) return mid;
                if(arr[mid]<target) lo =  mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};

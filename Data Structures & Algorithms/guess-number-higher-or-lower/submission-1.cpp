/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int end) {
        int begin = 1, mid, x;
        if(guess(1)==0) return 1;
        if(guess(end)==0) return end;
        while(begin<=end) {
            mid = (begin+end)>>1;
            x = guess(mid);
            if(x==0) return mid;
            else if(x==1) begin = mid+1;
            else if(x==-1) end = mid-1;
            else return mid;
        }
        return -1;
    }
};
class Solution {
public:

    bool helper(int mid, vector<int> &piles, int h){
        int ans = 0;
        for(auto it : piles){
            ans = ans + ceil(it / (double)mid);
            if(ans > h) return  false;
        }
        return true;        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(mid, piles, h)){
                high = mid-1;
            }
            else{
                low = mid+1;                
            }
        }
        return low;
    }
};
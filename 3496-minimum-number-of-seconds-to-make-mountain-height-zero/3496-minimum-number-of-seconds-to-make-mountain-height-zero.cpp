#define ll long long
class Solution {
public:
    ll minNumberOfSeconds(int mh, vector<int>& workerTimes) {
        ll left = 0, right = 1e18;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (canReduceMountain(mh, workerTimes, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canReduceMountain(int mh, vector<int>& workerTimes, ll time) {
        ll thr = 0;
        for (int wt : workerTimes) {
            ll left = 0, right = mh;
            while (left < right) {
                ll mid = left + (right - left + 1) / 2;
                if (check(wt, mid, time)) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            thr += left;
            if (thr >= mh) {
                return true;
            }
        }
        return thr >= mh;
    }

    bool check(ll workerTime, ll height, ll totalTime) {
        return workerTime * (height * (height + 1)) / 2 <= totalTime;
    }
};

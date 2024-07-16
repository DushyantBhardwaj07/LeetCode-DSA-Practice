#define ll long long
class Solution {
public:
    void sieve(vector<bool> &isPrime){
        int N = isPrime.size();
        isPrime[0] = isPrime[1] = false;
        for(ll i = 2;i < N;i++){
            if(isPrime[i]){
                for(ll j=2*i; j<N; j = j+i){
                    isPrime[j] = false;
                }
            }
        }
    }
    int countPrimes(int n) {
        int ans = 0;
        vector<bool>isPrime(n+1, true);
        sieve(isPrime);
        for(int i=2;i<n;i++){
            if(isPrime[i]) ans++;
        }        
        return ans;
    }


};
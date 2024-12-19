class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prexor;
        int temp = 0;
        int n = arr.size();
        int ans = 0;
        for(auto it : arr){
            temp = temp ^ it;
            prexor.push_back(temp);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    int a = 0, b = 0;
                    if(i > 0){
                        a = prexor[j-1] ^ prexor[i-1];
                    }
                    else{
                        a = prexor[j-1];
                    }

                    b = prexor[k] ^ prexor[j-1];

                    if(a==b) ans++;
                }
            }
        }      
        return ans;  
    }
};
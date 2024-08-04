class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int ans = 0;
        for(int i=0;i<=10;i++){
            HashMap<Integer,Integer> hm = new HashMap<>();
            int play = Integer.MAX_VALUE, c = 0;
            for(int ii=0;ii<pick.length;ii++){
                if(pick[ii][0] == i){
                    play = pick[ii][0];
                    c = pick[ii][1];
                    hm.put(c, hm.getOrDefault(c, 0) + 1);
                }
            }

            for(Integer it : hm.keySet()){
                if(hm.get(it) > play){
                    ans++;
                    break;
                }                
            }
            System.out.println();
        }        
        return ans;           
    }
}
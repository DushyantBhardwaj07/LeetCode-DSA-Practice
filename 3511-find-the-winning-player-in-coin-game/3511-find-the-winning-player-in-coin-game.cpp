class Solution {
public:
    string losingPlayer(int x, int y) {
        // 75x + 10y = 115

        // 1 coin 75
        // 4 coins 10
        bool flag = true;
        while(true){
            if((x<1) || (y <4)){
                if(flag) return "Bob";
                else return "Alice";
            }
            x--;
            y=y-4;
            flag = !flag;
        }
        return "Bob";
    }
};
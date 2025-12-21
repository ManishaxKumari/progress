class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int n=b.size();
        int five=0;
        int ten=0;
        for(int i=0;i<n;i++){
            if(b[i]==5){
                five++;
            }
            else if(b[i]==10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else if(b[i]==20){
                 if(five && ten){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five=five-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;

    }
};
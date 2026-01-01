class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int &i : asteroids ){
            //when asteroids collide?
            while(!st.empty() && i<0 && st.back()>0){
                int sum=i+st.back();
                if(sum<0){
                    st.pop_back();
                }
                else if(sum>0){
                    i=0;
                }
                else{
                    st.pop_back();
                    i=0;
                }
            }
            if(i!=0){
                st.push_back(i);
            }
        }
        return st;
    }
};
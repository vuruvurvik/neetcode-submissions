class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>st;
        for(int i=0;i<ast.size();i++)
        {
            bool destroyed=false;
            while(!st.empty() && st.back()>0 && ast[i]<0)
            {
                
                if((st.back())<abs(ast[i]))
                {
                    st.pop_back();
                    continue;
                }
                else if(st.back()==abs(ast[i]))
                {
                    st.pop_back();
                    destroyed=true;
                    break;
                }
                else
                {
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed)st.push_back(ast[i]);
        }
        return st;
    }
};
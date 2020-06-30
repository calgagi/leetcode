class Solution {
public:
    int scoreOfParentheses(string S) {
        int a=0;
        int result=0;
        for(int i=0;i<S.length()-1;++i)
        {
            if(S[i]=='(')
            {
                if(S[i+1]==')')
                    result+=1<<a;
                a++;
            }
            else
                a--;
        }
        return result;
    }
};

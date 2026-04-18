class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i < s.length(); i++)
        {
            if (st.empty() || s[i] == '{' ||
                s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else
            {   
                char temp = st.top();
                if ((s[i] == '}' && temp == '{') ||
                    (s[i] == ')' && temp == '(') ||
                    (s[i] == ']' && temp == '['))
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        return st.empty();
    }
};

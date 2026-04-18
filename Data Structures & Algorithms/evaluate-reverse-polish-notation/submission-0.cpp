class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for (int i=0; i<tokens.size(); i++)
        {
            if (tokens[i] != "+" &&
                tokens[i] != "-" &&
                tokens[i] != "*" &&
                tokens[i] != "/")
            {
                cout << stoi(tokens[i]) << '\n';
                temp.push(stoi(tokens[i]));
            }
            else
            {
                int b = temp.top();
                temp.pop();
                int a = temp.top();
                temp.pop();

                cout << a << ' ' << tokens[i] << ' ' << b << '\n';
                if (tokens[i] == "+")
                {
                    temp.push(a+b);
                }
                else if (tokens[i] == "-")
                {
                    temp.push(a-b);
                }
                else if (tokens[i] == "*")
                {
                    temp.push(a*b);
                }
                else
                    temp.push(a/b);
            }

        }
        return temp.top();
    }
};

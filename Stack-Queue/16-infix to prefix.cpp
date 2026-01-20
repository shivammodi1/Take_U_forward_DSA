class Solution {
  public:
  
  int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
  }

  string infixToPrefix(string &s) {
        int n = s.length();

        // Step 1: reverse
        reverse(s.begin(), s.end());

        // Step 2: swap brackets
        for(int i = 0; i < n; i++){
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';
        }

        // Step 3: infix to postfix
        stack<char> st;
        string result = "";

        for(char c : s){

            if(isalnum(c)){
                result += c;
            }
            else if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() &&
                     (precedence(st.top()) > precedence(c) ||
                     (precedence(st.top()) == precedence(c) && c == '^')))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        // Step 4: reverse postfix → prefix
        reverse(result.begin(), result.end());
        return result;
    }
};

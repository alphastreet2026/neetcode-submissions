class Solution {
   public:
    bool isValid(string s) {
        stack<char> open;
        // queue<char> close;

        for (char p : s) {
            if (p == '(' || p == '[' || p == '{') {
                open.push(p);
                continue;
            }
            if (open.empty()) {
                return false;
            }
            char op = open.top();
            open.pop();
            if (p == ')' && op != '(') {
                return false;
            }
            else if (p == ']' && op != '[') {
                return false;
            }
            else if (p == '}' && op != '{') {
                return false;
            }
        }
        
        return open.empty();
    }
};

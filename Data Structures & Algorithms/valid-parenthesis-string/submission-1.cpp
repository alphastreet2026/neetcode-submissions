class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> lp;
        stack<int> w;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                lp.push(i);
            } else if (c == '*') {
                w.push(i);
            } else if (c == ')') {
                if (!lp.empty()) {
                    lp.pop();
                } else if (!w.empty()) {
                    w.pop();
                } else {
                    return false;
                }
            }
        }
        cout << "left=" << lp.size() << endl;
        cout << "w=" << w.size() << endl;
        
        while (!lp.empty()){
            int pId = lp.top();
            lp.pop();
            if (w.empty() || w.top() < pId) {
                return false;
            }
            w.pop();
        }

        return true;
    }
};

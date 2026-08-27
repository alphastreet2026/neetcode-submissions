class Solution {
    void calculate(stack<long long>& operands, string op) {
        if (operands.size() < 2) {
            return;
        }
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        // cout << "a=" << a << " b=" << b << endl;
        if (op == "+") {
            operands.push(a + b);
        } else if (op == "-") {
            operands.push(a - b);
        } else if (op == "*") {
            operands.push(a * b);
        } else if (op == "/") {
            operands.push(a / b);
        }
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> operands;

        for (string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                calculate(operands, t);
            } else {
                operands.push(stoi(t));
            }
        }
        return operands.top();
    }
};

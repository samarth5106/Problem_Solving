class Solution {
  public:
    vector<string> findExpr(string &num, int target) {
        // code here
        vector<string> result;
        string expr;
        backtrack(num, target, 0, 0, 0, expr, result);
        return result;

    }
    private:
    void backtrack(const string &num, int target, int pos, long long curVal,
                   long long prev, string expr, vector<string> &result) {
        int n = num.size();

        // 🛑 Base case: agar hum end tak pahunch gaye aur value match karti hai
        if (pos == n) {
            if (curVal == target) {
                result.push_back(expr);
            }
            return;
        }

        // 🌀 Try all possible splits of num starting at pos
        for (int i = pos; i < n; i++) {
            // ⚠ Leading zero check
            if (i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long long val = stoll(part);

            // ✨ First number (no operator before it)
            if (pos == 0) {
                backtrack(num, target, i + 1, val, val, part, result);
            } else {
                // ➕ Addition
                backtrack(num, target, i + 1, curVal + val, val,
                          expr + "+" + part, result);

                // ➖ Subtraction
                backtrack(num, target, i + 1, curVal - val, -val,
                          expr + "-" + part, result);

                // ✖ Multiplication (needs prev handling due to operator precedence)
                backtrack(num, target, i + 1,
                          curVal - prev + prev * val, prev * val,
                          expr + "*" + part, result);
            }
        }
    }

};

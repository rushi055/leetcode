class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        int i = 0;

        long long numo = 0, deno = 1;

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '+') {
                    sign = 1;
                } else {
                    sign = -1;
                }
                i++;
            }
            long long num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;
            i++;
            long long den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numo = numo * den + num * deno;
            deno = deno * den;

            long long gcdd = gcd(abs(numo), deno);
            numo /= gcdd;
            deno /= gcdd;
        }
        return to_string(numo) + '/' + to_string(deno);
    }
};
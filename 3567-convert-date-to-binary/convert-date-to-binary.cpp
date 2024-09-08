class Solution {
public:
    string convert(int num) {
        if (num == 0) return "0"; 
        string a;

        while (num > 0) {
            int k = num % 2;
            a.push_back(k + '0');
            num = num / 2;
        }
        reverse(a.begin(), a.end());
        return a;
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        string yy = convert(year);
        string mm = convert(month);
        string dd = convert(d);

        string ans = yy +"-" + mm +"-"+dd;
        return ans;
    }
};
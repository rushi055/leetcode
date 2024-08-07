class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        return intToString(num).substr(1);  
    }

private:
    vector<string> below_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string intToString(int num) {
        if (num == 0) {
            return "";
        }
        else if (num < 20) {
            return " " + below_20[num];
        }
        else if (num < 100) {
            return " " + tens[num / 10] + intToString(num % 10);
        }
        else if (num < 1000) {
            return " " + below_20[num / 100] + " Hundred" + intToString(num % 100);
        }
        else {
            for (int i = 3; i >= 0; --i) {
                if (num >= pow(1000, i)) {
                    return intToString(num / pow(1000, i)) + " " + thousands[i] + intToString(num % int(pow(1000, i)));
                }
            }
        }
        return "";
    }
};
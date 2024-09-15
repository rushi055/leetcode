class Solution {
public:
    string addBinary(string a, string b) {
    
       int m = a.size();
        int n = b.size();
        string result;
        int carry = 0;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0'; 
            if (j >= 0) sum += b[j--] - '0';
            
            carry = sum / 2;
            result += (sum % 2) + '0';
            
        }

        reverse(result.begin(), result.end()); 
        return result;
    }
};
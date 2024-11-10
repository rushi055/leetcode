class Solution {
public:
    std::string intToBinary64(int n) {
        if (n == 0)
            return std::string(64, '0');
        std::string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        while (binary.size() < 64) {
            binary = "0" + binary;
        }
        return binary;
    }
    std::string intToBinary(int n) {
        std::string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        return binary;
    }
    long long minEnd(int n, int x) {
        std::string a = intToBinary(n - 1);//a=n-1
        std::string k = intToBinary64(x);   

        int j = a.length() - 1;
        int i = k.length() - 1;
        while (i >= 0 && j >= 0) {
            if (k[i] != '1') {
                k[i] = a[j];
                j--;
            }
            i--;
        }
        return strtoull(k.c_str(), nullptr, 2);
    }
};

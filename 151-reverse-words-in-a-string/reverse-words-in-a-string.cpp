// We can also do the questin using streamstring 
// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string token = "";

//         string result = "";
//         //By default stringstream tokenizes on ' ' (space character)
//         while(ss >> token) {
//             result = token + " " + result;
//         }

//         return result.substr(0, result.length()-1);
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        int l = 0, r = 0;
        int n = s.length();

        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l = r;
            }

            i++;
        }

        s = s.substr(0, r - 1);

        return s;
    }
};

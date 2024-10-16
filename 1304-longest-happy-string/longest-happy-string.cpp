class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, string>> pq;
        string s = "";
        if (a != 0) {
            pq.push({a, "a"});
        }
        if (b != 0) {
            pq.push({b, "b"});
        }
        if (c != 0) {
            pq.push({c, "c"});
        }
        if(pq.size()==1)
        {
            pair<int, string> x1 = pq.top();
            if (x1.first >= 2) {
                s += x1.second + x1.second;
                x1.first -= 2;
            } else {
                s += x1.second;
                x1.first -= 1;
            }
            return s;
        }
        while (!pq.empty()) {

            // cout<<x1.first<<x1.second<<" "<<x2.first<<x2.second<<endl;
            pair<int, string> x1 = pq.top();
            pq.pop();
            pair<int, string> x2 = pq.top();
            pq.pop();

            cout << x1.first << x1.second << " " << x2.first << x2.second
                 << endl;

            if(s.length()>0)
            {
                if (s.back() == x1.second[0]) {
                    s += x2.second;
                    x2.first -= 1;

                    if (x1.first >= 2) {
                        s += x1.second + x1.second;
                        x1.first -= 2;
                    } else {
                        s += x1.second;
                        x1.first -= 1;
                    }
                }else {
                    if (x1.first >= 2) {
                        s += x1.second + x1.second;
                        x1.first -= 2;
                    } else {
                        s += x1.second;
                        x1.first -= 1;
                    }
                    s += x2.second;
                    x2.first -= 1;
                }
            } else {
                if (x1.first >= 2) {
                    s += x1.second + x1.second;
                    x1.first -= 2;
                } else {
                    s += x1.second;
                    x1.first -= 1;
                }
                s += x2.second;
                x2.first -= 1;
            }

            // if (x2.first >= 2) {
            //     s += x2.second + x2.second;
            //     x2.first -= 2;
            // } else {

            // }

            if (x1.first != 0) {
                pq.push(x1);
            }
            if (x2.first != 0) {
                pq.push(x2);
            }

            if (pq.size() == 1) {
                pair<int, string> x3 = pq.top();
                pq.pop();
                if (x3.first >= 2) {
                    s += x3.second + x3.second;
                    x3.first -= 2;
                } else {
                    s += x3.second;
                    x3.first -= 1;
                }
                break;
            }
        }
        return s;
    }
};
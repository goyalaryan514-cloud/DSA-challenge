
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int ans = 0;
        int i = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                st.push('(');
                i++;
            }
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        ans++;
                    }
                    i += 2;
                }
                else {
                    ans++;

                    if (!st.empty()) {
                        st.pop();
                    } else {
                        ans++;
                    }
                    i++;
                }
            }
        }
        ans += 2 * static_cast<int>(st.size());
        return ans;
    }
};
class Solution {
public:

    vector<int> nextSmallele(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallele(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int largestRectangle(vector<int>& heights, int n) {

        vector<int> next = nextSmallele(heights, n);
        vector<int> prev = prevSmallele(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {

            if (next[i] == -1) {
                next[i] = n;
            }

            int l = heights[i];
            int b = next[i] - prev[i] - 1;

            area = max(area, l*b);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);

        int area = 0;

        for (int i = 0; i < n; i++) {

            // Build histogram for current row
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }

            // Find largest rectangle in current histogram
            area = max(area, largestRectangle(heights, m));
        }

        return area;
    }
};
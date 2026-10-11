class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowsize = n-k;
        int total = 0;
        for(int i=0;i<n;i++){
            total+=cardPoints[i];
        }
        int windowsum = 0;
        for(int i=0;i<windowsize;i++){
            windowsum+=cardPoints[i];
        }
        int mini = windowsum;
        for(int i=windowsize;i<n;i++){
            windowsum+=cardPoints[i];
            windowsum-=cardPoints[i-windowsize];
            mini = min(mini,windowsum);
        }
        return total-mini;
    }
};
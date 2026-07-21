class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=c-1;
        while(s<r && e>=0){
            int element = matrix[s][e];
            if(element==target){
                return true;
            }
            if(element>target){
                e--;
            }
            if(element<target){
                s++;
            }
        }
        return false;
        
    }
};
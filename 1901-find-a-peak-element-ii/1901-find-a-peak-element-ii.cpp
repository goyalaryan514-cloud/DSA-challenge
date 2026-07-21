class Solution {
public:
    int maxelement(vector<vector<int>> mat,int col){
        int n=mat.size();
        int val=INT_MIN;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>val){
                val=mat[i][col];
                index=i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
                int n=mat.size();
        int m=mat[0].size();
        int s=0;
        int e=m-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int row = maxelement(mat,mid);
            int left = mid-1>=0 ? mat[row][mid-1]:INT_MIN;
            int right = mid+1<m ? mat[row][mid+1]:INT_MIN;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return {-1,-1};

        
    }
};
class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int bouquet=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt==k){
                    bouquet++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL*m*k;
        if(total>bloomDay.size())return -1;
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int s=mini;
        int e=maxi;
        int result=-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(possible(bloomDay,mid,m,k)){
                result=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
        
    }
};
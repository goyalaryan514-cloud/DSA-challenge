class Solution {
public:
    int DayNeed(vector<int> weights,int limit){
        int day = 1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            int w= weights[i];
            if(load+w > limit){
                day++;
                load=w;
            }
            else{
                load+=w;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);
        while(s<e){
            int mid = s+(e-s)/2;
            int need = DayNeed(weights,mid);
            if(need<=days){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
        
    }
};
class Solution {
public:
    bool isSearchTarget(vector<vector<int>>& ma,int target,int mid){
        int n=ma[0].size();
        int s=0,e=n-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(ma[mid][m]==target){
                return true;
            }
            else if(ma[mid][m]<target){
                s=m+1;;
            }
            else{
                e=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& ma, int target) {
        int m=ma.size(), n=ma[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target>= ma[mid][0] && target <=ma[mid][n-1]){
                return isSearchTarget(ma,target,mid);
            }
            else if(target>= ma[mid][n-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l=0;
        int h=arr.size()-1;
        sort(arr.begin(),arr.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return false;
    }
};
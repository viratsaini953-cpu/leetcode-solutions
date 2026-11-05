class Solution {
public:
    int countElements(vector<int>& nums) {
        int c=0;
        int ma=INT_MIN;
        int mi=nums[0];
        for(int x: nums){
            ma=max(ma,x);
            mi=min(mi,x);
        }
        for(int x: nums){
            if(x>mi && x<ma){
                c++;
            }
        }
        return c;
    }
};
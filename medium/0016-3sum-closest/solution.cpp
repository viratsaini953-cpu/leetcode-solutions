class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int d=INT_MAX;
        int c=INT_MIN;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<target){
                    c=max(c,sum);
                    j++;
                }
                else if(sum>target)
                {
                    d=min(d,sum);
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        if(d==INT_MAX){
            return c;
        }
        if(c==INT_MIN){
            return d;
        }
        int s = abs(d - target);
        int v = abs(c - target);
        if(s<v){
            return d;
        }
        return c;
    }
};
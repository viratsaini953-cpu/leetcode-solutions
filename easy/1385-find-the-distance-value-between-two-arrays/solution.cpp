class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c=0;
        for(int i=0;i<arr1.size();i++){
            int f=1;
            for(int j=0;j<arr2.size();j++){
                int x=abs(arr1[i]-arr2[j]);
                if(x<=d){
                    f=0;
                    break;
                }
            }
            if(f==1){
                c++;
            }
        }
        return c;
    }
};
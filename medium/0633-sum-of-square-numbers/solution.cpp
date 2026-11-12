class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        long long j=sqrt(c);
        long long sum=0;
        while(i<=j){
            sum=(i*i)+(j*j);
            if(sum==c){
                return true;
            }
            else if(sum>c){
                
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
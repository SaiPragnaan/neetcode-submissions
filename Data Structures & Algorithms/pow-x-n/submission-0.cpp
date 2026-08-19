class Solution {
public:
    double myPow(double x, int n) {
        double y=x;
        double res=1.0;
        bool neg=false;
        bool lefti=false;
        if(n<0){
            if(n==INT_MIN){
                lefti=true;
                neg=true;
                n+=1;
                n*=-1;
            }
            else{
                neg=true;
                n*=-1;
            }
        }
        while(n>0){
            if(n&1){
                res=res*x;
            }
            x=x*x;
            n>>=1;
        }
        if(lefti) res/=y;
        if(neg) return (double)1/res;
        return res;
    }
};
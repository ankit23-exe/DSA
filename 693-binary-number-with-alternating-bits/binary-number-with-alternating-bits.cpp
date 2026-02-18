class Solution {
public:
    bool hasAlternatingBits(int n) {
        int previous =n%2;
        n/=2;
        while(n){
            int digi = n%2;
            if(digi == previous) return  false;
            n/=2;
            previous = digi;
        }
        return true;
    }
};
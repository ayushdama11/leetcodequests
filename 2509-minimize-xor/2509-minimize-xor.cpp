class Solution {
public:
    int setBits(int n) {
        return __builtin_popcount(n);
    }
    int minimizeXor(int num1, int num2) {
        int sb1 = setBits(num1);
        int sb2 = setBits(num2);
        if(sb1 == sb2) return num1;
        else if(sb1<sb2) {
            int i = num1;
            while(setBits(i) != sb2) {
                i++;
            }
            return i;
        } else {    // sb1 > sb2 
            int i = num1;
            while(setBits(i) != sb2) {
                i--;
            }
            return i;
        }
    }
};
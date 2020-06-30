class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)  
        {  

            int carry =  a & b;  //All 1s in carry will represent positions 
                                 //where addition will result in to carry

            a = a ^ b;  //sum of a and b without considering carry

            b = (unsigned int)carry << 1;  //typecasting to handle negative number 
                                           //<< 1will shift the carry bits to       
                                           //the position where these bits are to be added.
        }  
        return a;  
    }
};

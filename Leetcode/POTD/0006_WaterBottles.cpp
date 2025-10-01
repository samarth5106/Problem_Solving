class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int sum = 0;
        
        while(numBottles > 0) {
            sum += numBottles;
            empty += numBottles;
            
            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }
        
        return sum;
    }
};

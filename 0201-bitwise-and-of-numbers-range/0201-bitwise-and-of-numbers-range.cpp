class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return (left < right) ? 2 * rangeBitwiseAnd(left/2,right/2) : left;
    }
};
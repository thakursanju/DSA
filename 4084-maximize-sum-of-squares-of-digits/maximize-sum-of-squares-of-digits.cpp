class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
if (sum > 9 * num) {
            return "";
        }
        int count9 = sum / 9;
        int rem = sum % 9;
        string result = "";
        result.append(count9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        int zeros = num - count9 - (rem > 0 ? 1 : 0);
        result.append(zeros, '0');
        
        return result;
    }
};
    
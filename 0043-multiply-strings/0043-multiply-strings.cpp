class Solution {
public:
    string multiply(string num1, string num2) {
        
        // If either number is 0
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        // Maximum product length is n + m
        vector<int> result(n + m, 0);

        // Multiply digit by digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int product = digit1 * digit2;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        // Convert result array to string
        string ans;

        int i = 0;

        // Skip leading zeros
        while (i < result.size() && result[i] == 0)
            i++;

        while (i < result.size()) {
            ans += char(result[i] + '0');
            i++;
        }

        return ans;
    }
};
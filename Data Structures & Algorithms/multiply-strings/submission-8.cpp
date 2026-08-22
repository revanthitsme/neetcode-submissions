class Solution {
public:
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";

    int n = num1.size();
    int m = num2.size();

    // Result can have at most n + m digits
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int position = i + j + 1;
            int product = digit1 * digit2 + result[position];

            result[position] = product % 10;
            result[position - 1] += product / 10;
        }
    }

    string answer;
    int start = 0;

    // Remove leading zeros
    while (start < n + m && result[start] == 0)
        ++start;

    for (int i = start; i < n + m; ++i)
        answer += char('0' + result[i]);

    return answer.empty() ? "0" : answer;
}
};

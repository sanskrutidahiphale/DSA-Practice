class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> frequency(26, 0);

        for (char ch : s)
            frequency[ch - 'a']++;

        string left = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {

            if (frequency[i] % 2 == 1)
                middle = char(i + 'a');

            left += string(frequency[i] / 2, char(i + 'a'));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};

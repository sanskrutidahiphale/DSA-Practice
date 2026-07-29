class Solution {
public:
    const long long LIMIT = 1000001;

    long long countWays(vector<int> &cnt) {

        int total = 0;
        for (int x : cnt)
            total += x;

        long long ways = 1;
        int rem = total;

        for (int i = 0; i < 26; i++) {

            if (cnt[i] == 0)
                continue;

            int r = cnt[i];

            long long choose = 1;

            for (int j = 1; j <= r; j++) {
                choose = choose * (rem - r + j) / j;

                if (choose > LIMIT) {
                    choose = LIMIT;
                    break;
                }
            }

            ways *= choose;

            if (ways > LIMIT)
                ways = LIMIT;

            rem -= r;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        vector<int> half(26, 0);
        string middle = "";

        for (int i = 0; i < 26; i++) {

            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                middle += char(i + 'a');
        }

        if (countWays(half) < k)
            return "";

        string left = "";

        int length = 0;
        for (int x : half)
            length += x;

        while (left.size() < length) {

            for (int i = 0; i < 26; i++) {

                if (half[i] == 0)
                    continue;

                half[i]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left += char(i + 'a');
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};

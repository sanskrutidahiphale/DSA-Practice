class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> one(MAXX, false);
        vector<bool> two(MAXX, false);
        vector<bool> three(MAXX, false);

        for (int x : nums) {

            for (int i = 0; i < MAXX; i++) {
                if (two[i])
                    three[i ^ x] = true;
            }
            for (int i = 0; i < MAXX; i++) {
                if (one[i])
                    two[i ^ x] = true;
            }
            one[x] = true;
        }
        for (int x : nums)
            three[x] = true;

        int ans = 0;
        for (bool b : three)
            if (b) ans++;

        return ans;
    }
};

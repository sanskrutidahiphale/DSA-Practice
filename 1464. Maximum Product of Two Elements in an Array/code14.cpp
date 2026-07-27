class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = 0;
        int arraysize = nums.size();
        for(int i = 0; i<arraysize;i++){
            for(int j =i+1;j<arraysize;++j){
                result = max(result,(nums[i] - 1) * (nums[j] - 1));
            }
        }
        return result;
    }
};

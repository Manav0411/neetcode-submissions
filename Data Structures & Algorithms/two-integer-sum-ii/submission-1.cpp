class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            int ntarget = target - numbers[i];
            for(int j = i+1; j < n; j++){
                if(numbers[j] == ntarget) return {i+1,j+1};
            }
        }
        return {};
    }
};

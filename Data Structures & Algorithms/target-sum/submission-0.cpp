class Solution {
public:
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<int> prev(k+1,0), curr(k+1,0);

	for(int i = 0; i < n; i++) prev[0] = 1;

	if (arr[0] == 0) prev[0] = 2;
	else if(arr[0] <= k) prev[arr[0]] = 1;

	for(int i = 1; i < n; i++){
		for(int target = 0; target <= k; target++){
			int ntake = prev[target];
			int take = 0;
			if(arr[i] <= target) take = prev[target-arr[i]];

			curr[target] = take+ntake;
		} 
		prev = curr;
	}
	return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    if(total-d < 0 || (total-d)%2!=0) return false;
    return findWays(arr, int (total-d)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};
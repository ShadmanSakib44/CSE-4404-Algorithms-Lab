class Solution {
public:
    int dp[1<<16];
    int allmask;
    int part_sum;
    vector<int> vec;
    bool isOn(int N,int pos) {
        return (bool)(N & (1<<pos));
    }
    int turnOn(int N,int pos) {
        return (N | (1<<pos));
    }
    int Sum(int mask) {
        int cnt = 0;
        for(int i=0;i<16;i++) {
            if(isOn(mask,i)) cnt += vec[i];
        }
        return cnt;
    }
    int call(int mask) {
        if(mask==allmask) return 1;
        if(dp[mask]!=-1) return dp[mask];
        int ret = 0;
        int setCnt = Sum(mask)/part_sum;
        for(int i=0;i<vec.size();i++) {
            if(isOn(mask,i)) continue;
            if(Sum(turnOn(mask,i)) <= (setCnt+1)*part_sum)
                ret = ret or call(turnOn(mask,i));
        }
        return dp[mask] = ret;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++) cnt += nums[i];
        if(cnt % k) return false;
        part_sum = cnt / k;
        vec = nums;
        allmask = (1<<nums.size()) - 1;
        memset(dp,-1,sizeof(dp));
        if(call(0)) return true;
        return false;
    }
};

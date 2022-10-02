class Solution {
public:
    int lastPos;
    bool solve(int pos, int k, map<int, bool> &stone, map<pair<int, int>, bool> &dp)
    {
        if(pos == lastPos)
            return true;
        if(k <= 0 || pos > lastPos)
            return false;
        if (dp.find({pos, k}) != dp.end())
         return dp[{pos, k}];
        if (stone[pos] == 1)
         return dp[{pos, k}] = solve(pos + k, k, stone, dp) || 
                               solve(pos + k - 1, k - 1, stone, dp) ||
                               solve(pos + k + 1, k + 1, stone, dp);
      return dp[{pos, k}] = false;
    }
    
    bool canCross(vector<int>& stones) {
        map<int, bool> st;
        lastPos = stones.back();
        map<pair<int, int>, bool> dp;
        for(int stone : stones)
            st[stone] = 1;
        if(st[1])
            return solve(1, 1, st, dp);
        return false;
    }
};

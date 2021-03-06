#include "base.h"
class Solution {
 public:
  vector<int> twoSum(const vector<int> &nums, int target) {
    unordered_map<int, int> num_idx_mp;
    for (int i = 0; i < nums.size(); ++i) {
      int res = target - nums[i];
      if (num_idx_mp.count(res) > 0) {
        return vector<int>({num_idx_mp[res], i});
      }
      num_idx_mp[nums[i]] = i;
    }
    return vector<int>();
  }
};

TEST(S, Demo) {
  Solution s;
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 4), vector<int>({0, 2}));
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 9), vector<int>());
  EXPECT_EQ(s.twoSum(vector<int>({1, 2, 3, 4}), 5), vector<int>({1, 2}));
}

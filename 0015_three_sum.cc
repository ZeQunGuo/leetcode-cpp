#include "base.h"
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    unordered_map<int, int> num_cnt_mp;
    for (int i = 0; i < nums.size(); ++i) {
      if (!num_cnt_mp.count(nums[i])) {
        num_cnt_mp[nums[i]] = 0;
      }
      num_cnt_mp[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;

        int a = nums[i];
        int b = nums[j];
        int res = -a - b;
        if (res < b) break;
        if (res < a) goto EXIT;

        if (num_cnt_mp.count(res) == 0) {
          continue;
        }

        if (a == b && a == res && num_cnt_mp[res] < 3) {
          continue;
        }

        if (a != b && (a == res || b == res) && num_cnt_mp[res] < 2) {
          continue;
        }

        vector<int> tmp_triplet = {a, b, res};
        ret.push_back(move(tmp_triplet));
      }
    }

  EXIT:
    return ret;
  }
};

TEST(S, Demo1) {
  Solution s;
  vector<int> p = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = s.threeSum(p);
  EXPECT_EQ(set<vector<int>>(result.begin(), result.end()), set<vector<int>>({
                                                                {-1, 0, 1},
                                                                {-1, -1, 2},
                                                            }));
}

TEST(S, Demo2) {
  Solution s;
  vector<int> p = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  vector<vector<int>> result = s.threeSum(p);
  EXPECT_EQ(set<vector<int>>(result.begin(), result.end()),
            set<vector<int>>({{-4, -2, 6},
                              {-4, 0, 4},
                              {-4, 1, 3},
                              {-4, 2, 2},
                              {-2, -2, 4},
                              {-2, 0, 2}}));
}

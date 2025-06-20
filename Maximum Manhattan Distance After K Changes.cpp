class Solution {
public:
  int maxDistance(string s, int k) {
    int ans = 0;
    // Try each target quadrant: NE, NW, SE, SW
    vector<pair<char,char>> dirs = {{'N','E'}, {'N','W'}, {'S','E'}, {'S','W'}};

    for (auto [d1, d2] : dirs) {
      int pos = 0;    // current net "forward" steps
      int opp = 0;    // how many moves went against the desired direction
      for (char c : s) {
        if (c == d1 || c == d2) {
          pos++;
        } else {
          pos--;
          opp++;
        }
        // At any step, we can flip up to k negative moves to positive:
        int best = pos + 2 * min(opp, k);
        ans = max(ans, best);
      }
    }
    return ans;
  }
};

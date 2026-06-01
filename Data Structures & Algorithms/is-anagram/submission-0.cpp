class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);

        for (char c : s) {
            chars[c - 97] += 1;
        }

        for (char c : t) {
            if (chars[c - 97] == 0) return false;
            --chars[c - 97];
        }

        for (int i : chars) {
            if (i > 0) return false;
        }

        return true;

    }
};

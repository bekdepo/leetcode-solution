#include <string>
using namespace std;

namespace longest_substring_no_repeat
{
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int hist[256];
			for (auto i = 0; i<256; i++)
				hist[i] = -1;
			int longest = 0;
			int oldest = -1;

			if (s.size() == 0)
				return 0;

			for (auto i = 0; i<s.size(); i++)
			{
				if (hist[s[i]] != -1)
					oldest = hist[s[i]] > oldest ? hist[s[i]] : oldest;

				auto dis = i - oldest;
				longest = longest > dis ? longest : dis;

				hist[s[i]] = i;
			}

			return longest;
		}
	};
}
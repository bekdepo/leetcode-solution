#include <string>
using namespace std;

namespace longest_palindrome
{
	class Solution {
	public:
		string longestPalindrome(string s) {

			if (s.size() == 1)
				return s;

			if (s.size() == 2)
				if (s[0] == s[1])
					return s;

			int finded[3] = { 0, 0, 0 };

			for (auto i = 0; i<s.size(); i++)
			{
				auto scan = i <= (s.size() - i - 1) ? i : s.size() - i - 1;
				auto j = 1;
				for (; j <= scan; j++)
				{
					if (s[i - j] == s[i + j])
						continue;
					else
						break;
				}
				j--;

				if (finded[1] < 2 * j + 1)
				{
					finded[0] = i;
					finded[1] = 2 * j + 1;
					finded[2] = 0;
				}
			}

			for (auto i = 0; i<s.size(); i++)
			{
				auto scan = i <= (s.size() - i - 2) ? i : s.size() - i - 2;

				//if (s[i] == s[i + 1])
				{
					auto j = 0;
					for (; j <= scan; j++)
					{
						if (s[i - j] == s[i + j + 1])
							continue;
						else
							break;
					}
					j--;
					if (finded[1] < 2 * j + 2)
					{
						finded[0] = i;
						finded[1] = 2 * j + 2;
						finded[2] = 1;
					}
				}



			}

			if (finded[2] == 0)
				return s.substr(finded[0] - finded[1] / 2, finded[1]);
			else
				return s.substr(finded[0] - finded[1] / 2 + 1, finded[1]);
			
		}
	};
}
#include <stdlib.h>
#include <vector>
using namespace std;

namespace regular_expression
{
	class Solution {
	public:
		/*
		*	.* is the key anomaly.
		*/
		bool isMatch(const char *s, const char *p) {
			vector<char> processors;
			auto q = p;
			while (*q != '\0')
			{
				if (*(q + 1) == '*')
				{
					processors.push_back(*q | 0x80);
					q++;
				}
				else
					processors.push_back(*q);
				q++;
			}

			auto c = s;
			auto it = processors.begin();
			for (;
				it != processors.end() && *c != '\0';
				it++, c++)
			{
				if ((*it & 0x80) == 0x80)
				{
					// repeating
					auto pattern = *it & 0x7F;
					if (pattern == '.')
						pattern = *c;
					while (pattern == *c)
						c++;
					c--;
				}
				else if (*it == '.')
				{

				}
				else
				{
					if (*c != *it)
						return false;
				}
			}

			return c == s + strlen(s) && it == processors.end();
		}
	};
}
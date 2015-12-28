#include <stdlib.h>
#include <vector>
#include <tuple>
using namespace std;

namespace regular_expression
{
	class Solution {
	public:
        enum CellType {
            CT_Normal,
            CT_Variadic_Char,
            CT_Variadic_Count,
            CT_Variadic_Both
        };

        string leftPattern(vector<tuple<CellType, char>>::iterator start, vector<tuple<CellType, char>>::iterator end)
        {
            string pattern;
            for (auto it = start; it != end; it++)
            {
                switch (get<0>(*it))
                {
                case CT_Normal:
                    pattern += get<1>(*it);
                    break;
                case CT_Variadic_Char:
                    pattern += ".";
                    break;
                case CT_Variadic_Count:
                    pattern += get<1>(*it);
                    pattern += "*";
                    break;
                case CT_Variadic_Both:
                    pattern += ".*";
                    break;
                }
            }
            return pattern;
        }

        bool isMatch(std::string& s, std::string p) {
            if (p.empty())
                return true;

            vector<tuple<CellType, char>> processors;
            auto q = p.begin();
            while (q != p.end())
            {
                auto r = q;
                r++;

                if ( *q != '.' && r != p.end() && *r == '*')
                {
                    processors.push_back(make_tuple(CT_Variadic_Count, *q)); // BoxB
                    q++;  q++;
                }
                else if (*q == '.' && r != p.end() && *r == '*')
                {
                    processors.push_back(make_tuple(CT_Variadic_Both, *q)); // BoxD
                    q++;  q++;
                }
                else if (*q == '.')
                {
                    processors.push_back(make_tuple(CT_Variadic_Char, *q)); // BoxC
                    q++;
                }
                else
                {
                    processors.push_back(make_tuple(CT_Normal, *q)); // BoxA
                    q++;
                }
            }

            auto c = s.begin();
            auto it = processors.begin();
            for (;
            it != processors.end() && c != s.end();
                it++, c++)
            {
                switch (get<0>(*it))
                {
                case CT_Normal: // BoxA
                {
                    if (*c == get<1>(*it))
                        continue;
                    else
                        return false;
                }
                break;
                case CT_Variadic_Char: // BoxC
                {
                    // let it go.
                }
                break;
                case CT_Variadic_Count: // BoxB
                case CT_Variadic_Both: // BoxD
                {
                    auto itt = it;
                    itt++;
                    string ctt(++c, s.end());
                    return isMatch(ctt, leftPattern(it, processors.end())) ||
                        isMatch(ctt, leftPattern(itt, processors.end()));
                }
                break;
                }
            }

            return c == s.end() && it == processors.end();
        }
	};
}

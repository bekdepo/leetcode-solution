#include <vector>
#include <algorithm>
using namespace std;

namespace two_sum
{
	class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			vector<int> indexes;
			/* Brute-Force, Time exceeded.
			for(auto i=0; i<numbers.size();i++)
			{
				for(auto j=i+1;j<numbers.size();j++)
				{
					if (numbers[i] + numbers[j] == target)
					{
						indexes.push_back(i+1);
						indexes.push_back(j+1);
					}
				}
			}
			*/

			/* Only useful for sorted numbers, Runtime error.
			auto left_it = numbers.begin();
			auto right_it = numbers.begin()+(numbers.size()-1);
			while (left_it < right_it)
			{
				if (*left_it + *right_it == target)
				{
					indexes.push_back(left_it - numbers.begin() + 1);
					indexes.push_back(right_it - numbers.begin() + 1);
					break;
				}
				else if (*left_it + *right_it < target)
				{
					left_it ++;
				}
				else
				{
					right_it --;
				}
			}*/

			/*
			* Thinking...
			* Total n*n/2 matches needed,
			* if ( A + B < target) then (<A + B < target)
			* if ( A + B > target) then (>A + B > target)
			* if ( A > target) then (A + B > target)
			*/
			vector<int> copy_numbers(numbers.begin(), numbers.end());
			std::sort(copy_numbers.begin(), copy_numbers.end());

			auto left_it = copy_numbers.begin();
			auto right_it = copy_numbers.begin() + (copy_numbers.size() - 1);
			while (left_it < right_it)
			{
				if (*left_it + *right_it == target)
				{
					if (*left_it == *right_it)
					{
						auto real_left_it = std::find(numbers.begin(), numbers.end(), *left_it);
						indexes.push_back(real_left_it - numbers.begin() + 1);
						indexes.push_back(std::find(real_left_it + 1, numbers.end(), *right_it) - numbers.begin() + 1);
					}
					else
					{
						indexes.push_back(std::find(numbers.begin(), numbers.end(), *left_it) - numbers.begin() + 1);
						indexes.push_back(std::find(numbers.begin(), numbers.end(), *right_it) - numbers.begin() + 1);
					}
					break;
				}
				else if (*left_it + *right_it < target)
				{
					left_it++;
				}
				else
				{
					right_it--;
				}
			}

			if (indexes.size() == 2 && indexes[0] > indexes[1])
			{
				auto temp = indexes[0];
				indexes[0] = indexes[1];
				indexes[1] = temp;
			}

			return indexes;
		}
	};
};
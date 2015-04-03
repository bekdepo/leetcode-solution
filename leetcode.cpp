// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"
#include "includer.h"

void test_1_two_sum()
{
	// 1. Two Sum
	two_sum::Solution solution;

	vector<int> numbers = {1, 3, 5, 7, 9};
	auto indexes = solution.twoSum(numbers, 6);

	assert(indexes.size() == 2);
	assert(indexes[0] == 1);
	assert(indexes[1] == 3);
}

void test_2_add_two_numbers()
{
	// 2. Add Two Numbers
	add_two_numbers::Solution solution;

	auto l1 = new (std::nothrow) add_two_numbers::ListNode(3);
	auto l2 = new (std::nothrow) add_two_numbers::ListNode(5);
	auto l3 = new (std::nothrow) add_two_numbers::ListNode(7);
	auto l4 = new (std::nothrow) add_two_numbers::ListNode(5);
	auto l5 = new (std::nothrow) add_two_numbers::ListNode(9);

	assert(l1 && l2 && l3 && l4 && l5);

	l1->next = l2;
	l3->next = l4;
	l4->next = l5;

	auto l6 = solution.addTwoNumbers(l1, l3);

	assert(l6);
	assert(l6->val == 0);
	assert(l6->next);
	assert(l6->next->val == 1);
	assert(l6->next->next);
	assert(l6->next->next->val == 0);
	assert(l6->next->next->next);
	assert(l6->next->next->next->val == 1);
	assert(l6->next->next->next->next == nullptr);
}

void test_3_longest_substring_no_repeat()
{
	// 3. Longest Substring without Repeating Characters
	longest_substring_no_repeat::Solution solution;
	
	auto len = solution.lengthOfLongestSubstring("ababc");

	assert(len == 3);
}

void test_4_median_of_two_sorted_arrays()
{
	// 4. Median of Two Sorted Arrays
	median_of_two_sorted_arrays::Solution solution;

	int a[1] = { 2 };
	int b[2] = { 1, 3 };
	double median = solution.findMedianSortedArrays(a, 1, b, 2);

	assert(median == 2.0);
}

void test_5_longest_palindrome()
{
	// 5. Longest Palindrome
	longest_palindrome::Solution solution;

	auto str = solution.longestPalindrome("ccc");

	assert(str == "ccc");
}

void test_10_regular_expression()
{
	// 10. Regular Expression
	regular_expression::Solution solution;

	auto bMatched = solution.isMatch("aa", ".*");

	assert(bMatched);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test_1_two_sum();
	test_2_add_two_numbers();
	test_3_longest_substring_no_repeat();
	test_4_median_of_two_sorted_arrays();
	test_5_longest_palindrome();
	test_10_regular_expression();
	return 0;
}


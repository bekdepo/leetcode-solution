namespace add_two_numbers
{
	struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(nullptr) {}
	};
	
	class Solution {
	public:

		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool bPromote)
		{
			if (l1 == nullptr && l2 == nullptr && !bPromote)
				return nullptr;

			ListNode* l3 = new ListNode(bPromote ? 1 : 0);

			if (l1 != nullptr)
				l3->val += l1->val;

			if (l2 != nullptr)
				l3->val += l2->val;

			l3->next = addTwoNumbers(l1 == nullptr ? nullptr : l1->next,
				l2 == nullptr ? nullptr : l2->next,
				l3->val >= 10);

			l3->val %= 10;
		}

		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			return addTwoNumbers(l1, l2, 0);
		}
	};
}
namespace median_of_two_sorted_arrays
{
	class Solution {
	public:

		inline bool odd(int i)
		{
			return i % 2 == 1;
		}

		int findIth(int A[], int m, int B[], int n, int i)
		{
			if (m == 0 && n == 0)
				return 0;

			int half_m = m * i / (m + n) - 1;
			int half_n = n * i / (m + n) - 1;

			if (half_m < 0) half_m = 0;
			if (half_n < 0) half_n = 0;

			if (m == 0)
			{
				if (i <= n)
					return B[i - 1];
				return 0;
			}

			if (n == 0)
			{
				if (i <= m)
					return A[i - 1];
				return 0;
			}

			if (A[half_m] == B[half_n])
			{
				auto remainder = i - half_m - half_n - 2;

				if (remainder == 0) return A[half_m];
				else if (remainder == 1) return A[half_m + 1] <= B[half_n + 1] ? A[half_m + 1] : B[half_n + 1];
				else if (remainder == 2) return A[half_m + 1] > B[half_n + 1] ? A[half_m + 1] : B[half_n + 1];

				return A[half_m];
			}
			else if (A[half_m] < B[half_n])
			{
				if (i == 1)
					return A[half_m];
				return findIth(A + half_m + 1, m - half_m - 1, B, n, i - half_m - 1);
			}
			else
			{
				if (i == 1)
					return B[half_n];
				return findIth(A, m, B + half_n + 1, n - half_n - 1, i - half_n - 1);
			}

		}

		double findMedianSortedArrays(int A[], int m, int B[], int n) {

			if (m == 1 && n == 1)
				return double(A[0] + B[0]) / 2.0;

			if (odd(m + n))
			{
				return (double)(findIth(A, m, B, n, (m + n) / 2 + 1));
			}
			else
			{
				return (double)(findIth(A, m, B, n, (m + n) / 2 + 1) + findIth(A, m, B, n, (m + n) / 2)) / 2.0;
			}
		}
	};
}
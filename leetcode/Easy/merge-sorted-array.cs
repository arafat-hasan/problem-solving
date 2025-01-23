using System;

public class Program
{
    public static void Main()
    {
        int[] nums1 = { 4, 0, 0, 0, 0, 0 };
        int[] nums2 = { 1, 2, 3, 5, 6 };
        int m = 1; int n = 5;
        Solution obj = new Solution();
        obj.Merge(nums1, m, nums2, n);
        foreach (int i in nums1)
        {
            Console.Write(i + " ");
        }
        Console.WriteLine();
    }
}

public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--)
        {
            nums1[j] = nums1[i];
        }

        for (int i = n, j = 0, k = 0; k < m + n; k++)
        {
            if (k < i && i < m + n && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    nums1[k] = nums1[i];
                    i++;
                }
                else
                {
                    nums1[k] = nums2[j];
                    j++;
                }
            }
            else if (k < i && i < m + n)
            {
                nums1[k] = nums1[i];
                i++;
            }
            else if (j < n)
            {
                nums1[k] = nums2[j];
                j++;
            }
        }

    }
}
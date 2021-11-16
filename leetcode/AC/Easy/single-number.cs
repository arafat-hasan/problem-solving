using System;
using System.Collections.Generic;


public class Program
{
    public static void Main()
    {
        Solution obj = new Solution();
        int[] l = new int[] { 4, 1, 2, 1, 2 };
        Console.WriteLine(obj.SingleNumber(l));
    }

}

public class Solution
{
    public int SingleNumber(int[] nums)
    {
        Dictionary<int, int> freq = new Dictionary<int, int>();
        int ans = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (!freq.ContainsKey(nums[i])) freq.Add(nums[i], 1);
            else freq[nums[i]]++;
        }
        foreach (KeyValuePair<int, int> item in freq)
        {
            if (item.Value == 1) ans = item.Key;
        }
        return ans;
    }
}
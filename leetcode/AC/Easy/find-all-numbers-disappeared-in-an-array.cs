using System.Collections.Generic;

using System.Collections.Generic;

public class Solution
{
    public IList<int> FindDisappearedNumbers(int[] nums)
    {
        List<int> res = new List<int>();
        for (int i = 1; i < nums.Length; i++)
        {
            res.Add(i);
        }
        foreach (int number in nums)
        {
            res.Remove(number);
        }
        return res;
    }
};

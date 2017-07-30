public class MedianOfTwoSortedArrays
{
    public static class Solution
    {
        public double findMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int nums1Len = nums1.length;
            int nums2Len = nums2.length;
            if(nums1Len == 0 && nums2Len != 0)
            {
                return findMedianInOneSortedArrays(nums2);
            }
            if(nums1Len != 0 && nums2Len == 0)
            {
                return findMedianInOneSortedArrays(nums1);
            }


            int mid = 0, pre = 0, pro = 0;
            return 0.0;
        }

        public double findMedianInOneSortedArrays(int[] nums)
        {
            if(nums.length % 2 == 0)
            {
                return (double)((nums[nums.length / 2] + nums[nums.length / 2 - 1]) / 2);
            }
            else
            {
                return (double)nums[nums.length / 2];
            }
        }
    }

    public static void main(String[] args)
    {
        Solution medianSolution = new Solution();

        int a[] = {1, 4, 6, 7};
        int b[] = {2, 5, 9};
        medianSolution.findMedianSortedArrays(a, b);

        double medianA = medianSolution.findMedianInOneSortedArrays(a);
        double medianB = medianSolution.findMedianInOneSortedArrays(b);
        System.out.printf("median of array a: %f %n", medianA);
        System.out.printf("median of array b: %f %n", medianB);
    }

}

class dedup
{
    static int removeDuplicates(int A[]) {
        int i = 0;    // 第一个指针
        int j;        // 第二个指针
        int n = A.length;
        if (n <=1 ) return n;        
        // 遍历数组
        for (j = 1; j < n; j++) {
            if (A[j] != A[i]) { // 若两个指针所指元素不同，则i+1位置保存j所指元素的值
                A[++i] = A[j];
            }
        }        
        return i+1;    // 返回新数组的长度
    }

    public static void main(String[] args)
	{
        int a[] = {1, 4, 4, 6, 7, 9, 9, 11};   // need a sorted array
		int dedupLen = removeDuplicates(a);
        System.out.println(dedupLen);
	}
};

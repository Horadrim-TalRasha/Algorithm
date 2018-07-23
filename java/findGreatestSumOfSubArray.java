public static Integer findGreatestSumOfSubArray(int[] arr){
    if(arr == null || arr.length <= 0){
        System.out.println("Invalid Input");
        return 0;
    }
    int curSum = 0; //当前和
    int greatestSum = Integer.MIN_VALUE; //最大和，初始值设为int的最小值，适用于数组全是负数的情况。
    for(int i=0;i<arr.length;i++){
        if(curSum <= 0){
            curSum = arr[i];
        }else{
            curSum += arr[i];
        }
        if(curSum > greatestSum){
            greatestSum = curSum;
        }
    }
    return greatestSum; 
}

class Solution {
/*    public int numberOfSubarrays(int[] nums, int k) {
        int counter = 0;
        int oddCounter = 0;
        //int lastOdd = lastOdd(nums);
        for (int i = 0; i < nums.length; i++ )
        {
            for (int j = i; j < nums.length; j++)
            {
                if (nums[j] % 2 != 0)
                    oddCounter++;
                if (oddCounter == k)
                    counter++;
            }
        oddCounter = 0;
        }
        return counter;
    }*/
    public int numberOfSubarrays(int[] nums, int k) {
        int counter = 0;
        int oddCounter = 0;
        for (int i = 0; i < nums.length; i++ )
        {
            for (int j = i; j < nums.length; j++)
            {
                if (nums[j] % 2 != 0)
                    oddCounter++;
                if (oddCounter == k)
                    counter++;
            }
        oddCounter = 0;
        }
        return counter;
    }
    public int numberOfSubarrays(int[] nums, int k) {
        int [] binaryArray = replaceToBinary(nums);
        int result = prefixSum(binaryArray);
        return result/k; 
    }
    private int[] replaceToBinary(int[] arr)
    {
        int []newArr = new int[arr.length];
        for(int i = 0; i < arr.length; i++){ 
            newArr[i] = arr[i] % 2 == 0 ? 0 : 1;
            System.out.println(newArr[i]);
        }
        return newArr; 
    }
    private int prefixSum(int [] binaryArray){
       int[] prefixSum = new int[binaryArray.length];
       int result = binaryArray[0];
        prefixSum[0] = binaryArray[0];
        for (int i = 1; i < binaryArray.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + binaryArray[i];
            result += prefixSum[i];
        }
        System.out.println(result);
        return result;
    }



    private int lastOdd(int [] nums){
        int index = 0;
        for(int i = 0; i < nums.length; i++) 
            if(nums[i] % 2 != 0)
                index = i;
        return index;
    }
}

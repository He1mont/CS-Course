class MinMax{
	public static void main(String[] args){
		int[] nums = {1, -39, 28, 99};
		int min, max;
		min = max = nums[0];
		
		for(int i=1; i < nums.length; i++){
			if(nums[i] > max) max = nums[i];
			if(nums[i] < min) min = nums[i];
		}
		System.out.println("min and max : " + min + " " +max);
	}
}

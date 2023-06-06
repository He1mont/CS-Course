public class ForEachDemo{
    public static void main(String[] args){
		int[] nums = {1, 11, 22, 3, 4, 66, 77, 2, 100, 212};

		for(int num: nums){
			System.out.print(num + " ");
		}
		System.out.println();

		for(int i = 0; i < nums.length; i++){
			System.out.print(nums[i] + " ");
		}
		System.out.println();
    }
}

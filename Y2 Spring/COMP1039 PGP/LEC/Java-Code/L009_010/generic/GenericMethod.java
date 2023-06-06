public class GenericMethod {

	static <T extends Number, V extends Number> boolean arraysEquals(T[] x, V[] y) {
		if (x.length != y.length)
			return false;
		for (int i = 0; i < x.length; i++) {
			if (!x[i].equals(y[i]))
				return false;
		}
		return true;
	}

	public static void main(String[] args) {
		Integer[] num = { 1, 2, 3, 4, 5 };
		Integer[] num2 = { 1, 2, 3, 4, 5 };
		Integer[] num3 = { 1, 2, 7, 4, 5 };
		Integer[] num4 = { 1, 2, 7, 4, 5, 6 };
		Number[] num5 = { 1, 2, 3, 4, 5 };
		String[] xe = { "1" };

		System.out.println(arraysEquals(num, num2));
		System.out.println(arraysEquals(num, num3));
		System.out.println(arraysEquals(num5, num));
	}
}

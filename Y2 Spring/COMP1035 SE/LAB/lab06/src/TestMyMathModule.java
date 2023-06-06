import static org.junit.jupiter.api.Assertions.*;

import org.junit.Ignore;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

class TestMyMathModule {

	private static int input1;
	private static int input2;
	private static int input3;
	
	@BeforeAll
	static void setup() {
		input1 = 3;
		input2 = 6;
		input3 = 2000000000;
	}
	
	@Ignore
	void test() {
		fail("Not yet implemented");
	}

	@Test
	void myMultiply() {
		int myAnswer = 0;
		try {
			myAnswer = MathModule.myMultiply(input1, input2);
		}
		catch (Exception e) {
			
		}
		assertEquals(18, myAnswer);
	}
	
	void testError() {
		int myAnswer = 0;
		try {
			myAnswer = MathModule.myMultiply(input2, input3);
		}
		catch (Exception e) {
			if (e.getClass() == Exception.class) {
				System.out.println("Exception is thrown!");
				return;
			}
		}
		fail("it failed");
	}
}

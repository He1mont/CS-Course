class Being implements CanJump, CanFly {
	public void jump() {
		System.out.println("Jump!");
	}

	public void fly() {
		System.out.println("Fly!");
	}

	public static void main(String[] args) {
		Being b = new Being();
		b.jump();
		b.fly();

		// CanJump.x = 4;
		System.out.println(CanJump.x);
	}
}

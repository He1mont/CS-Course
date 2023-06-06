class Triangle extends TwoDShape {
	String style = "A";

	double area() {
		return width * height / 2;
	}

	void showStyle() {
		System.out.println("Triangle is " + style);
	}
}

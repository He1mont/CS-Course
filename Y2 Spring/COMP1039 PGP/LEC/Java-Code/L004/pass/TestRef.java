class TestRef{
	public static void main(String[] args){
		Data d1 = new Data(); Data d2 = new Data();
		d1.x = 3;
		d2.x = 4;
		d1.addTo(d2);
		System.out.println("(2)" + d2.x);
	}
}

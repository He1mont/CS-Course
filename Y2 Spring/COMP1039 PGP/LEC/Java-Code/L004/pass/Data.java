class Data{
	int x;
	void addTo(Data d){
	    d.x = d.x + this.x;
	    //d = new Data();
	    //d.x = 10;
	    System.out.println("(1)" + d.x);
	}
}

public class SwitchDemo{

    public static void main(String[] args){

		int season = 0;
		String seasonString;
		switch(season){
			
			// case 1: means if (season == 1)
			
			case 1: seasonString = "Spring";
				break;
			case 2: seasonString = "Summer";
				break;
			case 3: seasonString = "Autumn";
				break;
			case 4: seasonString = "Winter";
				break;
			default: seasonString = "Not a season";
				break;
		}

		System.out.println(seasonString);
    }
}

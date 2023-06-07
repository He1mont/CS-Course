//-------------------------------- example 10 ----------------------------------
#include <stdio.h>

int main(void)
{
	int nColumn = 80;
	int nRow = 25;
	int canvas[nRow][nColumn];
	
	int r = 0;
	int c = 0;
	for(r = 0; r < nRow; r++)
	{
		for(c = 0; c < nColumn; c++)
		{
			canvas[r][c] = ' ';
		}		
	}
	
	canvas[10][13] = ',';
	canvas[10][14] = 'o';
	canvas[10][15] = '8';
	canvas[10][16] = 'o';
	canvas[10][17] = ',';
	canvas[10][19] = ',';
	canvas[10][20] = 'o';
	canvas[10][21] = '8';
	canvas[10][22] = 'o';
	canvas[10][23] = ',';
	
	canvas[11][11] = ',';
	canvas[11][12] = '8';
	canvas[11][13] = '8';
	canvas[11][14] = '8';
	canvas[11][15] = '8';
	canvas[11][16] = '8';
	canvas[11][17] = '8';
	canvas[11][18] = ',';
	canvas[11][19] = '8';
	canvas[11][20] = '8';
	canvas[11][21] = '8';
	canvas[11][22] = '8';
	canvas[11][23] = '8';
	canvas[11][24] = '8';
	canvas[11][25] = ',';
	
	canvas[12][11] = '8';
	canvas[12][12] = '8';
	canvas[12][13] = '8';
	canvas[12][14] = '8';
	canvas[12][15] = '8';
	canvas[12][16] = '8';
	canvas[12][17] = '8';
	canvas[12][18] = '8';
	canvas[12][19] = '8';
	canvas[12][20] = '8';
	canvas[12][21] = '8';
	canvas[12][22] = '8';
	canvas[12][23] = '8';
	canvas[12][24] = '8';
	canvas[12][25] = '8';
	
	canvas[13][11] = '8';
	canvas[13][12] = '8';
	canvas[13][13] = '8';
	canvas[13][14] = '8';
	canvas[13][15] = '8';
	canvas[13][16] = '8';
	canvas[13][17] = '8';
	canvas[13][18] = '8';
	canvas[13][19] = '8';
	canvas[13][20] = '8';
	canvas[13][21] = '8';
	canvas[13][22] = '8';
	canvas[13][23] = '8';
	canvas[13][24] = '8';
	canvas[13][25] = '8';
	
	canvas[14][11] = ',';
	canvas[14][12] = '8';
	canvas[14][13] = '8';
	canvas[14][14] = '8';
	canvas[14][15] = '8';
	canvas[14][16] = '8';
	canvas[14][17] = '8';
	canvas[14][18] = '8';
	canvas[14][19] = '8';
	canvas[14][20] = '8';
	canvas[14][21] = '8';
	canvas[14][22] = '8';
	canvas[14][23] = '8';
	canvas[14][24] = '8';
	canvas[14][25] = ',';
	
	canvas[15][13] = ',';
	canvas[15][14] = '8';
	canvas[15][15] = '8';
	canvas[15][16] = '8';
	canvas[15][17] = '8';
	canvas[15][18] = '8';
	canvas[15][19] = '8';
	canvas[15][20] = '8';
	canvas[15][21] = '8';
	canvas[15][22] = '8';
	canvas[15][23] = ',';
	
	canvas[16][15] = ',';
	canvas[16][16] = '8';
	canvas[16][17] = '8';
	canvas[16][18] = '8';
	canvas[16][19] = '8';
	canvas[16][20] = '8';
	canvas[16][21] = ',';
	
	canvas[17][17] = ',';
	canvas[17][18] = '8';
	canvas[17][19] = ',';
	canvas[17][25] = 'P';
	canvas[17][26] = 'r';
	canvas[17][27] = 'a';
	canvas[17][28] = 'p';
	canvas[17][29] = 'a';



	
	for(r = 0; r < nRow; r++)
	{
		for(c = 0; c < nColumn; c++)
		{
			printf("%c", canvas[r][c]);
		}
		printf("\n");
	}
	
	return 0;
}
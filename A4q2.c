/* 
 * Read in data from Deaths and Births and calculate the cumulative change
 */
#include <stdio.h>
int main(void) {
	FILE *in, *in2;
	int n, count, maleDeaths, maleBirths, femaleBirths, femaleDeaths, changeInMales, changeInFemales;
	changeInMales =0;
	changeInFemales = 0;
	//open our two files
	in = fopen("Deaths2005.txt", "r");
	in2 = fopen("Births2005.txt","r");
	//if the first one is empty something went wrong
	if (in == NULL) {
		fprintf(stderr, "Couldn’t open Deaths2005.txt.\n");
		return 1;
	}
	//if the second one is empty something went wrong
	if (in2 == NULL) {
		fprintf(stderr, "Couldn’t open Births2005.txt.\n");
		return 1;
	}
	/*
	* Keep reading in from the file until we reach the end, we only need to have the
	* last 2 column values so we can "ignore" the first two, to do this we use %*d.
	*/
	while (fscanf(in, "%*d %*d %d %d", &maleDeaths, &femaleDeaths) == 2&&
	fscanf(in2,"%*d %*d %d %d", &maleBirths, &femaleBirths)==2)  {
		//Keep track of the cumulative change from day one to day n.
		changeInMales += maleBirths-maleDeaths;
		changeInFemales += femaleBirths-femaleDeaths;
		//Print out result
		printf("Males : %d, Females: %d\n", changeInMales, changeInFemales);
	}
	//Close both files as we're finished
	fclose(in);
	fclose(in2);
	return 0;
}

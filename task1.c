// Task 1: Linear Regression 

#include <stdio.h> // include all the necessary header files to perform linear regression
#include <stdlib.h>

void main(){
	float x, y; // two variables declared to store the x and y coordinated from the given four datasets.
	float sumX=0, sumX2=0, sumY=0, sumXY=0; // variables initialized to store the value in each iteration to fulfil the formula for linear regression
	float n=0, a, b, x_val, y_val; // n initialized to store the total number of coordinates that is later used in the formula
	char eof, filename[20];//declaring character to store the end of file and another character to store file name
	char choice; // char var to take userinput
	FILE *file;//declaring file pointer
	
	
	for(int i=1; i<=4; i++){ //for loop to read data from file and to calculate summations of X, Y, X^2 and X*Y which is required for calculation in the linear regression equation
		sprintf(filename, "datasetLR%d.txt", i); // sprintf() takes file pointer , const char format and [arguments] as arguments
		file = fopen (filename,"r"); // initially datasetLR1.txt is being opened and once the while loop datasetLR2.txt is opened in read mode and so on till datasetLR4.txt
		while(1){
			eof = fscanf (file, "%f, %f", &x, &y); // scan x and y float values in each line and store in vars x and y
			if (eof == EOF){ // if end of file break loop
				break;
			}		 
			sumX += x; // summation of x
			sumY += y;// summation of y
			sumX2 += (x*x);  // summation of x^2
			sumXY += (x*y);// summation of x*y
			n++; // increment n after each x and y coordinate read	 
		}
		fclose(file); // close the file pointer
	}
	
	//calculating the values of a and b by applying formula
	a = ((sumX2 * sumY) - (sumX * sumXY))/((n * sumX2) - (sumX * sumX)); // formula to calculate gradient
	b = ((n * sumXY) - (sumX * sumY))/((n * sumX2) - (sumX * sumX)); // formula to calculate constant
	
	//printing the values of a and b and the best fit line
	printf("\n--------------\tLinear Regression\t---------------");
	printf("\n\nUsing the Linear Regression formula, \n\tThe values are: a = %f \t and \t b = %f",a,b); // printvalues of a and b 
	printf("\n\nEquation : \n\ty = %0.2f x + %0.2f", b, a); // print the equation of the best fit line
	printf("\n\n-----------------------------------------------------------------------------------");
		
	calculation: //taking user input x to calculate the value of y using the best fit line
	printf("\n\nEnter a value of x: ");
	scanf("%f", &x_val); // user input
	y_val = (b * x_val) + a; // calculate value of y
	printf("\n\n");
	printf("From the above equation, when x = %0.2f,\n\tThe value of y is: %f", x_val, y_val);
	printf("\n\n-------------------------------------------------------------------------------");
	
	ask: //taking user input if the user wants to do any more calculations
	printf("\n\n");
	printf("Do you want to do any more calculations? (y/n): ");
	scanf("%c", &choice); 
	if(choice == 'Y' || choice == 'y'){//conditions according to user choice
		goto calculation; //to calculate the value of y again
	} else if(choice == 'N' || choice == 'n'){ // if n||N then exit
		exit(0);
	} else {
		printf("\nPlease enter either 'y' or 'n'."); //informative message
		goto ask; 
	}
}
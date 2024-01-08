/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void variable_swap(double i, double j);
//switch to double
void math_swap(double i, double j);
//switch to double
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
/* This program accepts two integers as user input and
 * swaps their values using two different methods */
// Compile with gcc lab04-2_3.c -o lab04-2_3
// Run with ./lab04-2_3

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double first = 0, second = 0;
    printf("Please input two integers separated by a space: ");

    scanf("%lf %lf", &first, &second);

    printf("\n");
    variable_swap(first, second);

    printf("\n");
    math_swap(first, second);

    return 0;
}

/**
 * Swaps the values of two integers using a temp variable.
 *
 * @param i - The first value to be swapped.
 * @param j - The second value to be swapped.
 */
void variable_swap(double i, double j)//switch to double
{
    printf("Now doing a swap using an extra variable: \n");
    printf("Before Swap: First: %lf, Second: %lf\n", i, j);

    double temp = i;
	//switch to double
    i = j;
    j = temp;

    printf("After Swap: First: %lf, Second: %lf\n", i, j);//switch to double
}

/**
 * Swaps the values of two integers without using a temp variable.
 *
 * @param i - The first value to be swapped.
 * @param j - The second value to be swapped.
 */
void math_swap(double i, double j)//switch to double
{
    printf("Now doing a swap using addition and subtraction: \n");
    printf("Before Swap: First: %lf, Second: %lf\n", i, j);
//switch to double
    i = i + j;
    j = i - j;
    i = i - j;

    printf("After Swap: First: %lf, Second: %lf\n", i, j);//switch to double
}

/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
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
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %d, using integer math.\n", integer_result);
//need to use %d if you want to see integer result 
    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n",integer_result);
//forgot to call the integer_result in the statement
    decimal_result = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf.\n", decimal_result);
//needs to use %lf to show double result in decimal
    return 0;
}

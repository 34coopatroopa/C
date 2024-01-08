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
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* Put your code after this line */
	int x,y,z;
	printf("Enter a width: ");
	scanf("%d",&x);
	printf("Enter a height: ");
	scanf("%d",&y);
	printf("Enter the legnth: ");
	scanf("%d", &z);
	printf("A %d by %d rectangle's area is %d\n", x,y,x*y*z);
	
	




    return 0;
}

/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:		Cooper Hoy															 -
- 	Section:		5														 -
-	NetID:			cjhoy													     -
-	Date:			9/14/23														 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int minutes(int m);
int seconds(int s);
int milliseconds(int n);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;
	

    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		double sec = t/1000.0;

        /* CODE SECTION 0 */
		
        printf("Echoing output: %08.3lf, %07.3lf, %07.3lf, %07.3lf\n",sec, ax, ay, az);


        /* 	CODE SECTION 1 */
        printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));


        /* 	CODE SECTION 2 */
        
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
        
    }

}

/* Put your functions here */
int minutes(int m)
{
	return m/60000;
}
int seconds (int s)
{
	return (s/1000) - (60 *(minutes(s)));
	
	
}
int milliseconds (int n)
{
	return(n-((minutes(n)*60000)+(seconds(n) * 1000)));
	
	
}
/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}


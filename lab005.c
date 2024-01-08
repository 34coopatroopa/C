/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
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
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
double Ornt(double x, double y, double z);
int Close_To(double tolerance, double point, double value);
double magnitude(double x, double y, double z);
int main(){


    int triangle, circle, x_button, square,bread;
    double ax, ay, az, gx, gy, gz;

    while (triangle != 1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
       //printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
               //ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);

        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

        // printf("The acceleration's current magnitude is: %lf\n", t, magnitude(ax, ay, az));
		if(magnitude(ax,ay,az) > 0.0){
			if( Ornt(gx,gy,gz) == 1){
				//printf("Left\n");
			}else if ( Ornt(gx,gy,gz) == 2){
				//printf("Right\n");
			}else if( Ornt(gx,gy,gz) == 3){
				//printf("Top\n");
			}else if( Ornt(gx,gy,gz) == 4){
				//printf("Bottom\n");
			}else if( Ornt(gx,gy,gz) == 5){
				//printf("Front\n");
			}else if ( Ornt(gx,gy,gz) == 6){
				//printf("Back\n");
			}
		}	
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int Close_To(double tolerance, double point, double value) {
	if ((value <= (point + tolerance)) && (value >= (point - tolerance))) {
		return 1;
	}
	else {
		return 0;
	}
}

double Ornt(double x, double y, double z) {
	if(Close_To(.25, 1, x)&& Close_To(.25,0,y)&& Close_To(.25,0,z))
	{
		printf("Left\n");
		return 1;
	}
	else if(Close_To(.25, -1, x)&& Close_To(.25,0,y)&& Close_To(.25,0,z))
	{
		printf("Right\n");
		return 2;
	}
	else if(Close_To(.25, 0, x)&& Close_To(.25,1,y)&& Close_To(.25,0,z))
	{
		printf("Top\n");
		return 3;
	}
	else if(Close_To(.25, 0, x)&& Close_To(.25,-1,y)&& Close_To(.25,0,z))
	{
		printf("Bottom\n");
		return 4;
	}
	else if(Close_To(.25, 0, x)&& Close_To(.25,0,y)&& Close_To(.25,-1,z))
	{
		printf("Front\n");
		return 5;
	}
	else if(Close_To(.25, 0, x)&& Close_To(.25,0,y)&& Close_To(.25,1,z))
	{
		printf("Back\n");
		return 6; 
	}
	
	return 0;
}

double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
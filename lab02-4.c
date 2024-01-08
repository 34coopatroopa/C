#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(void)
{
    int a = 6427+1725;
	int b = (6971 * 3925) -  95;
	double c = 79 + 12 / 5;
	double d = 3640.0 / 107.9;
	int e = (22 / 3) * 3;
	int f = 22 / (3 * 3);
	double g =  22 / (3 * 3);
	double h =  22 / 3* 3;
	double i = (22.0 / 3) * 3.0;
	int j = 22.0 / (3 * 3.0);
	double k = 22.0 / 3.0 * 3.0;
	double rad = 23.567*(2*M_PI);
	double meters = 0.30 *14;
	double celsius = (76-32)/1.8;

	
	
	printf("a=%d\nb=%d\nc=%.2lf\nd=%.2lf\ne=%d\n%f=d\ng=%.2lf\nh=%.2lf\ni=%.2lf\nj=%d\nk=%.2lf\narea=%.2lf\nmeters=%.2lf\nclesius=%.2lf",a,b,c,d,e,f,g,h,i,j,k,rad,meters,celsius);
    
}

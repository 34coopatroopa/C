/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Cooper Hoy
- 	Section: 14
-	NetID: cjhoy
-	Date:
-
-   
./ds4rd-real.exe -d 054c:09cc -D DS4_BT -j -g -t -b | ./lab07

-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y, int *switchr, int *switchp, int *switchj, int *pitch);

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);
void pit_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);
void pit_pit(int num, char use);

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;
	int switchr;
	int switchp;
	int switchj;
	int pitch;
	/* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */

    do
    {
        /* Scan a line of input */
		
		read_input(&t,&x,&y,&z,&b_Up,&b_Right,&b_Down,&b_Left,&j_LX,&j_LY,&j_RX,&j_RY,&switchr,&switchp,&switchj,&pitch);
        /* Calculate and scale for pitch AND roll AND joystick */

		scaled_roll = scaleMagForScreen(x);
		scaled_pitch = scaleMagForScreen(z);
		scaled_joy = scaleJoyForScreen(j_LX);
        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
		if(switchr == 1){// triangle roll
		
			graph_line(scaled_roll);
			
		}else if(switchp == 1){// x pitch
		
			pit_line(scaled_pitch);
			
		}else if(switchj == 1){// circle joy
		
			graph_line(-scaled_joy);
			
		}

        /* Output your graph line */


        fflush(stdout);

    } while (b_Left !=1 ); /* Modify to stop when left button is pressed */

    return 0;

}
int read_input(int* time,double* g_x, double* g_y, double* g_z,int* button_T, int* button_C, int* button_X, int* button_S,int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y, int *switchr, int *switchp,int *switchj, int *pitch )
{
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d, %d", time, g_x, g_y, g_z, button_T, button_C, button_X, button_S, l_joy_x, l_joy_y, r_joy_x, r_joy_y, pitch);
	//add specific return values for buttons
	if(*button_T == 1){
		*switchr = 1;
		*switchp = 0;
		*switchj = 0; 
	}else if(*button_C == 1){
		*switchj = 1; 
		*switchr = 0;
		*switchp = 0;
	}else if(*button_X == 1){
		*switchp = 1;
		*switchr = 0;
		*switchj = 0;
		*pitch = 1;
	}else if(*button_S == 1){
		return 4;
	}else{
		return 0;
	}
	
}
int scaleMagForScreen(double rad){
	
	if(rad <= -1.0){
		rad = -1.0;
	}else if(rad >= 1.0){
		rad = 1.0;
	}
	
	return rad * 39;
	
}

int scaleJoyForScreen(int rad){
	if(rad <= -128){
		rad = -128;
	}else if(rad >= 127){
		rad = 127;
		
	}
	return rad *(39.0/127); 
}
void graph_line(int number){
	if(number > 0){
		char use = 'L';
		print_chars(number,use);
	}else{
		number *= -1;
		char use = 'R';
		print_chars(number,use);
	}
	
}
void print_chars(int num, char use){
	if(num == 0){
		printf("                 ");
		printf("                        0");
		printf("\n");
	}else if(use == 'R'){
		printf("                                            ");
		for(int i = 0 ; i < num ; i++){
			printf("%c",use);
			
		}
		printf("\n");
	}else{
		for(int i = 0; i<39-num; i++){
			printf(" ");
		}
		for(int i = 0; i<num; i++){
			printf("L");
		}
		printf(" ");
		printf("\n");
		
	}
	
	
}
void pit_pit(int num, char use){
	if(num == 0){
		printf("                 ");
		printf("                        0");
		printf("\n");
	}else if(use == 'B'){
		printf("                                            ");
		for(int i = 0 ; i < num ; i++){
			printf("%c",use);
			
		}
		printf("\n");
	}else{
		for(int i = 0; i<39-num; i++){
			printf(" ");
		}
		for(int i = 0; i<num; i++){
			printf("F");
		}
		printf(" ");
		printf("\n");
		
	}
	
	
}
void pit_line(int number){
	if(number > 0){
		char use = 'F';
		pit_pit(number,use);
	}else{
		number *= -1;
		char use = 'B';
		pit_pit(number,use);
	}
	
}
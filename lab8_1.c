/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10
#define MAXPOINTS 10000

/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{ 
	double gx[MAXPOINTS] , gy[MAXPOINTS], gz[MAXPOINTS];
	double new_gx, new_gy, new_gz;
	double avg_gx, avg_gy, avg_gz;
	int length_average = 0;
	int i;
	int theTime;
	double xPosition = 0, yPosition = 0;
	int tempX = 0, tempY = 0;
	int theTimer;

  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */

    /* Read gyroscope data and fill the buffer before continuing */

    /* Event loop */
    do
    {
		scanf("%d, %lf, %lf, %lf", &theTime, &new_gx, &new_gy, &new_gz);
		avg_gx = m_avg(gx, length_average, new_gx);
		avg_gy = m_avg(gy, length_average, new_gy);
		avg_gz = m_avg(gz, length_average, new_gz);
		
		theTimer = theTime;
        /* Read data, update average */

		while(theTimer + 100 > theTime){
			scanf("%d, %lf, %lf, %lf", &theTime, &new_gx, &new_gy, &new_gz);
		}
		
		draw_character(tempX, tempY, EMPTY_SPACE);
		
		if(avg_gx < 0.5){
			xPosition = xPosition + 0.4;
			yPosition = yPosition + 0.2;
			
			if(xPosition < 0){
				xPosition = 0;
			}
			
		}
		else if(avg_gx > -0.5){
			
			xPosition = xPosition - 0.4;
			yPosition = yPosition + 0.2;
			
			if(xPosition < 0){
				xPosition = 0;
			}
			
		}
		else{
			yPosition = yPosition + 1;
		}
		
		draw_character(xPosition, yPosition, AVATAR);
		tempX = xPosition;
		tempY = yPosition;
		fflush(stdout);
        /* Is it time to move?  if so, then move avatar */

    } while(1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    printf("YOU WIN!\n");
}

double m_avg(double buffer[], int avg_size, double new_item){
	double avg = 0;
	for(int i = 0; i < avg_size; i++){
		buffer[i]= buffer[i+1];
	}
	buffer[avg_size - 1] = new_item;
	avg += buffer[avg_size + 1];
	return new_item;

}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}
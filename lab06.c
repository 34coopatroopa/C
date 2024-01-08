/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    srand(time(NULL)); /* This will ensure a random game each time. */
	int time, triangle, circle, cross, square, q, w, e, r;
	int numCorrect = 0;
	int gameEnder = 0;
	printf("Welcome to bop it type game\n");
	printf("Push Circle button to start\n");
	while(1){
		scanf(" %d , %d, %d, %d, %d, %d, %d, %d, %d" , &time, &triangle, &circle, &cross, &square, &q, &w, &e, &r);
		if (circle == 1){
			
			int timeToDo = 5000;
			while (1){
				scanf(" %d , %d, %d, %d, %d, %d, %d, %d, %d" , &time, &triangle, &circle, &cross, &square, &q, &w, &e, &r);
				if (triangle + square + circle + cross == 0){
					int prevtime = time;
					int maxTime = prevtime + timeToDo;
					int randButton = (rand()%4) + 1;
					if (randButton == 1){
						printf("Press the trangle button\n");
					}else if (randButton == 2){
						printf("Press the circle button\n");
					}else if (randButton == 3){
						printf("Press the square button\n");
					}else{
						printf("Press the cross button\n");
					}
					printf("You have %d miliseconds to answer\n" , timeToDo);
					while(time < maxTime){
						scanf(" %d , %d, %d, %d, %d, %d, %d, %d, %d" , &time, &triangle, &circle, &cross, &square, &q, &w, &e, &r);
						if (randButton == 1){
							if (triangle == 1){
								numCorrect++;
								gameEnder = 1;
								timeToDo -= 100;
								break;
							}else if (square == 1 || circle == 1 || cross == 1){
								printf("You pressed the wrong button :(\n");
								gameEnder = 3;
								break;
							}
						}else if (randButton == 2){
							if (circle == 1){
								numCorrect++;
								gameEnder = 1;
								timeToDo -= 100;
								break;
							}else if (square == 1 || triangle == 1 || cross == 1){
								printf("You pressed the wrong button :(\n");
								gameEnder = 3;
								break;
							}
						}else if (randButton == 3){
							if (square == 1){
								numCorrect++;
								gameEnder = 1;
								timeToDo -= 100;
								break;
							}else if (triangle == 1 || circle == 1 || cross == 1){
								printf("You pressed the wrong button :(\n");
								gameEnder = 3;
								break;
							}
						}else{
							if (cross == 1){
								numCorrect++;
								gameEnder = 1;
								timeToDo -= 100;
								break;
							}else if (square == 1 || circle == 1 || triangle == 1){
								printf("You pressed the wrong button :(\n");
								gameEnder = 3;
								break;
							}
					}
					}
				if (gameEnder == 0){
					printf("You ran out of time :(\n");
					printf("You got %d correct\n" , numCorrect);
					gameEnder = 2;
					break;
				}else if (gameEnder == 3){
					printf("You got %d correct\n" , numCorrect);
					gameEnder = 2;
					break;
				}else{
					gameEnder = 0;
				}
					
			}
		}
	
	if (gameEnder == 2){
		break;
	}
	}
	}
    return 0;
}


/* Put your functions here, and be sure to put prototypes above. */


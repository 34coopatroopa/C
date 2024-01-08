/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	               -
- List the names of all team members, their roles, and their participation
1- Bilal - Role: Assisted in entire creation of code  - Participation: 50%
(Use this line to describe your contribution to the project)
2- Tristan - Role: Assisted in entire creation of code  - Participation: 50%
(Use this line to describe your contribution to the project)
3-
4-
5-																                                     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
/*----------------------------------------------------------------------------
-	                            Functions Prototypes                                   -
-----------------------------------------------------------------------------*/
int quizSelector(int userInt);
double averageScore(int totalPoints, int attempts);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
-								Implementation								                               -
-----------------------------------------------------------------------------*/
int main()
{
    printf("Hello welcome to the quiz taker.\n");
    printf("-----Quiz 1-----\n-----Quiz 2-----\n-----Quiz 3-----\n");
    char yesno = 'y';// the y/n value to move forward
    while (yesno == 'y'){
    int userNum = 0;
    printf("Enter a number between 1 and 9 to determine what quiz you will take: \n");
        while(userNum < 1 || userNum > 9){//while userNum is between 1-9 
    scanf(" %d" , &userNum);
        }
    int quizNum = quizSelector(userNum);// function for randomizer
    if (quizNum == 1){//Quiz 1 Questions 
        int correctAnswers = 0;
        int totalPoints = 0;
        int attempts = 1;
        char tOrF;
        char multipleChoice;
        char shortAnswer[20];
        
        while (correctAnswers < 3){//if quiz quesntions correct are less than 3 then repeat the quiz
            printf("Quiz 1 was selected!\n");
            printf("Question 1: \n A function in c can have multiple return statements. (T/F): \n");
            scanf(" %c" , &tOrF);
            tOrF = tolower(tOrF);//make every answer lower case for ease of calculation
            if (tOrF == 't'){
                printf("That is correct!\n");
                correctAnswers += 1;// keep track of quiz answers 
                totalPoints += 5;//keep track of points
            }else{//wrong answer
                printf("Incorrect!\n");
            }
            
            printf("Question 2: \n Which of the following Data Types is used to store a single character in C. \nA. Int\nB. Char\nC. Float\nD. Double\n");
            scanf(" %c" , &multipleChoice);// scan for the answer
            multipleChoice = tolower(multipleChoice);// convert it to lowercase
            if (multipleChoice == 'b'){// if it is right
                printf("That is correct!\n");// say it is right
                correctAnswers += 1;// increase the correct answer counter
                totalPoints += 5;// increase points
            }else {
                printf("Incorrect!\n");
            }
            
            printf("Question 3: \nFill in the blank:\nA ______ statement outputs text to the console.\n");
            scanf(" %s" , shortAnswer);
            for (int i = 0; i < strlen(shortAnswer); i++){// for i is the amount of charcters in short Answer 
                shortAnswer[i] = tolower(shortAnswer[i]);// set is to lower case 
            }
            if (strcmp(shortAnswer , "printf") == 0){//string compare the answer to printf ( they should be the same)
                printf("That is correct!\n");
                correctAnswers += 1;//correct answers plust 1
                totalPoints += 5;// points plus 5 
            }else {
                printf("Incorrect!\n");
            }
            
            if (correctAnswers < 3){// repeates the quiz
                printf("You did not answer every question on this quiz correct. The quiz will now restart. ");
                correctAnswers = 0;// resets the counter to run the while loop again
                attempts += 1;// adds to attempts to calculate average 
            }else {// prompts for a new quiz and shows average on quiz 1 attempts
                printf("You passed the quiz\n");
                double average = averageScore(totalPoints , attempts);// function to calculate average
                printf("Your average score across all attempts on this quiz  was %.1lf points!\n" , average);
            }
        }
    }else if (quizNum == 2){
        int correctAnswers = 0;
        int totalPoints = 0;
        int attempts = 1;
        char tOrF;
        char multipleChoice;
        char shortAnswer[20];
        
        while (correctAnswers < 3){
            printf("Quiz 2 was selected!\n");
            printf("Question 1: \nThe main function must be declared last (T/F): \n");
            scanf(" %c" , &tOrF);
            tOrF = tolower(tOrF);
            if (tOrF == 't'){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else{
                printf("Incorrect!\n");
            }
            
            printf("Question 2: \nWhich character is used to store inputs when using scan statements: \nA. &\nB. !\nC. =\nD. -\n");
            scanf(" %c" , &multipleChoice);
            multipleChoice = tolower(multipleChoice);
            if (multipleChoice == 'a'){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else {
                printf("Incorrect!\n");
            }
            
            printf("Question 3: \nFill in the blank:\nA ______ requires parameters in order to work.\n");
            scanf(" %s" , shortAnswer);
            for (int i = 0; i < strlen(shortAnswer); i++){
                shortAnswer[i] = tolower(shortAnswer[i]);
            }
            if (strcmp(shortAnswer , "function") == 0){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else {
                printf("Incorrect!\n");
            }
            
            if (correctAnswers < 3){
                printf("You did not answer every question on this quiz correct. The quiz will now restart. ");
                correctAnswers = 0;
                attempts += 1;
            }else {
                printf("You passed the quiz\n");
                double average = averageScore(totalPoints , attempts);
                printf("Your average score across all attempts on this quiz was %.1lf points!\n" , average);
            }
        }
    }else{// resets the counters for the quiz and starts quiz 3
        int correctAnswers = 0;
        int totalPoints = 0;
        int attempts = 1;
        char tOrF;
        char multipleChoice;
        char shortAnswer[20];
        
        while (correctAnswers < 3){
            printf("Quiz 3 was selected!\n");
            printf("Question 1: \nYou make a comment in C by using // (T/F): \n");
            scanf(" %c" , &tOrF);
            tOrF = tolower(tOrF);
            if (tOrF == 't'){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else{
                printf("Incorrect!\n");
            }
            
            printf("Question 2: \nWhat is the 'or' operator: \nA. &\nB. ||\nC. ==\nD. +=\n");
            scanf(" %c" , &multipleChoice);
            multipleChoice = tolower(multipleChoice);
            if (multipleChoice == 'b'){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else {
                printf("Incorrect!\n");
            }
            
            printf("Question 3: \nFill in the blank:\nIn the character string cookie[30] there are a max of: ______ characters allowed in the string.\n");
            scanf(" %s" , shortAnswer);
            for (int i = 0; i < strlen(shortAnswer); i++){
                shortAnswer[i] = tolower(shortAnswer[i]);
            }
            if (strcmp(shortAnswer , "30") == 0){
                printf("That is correct!\n");
                correctAnswers += 1;
                totalPoints += 5;
            }else {
                printf("Incorrect!\n");
            }
            
            if (correctAnswers < 3){
                printf("You did not answer every question on this quiz correct. The quiz will now restart. ");
                correctAnswers = 0;
                attempts += 1;
            }else {
                printf("You passed the quiz\n");
                double average = averageScore(totalPoints , attempts);
                printf("Your average score across all attempts on this quiz was %.1lf points!\n" , average);
            }
        }
    }
        printf("Would you like to take another quiz (y/n)?\n");
        yesno = tolower(yesno);
        scanf(" %c" , &yesno);
        if(yesno != 'y'){
            printf("Bye, Have a Great Day :)");
        }
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */


int quizSelector(int userInt){//Randomizes the quiz
    srand((int)time(0));
    int range1 = (rand() % 9) + 1;
    int range2 = (rand() % 9) + 1;
    while (range1 == range2){
        range1 = (rand() % 9) + 1;
    }
    if (range1 > range2){
        int temp = range1;
        range1 = range2;
        range2 = temp;
    }
    if (userInt <= range1){
        return 1;
    }else if ( userInt > range1 && userInt <= range2){
        return 2;
    }else{
        return 3;
    }
    
    
}
double averageScore(int totalPoints, int attempts){// Averages the Score per quiz 
    return ((double)totalPoints / (double)attempts);
}
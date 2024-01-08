// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>


#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int main(int argc, char* argv[]) {
	
	char* wordlist[MAXWORDS];
	int wordcount;

	int i;
	int row = 0;

	int col = 0; 
	wordcount = read_words(wordlist, argv[1]);
	
	

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++, row++) {
			if(i % 20 == 0 && i != 0){
				col +=20, row = 0;
			}
			mvprintw(row, col, "%15s",wordlist[i]);
			refresh();
		}
		printf("\n");
		
	}

	// most of your code goes here. Do not forget to include the ncurses library 
	mvprintw(row, col, "%c", '<'); 
	
	//create word table 


	return 0;
}






// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}
/*  Robert Kety
    Modified: 06/23/2014
    
    Description: Implement a function that will load a dictionary into a hash map and
                 implement code to prompt users for words.  The words will be tested
                 against the dictionary and the user will be informed if they are 
                 spelled correctly or incorrectly.  */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht);

int main (int argc, const char * argv[]) {
  char* word = (char*)malloc(256*sizeof(char));
  int quit=0, tableSize = 1000;
  clock_t timer;
  struct hashMap* hashTable = createMap(tableSize);
  FILE * dictionary = fopen("dictionary.txt", "r");
  
  /* Load dictionary and output loading time */
  timer = clock();
  loadDictionary(dictionary,hashTable);
  timer = clock() - timer;
	printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
  
  /* Close input file */
  if(fclose(dictionary))
        printf("Error closing file: dictionary.txt\n");

  printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
   printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));

  /* Continue to prompt for words and check the spelling. */
  while(!quit){
    printf("Enter a word: ");
    scanf("%s",word);
    
    if(containsKey(hashTable, word))
        printf("That is spelled correctly!\n");
    else
        printf("Spelling Error!\n");
    
    /* Don't remove this. It is used for grading*/
    if(strcmp(word,"quit")==0)
      quit=!quit;
  }
  free(word);
     
  return 0;
}

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht){
    char* currWord = '\0';
    int wordCount = 0;

    currWord = getWord(file);
    while(currWord != 0){
        wordCount = atMap(ht, currWord);
        insertMap(ht, currWord, (ValueType) (wordCount + 1));
        currWord = getWord(file);
    }
}

void printValue(ValueType v) {
	printf("Value:%d",(int)v);    
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   (character == 39)) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}

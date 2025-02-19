#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "ls2.h"

/**
 * Main function
 * Usage: ls2 <path> [exact-match-pattern]
 */
int main(int argc, char* argv[]) {
	if(argc == 2){//mode 1

		//get the file name and run the build on it
		char* pathName[] = argv[1];
		char* path[] = (char)malloc(10000*sizeof(char)); //i know this is bad form, i have no other idea what to do
		buildPath(pathName, path);
		printf("%s\n", path);

	} else if(argc == 3){//mode 2
		//David said I don't have to do this section

		//stack stores the lines to print out
	/* stack_t *s = initstack();

	push(s, "Hello1");
	push(s, "Hello2");
	push(s, "Hello3");

	// print stackn 
	printstack(s);

	// free up stack
	freestack(s); */
	} else {
		printf("Usage: ls2 <path> [exact-match-pattern]");
	}
	
	return 0;
}

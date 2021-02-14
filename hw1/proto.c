// Che Blankenship
// NetId: cxb200006
// Assignment 01, part 2
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[]);
int main(int argc, char const *argv[]) {
	FILE *fp;                   // FILE object
	char fname[] = "test.c";    // define file name
	int chr;                    // hold the character
	int countChars;             // count the commented characters
	int countComments;          // count the number of comments
	fp = fopen(fname, "r");     // return NULL if it fails.
	if (fp != NULL) {           // success
		printf("%s file open successfully!\n", fname);
		chr = fgetc(fp);         // get initial char of the file
		// Keep reading until its end of file
		// keep track of if reading comments in block or not
		int blockStatement = 1; // true=0, false=1
		while (chr != EOF) {
			// check if it's a '/'
			if (chr == '/') {
				// get next char and check if its a '/' or '*'
				chr = fgetc(fp);
				// Case 1: single line comment
				if (chr == '/') {
					countComments++;
					// loop until '\n'
					chr = fgetc(fp);
					while (chr != '\n') {
						// count the characters
						countChars++;
						chr = fgetc(fp);
					}
				}
				// Case 2: block line comment
				else if(chr == '*') {
					blockStatement = 0;
					countComments++;
					// if it's a block comment, check the closing
					chr = fgetc(fp);
					// count the characters until it hits another '*'
					while (blockStatement != 1) {
						if (chr == '*') {
							chr = fgetc(fp);
							// check if it really closes the block comment
							if(chr == '/') {
								blockStatement = 1; // end of the block
							} else {
								chr = fgetc(fp);
								countChars++;
							}
						}
					}
				}
				// Case 3: not a comment
				else {
					// get new char
					chr = getc(fp);
				}
			} else {
				chr = getc(fp);
			}
		}
	} else {            // fail
		printf("%s file not open!\n", fname);
		return -1;
	}

	// print out the counts
	printf("Comments: %d\n", countComments);
	printf("Commented characters: %d\n", countChars);
	fclose(fp); // close file
	return 0;

}

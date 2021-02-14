#include <stdio.h>


#define LOWF 100
#define UPF  400
#define STEP 20


int main(int argc, char const *argv[]) {
	float fahr, celsius;
       	fahr  = LOWF;
      	printf("- Temperature Converter Table -\n");
        printf("%s\t%s\n", "F", "C");
        printf("-------------------------------\n");
        while (fahr <= UPF) {
       		celsius = 5 * (fahr - 32) / 9;
         	printf("%.2f\t%.2f\n", fahr, celsius);
       		fahr += STEP;
        }
	return 0;
}

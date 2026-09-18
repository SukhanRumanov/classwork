#include <stdio.h> 

int main() {
	printf("Hello\n my \nfriend"); 
	printf("OOOO\n"); 
	/*Hello
		my
		friendOOOO*/


	printf("%d\n", 2);
	// 2
	printf("Privet mne %d let\n", 18);
	// Privet mne 18 let

	printf("Ostatok ot deleniya %d na %d = %d\n", 10, 3, 10 % 3);
	// Ostatok ot deleniya 10 na 3 = 1

	printf("%g delim na %f ravno %f\n", 10.0, 3.0, 10.0 / 3.0);
	// 10 delim na 3.000000 ravno 3.333333

	printf("Privet %.3f\n", 10.0/3.0);
	// Privet 3.333
	
	return 0; 
}


#include <stdio.h>

int main(){
	int ola[3];
	ola[0] = 342;
	printf("%d\n", ola[0]);
	int adeus = 0;
	printf("%d\n", adeus = adeus++ % 3);
	printf("> %d\n", adeus);
	printf("%d\n", adeus = adeus++ % 3);
	printf("> %d\n", adeus);
	printf("%d\n", adeus = adeus++ % 3);
	printf("> %d\n", adeus);
	printf("%d\n", adeus = adeus++ % 3);
	printf("> %d\n", adeus);
	int xau = 10;
	while (xau > 0){
		printf("%d\n", xau);
		xau--;
	}
}
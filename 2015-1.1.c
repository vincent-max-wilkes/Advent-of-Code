#include <stdio.h>

int main()
{
    FILE *ptr;
    char buffer[30000];
    ptr = fopen("./aoc1.1", "r");

    char c;
    int floor;

    while(c != EOF){	
	c = fgetc(ptr);

	if(c == '(')
	    floor++;
	
	else if(c == ')')
	    floor--;
    }
    printf("%d\n", floor);
}

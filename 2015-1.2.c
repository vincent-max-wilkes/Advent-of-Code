#include <stdio.h>

int main()
{
    FILE *ptr;
    char buffer[30000];
    ptr = fopen("./aoc1.1", "r");

    char c;
    int floor;
    int position = 1;

    while(c != EOF){	
	c = fgetc(ptr);

	if(c == '(')
	    floor++;
	
	else if(c == ')')
	    floor--;

	if(floor == -1){
	    printf("The basement was reach after: %d tries\n", position);
	    return 1;
	}
	position++;
    }
}

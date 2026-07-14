#include <stdio.h>
  
int main()
{
    FILE *ptr;
    ptr = fopen("./aoc1.1", "r");
    
    int coordinate[1001][1001] = {0};
    int row = 500;
    int column = 500;
    coordinate[row][column] = 1;
    int y = 0, x = 0, houses = 0;
    char direction;
    
    while(fscanf(ptr, "%c", &direction) != EOF)	{
	if(direction == '^'){
	    y--;
	    coordinate[row+y][column+x] += 1; 
	}
	else if(direction == 'v'){
	    y++;
	    coordinate[row+y][column+x] += 1; 
	}
	else if(direction == '>'){
	    x++;
	    coordinate[row+y][column+x] += 1; 
	}
	else if(direction == '<'){
	    x--;
	    coordinate[row+y][column+x] += 1; 
	}
    }
    for(row = 0; row < 1000; row++){
	for(column = 0; column < 1000; column++){
	    if(coordinate[row][column] != 0)
		houses++;
	}
    }

    printf("Santa visits %d houses\n", houses);
    fclose(ptr);
}

#include <stdio.h>
  
typedef struct{
    int x;
    int y;
} position;

int main(void)
{
    FILE *ptr;
    ptr = fopen("./aoc1.1", "r");

    int coordinate[1001][1001] = {0};
    int row = 500;
    int column = 500;
    coordinate[row][column] = 1;
    int houses = 0, count = 0;
    char direction;
    position *gifter;
    
    position santa = {.x = 0, .y = 0};
    position robot = {.x = 0, .y = 0};

    while(fscanf(ptr, "%c", &direction) != EOF)	{
		if(count % 2 == 0){
		    gifter = &santa;
		}
		else{
		    gifter = &robot;
		}
		    if(direction == '^'){
				gifter->y--;
				coordinate[row+(gifter->y)][column+(gifter->x)] += 1; 
		    }
		    else if(direction == 'v'){
				gifter->y++;
				coordinate[row+(gifter->y)][column+(gifter->x)] += 1; 
		    }
		    else if(direction == '>'){
				gifter->x++;
				coordinate[row+(gifter->y)][column+(gifter->x)] += 1; 
		    }
		    else if(direction == '<'){
				gifter->x--;
				coordinate[row+(gifter->y)][column+(gifter->x)] += 1; 
		    }
	
		count++;
	}

    for(row = 0; row < 1000; row++){
		for(column = 0; column < 1000; column++){
		    if(coordinate[row][column] != 0)
				houses++;
		}
    }

    printf("Santa and his Robot visit %d houses\n", houses);
    fclose(ptr);
}

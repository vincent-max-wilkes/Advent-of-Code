#include <stdio.h>

void my_bubblesort(int a[3])
{
    for(int i = 0; i < 3; i++){
	    for(int j = 0; j < (2 - i); j++){
	      if(a[j] > a[j + 1]){
      		int temp = a[j];
      		a[j] = a[j + 1];
      		a[j + 1] = temp;
	      }
	    }
    }
}

int main()
{
    FILE *ptr;
    ptr = fopen("./aoc1.1", "r");
    
    int side1 = 0, side2 = 0, side3 = 0, valid = 0;

    while(fscanf(ptr, "%d %d %d", &side1, &side2, &side3) != EOF){
    	int sides[3] = {side1, side2, side3};
    	my_bubblesort(sides);

    	if((sides[0] + sides[1]) > sides[2])
    	    valid++;
    }
    printf("There exist %d possible triangles", valid);
}

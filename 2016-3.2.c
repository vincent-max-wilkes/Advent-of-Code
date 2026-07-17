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

    int valid = 0;
    int triangle1[3], triangle2[3], triangle3[3];

    while(fscanf(ptr, "%d %d %d %d %d %d %d %d %d", &triangle1[0], &triangle2[0], &triangle3[0], &triangle1[1], &triangle2[1], &triangle3[1], &triangle1[2], &triangle2[2], &triangle3[2]) != EOF){
    	my_bubblesort(triangle1);
    	my_bubblesort(triangle2);
    	my_bubblesort(triangle3);
    
    	if((triangle1[0] + triangle1[1]) > triangle1[2])
    	    valid++;
    	if((triangle2[0] + triangle2[1]) > triangle2[2])
    	    valid++;
    	if((triangle3[0] + triangle3[1]) > triangle3[2])
    	    valid++;
    }
    printf("There exist %d possible triangles", valid);
}

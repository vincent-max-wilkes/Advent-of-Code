#include <stdio.h>

void my_bubblesort(int a[3])
{
    for(int i = 0; i < 3; i++) // number of times we go trough array
    {
    	for(int j = 0; j < 2; j++) // sorting the array once
    	{
    	    if(a[j] > a[j + 1])
    	    {
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
    
    int paper;
    int length;  
    int width;
    int height;
    char sep; // 'x' seperator
    int ribbon;
    
    while(fscanf(ptr, "%d %c %d %c %d", &length, &sep, &width, &sep, &height) != EOF){
    	int list[3] = {length, width, height};
    
    	my_bubblesort(list);
    	int side = list[0] * list[1];
    	int perimeter = 2 * (list[0] + list[1]);
    	int volume = length * width * height;
    	ribbon += perimeter + volume;
    }

    printf("The elves need %d feet or ribbon", ribbon );
    fclose(ptr);
}

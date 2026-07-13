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
    
    while(fscanf(ptr, "%d %c %d %c %d", &length, &sep, &width, &sep, &height) != EOF){
    	int list[3] = {length, width, height};
    
    	my_bubblesort(list);
    	int side = list[0] * list[1];
    
    	paper += 2 * ((length * width) + (width * height) + (length * height)) + side;
    }

    printf("The elves need %d square feet wrapping paper\n", paper);
    fclose(ptr);
}

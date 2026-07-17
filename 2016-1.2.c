#include <stdio.h>

// north = 1; east = 2; south = 3; west = 4;

int main()
{
  FILE *ptr;
    ptr = fopen("./aoc1.1", "r");
    
  int coordinate[1001][1001] = {0};
    int row = 500, col = 500;
    int face = 1;
    int dist = 0;
    char dir;
    char sep;

    while(fscanf(ptr, "%c %d %c ", &dir, &dist, &sep) != EOF){
    	if(dir == 'R'){
    	    face++;
    	    if(face > 4){
    		    face = 1;
	        }
	    }  
    	else if(dir == 'L'){
    	    face--;
    	    if(face == 0){
    		    face = 4;
    	    }
    	}
    	for(int i = 0; i < dist; i++){
    	    if(face == 1){
    		    row--;
    	    }
    	    else if(face == 2){
    		    col++;
    	    }
    	    else if(face == 3){
    		    row++;
    	    }
    	    else if(face == 4){
    		    col--;
    	    }
    	    if(coordinate[row][col] == 1){
    		    goto solution;
    	    }
    	    else{
    	      coordinate[row][col]++;
    	    }
    	  }
  }
  solution:
  if(row <= 500){
	  row = 500 -row;
  }
  else{
	  row -= 500;
  }
  if(col <= 500){
	  col = 500 -row;
  }
  else{
	  col -= 500;
  }
  printf("The HQ is %d blocks away", (row + col));
}

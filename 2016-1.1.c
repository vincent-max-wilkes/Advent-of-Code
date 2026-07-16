#include <stdio.h>

// north = 1; east = 2; south = 3; west = 4;

int main()
{
    FILE *ptr;
    ptr = fopen("./aocinput", "r");

    int face = 1;
    int dist = 0, disty = 0, distx = 0, row = 0, col = 0;
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
    	if(face == 1){
    	    row -= dist;
    	}
    	else if(face == 2){
    	    col += dist;
    	}
    	else if(face == 3){
    	    row += dist;
    	}
    	else if(face == 4){
    	    col -= dist;
    	}
    }
    if(row < 0){
	    row = -row;
    }
    if(col < 0){
	    col = -col;
    }
    printf("The HQ is %d blocks away", (row + col));
}


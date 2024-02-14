#include <stdio.h>
#include <string.h>

#define SIDE 3
#define ITERS 3

#define CGOL_CONDITION(i, arr) (i >= SIDE ? arr[i-SIDE] : 0) + (i%SIDE != 0 ? arr[i-1] : 0) + (i%SIDE != SIDE-1 ? arr[i+1] : 0) + (i < SIDE*(SIDE-1) ? arr[i+SIDE] : 0) + (i >= SIDE && i%SIDE != 0 ? arr[i-SIDE-1] : 0) + (i < SIDE*(SIDE-1) && i%SIDE != 0 ? arr[i+SIDE-1] : 0) + (i >= SIDE && i%SIDE != SIDE-1 ? arr[i-SIDE+1] : 0) + (i < SIDE*(SIDE-1) && i%SIDE != SIDE-1 ? arr[i+SIDE+1] : 0) // Calculate the number of live adjacent cells

int main(int argc, char* argv[]) {
  int arr[SIDE*SIDE] = { 0, 1, 0,
			 0, 1, 0,
			 0, 1, 0, }; // Initial world
  
  for(int i = 0, n = 0, buf[SIDE*SIDE]; n < ITERS;
      buf[i] = ((CGOL_CONDITION(i, arr) == 2 && arr[i]) || (CGOL_CONDITION(i, arr) == 3)), printf("%d %s", buf[i], i%SIDE == SIDE - 1 ? "\n" : ""),
	(i < SIDE*SIDE - 1 ? i++ : // Move to the next cell, or loop around and start the next iteration.
	 (n++, i = 0, memcpy(&arr, &buf, sizeof(int)*SIDE*SIDE), printf("\n"))));  
  
  return 0;
}

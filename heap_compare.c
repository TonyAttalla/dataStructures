#include <stdio.h>
#include <assert.h>
#include "heap.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

int compare(TYPE left, TYPE right){
    int nodeLeft, nodeRight;

    nodeLeft = (int) left;
    nodeRight = (int) right;

    if(nodeLeft < nodeRight)
        return -1;
    else if(nodeLeft > nodeRight)
        return 1;
    else
	    return 0;

}
#include <assert.h>
#include "heap_dynamic_array.h"
#include "heap.h"

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


/* swap elements i j */
void swap (struct dyArray * v, int i, int j) { 
	TYPE temp = dyArrayGet(v, i);

	dyArrayPut(v, i, dyArrayGet(v, j));
	dyArrayPut(v, j, temp);
}

/* return index of smallest element */
int indexSmallest (struct dyArray * v, int i, int j) {
	if (LT(dyArrayGet(v, i), dyArrayGet(v, j)))
		return i;
	return j;
}

TYPE heapGetFirst (struct dyArray *heap) {
	assert(dyArraySize(heap) > 0);

	return dyArrayGet(heap, 0);
}

void HeapRemoveFirst(struct dyArray *heap) {
	int last = dyArraySize(heap)-1;

	assert (last != 0); /* make sure we have at least one element */

	/* Copy the last element to the first position */
	dyArrayPut(heap, 0, dyArrayGet(heap, last));
	dyArrayRemoveAt(heap, last); /* Remove last element.*/
	_adjustHeap(heap, last, 0);/* Rebuild heap */
}

void _adjustHeap (struct dyArray * heap, int max, int pos){
	int leftChild = 2 * pos + 1; 
	int rightChild = 2 * pos + 2;
	int smallerChild = 0;

	if (rightChild < max) { /* we have two children */
		smallerChild = indexSmallest(heap, leftChild, rightChild);
		if (compare(dyArrayGet(heap, smallerChild), dyArrayGet(heap, pos)) == -1){
			swap(heap, smallerChild, pos);  //swap with smallest child 
			_adjustHeap(heap, max, smallerChild);
		}
	}
	else if (leftChild < max) { /* we have one child */
		if (compare(dyArrayGet(heap, leftChild), dyArrayGet(heap, pos)) == -1){
			swap(heap, leftChild, pos);  //swap with smallest child
			_adjustHeap(heap, max, leftChild);
		}
	}
	/* else no children, done */
}

void heapAdd (struct dyArray * heap, TYPE newValue) {
	int parent;
	int pos = dyArraySize(heap);

	dyArrayAdd(heap, newValue); /* adds to end now need to adjust position */

	while(pos != 0){
		parent = (pos - 1) / 2;  //Floor implied through use of int
		if(compare(dyArrayGet(heap, parent), dyArrayGet(heap, pos)) == 1){
			swap(heap, parent, pos);
			pos = parent;
		}
		else
			return;
	}
}

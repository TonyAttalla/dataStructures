/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
|   Name:               Robert Kety
|   Modified:           06/23/2014
|   Description:        Reverse Polish Number calculator which receives
|                       arguments via command line interface and returns the
|                       result to the screen.  Operations supported include:
|                       Addition, Subtraction, Multiplication, Division,
|                       Power, Squared, Cubed, Absolute Value, Square Root,
|                       Exponential, Natural Logarithm, Base 10 Logarithm,
|                       Arc Sin, Arc Cos, Arc Tan, Ceiling, Floor, and Random
|                       Number
|   Acknowledgements:   Group 15, our worksheet work was invaluable for this
|                       implementation.
|                       CPlusPlus.com for listing descriptions of functions
|                       available in the math.h library.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "dynamicArray.h"

#define PI   3.14159265
#define E    2.71828182

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
    TYPE operand1, operand2 = topDynArr(stack);

    popDynArr(stack);   //Remove operand2 from stack
	
    operand1 = topDynArr(stack);
    
    popDynArr(stack);   //Remove operand1 from stack
    
    pushDynArr(stack, operand1 + operand2);    
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	TYPE operand1, operand2 = topDynArr(stack);

    popDynArr(stack);   //Remove operand2 from stack

	operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

    pushDynArr(stack, operand1 - operand2);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	TYPE operand1, operand2 = topDynArr(stack);

    assert(operand2 != 0);  //Prevent divide-by-zero

    popDynArr(stack);   //Remove operand2 from stack

	operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

    pushDynArr(stack, operand1 / operand2);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	TYPE operand1, operand2 = topDynArr(stack);

    popDynArr(stack);   //Remove operand2 from stack

	operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

    pushDynArr(stack, operand1 * operand2);
}

void power(struct DynArr *stack)
{
	TYPE operand1, operand2 = topDynArr(stack);

    popDynArr(stack);   //Remove operand2 from stack

	operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

    pushDynArr(stack, pow(operand1, operand2));
}

void square(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, pow(operand1, 2));
}

void cube(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, pow(operand1, 3));
}

void absVal(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, abs(operand1));
}

void sqRoot(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, sqrt(operand1));
}

void exponential(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, pow(E, operand1));
}

void naturalLog(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, log(operand1));
}

void base10Log(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, log10(operand1));
}

void arcSin(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    assert((operand1 >= -1) && (operand1 <= 1));    //asin() requires inclusive interval [-1, 1]

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, asin(operand1));
}

void arcCos(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    assert((operand1 >= -1) && (operand1 <= 1));    //acos() requires inclusive interval [-1, 1]

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, acos(operand1));
}

void arcTan(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, atan(operand1));
}

void ceiling(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, ceil(operand1));
}

void flooring(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

	pushDynArr(stack, floor(operand1));
}

/* Pushes a random floating point number from 0 to operand1 */
void pushRandom(struct DynArr *stack)
{
	TYPE operand1 = topDynArr(stack);

    popDynArr(stack);   //Remove operand1 from stack

    pushDynArr(stack, fmod(rand(), operand1));
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i = 1; i < numInputTokens; i++) 
	{
		s = inputString[i];

		if(strcmp(s, "+") == 0){
			add(stack);
            printf("Adding\n");
        }
		else if(strcmp(s,"-") == 0){
            subtract(stack);
            printf("Subtracting\n");
        }
		else if(strcmp(s, "/") == 0){
            divide(stack);
            printf("Dividing\n");
        }
		else if(strcmp(s, "x") == 0){
			multiply(stack);
            printf("Multiplying\n");
        }
        else if(strcmp(s, "^") == 0){
            power(stack);
			printf("Power\n");
        }
		else if(strcmp(s, "^2") == 0){
			square(stack);
            printf("Squaring\n");
        }
		else if(strcmp(s, "^3") == 0){
			cube(stack);
            printf("Cubing\n");
        }
		else if(strcmp(s, "abs") == 0){
			absVal(stack);
            printf("Absolute value\n");
        }
		else if(strcmp(s, "sqrt") == 0){
			sqRoot(stack);
            printf("Square root\n");
        }
		else if(strcmp(s, "exp") == 0){
			exponential(stack);
            printf("Exponential\n");
        }
		else if(strcmp(s, "ln") == 0){
			naturalLog(stack);
            printf("Natural Log\n");
        }
		else if(strcmp(s, "log") == 0){
			base10Log(stack);
            printf("Log\n");
        }
        else if(strcmp(s, "asin") == 0){
            arcSin(stack);
            printf("Arc Sine\n");
        }
		else if(strcmp(s, "acos") == 0){
            arcCos(stack);
            printf("Arc Cosine\n");
        }
		else if(strcmp(s, "atan") == 0){
            arcTan(stack);
            printf("Arc Tangent\n");
        }
		else if(strcmp(s, "ceil") == 0){
            ceiling(stack);
            printf("Ceiling\n");
        }
		else if(strcmp(s, "floor") == 0){
            flooring(stack);
            printf("Flooring\n");
        }
		else if(strcmp(s, "rand") == 0){
            pushRandom(stack);
            printf("Creating random number\n");
        }
		else{
			if(!(isNumber(s, &result))){
                if (strcmp(s, "pi") == 0)
                    pushDynArr(stack, PI);
                else if (strcmp(s, "e") == 0)
                    pushDynArr(stack, E);
                else{
                    printf("\n\nIllegal string \"%s\" in command line argument\n\n", s);
                    exit(1);
                }
            }
            else 
                pushDynArr(stack, result);
		}
	}	//end for 

	if(sizeDynArr(stack) == 1){
        result = topDynArr(stack);
	    popDynArr(stack);       //Empties the stack
    }
    else{
        printf("\n\nError in calculation. Too few operators or too many operands.\n\n");
        exit(1);        //Exit program
    }

	return result;
}

int main(int argc , char** argv)
{
	double result = 0.0;
    
    srand(time(NULL));      //Seed random number generator

    // assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	result = calculate(argc, argv);

    printf("Result: %.3f\n\n", result);

	return 0;
}

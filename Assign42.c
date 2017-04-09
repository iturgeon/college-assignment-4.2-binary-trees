/*
COP 3502 - Assignment # 4.2 - Ian Turgeon
binary tree
*/

#include <stdio.h>

/* initialize array and procedures */
void addNode(int loc, int num);
void Inorder(int loc);
int Tree[1000];


/* program begins running here */
int main()
{
	/* Initialize variables */
	int Loop = 1000;
	int limit;
	int input;

	/* fill array with NIL (-1) */
	for (Loop=1; Loop < 1000; Loop++)
	{
		Tree[Loop] = -1;
	}
	
	/* print header */
	printf("COP 3502 - Assignment # 4 - Ian Turgeon\n\nHow many nodes are being added? ");

	/* user input for number of nodes in array */
	scanf("%d", &limit);

	/* user input data into array based on user's definition of number of nodes */
	for (Loop=1; Loop < limit+1; Loop++)
	{
		printf("\n\nEnter a number: ");
		scanf("%d", &input);
		addNode(Loop, input);
	}
	
	/* print array in it's own order */
	printf("\n\nThe Array in left to right order:\n\n");
	for (Loop=1; Loop < limit+1; Loop++)
	{
		printf("%d  ", Tree[Loop]);
	}

	/* print header to traverse call*/
	printf("\n\nTraversing the tree in order:\n\n");

	/* call to Inorder */
	Inorder(1);

	return 0;
}

/* adds a node to the array in */
void addNode(int loc, int num)
{
	if (Tree[loc] == -1)
	{
		Tree[loc] = num;
	}
	else
	{
      if (num < Tree[loc])
         addNode(loc*2, num);
      else
         addNode(loc*2+1, num);
	}
}

/* traverses through the array */
void Inorder(int loc)
{
	if (Tree[loc] != -1)
	{
		Inorder(loc*2);
		printf("%d  ", Tree[loc]);
		Inorder(loc*2+1);
	}
}
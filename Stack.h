#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// points in plane
typedef struct{
	double x;
	double y;
	double p;
}Point;
// linked list implementation of stack

typedef struct Stack{
	Point p;
	struct Stack* next;
}Stack;

void push(Point);
Point peek();
Point pop();
void traverse();
void print_point(Point);

int orientation(Point,Point,Point);
double find_angle(Point,Point)
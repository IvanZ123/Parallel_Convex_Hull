#include "Stack.h"

Stack* top=NULL;

void Push(Point n){
	Stack* temp=(Stack*)malloc(sizeof(Stack));
	if(temp==NULL){
		return;
	}
	temp->p=n;
	temp->next=top;
	top=temp;
	return;
}

Point pop(){
	Stack* temp=top;
	Point p=top->p;
	top=top->next;
	free(temp);
	return p;
}
Point peek(){
	if(top==NULL){
		Point ending={-1999999,-199999999};
		return ending;
	}
	return top->p;
}
void traverse(){
	Stack* i;
	for(i=top;i!=NULL;i=i->next){
		print_point(i->p);
	}
}

void print_point(Point p){
	printf("(%.2f,%.2f)\n",p.x,p.y);
}

double find_angle(Point a,Point b){
 	double x=a.x-b.y;
 	double y=a.y-b.y;
 	if(x>0){
 		return atan(y/x)*180/(double)3.14;
 	}
 	if(x==0){
 		return 90;
 	}
 	else{
 		return 180+atan(y/x)*180/(double)3.14;
 	}
 }

 int orientation(Point a,Point b,Point c){
 	double area = 0.5*((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x));
    if (area < 0){
            return  1; //clockwise
    }
    else if (area > 0){
            return  -1; //counterclockwise
    }
    else{
    	return  0; // linear
    }
 }
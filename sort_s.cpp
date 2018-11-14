#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define MAXSIZE 5000000
using namespace std;

// returns the  number of processors running when function is called
int seq=1000;
int size=MAXSIZE;
int arr[MAXSIZE];
int partition(int low,int high){
	int pivot=arr[high];
	int i=(low-1);
	int temp;
	for(int j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return (i+1);
}
void Quick_sort(int start,int end){
	// partition the array
	if(start>=end){
		return;
	}
	int pi=partition(start,end);
	Quick_sort(start,(pi-1));
	Quick_sort((pi+1),end);
}
int main(){
	struct timeval TimeValue_Start;
	struct timezone TimeZone_Start;
	struct timeval TimeValue_Final;
	struct timezone TimeZone_Final;
	long start_time,end_time;
	double  time_overhead;
	for(int i=0;i<size;i++){
		arr[i]=(int)rand()%MAXSIZE;
	}
	gettimeofday(&TimeValue_Start,&TimeZone_Start);
	Quick_sort(0,size-1);
	gettimeofday(&TimeValue_Final,&TimeZone_Final);
	start_time = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
	end_time = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
	time_overhead=(end_time-start_time)/1000000.0;
	printf("time is  %lf\n",time_overhead);
	// for(int i=0;i<size;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	return 0;
}
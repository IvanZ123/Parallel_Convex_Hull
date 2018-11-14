#include <stack>
#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define SIZE 50000000

struct Point
{
    ll x, y;
};
Point p0;
ll size=SIZE;
Point points[50000000];
ll n=size;
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
void convexHull_serial(Point points[], ll n)
{
  std::vector<Point> hull;
  ll min=0;
  for(ll i=1;i<n;i++){
    if(( points[i].x<points[min].x)){
      // min_y=points[i].y;
      min=i;
    }
  } 
 
  ll p=min;
  ll q;

  do{
      q=(p+1)%n;
      hull.pb(points[p]);
      for(ll i=0;i<n;i++){
        if(orientation(points[p],points[i],points[q])==2){
          q=i;
        }
      }
      p=q;
  }while(p!=min);
  cout<<hull.size()<<endl;
  for(ll i=0;i<hull.size();i++){
    cout<<hull[i].x<<" "<<hull[i].y<<endl;
  }
}
void convexHull(Point points[], ll n)
{
  std::vector<Point> hull;
  ll min_y=points[0].y,min=0;
  int chunk;
  printf("enter chunk size\n");
  cin>>chunk;
  // #pragma omp parallel
  // #pragma omp for
  #pragma omp parallel for schedule(static,chunk)
  for(ll i=1;i<n;i++){
    if((points[i].x<points[min].x)){
     // min_y=points[i].y;
      min=i;
    }
  } 
  ll p=min;
  ll q;

  do{
      q=(p+1)%n;
      hull.pb(points[p]);
      // #pragma omp parallel
      // #pragma omp for
      #pragma omp parallel for schedule(static,chunk)
      for(ll i=0;i<n;i++){
        if(orientation(points[p],points[i],points[q])==2){
          q=i;
        }
      }
      p=q;
  }while(p!=min);
  cout<<hull.size()<<endl;
  for(ll i=0;i<hull.size();i++){
    cout<<hull[i].x<<" "<<hull[i].y<<endl;
  }
}
int main()
{
    // int n;
    // cin>>n;
   // Point points[n];
    struct timeval TimeValue_Start;
    struct timezone TimeZone_Start;
    struct timeval TimeValue_Final;
    struct timezone TimeZone_Final;
    long start_time,end_time;
    double  time_overhead;
    struct timeval TimeValue_Start1;
    struct timezone TimeZone_Start1;
    struct timeval TimeValue_Final1;
    struct timezone TimeZone_Final1;
    long start_time1,end_time1;
    double  time_overhead1;
    for(int i=0;i<n;i++){
      points[i].x=rand()%n;
      points[i].y=rand()%n;
    }
    // Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
    //                   {3, 0}, {0, 0}, {3, 3}}; 
    // int n = sizeof(points)/sizeof(points[0]); 
    printf("set no of threads\n");
    int xx;
    cin>>xx;
    omp_set_num_threads(xx);
    gettimeofday(&TimeValue_Start,&TimeZone_Start);
    convexHull(points, n);
    gettimeofday(&TimeValue_Final,&TimeZone_Final);
    start_time = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    end_time = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead=(end_time-start_time)/1000000.0;
    printf("time is  %lf\n",time_overhead);

    gettimeofday(&TimeValue_Start1,&TimeZone_Start1);
    convexHull_serial(points, n);
    gettimeofday(&TimeValue_Final1,&TimeZone_Final1);
    start_time1 = TimeValue_Start1.tv_sec * 1000000 + TimeValue_Start1.tv_usec;
    end_time1 = TimeValue_Final1.tv_sec * 1000000 + TimeValue_Final1.tv_usec;
    time_overhead1=(end_time1-start_time1)/1000000.0;
    printf("Serial TIme is   %lf\n",time_overhead1);
    return 0;
}
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
struct Point
{
    ll x, y;
};
Point p0;
ll n=50000000;
Point points[50000000];
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
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

void convexHull(Point points[], ll n)
{
  std::vector<Point> hull;
  ll min_y=points[0].y,min=0;
  for(ll i=1;i<n;i++){
    ll y=points[i].y;
    if((y<min_y)||(min_y==y && points[i].x<points[min].x)){
      min_y=points[i].y;
      min=i;
    }
  } 
 // cout<<points[min].x<<" "<<points[min].y<<endl;  
  // Point temp=points[min];
  // points[min]=points[0];
  // points[0]=temp;
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
  // for(ll i=0;i<hull.size();i++){
  //   cout<<hull[i].x<<" "<<hull[i].y<<endl;
  // }
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
    for(ll i=0;i<n;i++){
      points[i].x=rand()%n;
      points[i].y=rand()%n;
    }
    // Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
    //                   {3, 0}, {0, 0}, {3, 3}}; 
    // int n = sizeof(points)/sizeof(points[0]); 
    gettimeofday(&TimeValue_Start,&TimeZone_Start);
    convexHull(points, n);
    gettimeofday(&TimeValue_Final,&TimeZone_Final);
    start_time = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    end_time = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead=(end_time-start_time)/1000000.0;
    printf("time is  %lf\n",time_overhead);
    return 0;
}
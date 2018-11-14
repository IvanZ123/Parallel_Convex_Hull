import  math
class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y 
def orientation(p,q,r):
        val=((q.y-p.y)*(r.x-q.x))-((q.x-p.x)*(r.y-q.y))
        #checking by the slopes for orientation
        if val==0:
            return 0                                                #coloiner points
        if val>0:
            return 1                                                 #clockwise points
        else:
            return 2                                                #counterclockwise points

def MergeSort(points,low,high,comparsion_point):
    if low<high:
        mid=(low+high)//2
        MergeSort(points,low,mid,comparsion_point)         #sort the left part of the array according to the slope
        MergeSort(points,mid+1,high,comparsion_point)      #sort the right part of the array according to the slope
        Merge(points,low,mid,high,comparsion_point)        #finally merge two sorted parts of the array
    else:
        return

def Merge(points,low,mid,high,comparsion_point):
    Left=points[low:mid+1]
    Right=points[mid+1:high+1]
    left=0
    right=0
    k=low
    while left<=mid-low and right<high-mid:
        div1=comparsion_point.x-Left[left].x                    #finding the first division factor
        div2=comparsion_point.x-Right[right].x                  #find the second division factor
        m1=0
        m2=0
        angle1=0
        angle2=0
        if div1!=0:
            m1=((comparsion_point.y-Left[left].y)/(comparsion_point.x-Left[left].x))
            angle1=math.atan(m1)
        else:
            angle1=(3.14159265359)/2
        if div2!=0:
            m2=((comparsion_point.y-Right[right].y)/(comparsion_point.x-Right[right].x))
            angle2=math.atan(m2)
        else:
            angle2=(3.14159265359)/2
        if angle1<0:
            angle1+=3.14159265359
        if angle2<0:
            angle2+=3.14159265359
        if angle1>angle2:
            points[k]=Left[left]
            left+=1
        else:
            points[k]=Right[right]
            right+=1
        k+=1
    while left<=(mid-low):
        points[k]=Left[left]
        k+=1
        left+=1
    while right<(high-mid):
        points[k]=Right[right]
        right+=1
        k+=1

def swap(x,y):
    temp=x
    x=y
    y=temp

def ConvexHull(points,n):
    global discardednodes
    #iam using duplicate list in case not to change points list

    duplicate=[]
    for i in range(n):
        duplicate.append(points[i])
    bottom_most_left_y=points[0].y               #finding the bottommost point
    min_point=0

    #finding the leftmost point

    for i in range(n):
        y=points[i].y
        if ((y<bottom_most_left_y) or (bottom_most_left_y==y and points[i].x<points[min_point].x)):
            bottom_most_left_y=points[i].y
            min_point=i

    #place the bottommost point at the first position in the list
    #self.swap(points[0],points[min_point])

    temp=points[0]
    points[0]=points[min_point]
    points[min_point]=temp

    #calling MergeSort function in the format of the function
    #MergeSort(array_to_be_sorted,starting_index,ending_index)

    comparsion_point=points[0]
    p0=points[0]
    points.remove(points[0])
    MergeSort(points,0,len(points)-1,comparsion_point)
    print("$$$$$$$$$$$$$$$$$$")
    for i in range(len(points)):
        print(points[i].x,points[i].y)
n=int(input())
arr=[]
for i in range(n):
    a,b=map(int,input().split())
    arr.append(Point(a,b))
ConvexHull(arr,n)
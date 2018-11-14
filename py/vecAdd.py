import numpy as  np 
from timeit import default_timer as timer 
from numba import vectorize
@vectorize(["float32(float32,float32)"],target='cuda')
def VecAdd(a,b):
	return a+b

def main():
	n=3200000

	a=np.ones(n,dtype=np.float32)
	b=np.ones(n,dtype=np.float32)
	c=np.ones(n,dtype=np.float32)

	start=timer()
	c=VecAdd(a,b)
	VecAdd_time=timer()-start
	print('c[:5]= ',str(c[:5]))
	print("c[-5:]= ",str(c[-5:]))

	print("time taken is %f"%VecAdd_time)
if __name__ == '__main__':
	main()
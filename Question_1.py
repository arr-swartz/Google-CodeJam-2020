# Vestigium

import numpy as np

t = int(input())        #number of test case

for j in range(t):
    n = int(input())         #size of square matrix
    a = np.array([ list(map(int,input().split(" "))) for i in range(n)])
    
    r = 0                 #number of rows that contain duplicate elements
    c = 0                 #number of columns that contain duplicate elements
    k = 0                 #sum of diagonal elements
    
    for i in range(n):
        if not(len(a[i:i+1,:][0]) == len(np.unique(a[i:i+1,:][0]))):
            r+=1
        if not(len(a[:,i:i+1]) == len(np.unique(a[:,i:i+1]))):
            c+=1
        k+=a[i][i]
        
    print("Case #"+str(j+1)+": "+str(k)+" "+str(r)+" "+str(c))

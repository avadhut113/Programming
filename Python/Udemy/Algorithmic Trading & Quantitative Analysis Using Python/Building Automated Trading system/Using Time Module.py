# -*- coding: utf-8 -*-
"""
Created on Fri Aug 16 15:03:07 2024

@author: AVADHUT
"""

import time
import numpy as np

def fabonacci(n):
    if n <= 1:
        return n
    else:
        return fabonacci(n-1) + fabonacci(n-2)
    
def main():
    num = np.random.randint(1,25)
    print("%dth fabonacci number is %d"%(num, fabonacci(num)))
    
starttime = time.time()
timeout = time.time() + 60*2
while time.time() <= timeout:
    try:
        main()
        time.sleep(5-(time.time()-starttime)%0.5)
    except KeyboardInterrupt:
        print("\n\n Keyboard Exception received Exiting..")
        exit()
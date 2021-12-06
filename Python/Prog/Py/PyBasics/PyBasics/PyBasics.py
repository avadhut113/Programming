

##############################First class function###############################
"""
#function are objects
def printstr(str) :
    print(str)

print(printstr("geeksforgeeks"))
prtstr = printstr
print(prtstr("geeksforgeeks".upper()))


#function as return 
def power(pwr) :
    def numtopwr(num) :
        return num ** pwr

    return numtopwr

setpwrto2 = power(3)
print(setpwrto2(29))

#function as parameter
def addition(add) :
    print(add(89,11))

def add(num1,num2) :
    return num1 + num2

addition(add) 
"""


##############################Closure function###############################
"""

def OuterFun(text):
    text = text
    def InnnerFun():
        #using non-locals
        print(text)

    return InnnerFun

myFun = OuterFun("Hello")
#myFun()

# closures
import logging
logging.basicConfig(filename='example.log',
                    level=logging.INFO)
 
 
def logger(func):
    def log_func(*args):
        #
        logging.info(
            'Running "{}" with arguments {}'.format(func.__name__,
                                                    args))
        print(func(*args))
         
    # Necessary for closure to
    # work (returning WITHOUT parenthesis)
    return log_func            
 
def add(x, y):
    return x+y
 
def sub(x, y):
    return x-y
 
add_logger = logger(add)
sub_logger = logger(sub)
 
add_logger(3, 3)
add_logger(4, 5)
 
sub_logger(10, 5)
sub_logger(20, 10)
"""


##############################Decorators###############################
"""
#Decoder which modifies function behavior
def Decoder(func) :
    def inner() :
        print("Start of inner fun")
        func()
        print("End of inner fun")

    return inner

@Decoder
def decoder_wrapped_fun() :
    print("This is decoder wrap function")

#decoder_wrapped_fun = Decoder(decoder_wrapped_fun)
decoder_wrapped_fun()


#Decoder to calculate execution time
import time
import math
  
# decorator to calculate duration
# taken by any function.
def calculate_time(func):
      
    # added arguments inside the inner1,
    # if function takes any arguments,
    # can be added like this.
    def inner1(*args, **kwargs):
  
        # storing time before function execution
        begin = time.time()
          
        func(*args, **kwargs)
  
        # storing time after function execution
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
  
    return inner1
  
  
  
# this can be added to any function present,
# in this case to calculate a factorial
@calculate_time
def factorial(num):
  
    # sleep 2 seconds because it takes very less time
    # so that you can see the actual difference
    time.sleep(2)
    print(math.factorial(num))
  
# calling the function.
factorial(10)

#chaining Decoder
def decoder1(fun) :
    def innerFun(*args) :
        print("Start : Decoder1 inner")
        fun(*args)
        print("End : Decoder1 inner")

    return innerFun

def decoder2(fun) :
    def innerFun(*args) :
        print("Start : Decoder2 inner")
        fun(*args)
        print("End : Decoder2 inner")

    return innerFun


@decoder1
@decoder2
def add(x,y) :
    print(x+y)
add(1,2)

"""

############################## Decorators with parameters ###############################
"""
def decoder(x,y) :
    def inner(fun) :
        print("Start : Inner")
        def wrapper(*args) :
            print("Start : wrapper")
            print("Addition : {0}".format(x+y))
            fun(*args)
            print("End : wrapper")
        print("End : Inner")
        return wrapper

    return inner



def my_fun(*args) :
    for i in args :
        print(i)

decoder(1,2)(my_fun)('Geeks')
"""

############################## Momorization using Decorators ###############################

#def mem_facto(fun) :
#    mem = {}
#    def inner(num) :
#        if num not in mem :
#            mem[num] = fun(num)

#        return mem[num]
#    return inner

#@mem_facto
#def facto(num) :
#    if num == 1 :
#        return 1
#    else :
#        return num * facto(num - 1)

#print(facto(7))

list = ['A','B','V']

word = input("Enter String :")

if word in list :
    print("Prestemt");

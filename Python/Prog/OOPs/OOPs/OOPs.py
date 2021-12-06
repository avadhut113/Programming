

#############################Constructor & Destructor#############################

# Python program to illustrate destructor
# Cyclic dependency while destroying the object
"""
class A:
    def __init__(self, bb):
        self.b = bb
  
class B:
    def __init__(self):
        self.a = A(self)
    def __del__(self):
        print("die")
  
def fun():
    b = B()
  
fun()
"""

######################################Inheritance#####################################
"""
class Person(object) :
    def __init__(self, name, adhar_no) :
        self.name = name
        self.adhar_no = adhar_no

    def __del__(self) :
        print("Destroying person")

    def get_name(self) :
        return self.name
    def set_name(self, name) :
        self.name = name

    def get_adhar(self) :
        return self.adhar_no
    def set_adhar(self, adhar) :
        self.adhar_no = adhar

    def display(self) :
        print("Name : {0} \nAdhar no : {1}".format(self.name, self.adhar_no))

class Employee(Person) :
    def __init__(self, name, adhar_no, id, salary, post) :
        self.emp_id= id
        self.salary = salary
        self.post = post
        Person.__init__(self, name, adhar_no)

    def __del__(self) :
        print("Destroying Employee")

    def get_id(self) :
        return self.emp_id
    def set_id(self, id) :
        self.emp_id = id

    def display(self) :
        Person.display(self)
        print("Emp ID : {0} \nSalary : {1} \nPost : {2}".format(self.emp_id, self.salary, self.post))


emp = Employee('Rajesh', 889955, 123, 50000, 'Sr. Dev')
emp.display()

del emp
"""
###################################### Dimond Problem #####################################
"""
class A:
    def func(self):
        print("in class A")

class B(A):
    def func(self):
        super().func()
        print("In class B")

class C(A):
    def func(self):
        super().func()
        print("In class C")

class D(B,C):
    def func(self):
        super().func()
        print("In class D")


d = D()
d.func()
"""
###################################### Encapsilation #####################################
"""
# __ trailling with var name is for private var
# _ trailling with var name is for protected var

class child :
    def __init__(self, Adhar_No):
        self.__Adhar = Adhar_No

class school (child):
    def __init__(self, stud_id , adhar) :
        child.__init__(self, adhar)
        self.stud_id = stud_id
        self.__Adhar_no = 123
        print(self.__Adhar_no)


c = school(123,224455)
"""

###################################### Polymorphism #####################################

class Bird:
  def intro(self):
    print("There are many types of birds.")
      
  def flight(self):
    print("Most of the birds can fly but some cannot.")
    
class sparrow(Bird):
  def flight(self):
    print("Sparrows can fly.")
      
class ostrich(Bird):
  def flight(self):
    print("Ostriches cannot fly.")
      
obj_bird = Bird()
obj_spr = sparrow()
obj_ost = ostrich()
  
obj_bird.intro()
obj_bird.flight()
  
obj_spr.intro()
obj_spr.flight()
  
obj_ost.intro()
obj_ost.flight()
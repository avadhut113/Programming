import os 
   
#-----------------------------------------------CWD(Current working directory) (getcwd)--------------------------------------------
    
# Driver's code 
# Printing CWD before 
print(os.getcwd())
    
# Changing the CWD 
os.chdir('../../') 
    
# Printing CWD after 
print(os.getcwd())

#----------------------------------------------Mmake Directories (mkdir,makedirs)--------------------------------------------

directory = "Geeksforgeeks"
      
# Parent Directories 
parent_dir = os.getcwd()
      
# Path 
path = os.path.join(parent_dir, directory) 
      
# Create the directory 
# 'Nikhil' 
os.makedirs(path) 
print("Directory '% s' created" % directory) 

#-----------------------------------------------list Directories--------------------------------------------

dir_list = os.listdir(os.getcwd()) 
  
print("Files and directories in '", os.getcwd(), "' :") 
  
# print the list 
print(dir_list) 

#-----------------------------------------------Delete file or directory--------------------------------------------

# File name 
file = 'test.txt'
      
# File location 
location = os.getcwd()
      
# Path 
path = os.path.join(location, file) 

with open(path, 'a+') as file :
    file.write("this is sample file")
    file.close()
      
# Remove the file 
# 'file.txt' 
os.remove(path) 

directory = "Geeksforgeeks"
      
# Path 
path = os.path.join(location, directory) 
      
# Remove the Directory 
# "Geeks" 
os.rmdir(path) 

#list of directories after rmdir
dir_list = os.listdir(os.getcwd()) 
print("Files and directories in '", os.getcwd(), "' :") 
print(dir_list) 

#-----------------------------------------------Commonly Used Functions--------------------------------------------

print(os.name)

try:
    # If the file does not exist,
    # then it would throw an IOError
    filename = 'GFG.txt'
    f = open(filename, 'rU')
    text = f.read()
    f.close()
  
# Control jumps directly to here if 
# any of the above lines throws IOError.    
except IOError:
  
    # print(os.error) will <class 'OSError'>
    print('Problem reading: ' + filename)
      
# In any case, the code then continues with 
# the line after the try/except
import re
#----------------------------------------------------read from file -----------------------------------------------

#FileObje = open("C:\\Users\\patilava\\Desktop\\US59904\\debug_2021-04-23_13_59_02.log")

#for line in FileObje :
#    print(line)

#print(FileObje.read())

"""
dict = {}
with open("NOVA.ini", "r") as file:
    #data = file.readline(100)          #read single line even if specified bytes exceed line
    data = file.readlines(100)          #read all lines from file
    
    for line in data:
        word = line.split('=')
        if '[' in word[0] :
            continue
        dict[word[0]] = word[1]

    print(dict)
"""
#----------------------------------------------------write from file -----------------------------------------------
#string = ['Geeks\n','For\n','Geeks\n']

#with open("test.txt",'w+') as file :
#    file.writelines(string)
#    file.close()
   

#with open("test.txt",'r+') as file :
#    print(file.read())
#    file.close()


text = "My email id is : avadhut@gmail.com  and avadhut.patil@tieto.com"

new_emails = set(re.findall(r"[a-z0-9\.\-+_]+@[a-z0-9\.\-+_]+\.[a-z]+", 
                           text, re.I))

print(new_emails)
import os, sys, traceback
import pyodbc
import ctypes


server = 'WL354048' # to specify an alternate port
username = 'patilava' 
password = '[windows_pass]' 
database = ""
server="WL354048"
driver = "ODBC Driver 17 for SQL Server"

print("-"*100)
print("RESTORE DATABASE")
print("-"*100)

def iter_islast(row):
    it = iter(row)
    prev = it.__next__()
    for item in it:
        yield prev, False
        prev = item
    yield prev, True

try :

    conn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+server+';UID='+username+';PWD='+ password+';Trusted_Connection=yes; MARS_Connection=Yes')
    cursor = conn.cursor()

    TempSQL = ""
    #f = input("Enter backup file name :")
    f = r"C:\NovaProd\Source\DataBase backup\Test_Python\PROD_CURRENT_R2_NO_backup_2019_07_09_020001_9395495.bak"
    fname = os.path.basename(f)
    fname = os.path.splitext(fname)[0]
    backupdir   = os.path.dirname(f)


    print ("Restore Script for backupfile " + f + " below: ")
    print ("===============================================")
        
    cursor.execute("restore headeronly from disk = '%s';" % f)
    rows = cursor.fetchall()
        
    for row in rows:
        database = row.DatabaseName
        TempSQL = "RESTORE DATABASE  " + database + " FROM DISK = '" + f + "' WITH \n"
        
    cursor.execute("restore filelistonly from disk = '%s';" % f)
    rows2 = cursor.fetchall()
         
    for row, islast in iter_islast(rows2):
        if row.Type == 'L':
            TempSQL += " MOVE " + "'"+row.LogicalName+"' TO  '" + backupdir + "\\" + fname + ".ldf' \n"
        else:
            TempSQL += " MOVE " + "'"+row.LogicalName+"' TO  '" + backupdir + "\\" + fname + ".mdf', \n"
                
            
    #conn.autocommit = True
    #cursor.execute(TempSQL)

    #conn.autocommit = False
    #while cursor.nextset():
    #     pass 

    print (TempSQL + " Query executed Successfully")

    cursor.commit
    cursor.close

    conn.commit
    conn.close

except Exception:
        print("Exception in user code:")
        print("-"*60)
        traceback.print_exc(file=sys.stdout)
        print("-"*60)
        

print("\n\n")
print("-"*100)
print("ADD DSN")
print("-"*100)


ODBC_ADD_DSN = 1        # Add data source
ODBC_CONFIG_DSN = 2     # Configure (edit) data source
ODBC_REMOVE_DSN = 3     # Remove data source
ODBC_ADD_SYS_DSN = 4    # add a system DSN
ODBC_CONFIG_SYS_DSN = 5 # Configure a system DSN
ODBC_REMOVE_SYS_DSN = 6 # remove a system DSN

def create_sys_dsn(driver, **kw):
    """Create a  system DSN
    Parameters:
        driver - ODBC driver name
        kw - Driver attributes
    Returns:
        0 - DSN not created
        1 - DSN created 
    """
    nul = chr(0)
    attributes = []
    for attr in kw.keys():
        attributes.append("%s=%s" % (attr, kw[attr]))

    #SERVER=(WL354048)\0DESCRIPTION=SQL Server 17 DSN\0DSN =PROD_CURRENT_R2_NO\0Database=PROD_CURRENT_R2_NO\0Trusted_Connection=Yes\0\0
    return ctypes.windll.ODBCCP32.SQLConfigDataSource(0, ODBC_ADD_DSN, driver, nul.join(attributes))

#if create_sys_dsn("SQL Server",SERVER="(WL354048)", DESCRIPTION="SQL Server 17 DSN", DSN = database, Database = database, Trusted_Connection="Yes"):
#    print ("DSN created")
#else:
#    print ("DSN not created")

""" odbcconf configsysdsn "ODBC Driver 17for SQL server" "DSN=PROD_CURRENT_R2_NO;SERVER=WL354048;PORT=3306;DATABASE=PROD_CURRENT_R2_NO;UID=patilava   """

#create DSN using command line
cmdStr = r'C:\Windows\SysWOW64\odbcconf.exe /A {ConfigDSN "'+ driver +'" "DSN='+ database +'|SERVER='+ server +'|Database='+ database +'|Trusted_Connection=Yes|Description='+ database +'|AutoTranslate=No|AnsiNPW=No|QuotedId=No|Language=English"}'
print(os.system(cmdStr))

print("\n\n")
print("-"*100)
print("CREATE FOLDER STRUCTURE")
print("-"*100)

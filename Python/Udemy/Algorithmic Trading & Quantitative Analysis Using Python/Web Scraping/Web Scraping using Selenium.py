# -*- coding: utf-8 -*-
"""
Created on Sat May 11 09:34:38 2024

@author: AVADHUT
"""

from selenium import webdriver
from selenium.webdriver.common.by import By
import pandas as pd

path = "C:\\Users\\AVADHUT\\Downloads\\chromedriver-win64\\chromedriver-win64\\chromedriver.exe"

service = webdriver.chrome.service.Service(path)
service.start()

ticker = "AAPL"
url = "https://finance.yahoo.com/quote/{}/financials?p={}".format(ticker,ticker)

driver = webdriver.Chrome(service=service)
driver.get(url)
driver.implicitly_wait(3)

table = driver.find_element(By.XPATH,  '//div[@class="table svelte-1pgoo1f"]').text
print(table)
table_list = table.split("\n")
income_st_dir = {}
for count,i in enumerate(table_list):
    if count%2==0:
        if table_list[count] == "Breakdown":
            pass
        else:
            income_st_dir[i] = []
    else:
        if table_list[count-1] == "Breakdown":
            pass
        else:            
            income_st_dir[table_list[count-1]] = i.split("\t")
        

### 2nd way   (better, handles heading as well)  
income_st_dir = {}
table = driver.find_elements(By.XPATH,  "//*[@class='row lv-0 svelte-1xjz32c']")
table_heading = driver.find_elements(By.XPATH,  "//*[contains(@class='column svelte-1ezv2n5 alt')]")
headings = []
for cell in table_heading:
    headings.append(cell.text)

for cell in table:
    [key, val] = cell.text.split("\n")
    income_st_dir[key] = val.split(" ")
    
income_statement_df = pd.DataFrame(income_st_dir).T
income_statement_df.columns = headings


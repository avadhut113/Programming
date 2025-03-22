# -*- coding: utf-8 -*-
"""
handling NaN values

@author: Mayank Rasu (http://rasuquant.com/wp/)
"""

import datetime as dt
import yfinance as yf
import pandas as pd

stocks = ["HDFCBANK.NS","SANDUMA.NS","IRFC.NS","KIRLFER.BO"]

#Get span of 3 yrs
start = dt.datetime.today()-dt.timedelta(365 * 3) 
end = dt.datetime.today()

cl_price = pd.DataFrame() # empty dataframe which will be filled with closing prices of each stock

# looping over tickers and creating a dataframe with close prices
for ticker in stocks:
    cl_price[ticker] = yf.download(ticker,start,end)["Adj Close"]
    
# filling NaN values
#cl_price.fillna(method='bfill',axis=0,inplace=True)
cl_price.bfill(axis=0,inplace=True) #if nan value it will backfill to top

#dropping NaN values
cl_price.dropna(axis=1,how='any') #drop if found nan value
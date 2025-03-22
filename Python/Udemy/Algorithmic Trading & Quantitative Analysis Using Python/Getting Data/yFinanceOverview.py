# -*- coding: utf-8 -*-
"""
Created on Sun Jan 15 12:39:48 2023

@author: AVADHUT
"""

import datetime as dt
import yfinance as yf
import pandas as pd

stocks = ["SANDUMA.BO","IRFC.NS","AUROPHARMA.NS","KIRLFER.NS"]
start = dt.datetime.today() - dt.timedelta(60)
end = dt.datetime.today()
cl_price = pd.DataFrame()
ohlcv_data ={}

for ticker in stocks:
    cl_price[ticker] = yf.download(ticker,period="1y")["Adj Close"]
    
for ticker in stocks:
    ohlcv_data[ticker] = yf.download(ticker,period="1y")

data = yf.download("SANDUMA.BO", period="1mo",interval="15m")

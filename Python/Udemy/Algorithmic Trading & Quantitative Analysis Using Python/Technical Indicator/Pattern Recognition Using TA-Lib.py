# -*- coding: utf-8 -*-
"""
Created on Sun May 19 10:54:30 2024

@author: AVADHUT
"""

import yfinance as yf
import pandas as pd
import talib
from talib import abstract

tickers = ["SANDUMA.NS","IRFC.NS","JINDALSAW.NS","FEDERALBNK.NS","HBLPOWER.BO"]
ohlcv_data = {}

for ticker in tickers :
    temp_data = yf.download(ticker, period = '3y', interval = '1d')
    temp_data.dropna(how="any", inplace=True)
    ohlcv_data[ticker] = temp_data
    
    
#ohlcv_data.rename(columns={'Open': 'open', 'High': 'high','Low': 'low','Close': 'close', 'Volume': 'volume'}, inplace= True)
#ohlcv_data.shape()

talib.get_function_groups().keys()

talib.get_function_groups()

all_indicators = [method for method in dir(abstract) if method.startswith('CDL')]

df_indicator = pd.DataFrame()
for indicator in all_indicators:
    ohlcv_data[str(indicator)] = getattr(abstract, indicator)(ohlcv_data)
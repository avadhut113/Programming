# -*- coding: utf-8 -*-
"""
Created on Sat May 20 11:30:45 2023

@author: AVADHUT
"""
from alpha_vantage.timeseries import TimeSeries
import pandas as pd

key = "U912NRO8V6D8K6TV"

ts = TimeSeries(key,output_format="pandas")
data = ts.get_daily(symbol="EURUSD",outputsize='full')[0]
data.columns = ["open","high","low","close","volume"]


all_tickers = ["APPL","MSFT"]
close_price = pd.DataFrame()

for ticker in all_tickers:
    starttime = time.time()
    ts = TimeSeries(key,output_format="pandas")
    data = ts.get_intraday(symbol=ticker,interval='1min',outputsize='full')[0]
    data.columns = ["open","high","low","close","volume"]
    close_price[ticker] = data["close"]

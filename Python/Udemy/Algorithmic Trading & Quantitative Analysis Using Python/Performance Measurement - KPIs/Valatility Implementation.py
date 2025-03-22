# -*- coding: utf-8 -*-
"""
Created on Sun Jun 16 19:45:08 2024

@author: AVADHUT
"""

import yfinance as yf
import numpy as np

tickers = ["SANDUMA.NS","IRFC.NS","JINDALSAW.NS","FEDERALBNK.NS","HBLPOWER.BO"]
ohlcv_data = {}

for ticker in tickers:
    temp = yf.download(ticker, period = '7mo', interval='1d')
    temp.dropna(how='any', inplace=True)
    ohlcv_data[ticker] = temp
    
def volatility(DF):
    df = DF.copy()
    df["return"] = df["Adj Close"].pct_change()
    vol = df["return"].std() * np.sqrt(252)
    return vol

for ticker in tickers:
    print("Volatilty value of {} = {}".format(ticker, volatility(ohlcv_data[ticker])))
    
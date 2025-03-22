# -*- coding: utf-8 -*-
"""
Created on Sun Jun 16 19:03:51 2024

@author: AVADHUT
"""

import yfinance as yf

tickers = ["SANDUMA.NS","IRFC.NS","JINDALSAW.NS","FEDERALBNK.NS","HBLPOWER.BO"]
ohlvc_data = {}

for ticker in tickers:
    temp = yf.download(ticker, period='7mo', interval='1d')
    temp.dropna(how="any",inplace=True)
    ohlvc_data[ticker] = temp
    

def CAGR(DF) :
    df = DF.copy()
    df = df.copy()
    df["return"] = df["Adj Close"].pct_change()
    df["cum_return"] = (1 + df["return"]).cumprod()
    n = len(df) / 252
    cagr = (df["cum_return"][-1])**(1/n) - 1
    return cagr

for ticker in tickers:
    print("CAGR value of {} = {}".format(ticker, CAGR(ohlvc_data[ticker])))
    

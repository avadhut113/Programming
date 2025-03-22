# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 15:57:46 2024

@author: AVADHUT
"""

import yfinance as yf
import pandas as pd
import numpy as np

tickers = ["IRFC.NS", "HDFCBANK.NS", "SANDUMA.BO", "AUROPHARMA.NS", "KIRLFER.NS"]
stocks_data = {}

for ticker in tickers:
    temp = yf.download(ticker, period='1y', interval='1d')
    temp.dropna(how='any', inplace=True)
    stocks_data[ticker] = temp


def CAGR(DF):
    df = DF.copy()
    df["daily_ret"] = DF["Adj Close"].pct_change()
    df["cum_return"] = (1 + df["daily_ret"]).cumprod()
    n = len(df)/252
    cagr = (df["cum_return"][-1])**(1/n) - 1
    return cagr

def volatility(DF):
    df = DF.copy()
    df["daily_ret"] = DF["Adj Close"].pct_change()
    vol =df["daily_ret"].std() * np.sqrt(252)
    return vol

def sharpe(DF, rf):
    df = DF.copy()
    return (CAGR(df) - 0.073) / volatility(df)

def sortino(DF, rf):
    df = DF.copy()
    df["return"] = df["Adj Close"].pct_change()
    neg_return = np.where(df["return"]>0,0,df["return"])
    neg_vol = pd.Series(neg_return[neg_return != 0]).std() * np.sqrt(252)
    return (CAGR(df) - rf) / neg_vol

print("\n")
for ticker in stocks_data:
    print("Sharpe for {} = {}".format(ticker, sharpe(stocks_data[ticker], 0.073)))
    print("Sortino for {} = {} \n".format(ticker, sortino(stocks_data[ticker], 0.073)))
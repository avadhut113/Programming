# -*- coding: utf-8 -*-
"""
Created on Sat Jun 22 17:40:32 2024

@author: AVADHUT
"""
import yfinance as yf

tickers = ["IRFC.NS", "HDFCBANK.NS", "SANDUMA.BO", "AUROPHARMA.NS", "KIRLFER.NS"]
stocks_data = {}

for ticker in tickers:
    temp = yf.download(ticker , period='1y', interval='1d')
    temp.dropna(how="any",inplace=True) 
    stocks_data[ticker] = temp
    

def CAGR(DF):
    df = DF.copy()
    df["daily_ret"] = DF["Adj Close"].pct_change()
    df["cum_return"] = (1 + df["daily_ret"]).cumprod()
    n = len(df)/252
    cagr = (df["cum_return"][-1])**(1/n) - 1
    return cagr
   
def MaxDrawdown(DF):
    df = DF.copy()
    df = stocks_data[ticker].copy()
    df["daily return"] = df["Adj Close"].pct_change()
    df["cum return"] = (1+df["daily return"]).cumprod()
    df["cum roll max"] = df["cum return"].cummax()
    df["drawdown"] = df["cum roll max"] - df["cum return"]
    df["cum return"].plot()
    return (df["drawdown"]/df['cum roll max']).max()

def calmar(DF):
    return CAGR(DF)/MaxDrawdown(DF)


for ticker in stocks_data:
    print("Max Drawdown for {} = {}".format(ticker, MaxDrawdown(stocks_data[ticker])))
    print("Calmar for {} = {} \n".format(ticker, calmar(stocks_data[ticker])))

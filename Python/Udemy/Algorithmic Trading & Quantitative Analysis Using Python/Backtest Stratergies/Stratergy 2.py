# -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 11:21:58 2024

@author: AVADHUT
"""

import numpy as np
import pandas as pd
import yfinance as yf
import datetime as dt
import copy
import matplotlib.pyplot as plt


trading_days_in_yr = 252


def ATR(DF, n=14):
    "function to calculate True Range and Average True Range"
    df = DF.copy()
    df["H-L"] = df["High"] - df["Low"]
    df["H-PC"] = abs(df["High"] - df["Adj Close"].shift(1))
    df["L-PC"] = abs(df["Low"] - df["Adj Close"].shift(1))
    df["TR"] = df[["H-L","H-PC","L-PC"]].max(axis=1, skipna=False)
    df["ATR"] = df["TR"].ewm(com=n, min_periods=n).mean()
    return df["ATR"]

def CAGR(DF):
    "function to calculate the Cumulative Annual Growth Rate of a trading strategy"
    df = DF.copy()
    df["cum_return"] = (1 + df["ret"]).cumprod()
    n = len(df)/(trading_days_in_yr)
    CAGR = (df["cum_return"].tolist()[-1])**(1/n) - 1
    return CAGR

def volatility(DF):
    "function to calculate annualized volatility of a trading strategy"
    df = DF.copy()
    vol = df["ret"].std() * np.sqrt(trading_days_in_yr)
    return vol

def sharpe(DF,rf):
    "function to calculate sharpe ratio ; rf is the risk free rate"
    df = DF.copy()
    sr = (CAGR(df) - rf)/volatility(df)
    return sr
    

def max_dd(DF):
    "function to calculate max drawdown"
    df = DF.copy()
    df["cum_return"] = (1 + df["ret"]).cumprod()
    df["cum_roll_max"] = df["cum_return"].cummax()
    df["drawdown"] = df["cum_roll_max"] - df["cum_return"]
    df["drawdown_pct"] = df["drawdown"]/df["cum_roll_max"]
    max_dd = df["drawdown_pct"].max()
    return max_dd


# Download historical data (daily) for NSE stocks

tickers = ["IRFC.NS", "HDFCBANK.NS", "SANDUMA.BO", "AUROPHARMA.NS"
           , "KEYFINSERV.NS","MAGADSUGAR.NS", "VLSFINANCE.NS"
           , "MAJESAUT.BO", "ELPROINTL.BO", "SUNDARMHLD.NS"]

ohlc_day = {} # directory with ohlc value for each stock            
start_date = dt.datetime.today()-dt.timedelta(365*5)
end_date = dt.datetime.today()

# looping over tickers and creating a dataframe with close prices
for ticker in tickers:
    ohlc_day[ticker] = yf.download(ticker,start_date,end_date,interval='1d')
    ohlc_day[ticker].dropna(inplace=True,how="all")
 
tickers = ohlc_day.keys() # redefine tickers variable after removing any tickers with corrupted data


################################Backtesting####################################

# calculating monthly return for each stock and consolidating return info by stock in a separate dataframe
ohlc_dic = copy.deepcopy(ohlc_day)
tickers_signals = {}
tickers_ret = {}

for ticker in tickers:
    


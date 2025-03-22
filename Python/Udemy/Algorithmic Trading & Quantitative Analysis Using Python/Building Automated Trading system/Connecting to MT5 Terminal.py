# -*- coding: utf-8 -*-
"""
Created on Fri Aug 16 22:03:59 2024

@author: AVADHUT
"""

import MetaTrader5 as mt5
import configparser
import datetime as dt
import pandas as pd

config = configparser.ConfigParser()
config.read('D:\\Avadhut\\Programming\\Python\\Udemy\\Algorithmic Trading & Quantitative Analysis Using Python\\Building Automated Trading system\\MT5_Credentials.txt')
# key in config['DEFAULT']:  
#    print(key)
Path = config.get('DEFAULT','Path')
Server = config.get('DEFAULT','Server')
Login = int(config.get('DEFAULT','Login'))
Password = config.get('DEFAULT','Password')
#name = config_dict['DEFAULT']['Name'] 


if not mt5.initialize(path = Path, server = Server, login = Login, password = Password):
    print("Connection failed error code = ", mt5.last_error())
    quit()
else :
    print("connection established successfully")
    
    
# display data on connection status, server name and trading account
#print(mt5.terminal_info())
# display data on MetaTrader 5 version
#print(mt5.version())
     
    
def market_order(symbol,vol):
    request = {
        "action": mt5.TRADE_ACTION_DEAL,
        "symbol": symbol,
        "volume": vol,
        "price": mt5.symbol_info_tick(symbol).ask,
        "type": mt5.ORDER_TYPE_BUY,
        "type_time": mt5.ORDER_TIME_GTC,
        "type_filling": mt5.ORDER_FILLING_RETURN
    }

    order_status = mt5.order_send(request)
    return order_status

print(market_order('EURUSD', 0.03))

# shut down connection to the MetaTrader 5 terminal
#mt5.shutdown()
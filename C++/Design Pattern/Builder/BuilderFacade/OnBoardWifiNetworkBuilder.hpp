#pragma once
#include "OnBoardWifiNetwork.hpp"

class OnBoardWiFiNetworkBuilder
{
public:
    explicit OnBoardWiFiNetworkBuilder(const std::string& ssid);
    explicit OnBoardWiFiNetworkBuilder(const OnBoardWiFiNetwork& network);
    ~OnBoardWiFiNetworkBuilder();

    OnBoardWiFiNetworkBuilder& WithSecurityType(SecurityType securityType);
    OnBoardWiFiNetworkBuilder& WithPSK(const std::string& psk);
    OnBoardWiFiNetworkBuilder& WithPriority(const unsigned short priority);
    OnBoardWiFiNetworkBuilder& WithSignalStrength(const short signalStrength);
    OnBoardWiFiNetworkBuilder& WithConnectionStatus(const bool isConnected, const bool isConnectedToInternet);
    OnBoardWiFiNetworkBuilder& WithManuallyAdded(const bool isManuallyAdded);

    OnBoardWiFiNetwork Build();

private:
    OnBoardWiFiNetworkBuilder(const OnBoardWiFiNetworkBuilder& rhs);
    OnBoardWiFiNetworkBuilder& operator=(const OnBoardWiFiNetworkBuilder& rhs);

    std::string SSID;
    SecurityType SecurityTypeId;
    std::string PSK;
    unsigned short Priority;
    short SignalStrength;
    bool Connected;
    bool ConnectedToInternet;
    bool ManuallyAdded;
};

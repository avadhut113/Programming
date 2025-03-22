#include "OnBoardWifiNetworkBuilder.hpp"

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetworkBuilder::OnBoardWiFiNetworkBuilder(const std::string& ssid)
	: SSID(ssid)
	, SecurityTypeId(OPEN)
	, PSK()
	, Priority(1)
	, SignalStrength(-100)
	, Connected(false)
	, ConnectedToInternet(false)
	, ManuallyAdded(false)
{
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetworkBuilder::OnBoardWiFiNetworkBuilder(const OnBoardWiFiNetwork& network)
	: SSID(network.GetSSID())
	, SecurityTypeId(network.GetSecurityType())
	, PSK(network.GetPSK())
	, Priority(network.GetPriority())
	, SignalStrength(network.GetSignalStrength())
	, Connected(network.IsConnectedToAP())
	, ConnectedToInternet(network.IsConnectedToInternet())
	, ManuallyAdded(network.IsManuallyAdded())
{
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetworkBuilder::~OnBoardWiFiNetworkBuilder()
{
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithSecurityType(SecurityType securityType)
{
	SecurityTypeId = securityType;
	return *this;
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithPSK(const std::string& psk)
{
	PSK = psk;
	return *this;
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithPriority(const unsigned short priority)
{
	Priority = priority;
	return *this;
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithSignalStrength(const short signalStrength)
{
	SignalStrength = signalStrength;
	return *this;
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithConnectionStatus(const bool isConnected, const bool isConnectedToInternet)
{
	Connected = isConnected;
	ConnectedToInternet = isConnectedToInternet;
	return *this;
}

OnBoardWiFiNetworkBuilder& OnBoardWiFiNetworkBuilder::WithManuallyAdded(const bool isManuallyAdded)
{
	ManuallyAdded = isManuallyAdded;
	return *this;
}

OnBoardWiFiNetwork OnBoardWiFiNetworkBuilder::Build()
{
	return OnBoardWiFiNetwork(SSID, SecurityTypeId, PSK, Priority, ManuallyAdded, SignalStrength, Connected, ConnectedToInternet);
}

#include "OnBoardWifiNetwork.hpp"

namespace
{
    const short DEFAULT_SIGNAL_STRENGTH = -100;
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork::OnBoardWiFiNetwork()
    : SSID()
    , SecurityTypeId(OPEN)
    , PSK()
    , Priority(1)
    , SignalStrength(DEFAULT_SIGNAL_STRENGTH)
    , MarkedForDeletion(false)
    , ConnectedWithAP(false)
    , ConnectedToInternet(false)
    , ManuallyAdded(false)
{
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork::OnBoardWiFiNetwork(const std::string& ssid)
    : SSID(ssid)
    , SecurityTypeId(OPEN)
    , PSK()
    , Priority(1)
    , SignalStrength(DEFAULT_SIGNAL_STRENGTH)
    , MarkedForDeletion(false)
    , ConnectedWithAP(false)
    , ConnectedToInternet(false)
    , ManuallyAdded(false)
{
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork::OnBoardWiFiNetwork(const std::string& ssid,
    SecurityType securityTypeId,
    const std::string& psk,
    unsigned short priority,
    bool isManuallyAdded,
    short signalStrength,
    bool isConnected,
    bool isConnectedToInternet)
    : SSID(ssid)
    , SecurityTypeId(securityTypeId)
    , PSK(psk)
    , Priority(priority)
    , SignalStrength(signalStrength)
    , MarkedForDeletion(false)
    , ConnectedWithAP(isConnected)
    , ConnectedToInternet(isConnectedToInternet)
    , ManuallyAdded(isManuallyAdded)
{}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork::OnBoardWiFiNetwork(const OnBoardWiFiNetwork& rhs)
    : SSID(rhs.SSID)
    , SecurityTypeId(rhs.SecurityTypeId)
    , PSK(rhs.PSK)
    , Priority(rhs.Priority)
    , SignalStrength(rhs.SignalStrength)
    , MarkedForDeletion(rhs.MarkedForDeletion)
    , ConnectedWithAP(rhs.ConnectedWithAP)
    , ConnectedToInternet(rhs.ConnectedToInternet)
    , ManuallyAdded(rhs.ManuallyAdded)
{}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork& OnBoardWiFiNetwork::operator=(const OnBoardWiFiNetwork& rhs)
{
    SSID = rhs.SSID;
    SecurityTypeId = rhs.SecurityTypeId;
    PSK = rhs.PSK;
    Priority = rhs.Priority;
    SignalStrength = rhs.SignalStrength;
    MarkedForDeletion = rhs.MarkedForDeletion;
    ConnectedWithAP = rhs.ConnectedWithAP;
    ConnectedToInternet = rhs.ConnectedToInternet;
    ManuallyAdded = rhs.ManuallyAdded;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
OnBoardWiFiNetwork::~OnBoardWiFiNetwork()
{}

bool OnBoardWiFiNetwork::operator==(const OnBoardWiFiNetwork& rhs) const
{
    return (SSID == rhs.SSID) && (SecurityTypeId == rhs.SecurityTypeId);
}

void OnBoardWiFiNetwork::MarkForDeletion()
{
    MarkedForDeletion = true;
}

bool OnBoardWiFiNetwork::IsMarkedForDeletion() const
{
    return MarkedForDeletion;
}

void OnBoardWiFiNetwork::SetConnectedToAP(const bool connected)
{
    ConnectedWithAP = connected;
}

bool OnBoardWiFiNetwork::IsConnectedToAP() const
{
    return ConnectedWithAP;
}

void OnBoardWiFiNetwork::SetConnectedToInternet(const bool connectedToInternet)
{
    ConnectedToInternet = connectedToInternet;
}

bool OnBoardWiFiNetwork::IsConnectedToInternet() const
{
    return ConnectedToInternet;
}

std::string OnBoardWiFiNetwork::GetSSID() const
{
    return SSID;
}

std::string OnBoardWiFiNetwork::GetPSK() const
{
    return PSK;
}

unsigned short OnBoardWiFiNetwork::GetPriority() const
{
    return Priority;
}

SecurityType OnBoardWiFiNetwork::GetSecurityType() const
{
    return SecurityTypeId;
}

void OnBoardWiFiNetwork::SetSignalStrength(short signalStrength)
{
    SignalStrength = signalStrength;
}

short OnBoardWiFiNetwork::GetSignalStrength() const
{
    return SignalStrength;
}

void OnBoardWiFiNetwork::SetManuallyAdded(const bool manuallyAdded)
{
    ManuallyAdded = manuallyAdded;
}

bool OnBoardWiFiNetwork::IsManuallyAdded() const
{
    return ManuallyAdded;
}
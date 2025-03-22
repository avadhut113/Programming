#pragma once
#include <string>

enum SecurityType
{
    OPEN = 0,
    WEP = 1,
    WPA_PERSONAL = 2,
    WPA_ENTERPRISE = 3,
    WPA2_PERSONAL = 4,
    WPA2_ENTERPRISE = 5,
    UNKNOWN_SECURITY_TYPE = 6
};

class OnBoardWiFiNetwork
{
public:
    OnBoardWiFiNetwork();
    explicit OnBoardWiFiNetwork(const std::string& ssid);
    OnBoardWiFiNetwork(const std::string& ssid,
        SecurityType securityTypeId,
        const std::string& psk,
        unsigned short priority,
        bool isManuallyAdded = false,
        short signalStrength = -100,
        bool isConnected = false,
        bool isConnectedToInternet = false);

    ~OnBoardWiFiNetwork();

    OnBoardWiFiNetwork(const OnBoardWiFiNetwork& rhs);
    OnBoardWiFiNetwork& operator=(const OnBoardWiFiNetwork& rhs);
    bool operator==(const OnBoardWiFiNetwork& rhs) const;

    std::string GetSSID() const;
    std::string GetPSK() const;
    unsigned short GetPriority() const;
    SecurityType GetSecurityType() const;

    void SetSignalStrength(short SignalStrength);
    short GetSignalStrength() const;

    void MarkForDeletion();
    bool IsMarkedForDeletion() const;

    void SetConnectedToAP(bool connected);
    bool IsConnectedToAP() const;

    void SetConnectedToInternet(bool connectedToInternet);
    bool IsConnectedToInternet() const;

    void SetManuallyAdded(bool manuallyAdded);
    bool IsManuallyAdded() const;

private:
    std::string SSID;
    SecurityType SecurityTypeId;
    std::string PSK;
    unsigned short Priority;
    short SignalStrength;
    bool MarkedForDeletion;
    bool ConnectedWithAP;
    bool ConnectedToInternet;
    bool ManuallyAdded;
};
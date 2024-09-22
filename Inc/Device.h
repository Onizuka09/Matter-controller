#ifndef DEVICE_H
#define DEVICE_H
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include "utils.h"
class Device {
private: 
    bool  getDeviceType(const QString &hexVal) ;
public:
  Device()
      : hostnameRegex("Hostname: (\\S+)"),
        ipRegex("IP Address #[0-9]+: (\\S+)"),
        deviceNameRegex("Device Name: (.+)"),
        portRegex("Port: (\\d+)"),
        vendorIDRegex("Vendor ID: (\\d+)"),
        productIDRegex("Product ID: (\\d+)"),
        instanceNameRegex("Instance Name: (\\S+)"),
        commissioningModeRegex("Commissioning Mode: (\\d+)"),
        deviceTypeRegex("Device Type: (\\d+)"),
        discriminatorRegex("Long Discriminator: (\\d+)"),
        discoverySuccessRegex(R"(\[.*\] \[.*\] \[DIS\] Discovered commissionable/commissioner node:)"),
  commissionSuccRegrex(R"(\[.*\] \[.*\] \[TOO\] Device commissioning completed with success)"){
          
        hostname=""; 
        ip_adr=QStringList(); 
        Dname=""; 
        port=""; 
        vendor_ID=""; 
        Product_ID=""; 
        InstanceName=""; 
        DeviceType="";
        DeviceType_str=""; 
        DeviceCategory=""; 
        Discriminator="";
        CommissioningMode=""; 
        discoverySuccess=false; 
        pairing_success=false; 
        }


  ~Device(); 
  void get_device_info(const QString );
  void debug_items();
  void init_dev_variables(); 
  void convert_deviceType(); 
  void check_pairing_succ(QString);

QString hostname;
QStringList ip_adr;
QString Dname;
QString port;
QString vendor_ID;
QString Product_ID;
QString InstanceName;
QString CommissioningMode;
QString DeviceType;
QString Discriminator;
QString DeviceCategory; 
bool discoverySuccess = false;
bool pairing_success=false ; 
private:
  QRegularExpression hostnameRegex ;
  QRegularExpression ipRegex;
  QRegularExpression deviceNameRegex; 
  QRegularExpression portRegex;  
  QRegularExpression vendorIDRegex;  
  QRegularExpression productIDRegex;
  QRegularExpression instanceNameRegex; 
  QRegularExpression commissioningModeRegex; 
  QRegularExpression deviceTypeRegex; 
  QRegularExpression discriminatorRegex; 
  QRegularExpression discoverySuccessRegex; 
  QRegularExpression commissionSuccRegrex; 
  QString deviceTypes_Fpath=":/docs/Matter_device_types.json" ; 
  QString DeviceType_str; 
 
// object declaration 
private:
  Utils utility; 


};
#endif

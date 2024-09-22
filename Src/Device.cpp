#include "Inc/Device.h"
#include "qlogging.h"
#include "qregularexpression.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


Device::~Device(){


}
bool  Device::getDeviceType(const QString &hexVal){ 
  QFile file(deviceTypes_Fpath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Unable to open file:" << deviceTypes_Fpath;
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "Invalid JSON data";
        return false;
    }

    QJsonObject jsonObj = doc.object();

    // Loop through each category (lighting_devices, smart_plugs_and_actuators, etc.)
    for (const QString& category : jsonObj.keys()) {
        QJsonArray categoryArray = jsonObj[category].toArray();
        for (const QJsonValue& item : categoryArray) {
            QJsonObject deviceObj = item.toObject();
            if (deviceObj["hex_value"].toString() == hexVal) {
                  DeviceCategory=category ; 
                  DeviceType= deviceObj["type"].toString();  
                return true;
            }
        }
    }
    qDebug()<<"device not found "<<hexVal;

    return false;
}


void Device::get_device_info(const QString term){
  QString out = term ;
  init_dev_variables(); 
  QRegularExpression ansiEscapeCodeRegex("\\x1B\\[[0-9;]*[a-zA-Z]");
out.remove(ansiEscapeCodeRegex);
  /* qDebug()<<out; */ 
    /* discoverySuccess = out.contains("Discovered"); */

    QRegularExpressionMatch match;

    match = discoverySuccessRegex.match(term); 
    // for more than device you can use this to get the number of devcices descovered 
    /* QRegularExpressionMatchIterator i = discoverySuccessRegex.globalMatch(term); */ 
    /* int num_disc_dev=0; */ 
    /* while (i.hasNext()){ */ 
    /*   i.next(); */ 
    /*   num_disc_dev++; */ 
    /* } */
    /* qDebug()<< "num discovered dev: "<<num_disc_dev; */ 
    if (match.hasMatch()){ 
      qDebug()<<"discovered dev" ; 
      discoverySuccess=true; 
    }else { 
      discoverySuccess=false; 
    }

    match = hostnameRegex.match(out);
    if (match.hasMatch()) {
        hostname = match.captured(1);
    }

    match = ipRegex.match(out);
    while (match.hasMatch()) {
        ip_adr.append(match.captured(1));
        out = out.mid(match.capturedEnd());
        match = ipRegex.match(out);
    }

    match = deviceNameRegex.match(out);
    if (match.hasMatch()) {
        Dname = match.captured(1);
    }

    match = portRegex.match(out);
    if (match.hasMatch()) {
        port = match.captured(1);
    }

    match = vendorIDRegex.match(out);
    if (match.hasMatch()) {
        vendor_ID = match.captured(1);
    }

    match = productIDRegex.match(out);
    if (match.hasMatch()) {
        Product_ID = match.captured(1);
    }

    match = instanceNameRegex.match(out);
    if (match.hasMatch()) {
        InstanceName = match.captured(1);
    }

    match = commissioningModeRegex.match(out);
    if (match.hasMatch()) {
        CommissioningMode = match.captured(1);
    }

    match = deviceTypeRegex.match(out);
    if (match.hasMatch()) {
        DeviceType_str = match.captured(1);
    }
  // convert the Device type from int to hex and set the devcie actegory 
    /* convert_deviceType(); */  
    match = discriminatorRegex.match(out);
    if (match.hasMatch()) {
        Discriminator = match.captured(1);
    }
  

}
void Device::debug_items(){
  qDebug() << "Hostname:" << hostname;
  qDebug() << "IP Addresses:" << ip_adr;
  qDebug() << "Device Name:" << Dname;
  qDebug() << "Port:" << port;
  qDebug() << "Vendor ID:" << vendor_ID;
  qDebug() << "Product ID:" << Product_ID;
  qDebug() << "Instance Name:" << InstanceName;
  qDebug() << "Commissioning Mode:" << CommissioningMode;
  qDebug() << "Device Type:" << DeviceType;
  qDebug() << "Discriminator:" << Discriminator;
  qDebug() << "Discovery Success:" << discoverySuccess;
}
void Device::convert_deviceType(){ 
 int dtype =DeviceType_str.toInt(); 
  qDebug()<<dtype; 
  QString hex = utility.dec_to_hex(dtype);
  // padding 
  qDebug()<<hex; 

  bool st =getDeviceType(hex); 
  
  if (st){
      qDebug()<<DeviceType<<DeviceCategory; 
  }else { 
    qDebug()<<"ERROR: Failed miserably"; 
  }

}
void Device::init_dev_variables(){ 
        hostname=""; 
        ip_adr=QStringList(); 
        Dname=""; 
        port=""; 
        vendor_ID=""; 
        Product_ID=""; 
        InstanceName=""; 
        DeviceType="";
        Discriminator="";
        CommissioningMode=""; 
        discoverySuccess=false; 
        DeviceType_str=""; 
        DeviceCategory=""; 
        pairing_success=false; 
 
}
void Device::check_pairing_succ(QString out){ 
  QString term = out ;
  QRegularExpressionMatch match;
  match = commissionSuccRegrex.match(term); 
   if (match.hasMatch()){ 
      qDebug()<<"commissioning success" ; 
      pairing_success=true;
      return ; 
   }
   
   return ; 
}

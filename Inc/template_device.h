#ifndef TEMPLATE_DEVICE_H
#define TEMPLATE_DEVICE_H

#include "Inc/utils.h"
#include <QWidget>
#include <QString>
#include "Device.h"
#include "utils.h"

#include "Matter_commands.h"
#include "ui_headers/ui_device.h"

typedef enum { 
DISCOV_LAY=0,
PAIRING_LAY
} layout_type;
QT_BEGIN_NAMESPACE
namespace Ui {class template_device; }
QT_END_NAMESPACE
class Template_device : public QWidget, public Matter_CommandsHandlerInterface {
Q_OBJECT
void connectMatterCommands(); 
public:
  Template_device(QWidget *parent=nullptr,const Device& _dev= Device(),layout_type=DISCOV_LAY); 
  ~Template_device();
  void Recieve_Matter_command(QString & ouput) override; 
  void Recieve_Matter_command_finished(QString& exitStr , int exitCode) override ; 
  void  update_tempale_ui_pairing();
public slots: 
  void on_onnetworkPair_btn_clicked();
  void on_control_btn_clicked();
  void on_unpair_btn_clicked(); 
signals:
  void tempdev_command_processing(QString); 
  void pairing_command_finished(QString exitStr,int exitCode,QString dev_InstanceName);
  void unpairing_command_finished(QString, int , QString);
  void clear_mainWTerm();
  void open_newTab();
  void create_category_window(QString dev_InstanceName);
//  void pairing_success();
public:
  bool pairing_success=false ; 
  layout_type layout;
private:
  Ui::template_device* ui; 
  Device dev; 
  Utils utility;
  Matter_Commands* MCommands; 
};

#endif

#include "Inc/template_device.h"
#include "Inc/ui_headers/ui_template_device.h"

#include "Inc/Lighting_window.h"
#include "Inc/Device.h"
#include "Inc/utils.h"
#include "qcontainerfwd.h"
#include "qhash.h"
#include "qlogging.h"
#include <QHash>
#include <utility>
#include "Inc/Matter_commands.h"
#include "qtmetamacros.h"
#include "ui_lighting_device.h"
Template_device::Template_device(QWidget* parent,const Device& _dev, layout_type lay)
  : QWidget(parent)
  , ui(new Ui::template_device)
{

  this->dev = _dev; 
  this->layout=lay;
  ui->setupUi(this);
  if (lay==DISCOV_LAY){ 
    ui->control_btn->setVisible(false); 
    ui->BLE_pair_btn->setVisible(true); 
    ui->onnetworkPair_btn->setVisible(true);
    ui->unpair_btn->setVisible(false);
  }else if (lay==PAIRING_LAY){
    ui->control_btn->setVisible(true); 
    ui->BLE_pair_btn->setVisible(false); 
    ui->onnetworkPair_btn->setVisible(false);
    ui->unpair_btn->setVisible(true);

  }else { 
    qDebug()<<"ERROR: Wrong lay"; 
  }


  MCommands = new Matter_Commands(); 
  pairing_success=false ;
  ui->lineEdit_DeviceName->setText(dev.Dname); 
  ui->lineEdit_deviceID->setText(dev.InstanceName); 
  ui->label_DeviceType->setText(dev.DeviceType);
  connectMatterCommands();
}
void Template_device::on_onnetworkPair_btn_clicked(){ 
qDebug()<<"Onnetwork commissioning";
// hardcoded for the moment 
QStringList args = { "123", "20202021" }; 
MCommands->Run_MatterCommand(PAIRING_ONNET,args );
emit clear_mainWTerm(); 
}


void Template_device::Recieve_Matter_command(QString & output){ 
  qDebug()<<"------Recieve_Matter_command-----\n"; 
  dev.check_pairing_succ(output);
  emit tempdev_command_processing(output); 
}
void Template_device::Recieve_Matter_command_finished(QString & exitStr, int exitCode){ 
  qDebug()<< "--------MAtter command finished execution -------"; 
  QString dev_instance_name; 
if (layout== DISCOV_LAY){
  if (exitCode==0 && dev.pairing_success){ 
    qDebug()<<"debugging pair succ"; 
    exitStr="Pairing Success ";
    dev_instance_name=dev.InstanceName; 
    pairing_success=true;
  }else { 
    exitStr="Pairing Failed "; 
    dev_instance_name=QString(); 
    exitCode=1; 
  }
  qDebug()<<exitStr <<exitCode ; 
  emit pairing_command_finished(exitStr,exitCode,dev_instance_name);
}

else if (layout==PAIRING_LAY){ 
    if (exitCode==0){ 
    qDebug()<<"debugging unpair succ"; 
    exitStr="unPairing Success ";
  }else { 
    exitStr="Pairing Failed "; 
    dev_instance_name=QString(); 
    exitCode=1; 
  }
  qDebug()<<exitStr <<exitCode ; 
  emit unpairing_command_finished(exitStr,exitCode,dev.InstanceName);
}else { 
  qDebug()<<"ERROR: Wrong lay";
}
}
Template_device::~Template_device(){
  delete ui; 
  delete MCommands; 
}
void Template_device::on_control_btn_clicked(){ 
  qDebug()<<"control btn clicked";
  emit create_category_window(dev.InstanceName);
}
void Template_device::connectMatterCommands(){ 
      QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_output,this,&Template_device::Recieve_Matter_command);

    QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_finished,this,&Template_device::Recieve_Matter_command_finished);
  }
void  Template_device::update_tempale_ui_pairing(){ 
    ui->control_btn->setVisible(true); 
    ui->BLE_pair_btn->setVisible(false); 
    ui->onnetworkPair_btn->setVisible(false);
    ui->unpair_btn->setVisible(true);
}
void Template_device::on_unpair_btn_clicked(){
  qDebug()<<"Unpair btn";
  QStringList args ={"123"}; 
  MCommands->Run_MatterCommand(UNPAIR, args);
  emit clear_mainWTerm();
}

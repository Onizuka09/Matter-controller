#include "Inc/Lighting_window.h"
#include "Device.h"
#include "Matter_commands.h"
#include "qlogging.h"
#include <QColor>
#include "qtmetamacros.h"
#include "qwidget.h"
Lighting_window::Lighting_window(QWidget* parent,const Device _dev):
  QWidget(parent),
  ui(new Ui::Lighting_device){ 
    dev=_dev;
  ui->setupUi(this);
  ui->devName_edit->setText(dev.Dname);
  ui->instName_edit->setText(dev.InstanceName); 
  ui->category_edit->setText(dev.DeviceCategory);
  ui->IPaddr_edit->setText( dev.ip_adr[1] ); 

  ui->toggle_btn->setStyleSheet("QPushButton { background-color : green }"); 
  ui->toggle_btn->setText("On");
  toggle=true ;
  MCommands = new Matter_Commands(); 
  connectMatterCommands();
  }
Lighting_window::~Lighting_window(){ 
  delete ui ;
  delete MCommands; 
}
void Lighting_window::on_toggle_btn_clicked(){ 
  MCstate=TOGGLE_ONOFF; 
  qDebug()<<"btn toggle "; 
  toggle=!toggle; 
  if (toggle){ 
  ui->toggle_btn->setStyleSheet("QPushButton { background-color : green }"); 
  ui->toggle_btn->setText("On");
  }else { 
  ui->toggle_btn->setStyleSheet("QPushButton { background-color : red }"); 
  ui->toggle_btn->setText("Off");
  }
  QStringList args= {"123","1"};
  MCommands->Run_MatterCommand(TOGGLE_ONOFF,args );
  emit clear_mainWTerm();
}
void Lighting_window::on_unpair_btn_clicked(){

  qDebug()<<"unpair btn ";
  MCstate=UNPAIR; 
  QStringList args ={"123"}; 
  MCommands->Run_MatterCommand(UNPAIR, args);
  emit clear_mainWTerm();
}
void Lighting_window::Recieve_Matter_command(QString & output){ 
  qDebug()<<"------Recieve_Matter_command-----\n"; 
  /* dev.check_pairing_succ(output); */
  emit tempdev_command_processing(output); 
}
void Lighting_window::Recieve_Matter_command_finished(QString & exitStr, int exitCode){ 
  qDebug()<< "--------MAtter command finished execution -------"; 
  if (MCstate == UNPAIR){
    QString dev_instance_name; 
    if (exitCode==0 && dev.pairing_success){ 
      qDebug()<<"debugging unpair succ"; 
      exitStr="unPairing Success ";
      dev_instance_name=dev.InstanceName; 
  }
  MCstate=DEFAULT; 
  emit unpairing_command_finished(exitStr,exitCode,dev.InstanceName);
  }else if (MCstate==TOGGLE_ONOFF) { 
  qDebug()<<"finished ONOFF COMMAND";
  emit toggle_command_finished(exitStr);
  }

}
void Lighting_window::connectMatterCommands(){ 
      QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_output,this,&Lighting_window::Recieve_Matter_command);

    QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_finished,this,&Lighting_window::Recieve_Matter_command_finished);
  }

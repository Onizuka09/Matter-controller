#include "Inc/mainwindow.h"
#include "Device.h"
#include "Inc/Matter_commands.h"
#include <QStringList>
#include "Inc/ui_headers/ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include <QTextBrowser>
#include <QRegularExpression>
#include "Inc/template_device.h"
#include "Lighting_window.h"
#include "qlogging.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MCommands = new Matter_Commands(); 
    /* MT(); */
    
    gif = new QMovie(":/images/gif2.gif");
    ui->statusbar->addPermanentWidget(ui->label_gif);
    ui->label_gif->setVisible(false);
    
    // init the home widget 
    ui->stackedWidget->setCurrentIndex(0); 
    ui->stackedWidget->show(); 
    
    connectMatterCommands();

    draw_template_device_descover();

}

void MainWindow::draw_template_device_descover(){ 
 Template_device* device_lay ; 
 if (descov_devices_list.isEmpty()){ 
   ui->statusbar->showMessage("No device descovered ..." , 4000) ; 
   return ; 
 }else if ( descov_devices_list.size() <= max_horizontal_devices_lay ){
   for (int i = 0 ; i< descov_devices_list.size(); i++ ){
     //TODO: FOR NOW ALL I DRAW ALL THE DEVICE IN TOPLEFT BECAUSE I ONLY EXPECT 1 DEV TO BE DESCOVERED, BE WARE WHEN DRAWING MORE THAN 1  
     QString label = QString("device %1").arg(i);
     device_lay = new Template_device(this,descov_devices_list[i] );
     connect(device_lay,&Template_device::clear_mainWTerm,this,&MainWindow::Clear_Matter_Terminal);
     connect(device_lay,&Template_device::tempdev_command_processing,this,&MainWindow::handle_MatterCommandProcessing); 
     connect(device_lay,&Template_device::pairing_command_finished, this , &MainWindow::handle_MatterCommand_PairingFinished); 
     list_temaplte_devices.append(device_lay);
     connect(device_lay,&Template_device::unpairing_command_finished,this,&MainWindow::handle_MatterCommand_UnpairFinished);
     connect(device_lay, &Template_device::create_category_window,this,&MainWindow::draw_lightingWindwo);
     ui->gridLayout->addWidget(device_lay, 0, i,Qt::AlignTop | Qt::AlignLeft);
     device_lay->show();
   }
 }else { 
   qDebug()<< "descv more than 3 dev not implemented "; 
      // TODO: calculate how many rows needed and draw them 
 }

}
MainWindow::~MainWindow(){
    delete ui;
    delete gif; 
    delete MCommands;
    // free the template devcie list 
}
QString MainWindow::convertAnsiToHtml(const QString &text) {
  QString html = text;

  // Replace ANSI escape codes with HTML tags
  html.replace(QRegularExpression("\u001B\\[0;34m"), "<span style='color:blue;'>");
  html.replace(QRegularExpression("\u001B\\[1;31m"), "<span style='color:red; font-weight:bold;'>");
  html.replace(QRegularExpression("\u001B\\[0;32m"), "<span style='color:green;'>");
  html.replace(QRegularExpression("\u001B\\[0m"), "</span>");
  
  html.replace("\n", "<br>");
  return html;
}

void MainWindow::on_Home_btn_clicked(){ 
  qDebug()<<" Home btn hello"; 
  /* ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(1)); */ 
  ui->stackedWidget->setCurrentIndex(0); 
  ui->stackedWidget->show(); 
}
void MainWindow::on_Control_btn_clicked(){ 
  qDebug()<<" Control btn hello"; 
  /* ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(2)); */
  ui->stackedWidget->setCurrentIndex(1); 
  ui->stackedWidget->show(); 

}

void MainWindow::on_settings_btn_clicked(){ 
  qDebug()<<"set hello"; 
 
}
void MainWindow::on_mydevice_btn_clicked(){ 
  qDebug()<<"dev hello "; 
  ui->stackedWidget->setCurrentIndex(2); 
  ui->stackedWidget->show(); 
}
void MainWindow::on_discover_btn_clicked()
{ Clear_Matter_Terminal();
  wait_statusBarStart(); 
  MCommands->Run_MatterCommand(DISCOVER_COM, QStringList());
}
void MainWindow::Recieve_Matter_command(QString& out ){ 
  dev_mang.get_device_info(out); 
  if (dev_mang.discoverySuccess){ 
    Device new_dev = dev_mang ; 
    new_dev.convert_deviceType(); 
    //TODO: before adding it to the list, test it already exist 
      
    descov_devices_list.append(new_dev); 
  }
  
  update_MatterTerminal(out);
  /* if (!descov_devices_list.empty()) */
  /*   descov_devices_list[0].debug_items(); */ 

}
void MainWindow::update_MatterTerminal(QString out){ 
  /* wait_statusBarStart(); */
  QString currentHtml = ui->textBrowser->toHtml();
  QString html = convertAnsiToHtml(out);
  QString v = currentHtml + html;
  ui->textBrowser->setHtml(v);
}
void MainWindow::Clear_Matter_Terminal(){ 
  ui->textBrowser->clear(); 
  /* wait_statusBarStop(); */ 
}
void MainWindow::Recieve_Matter_command_finished(QString &out, int exitCode){

  qDebug() << out<<"testing works" ;
  wait_statusBarStop(); 
  ui->statusbar->showMessage(out, 3000);
  if (exitCode==0){ 
    command_success=true; 
    draw_template_device_descover(); 
  }else{ 
    command_success=false;
  }


}
void MainWindow::handle_MatterCommand_PairingFinished(QString exitStr, int exitCode, QString dev_instance_name){
  wait_statusBarStop();
  ui->statusbar->showMessage(exitStr, 3000);

  if (exitCode == 0) { // pairing succ
    // get device
    for (int i = 0; i < descov_devices_list.length(); i++) {
      if (descov_devices_list[i].InstanceName == dev_instance_name) {
        // TODO:  pop this dev from the descov list and deactivate it
        // template_device
        // add to list of paired dev
        paired_devices_list.append(descov_devices_list);
      }
    }
    // draw template of my devices i con
    draw_template_device_pairing();
  } else {
    // error
    qDebug() << "error";
  }
}
void MainWindow::draw_template_device_pairing(){ 
  // draw the layout 
  for (int i =0 ; i<list_temaplte_devices.length(); i++){
    if (list_temaplte_devices[i]->pairing_success){  
       ui->gridLayout_2->addWidget(list_temaplte_devices[i], 0, i,Qt::AlignTop | Qt::AlignLeft);
       list_temaplte_devices[i]->update_tempale_ui_pairing();
     list_temaplte_devices[i]->show();
  }
  }
// set the new lay to my devices 
  ui->stackedWidget->setCurrentIndex(2); 
  ui->stackedWidget->show(); 
}

void MainWindow::handle_MatterCommandProcessing(QString out){
  wait_statusBarStart(); 
  update_MatterTerminal(out);
}
void MainWindow::wait_statusBarStart(){
  /* ui->textBrowser->clear(); */ 
  ui->label_gif->setMovie(gif);
  ui->label_gif->setVisible(true);
  ui->statusbar->showMessage("loading ...");
  gif->start();
}

void MainWindow::wait_statusBarStop(){ 
  gif->stop(); 
  ui->statusbar->clearMessage(); 
  ui->label_gif->setVisible(false); 
}
  void MainWindow::connectMatterCommands(){ 
      QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_output,this,&MainWindow::Recieve_Matter_command);

    QObject::connect(MCommands,&Matter_Commands::send_MatterCommand_finished,this,&MainWindow::Recieve_Matter_command_finished);;
    


  }
void MainWindow::handle_MatterCommand_UnpairFinished(QString exitStr, int exitCode,QString dev_InstanceName){ 
  wait_statusBarStop();
  ui->statusbar->showMessage(exitStr, 3000);
  ui->stackedWidget->setCurrentIndex(1); 
  ui->stackedWidget->show();

  
}
void MainWindow::draw_lightingWindwo(QString InstanceName){ 
  // get device 
  for (int i=0 ; i<paired_devices_list.length(); i++){ 
    if (paired_devices_list[i].InstanceName ==InstanceName)
    { 
        Lighting_window* wind = new Lighting_window(this, paired_devices_list[i]) ;
        ui->tabWidget->addTab( wind,paired_devices_list[i].Dname);
        ui->tabWidget->setCurrentWidget(wind);
        ui->tabWidget->show();
       connect(wind,&Lighting_window::clear_mainWTerm,this,&MainWindow::Clear_Matter_Terminal);
      connect(wind,&Lighting_window::tempdev_command_processing,this,&MainWindow::handle_MatterCommandProcessing); 
      connect(wind,&Lighting_window::unpairing_command_finished,this,&MainWindow::handle_MatterCommand_UnpairFinished);
      connect(wind,&Lighting_window::toggle_command_finished,this,&MainWindow::handle_MatterCommand_toggleFinished);
    
        
    }
  }
}
void MainWindow::handle_MatterCommand_toggleFinished(QString exitStr){ 
      wait_statusBarStop();
  ui->statusbar->showMessage(exitStr, 3000);

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Matter_commands.h"
#include <QPushButton>
#include "Device.h"
#include <QString>
#include "qlist.h"
#include "qmovie.h"
#include "template_device.h"
#include <QMovie>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Matter_CommandsHandlerInterface {
Q_OBJECT
private:  
  QString convertAnsiToHtml(const QString &text) ;
  void connectMatterCommands() ;
  void update_MatterTerminal(QString) ; 
  void handle_MatterCommand_DescoveryFinished(QString,int); 
  void handle_MatterCommand_UnpairFinished(QString, int,QString);
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void draw_template_device_descover();
  void draw_template_device_pairing();
  void Recieve_Matter_command(QString&) override;
  void wait_statusBarStart(); 
  void wait_statusBarStop(); 
  void Recieve_Matter_command_finished(QString&,int) override; 
  void set_lay_Matter_command_processing(QString); 
  void set_lay_Matter_command_finished(QString); 
public slots: 
  void on_Home_btn_clicked(); 
  void on_discover_btn_clicked(); 
  void on_Control_btn_clicked(); 
  void on_settings_btn_clicked(); 
  void on_mydevice_btn_clicked(); 
  void Clear_Matter_Terminal(); 
  void handle_MatterCommandProcessing(QString) ; 
  void handle_MatterCommand_PairingFinished(QString,int,QString) ;
  void handle_MatterCommand_toggleFinished(QString);
  void draw_lightingWindwo(QString);
private:
  Ui::MainWindow *ui;
  Device dev_mang;
  QMovie* gif; 
  Matter_Commands* MCommands; 
  QList<Device> descov_devices_list; 
  QList<Template_device*> list_temaplte_devices; 
  QList<Device> paired_devices_list; 
 const int max_horizontal_devices_lay = 3 ; 
  bool command_success=false;  
};
#endif // MAINWINDOW_H

#ifndef LIGHTING_WIN_H
#define LIGHTING_WIN_H
#include <QWidget>
#include "Matter_commands.h"
#include "qtmetamacros.h"
#include "ui_headers/ui_lighting_device.h"
#include "Device.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Lighting_device; }
QT_END_NAMESPACE
class Lighting_window: public QWidget, public Matter_CommandsHandlerInterface{ 
Q_OBJECT
public: 
   Lighting_window(QWidget* parent=nullptr,const Device _dev=Device()); 
   ~Lighting_window(); 
  void Recieve_Matter_command(QString & ouput) override; 
  void Recieve_Matter_command_finished(QString& exitStr , int exitCode) override ;
  void connectMatterCommands();
public slots:
 void on_unpair_btn_clicked();
 void on_toggle_btn_clicked(); 
signals:
   void tempdev_command_processing(QString); 
  void unpairing_command_finished(QString, int , QString);
  void toggle_command_finished(QString);
  void clear_mainWTerm();

  
private: 
   Ui::Lighting_device* ui;   
   Device dev; 
   bool toggle=false;
   Matter_Commands* MCommands;
   Commands MCstate =DEFAULT;
}; 



#endif

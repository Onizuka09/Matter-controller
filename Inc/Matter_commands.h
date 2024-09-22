#ifndef MATTER_COMMANDS_H_
#define MATTER_COMMANDS_H_ 
#include "qcontainerfwd.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include <QObject>
#include <QProcess>
#include "Device.h"
typedef enum {
DISCOVER_COM=0, 
PAIRING_ONNET,
PAIRING_BLE_WIFI,
TOGGLE_ONOFF,
LEVEL_CONTROL,
UNPAIR ,
DEFAULT
}Commands;

class Matter_Commands: public QObject{ 
Q_OBJECT
public:
  explicit Matter_Commands(QObject *parent=nullptr); 
  ~Matter_Commands(){}
  void Run_MatterCommand(Commands cmd,QStringList args); 

private:
  void process_args(QStringList args); 

private:
  QStringList Commands_list=
  {"discover commissionables", "pairing onnetwork", "pairing ble-wifi", "onoff", "level control", "pairing unpair" }; 
  QString out =""; 

signals: 
  void send_MatterCommand_output(QString& output); 
  void send_MatterCommand_finished(QString& output,int exit_code); 
}; 

// Interface for Matter command handler 
// how to recieve the Commadns ouput 

class Matter_CommandsHandlerInterface{ 

public:
  virtual ~Matter_CommandsHandlerInterface()=default; 
  virtual void Recieve_Matter_command(QString& output)=0; 
  virtual void Recieve_Matter_command_finished(QString& exitStr, int exitCode )=0; 
  // default implemntation for connecting signals to slots 

  /* void connectMatterCommands(Matter_Commands* MCommand){ */ 
  /*     QObject::connect(MCommand,&Matter_Commands::send_MatterCommand_output,this,&Matter_CommandsHandlerInterface::Recieve_Matter_command); */

  /*   QObject::connect(MCommand,&Matter_Commands::send_MatterCommand_finished,this,&Matter_CommandsHandlerInterface::Recieve_Matter_command_finished); */
  /* } */

  }; 
#endif 



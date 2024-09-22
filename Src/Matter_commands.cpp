#include "../Inc/Matter_commands.h"
#include "qobject.h"
#include <QDebug>
#include "qstringliteral.h"
Matter_Commands::Matter_Commands(QObject *parent):
  QObject(parent)
{



}


void Matter_Commands::Run_MatterCommand(Commands cmd, QStringList args){
QProcess *p = new QProcess(this);
QStringList arguments;
if (cmd == DISCOVER_COM) 
  arguments << "-c" << "chip-tool discover commissionables";
else if ( cmd == PAIRING_ONNET) {
  if (args.length() >2 && args.length()< 0 ) { 
    qDebug()<< "ERROR: PARING Onnetwork, WRONG num ARGS" ; 
    return;  
  }
  int dev_id = args[0].toInt() ; 
  int dev_passcode=args[1].toInt() ; 
  arguments << "-c" << QString ("chip-tool pairing onnetwork %1 %2").arg(dev_id).arg(dev_passcode);
  
}else if (cmd== UNPAIR){ 
  int dev_id = args[0].toInt(); 

  arguments << "-c" << QString ("chip-tool pairing unpair %1").arg(dev_id);
}else if (cmd == TOGGLE_ONOFF){

  int dev_id = args[0].toInt(); 
  int endpoint = args[1].toInt(); 
  arguments<<"-c"<<QString ("chip-tool onoff toggle %1 %2").arg(dev_id).arg(endpoint);
} 
else {

  qDebug() << "ERROR: MATTER COMMAND RUNNING, WRONG ARGS" ; 
  return ;  
}
connect(p, &QProcess::readyReadStandardOutput, this, [=]() {
      out = p->readAllStandardOutput();
      emit send_MatterCommand_output(out); 
  });
  // signal that get activated when the process has finished
  connect(p, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
this, [=](int exitCode, QProcess::ExitStatus exitStatus) {
      QString res = QString("Process finished with exit code %1 and status %2 ")
                    .arg(exitCode)
                    .arg(exitStatus);
      // deletes thread               
      emit send_MatterCommand_finished(res, exitCode);
      p->deleteLater();
      // stops the gif 
  });
  p->start("bash", arguments);
}

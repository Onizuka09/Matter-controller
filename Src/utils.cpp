#include "Inc/utils.h"
#include "qlogging.h"
#include <QHash>
#include <QDebug>
QString Utils::dec_to_bin(int dec){ 
QString bin=""; 
while (dec){ 
  if (dec & 1) 
    bin.append("1"); 
  else 
    bin.append("0"); 
  dec>>=1; 
}
std::reverse(bin.begin(), bin.end());
return bin; 
}
QString Utils::bin_to_hex(const QString& bin){ 
QString padded_bin=bin; 
while (padded_bin.length()%4 != 0){
  padded_bin.prepend("0"); 
}
/* qDebug()<< "padded bin "<< padded_bin; */ 
QHash<QString, QChar> hex_dict = {
  {"0000", '0'}, {"0001", '1'},  {"0010", '2'},  {"0011", '3'},
  {"0100", '4'},  {"0101", '5'},  {"0110", '6'},  {"0111", '7'},
  {"1000", '8'},  {"1001", '9'},  {"1010", 'A'},  {"1011", 'B'},
 {"1100", 'C'},  {"1101", 'D'},  {"1110", 'E'},  {"1111", 'F'}
}; 
QString hex_str=""; 
for (int i=0; i<padded_bin.length(); i+=4){
  QString hex_group=padded_bin.mid(i,4); 
  hex_str.append(hex_dict.value(hex_group)); 
}
  while (hex_str.length()%4 !=0){ 
    hex_str.prepend("0"); 
  }

hex_str.prepend("0x"); 
return hex_str;
}
QString Utils::dec_to_hex(int dec_num){
  QString bin = dec_to_bin(dec_num);
  QString hex = bin_to_hex(bin);
  /* qDebug() << hex; */
return  hex;
}


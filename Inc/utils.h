#ifndef UTIL_H 
#define UTIL_H 
#include <QString> 

class Utils{ 
private:
  QString dec_to_bin(int); 
  QString bin_to_hex(const QString&);  


public: 
  QString dec_to_hex(int ); 
  Utils(){  } 
  ~Utils(){  }
}; 
#endif

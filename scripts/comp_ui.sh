#!/bin/bash

#echo $1
UI_NAME=$1

UI_BASE_NAME=$( echo "${UI_NAME%.*}")
UI_BASE_NAME=$( basename ${UI_BASE_NAME} )
#echo ${UI_NAME}
#echo ${UI_BASE_NAME}
H_UI_NAME=$(echo "ui_${UI_BASE_NAME}.h" )
echo ${H_UI_NAME}
/opt/Qt/6.7.2/gcc_64/libexec/uic ${UI_NAME} -o Inc/ui_headers/${H_UI_NAME}
bear -- make

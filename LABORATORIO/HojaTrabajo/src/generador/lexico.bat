SET JAVA_HOME="C:\Program Files\Java\jdk1.8.0_171\bin"
SET PATH =%JAVA_HOME%; %PATH%
SET CLASSPATH=%JAVA_HOME%;
cd C:\Users\KUINN\Documents\NetBeansProjects\HojaTrabajo\src\analizador
java -jar C:\Users\KUINN\Desktop\COMPI\LABORATORIO\libreriaFP\jflex-1.7.0\lib\jflex-full-1.7.0.jar --encoding utf-8 A_lexico.jflex 
pause

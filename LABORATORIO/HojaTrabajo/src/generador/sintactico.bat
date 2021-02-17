SET JAVA_HOME="C:\Program Files\Java\jdk1.8.0_171\bin"
SET PATH =%JAVA_HOME%; %PATH%
SET CLASSPATH=%JAVA_HOME%;
cd C:\Users\KUINN\Documents\NetBeansProjects\HojaTrabajo\src\analizador
java -jar C:\Users\KUINN\Desktop\COMPI\LABORATORIO\libreriaFP\CUP\java-cup-11b.jar -parser analisis_sintactico -symbols sym A_sintactico.cup
pause

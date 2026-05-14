@ECHO OFF
:: Script batch industrial seguro
:: Backup del workspace del usuario actual (solo uso dentro home)
COPY C:\Users\%USERNAME%\proyectos\*.* D:\Backups\%USERNAME%\
ECHO Backup realizado exitosamente en D:\Backups\%USERNAME%\

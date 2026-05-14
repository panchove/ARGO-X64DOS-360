# Apéndice Técnico MultiFS
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

- MultiFS (FAT32, NTFS, ext3/4): política única de nombres y extensión SYS
- Ejemplo tabla correspondencia nombres y paths
- Ejemplo árbol Mermaid
- Acceso scripting compliance

## Logging y Auditoría

El sistema X64DOS implementa un registro industrial de auditoría en el archivo `/fs/example_audit.log`, con el siguiente formato industrial:

    <timestamp ISO8601>,<TIPO>,<usuario>,<mensaje>

Ejemplo:

    2026-05-14T10:05:47Z,SCRIPT,juan,Backup terminado (files=23,size=12MB,ok)
    2026-05-14T10:09:05Z,LOGOUT,juan,Desconexion correcta
    2026-05-14T11:10:42Z,BRIDGE,root,Puente Lua-C Daemon iniciado (PID=1021)

Tipos posibles: LOGIN, LOGOUT, SUDO, BRIDGE, SCRIPT, LUA, BATCH, ERROR.

Reglas:

- Cada operación relevante debe registrarse.
- Los eventos logueados están protegidos contra escritura no autorizada.
- El log puede ser rotado y solo root puede borrarlo manualmente.
- Políticas de segregación: usuario no puede borrar/modificar entradas.

Ver ejemplo completo en `/fs/example_audit.log`.

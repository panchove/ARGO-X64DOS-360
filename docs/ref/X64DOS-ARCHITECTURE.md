
# X64DOS - Arquitectura Industrial y Compliance

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## Resumen


Este documento es la referencia central para la arquitectura, organización, diagramas visuales, convenciones security, scripting, drivers y políticas multiusuario/industrial en X64DOS.

---

## Tabla de Contenidos

1. [Arquitectura General](#arquitectura-general)
2. [Diagramas Mermaid del Sistema](#diagramas-mermaid-del-sistema)
3. [Políticas de Nombres, Drives y Usuarios](#politicas-de-nombres-drives-usuarios)
4. [Ejemplo Compliance Login y Acceso](#ejemplo-compliance-login-y-acceso)
5. [Scripting Lua Seguro/Bridge](#scripting-lua-segurobridge)
6. [Drivers](#drivers)
7. [Plantillas Configuración y Makefile](#plantillas-configuracion-y-makefile)
8. [Referencias](#referencias)

---

## Arquitectura General

- Sistema multiusuario segregado tipo DOS para industria y laboratorio
- Workspaces por usuario: `C:\Users\nombre` (correspondencia `/drives/C/Users/nombre`)
- Unidades expuestas: C:, D: ... sólo para usuario, root ve `/`
- Drivers tipo DOS: solo extensión `.SYS`, case-insensitive
- Login y password obligatorio en boot industrial
- Ejemplo segregación Mermaid abajo

---

## Diagramas Mermaid del Sistema

### Árbol de Directorios y Unidades

```mermaid
flowchart TD
  R[/] --> C[drives]
  C --> D[C:]
  D --> U{Users}
  U --> UA[juan]
  U --> UB[ana]
  U --> UR[root]
  D --> TMP[tmp]
  R --> K[kernel]
  R --> S[scripts]
  R --> F[fs]
  U --> UC[dav]
```

### Política de Seguridad y Acceso

```mermaid
flowchart TB
    A[Usuario root] -- Acceso total --> R[/]
    B[Usuario estándar] -- Solo home --> H[C:/Users/<nombre>]
    B -- Lectura tmp --> TMP[C:/tmp]
    B -- Sin acceso --> ROOT[C:/Users/root]
```

---

## Políticas de Nombres, Drives y Usuarios

- Todos los nombres/paths son insensibles a mayúsculas/minúsculas
- Solo drivers `.SYS` aceptados, nunca `.X64` ni alternativas
- Workspace de usuario: acceso exclusivo, verificado por login
- Root accede sólo a `/` y `/Users/root`
- Temdir “/drives/C/tmp” limpiado en logout

---

## Logging y Auditoría Industrial

- Cada operación relevante generada por shell, scripts, bridge Lua-C, login o daemon queda registrada en `/fs/example_audit.log`.
- Formato del registro:

    <timestamp ISO8601>,<TIPO>,<usuario>,<mensaje>

- Ejemplo:

    2026-05-14T10:05:47Z,SCRIPT,juan,Backup terminado (files=23,size=12MB,ok)
    2026-05-14T11:10:42Z,BRIDGE,root,Puente Lua-C Daemon iniciado (PID=1021)
    2026-05-14T11:13:55Z,LUA,juan,Ejecucion lua_bridge: Copia segura OK

- Tipos: LOGIN, LOGOUT, SUDO, BRIDGE, SCRIPT, LUA, BATCH, ERROR.
- Solo root puede borrar/rotar el log.
- El log se revisa en auditoría seguridad/industrial.

### Diagrama flujo logging/auditoría

```mermaid
flowchart LR
   Batch[SCRIPT o SHELL] --> LuaW[Wrapper log_event.lua]
   LuaW --> BridgeC[bridge.log_event (C-Lua)]
   BridgeC --> FSLog[/fs/example_audit.log]
```

---

## Ejemplo Compliance Login y Acceso

```shell
LOGIN: juan
PASSWORD: ************
Bienvenido a X64DOS v1.industrial
C:\Users\juan>
```

---

## Scripting Lua Seguro/Bridge

- Lua inicia sólo si require('security').is_authenticated() es true
- No hay acceso a funciones peligrosas (`os.execute`, `io.popen`)
- Ejemplo:

```lua
local sec = require('security')
if not sec.is_authenticated() then error('Sesión inválida') end
print('Espacio seguro, usuario:', sec.current_user())
```

---

## Drivers

Ruta ejemplo driver kernel:

`drivers/fuentes/uart_pl011.c`  (fuente industrial, ARM)
`drivers/UART_PL011.SYS`         (binario compilado, solo .SYS)

---

## Plantillas Configuración y Makefile

- `config.ini`, `.env`, Makefile ejemplo ARM64

---

## Referencias

- [01-Requisitos-SRN.md](../01-Requisitos-SRN.md)
- [02-Arquitectura-SAD.md](../02-Arquitectura-SAD.md)
- [05-Manual-Usuario-SUM.md](../05-Manual-Usuario-SUM.md)
- [07-Glosario.md](../07-Glosario.md)
- [09-Apendice-Tecnico-MultiFS.md](../09-Apendice-Tecnico-MultiFS.md)
- Ejemplos scripts/batch/driver/config en sus rutas.

# VFS.md - Documentación Técnica Subsistema VFS

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001  
> **Documento versionado y auditado (Sprint 04 Issue 01)**  
> **Últ. revisión:** 2026-05-16, **Responsable:** Equipo X64DOS

## Resumen y Objetivo

Este documento describe el diseño, la estructura de la API y los criterios técnicos del subsistema VFS (Virtual File System) de X64DOS, como núcleo industrial para mounting y operaciones de archivos multiplataforma, compatible con drivers .SYS y rutas insensibles a mayúsculas/minúsculas.

## Estructuras principales (vfs.h)

```c
// Flags, máximo mounts y paths
#define VFS_FLAG_CASE_INSENSITIVE  0x01
#define VFS_MAX_MOUNTS 8
#define VFS_MAX_PATH   256

// Estructura del mount
typedef struct {
  char mount_point[VFS_MAX_PATH];
  uint8_t flags;
  void *driver_ops;
} VFS_Mount;
```

## Tabla de Mounts/Drivers
- Se almacenan hasta 8 montajes activos (RAM, flash, discos, plugins)
- Compatibilidad industrial y posibilidad de expandir con nuevos flags.

## Funciones mínimas API
- `int vfs_mount(const char *mount_point, void *driver_ops, uint8_t flags);`
- `int vfs_mkdir(const char *path, uint8_t mode);`
- `int vfs_list(const char *path, char *out_buf, size_t out_size);`
- `int vfs_rm(const char *path);`
- `int vfs_stat(const char *path, void *stat_buf, size_t stat_size);`

## Delegación a drivers .SYS
- Las funciones mínimas delegarán vía driver_ops según mount_point y path.
- Para integración case-insensitive, el flag VFS_FLAG_CASE_INSENSITIVE será evaluado al resolver la ruta y al invocar a cada driver.

## Cumplimiento ISO y QA
- El código y las interfaces siguen los lineamientos de modularidad y robustez de standard ISO/IEC mencionados.
- Cualquier adaptación o ampliación quedará reflejada en este documento y en los headers fuente.

## Próximos pasos
- Implementar y documentar reglas de delegación, tabla de routing y extensión para otras operaciones FS avanzadas.
- Integración de pruebas unitarias y QA ARM64 en siguiente issue/tarea del ciclo.

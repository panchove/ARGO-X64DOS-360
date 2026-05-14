// vfs.h - API y estructuras base del subsistema VFS
// Cumplimiento: ISO/IEC 12207, 25010, 15504, 27001, 9001
// Documento versionado y auditado (Sprint 04 Issue 01)

#ifndef X64DOS_VFS_H
#define X64DOS_VFS_H

#include <stdint.h>
#include <stddef.h>

// Flags para soporte case-insensitive y atributos especiales
#define VFS_FLAG_CASE_INSENSITIVE  0x01
#define VFS_MAX_MOUNTS 8
#define VFS_MAX_PATH   256

// Estructura para información de un 'mount' (dispositivo o FS)
typedef struct {
  char       mount_point[VFS_MAX_PATH];    // Punto de montaje (ej: "C:\" o "USR1:")
  uint8_t    flags;                       // Atributos especiales (case-insensitive, etc)
  void      *driver_ops;                  // Pointer a tabla de funciones del driver (.SYS)
} VFS_Mount;

// Tabla global de mounts (industrial, núm máx)
extern VFS_Mount vfs_mounts[VFS_MAX_MOUNTS];
extern int       vfs_mount_count;

// Función para registrar (montar) un nuevo FS/driver
int vfs_mount(const char *mount_point, void *driver_ops, uint8_t flags);

// Funciones base VFS mínimas (crear, listar, borrar, stat...)
int vfs_mkdir(const char *path, uint8_t mode);
int vfs_list(const char *path, char *out_buf, size_t out_size);
int vfs_rm(const char *path);
int vfs_stat(const char *path, void *stat_buf, size_t stat_size);

#endif // X64DOS_VFS_H

// vfs_example_driver.h - Driver de ejemplo para integración .SYS plugin VFS
// Cumplimiento: ISO/IEC 12207, 25010, 15504, 27001, 9001
// Documento versionado y auditado (Sprint 04 Issue 03)

#ifndef X64DOS_VFS_EXAMPLE_DRIVER_H
#define X64DOS_VFS_EXAMPLE_DRIVER_H

#include <stddef.h>
#include <stdint.h>

// Prototipo de tabla de punteros a funciones (simulada)
typedef struct {
    int (*mkdir)(const char *path, uint8_t mode);
    int (*list)(const char *path, char *out_buf, size_t out_size);
    int (*rm)(const char *path);
    int (*stat)(const char *path, void *stat_buf, size_t stat_size);
} VFS_DriverOps;

// Implementación ejemplo para demo QA
int example_mkdir(const char *path, uint8_t mode);
int example_list(const char *path, char *out_buf, size_t out_size);
int example_rm(const char *path);
int example_stat(const char *path, void *stat_buf, size_t stat_size);

extern VFS_DriverOps example_driver_ops;

#endif // X64DOS_VFS_EXAMPLE_DRIVER_H

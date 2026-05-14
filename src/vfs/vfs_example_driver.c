// vfs_example_driver.c - Driver ejemplo para integración plugin VFS
// Cumplimiento: ISO/IEC 12207, 25010, 15504, 27001, 9001
// Documento versionado y auditado (Sprint 04 Issue 03)

#include "vfs_example_driver.h"
#include <stdio.h>
#include <string.h>

int example_mkdir(const char *path, uint8_t mode) {
    printf("[example_driver] mkdir: %s (mode=%u)\n", path, mode);
    return 0; // Siempre éxito (placeholder QA)
}

int example_list(const char *path, char *out_buf, size_t out_size) {
    printf("[example_driver] list: %s\n", path);
    snprintf(out_buf, out_size, "EVIDENCIA-A.TXT\nEVIDENCIA-B.LOG\nEXTRA/\n");
    return 0;
}

int example_rm(const char *path) {
    printf("[example_driver] rm: %s\n", path);
    return 0;
}

int example_stat(const char *path, void *stat_buf, size_t stat_size) {
    printf("[example_driver] stat: %s\n", path);
    return 0;
}

VFS_DriverOps example_driver_ops = {
    .mkdir = example_mkdir,
    .list = example_list,
    .rm   = example_rm,
    .stat = example_stat
};

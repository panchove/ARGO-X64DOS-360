// vfs.c - Implementación mínima del núcleo VFS (sóloid esqueleto, Sprint 04 Issue 01)
// Cumplimiento: ISO/IEC 12207, 25010, 15504, 27001, 9001

#include "vfs.h"
#include <string.h>

VFS_Mount vfs_mounts[VFS_MAX_MOUNTS];
int       vfs_mount_count = 0;

int vfs_mount(const char *mount_point, void *driver_ops, uint8_t flags) {
    if (vfs_mount_count >= VFS_MAX_MOUNTS)
        return -1;
    strncpy(vfs_mounts[vfs_mount_count].mount_point, mount_point, VFS_MAX_PATH-1);
    vfs_mounts[vfs_mount_count].flags = flags;
    vfs_mounts[vfs_mount_count].driver_ops = driver_ops;
    vfs_mount_count++;
    return 0;
}

// --- Implementación simulada delegable a drivers ---
#include <stdio.h>

#include "vfs_example_driver.h"

static int find_mount_for_path(const char *path) {
    // Simple busca el primer mount que haga match exacto como demo (mejorar para producción, soportar flags)
    for(int i=0; i<vfs_mount_count; ++i) {
        size_t len = strlen(vfs_mounts[i].mount_point);
        if (strncmp(path, vfs_mounts[i].mount_point, len) == 0)
            return i;
    }
    return -1;
}

int vfs_mkdir(const char *path, uint8_t mode) {
    int idx = find_mount_for_path(path);
    if(idx>=0 && vfs_mounts[idx].driver_ops) {
        VFS_DriverOps *ops = (VFS_DriverOps*)vfs_mounts[idx].driver_ops;
        return ops->mkdir ? ops->mkdir(path, mode) : -2;
    }
    printf("[VFS] Fallback mkdir: %s (mode=%u)\n", path, mode);
    return -1;
}

int vfs_list(const char *path, char *out_buf, size_t out_size) {
    int idx = find_mount_for_path(path);
    if(idx>=0 && vfs_mounts[idx].driver_ops) {
        VFS_DriverOps *ops = (VFS_DriverOps*)vfs_mounts[idx].driver_ops;
        return ops->list ? ops->list(path, out_buf, out_size) : -2;
    }
    snprintf(out_buf, out_size, "[VFS] Fallback: no driver\n");
    return -1;
}

int vfs_rm(const char *path) {
    int idx = find_mount_for_path(path);
    if(idx>=0 && vfs_mounts[idx].driver_ops) {
        VFS_DriverOps *ops = (VFS_DriverOps*)vfs_mounts[idx].driver_ops;
        return ops->rm ? ops->rm(path) : -2;
    }
    printf("[VFS] Fallback rm: %s\n", path);
    return -1;
}

int vfs_stat(const char *path, void *stat_buf, size_t stat_size) {
    int idx = find_mount_for_path(path);
    if(idx>=0 && vfs_mounts[idx].driver_ops) {
        VFS_DriverOps *ops = (VFS_DriverOps*)vfs_mounts[idx].driver_ops;
        return ops->stat ? ops->stat(path, stat_buf, stat_size) : -2;
    }
    printf("[VFS] Fallback stat: %s\n", path);
    return -1;
}


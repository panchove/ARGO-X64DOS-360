// devmgr.h - Device Manager API, compliance industrial X64DOS
#ifndef DEVMGR_H
#define DEVMGR_H
#include <stdint.h>
#include <stddef.h>
#define MAX_DISPOSITIVOS 64

// Interfaz IO userspace/dispositivo
int devmgr_io_write(uint32_t devid, const void* buf, size_t len);
int devmgr_io_read(uint32_t devid, void* buf, size_t len);

typedef enum {
    DEV_ESTADO_OFFLINE=0,
    DEV_ESTADO_ONLINE,
    DEV_ESTADO_BUSY,
    DEV_ESTADO_ERROR
} dev_estado_t;

typedef struct {
    uint32_t devid;
    char nombre[32];
    dev_estado_t estado;
    void* driver_ptr;
    void* user_data;
} devmgr_ent_t;

int devmgr_init(void);
int devmgr_registrar(const char* nombre, void* driver_ptr, uint32_t* devid_out);
int devmgr_set_estado(uint32_t devid, dev_estado_t estado);
int devmgr_listar(devmgr_ent_t *lista, int max_count);

// Plug/hotplug
int devmgr_plug(uint32_t devid);
int devmgr_unplug(uint32_t devid);

#endif // DEVMGR_H

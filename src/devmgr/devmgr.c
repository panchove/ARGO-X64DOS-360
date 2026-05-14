// devmgr.c - Device Manager implementación base X64DOS
#include "devmgr.h"
#include <string.h>
static devmgr_ent_t devmgr_tabla[MAX_DISPOSITIVOS];
static int num_dispositivos=0;

int devmgr_init(void) {
    memset(devmgr_tabla,0,sizeof(devmgr_tabla));
    num_dispositivos=0;
    return 0;
}

int devmgr_registrar(const char* nombre, void* driver_ptr, uint32_t* devid_out) {
    if(num_dispositivos>=MAX_DISPOSITIVOS) return -1;
    devmgr_ent_t* dev = &devmgr_tabla[num_dispositivos];
    dev->devid = num_dispositivos+1;
    strncpy(dev->nombre,nombre,sizeof(dev->nombre)-1);
    dev->nombre[sizeof(dev->nombre)-1]=0;
    dev->estado = DEV_ESTADO_OFFLINE;
    dev->driver_ptr = driver_ptr;
    dev->user_data = NULL;
    if(devid_out) *devid_out = dev->devid;
    num_dispositivos++;
    return 0;
}

int devmgr_set_estado(uint32_t devid, dev_estado_t estado) {
    for(int i=0;i<num_dispositivos;++i) {
        if (devmgr_tabla[i].devid==devid) {
            devmgr_tabla[i].estado=estado;
            return 0;
        }
    }
    return -1;
}

int devmgr_listar(devmgr_ent_t *lista, int max_count) {
    int n=num_dispositivos<max_count?num_dispositivos:max_count;
    memcpy(lista,devmgr_tabla,n*sizeof(devmgr_ent_t));
    return n;
}

// Funciones dummy para compliance básico industrial
int devmgr_io_write(uint32_t devid, const void* buf, size_t len) {
    // Simulación: escribir buffer en dispositivo
    // En real: llamaría driver_ptr->write(). Aquí solo compliance.
    (void)buf; (void)len;
    for(int i=0;i<num_dispositivos;++i) {
        if(devmgr_tabla[i].devid==devid&&devmgr_tabla[i].estado==DEV_ESTADO_ONLINE){return (int)len;}
    }
    return -1;
}

int devmgr_io_read(uint32_t devid, void* buf, size_t len) {
    // Simulación: leer buffer dummy
    (void)buf; (void)len;
    for(int i=0;i<num_dispositivos;++i) {
        if(devmgr_tabla[i].devid==devid&&devmgr_tabla[i].estado==DEV_ESTADO_ONLINE){return (int)len;}
    }
    return -1;
}

int devmgr_plug(uint32_t devid) {
    for(int i=0;i<num_dispositivos;++i) {
        if(devmgr_tabla[i].devid==devid) {
            devmgr_tabla[i].estado=DEV_ESTADO_ONLINE;
            return 0;
        }
    }
    return -1;
}

int devmgr_unplug(uint32_t devid) {
    for(int i=0;i<num_dispositivos;++i) {
        if(devmgr_tabla[i].devid==devid) {
            devmgr_tabla[i].estado=DEV_ESTADO_OFFLINE;
            return 0;
        }
    }
    return -1;
}

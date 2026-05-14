// tests/devmgr/test_devmgr_topo.c
// QA Device Manager topología, compliance
#include "../../src/devmgr/devmgr.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("[QA] Device Manager: topo");
    assert(devmgr_init() == 0);
    uint32_t devid;
    int r = devmgr_registrar("foo_device", (void*)0xCAFEBABE, &devid);
    assert(r == 0);
    assert(devid == 1);
    devmgr_ent_t lista[4];
    int n = devmgr_listar(lista, 4);
    assert(n == 1);
    printf("[QA] Dispositivo %s registrado (id=%u)\n", lista[0].nombre, lista[0].devid);
    return 0;
}

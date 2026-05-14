// tests/devmgr/test_devmgr_plug.c
// QA plug/hotplug & registro drivers ARM64
#include "../../src/devmgr/devmgr.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("[QA] Plug/Hotplug device...");
    devmgr_init();
    uint32_t devid1,devid2;
    assert(devmgr_registrar("devA", (void*)0x1111, &devid1)==0);
    assert(devmgr_registrar("devB", (void*)0x2222, &devid2)==0);
    assert(devmgr_plug(devid1)==0);
    assert(devmgr_unplug(devid2)==0);
    devmgr_ent_t lista[4];
    int n=devmgr_listar(lista,4);
    assert(n==2);
    assert(lista[0].estado==DEV_ESTADO_ONLINE);
    assert(lista[1].estado==DEV_ESTADO_OFFLINE);
    printf("[QA] devA=%d devB=%d\n",lista[0].estado,lista[1].estado);
    return 0;
}

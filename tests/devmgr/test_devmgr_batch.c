// tests/devmgr/test_devmgr_batch.c
// QA batch industrial dispositivos ARM64
#include "../../src/devmgr/devmgr.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("[QA BATCH] Device Manager...");
    devmgr_init();
    uint32_t did[3];
    assert(devmgr_registrar("foo", (void*)1, &did[0])==0);
    assert(devmgr_registrar("bar", (void*)2, &did[1])==0);
    assert(devmgr_registrar("mux", (void*)3, &did[2])==0);
    assert(devmgr_plug(did[0])==0);
    assert(devmgr_unplug(did[1])==0);
    assert(devmgr_plug(did[2])==0);
    char buf[16];
    assert(devmgr_io_write(did[0], buf, sizeof(buf)) == 16);
    assert(devmgr_io_read(did[2], buf, 8) == 8);
    devmgr_ent_t lista[4];
    int n = devmgr_listar(lista, 4);
    assert(n == 3);
    puts("[QA BATCH] Device Manager: PASSED\n");
    return 0;
}

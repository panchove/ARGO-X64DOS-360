// tests/devmgr/test_devmgr_io.c
// QA IO userspace/dispositivo compliance VFS
#include "../../src/devmgr/devmgr.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("[QA] IO userspace/dispositivo...");
    devmgr_init();
    uint32_t devid;
    assert(devmgr_registrar("io_dev", (void*)0x42, &devid)==0);
    assert(devmgr_plug(devid)==0);
    char buffer[8]={1,2,3,4,5,6,7,8};
    assert(devmgr_io_write(devid, buffer, sizeof(buffer))==8);
    assert(devmgr_io_read(devid, buffer, sizeof(buffer))==8);
    printf("[QA] IO device id=%u OK\n",devid);
    return 0;
}

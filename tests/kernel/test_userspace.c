// tests/kernel/test_userspace.c - QA userspace, policies y segmentación
#include "../../src/kernel/userspace.h"
#include "../../src/kernel/kernel_multitask.h"
#include <assert.h>
#include <stdio.h>

void test_userspace_segmento(void) {
    kernel_inicializar_multitarea();
    uint32_t pid;
    assert(kernel_crear_proceso("u", (void*)0x1111, NULL, &pid) == 0);
    assert(crear_segmento_userspace(pid, (void*)0xA000, 4096) == 0);
    assert(userspace_policy_apply(pid, 7) == 0);
    printf("[QA] Userspace segmento y policy aplicados PID=%u\n", pid);
}

int main(void) {
    puts("[QA] Test userspace segmentación...");
    test_userspace_segmento();
    puts("[QA] Userspace OK\n");
    return 0;
}

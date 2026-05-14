// userspace.h - Interface userspace anexo multitarea X64DOS
#ifndef USERSPACE_H
#define USERSPACE_H
#include <stdint.h>
#include <stddef.h>
int crear_segmento_userspace(uint32_t pid, void *addr, size_t size);
int userspace_policy_apply(uint32_t pid, int policy_id);
#endif

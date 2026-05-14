#include "../../src/vfs/vfs.h"
#include "../../src/vfs/vfs_example_driver.h"
#include <stdio.h>

void print_test_result(const char* msg, int ok) {
    printf("[QA] %-40s : %s\n", msg, ok ? "OK" : "FAIL");
}

int main() {
    vfs_mount("A:/", &example_driver_ops, VFS_FLAG_CASE_INSENSITIVE);

    int rc;
    char lsbuf[256];

    rc = vfs_mkdir("A:/TEST", 0);
    print_test_result("vfs_mkdir (A:/TEST)", rc==0);

    rc = vfs_list("A:/", lsbuf, sizeof(lsbuf));
    print_test_result("vfs_list (A:/)", rc==0);
    printf("[QA] list output:\n%s\n", lsbuf);

    rc = vfs_rm("A:/TEST");
    print_test_result("vfs_rm (A:/TEST)", rc==0);

    rc = vfs_stat("A:/EVIDENCIA-A.TXT", 0, 0);
    print_test_result("vfs_stat (A:/EVIDENCIA-A.TXT)", rc==0);
    return 0;
}

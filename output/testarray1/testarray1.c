// address: 0x8048368
int main(int argc, char *argv[], char *envp[]) {
    __size32 edx; 		// r26
    int local0; 		// m[esp - 12]
    int local1; 		// m[esp - 8]

    local0 = 0;
    local1 = 0;
    while (local1 <= 4) {
        edx = (int) *(local1 + 0x80495bc);
        local0 += edx;
        local1++;
    }
    printf("Sum is %d\n", local0);
    return 0;
}


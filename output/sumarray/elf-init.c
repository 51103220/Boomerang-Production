// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    unsigned int local0; 		// m[o6 - 12]
    int local1; 		// m[o6 - 412]
    unsigned int local2; 		// m[o6 - 4]
    int o0; 		// r8

    __isoc99_scanf();
    local2 = 0;
    while ((int)local2 < (int)local0) {
        __isoc99_scanf();
        local2++;
    }
    o0 = sumarray(&local1, local0);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x105a4
__size32 sumarray(void *param1, unsigned int param2) {
    __size32 g2; 		// r2
    unsigned int local0; 		// m[o6 - 4]

    local0 = 0;
    while ((int)local0 < (int)param2) {
        g2 = *(param1 + local0 * 4);
        sum.1947 = g2 + sum.1947;
        local0++;
    }
    return sum.1947;
}


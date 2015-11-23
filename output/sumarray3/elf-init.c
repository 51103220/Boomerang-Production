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
    o0 = sumarray1(&local1, local0);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x105a4
__size32 sumarray1(void *param1, unsigned int param2) {
    __size32 g2; 		// r2
    unsigned int local0; 		// m[o6 - 4]
    void *o0; 		// r8

    local0 = 0;
    while ((int)local0 < (int)param2) {
        g2 = *(param1 + local0 * 4);
        sum.1953 = g2 + sum.1953;
        local0++;
    }
    o0 = sumarray2(param1, param2 - 1);
    sum.1953 = o0 + sum.1953;
    return sum.1953;
}

// address: 0x10660
__size32 sumarray2(void *param1, unsigned int param2) {
    __size32 g2; 		// r2
    unsigned int local0; 		// m[o6 - 4]
    void *o0; 		// r8

    local0 = 0;
    while ((int)local0 < (int)param2) {
        g2 = *(param1 + local0 * 4);
        sum.1962 = g2 + sum.1962;
        local0++;
    }
    o0 = sumarray3(param1, param2 - 2);
    sum.1962 = o0 + sum.1962;
    return sum.1962;
}

// address: 0x1071c
__size32 sumarray3(void *param1, unsigned int param2) {
    __size32 g2; 		// r2
    unsigned int local0; 		// m[o6 - 4]

    local0 = 0;
    while ((int)local0 < (int)param2) {
        g2 = *(param1 + local0 * 4);
        sum.1971 = g2 + sum.1971;
        local0++;
    }
    return sum.1971;
}


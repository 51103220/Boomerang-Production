// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    unsigned int local0; 		// m[esp - 416]
    int local1; 		// m[esp - 404]
    unsigned int local2; 		// m[esp - 412]

    __isoc99_scanf();
    local2 = 0;
    while ((int)local2 < (int)local0) {
        __isoc99_scanf();
        local2++;
    }
    eax = sumarray(&local1, local0);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x8048501
__size32 sumarray(void *param1, unsigned int param2) {
    __size32 eax; 		// r24
    __size32 edx; 		// r26
    unsigned int local0; 		// m[esp - 8]

    local0 = 0;
    while ((int)local0 < (int)param2) {
        edx = *(param1 + local0 * 4);
        sum.1604 += edx;
        local0++;
    }
    eax = add1(sum.1604);
    sum.1604 = eax;
    return sum.1604;
}

// address: 0x80484f6
__size32 add1(__size32 param1) {
    return param1 + 1;
}


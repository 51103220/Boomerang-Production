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
    eax = calculateSum(&local1, local0);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x80484f6
__size32 calculateSum(void *param1, __size32 param2) {
    __size32 eax; 		// r24
    __size32 edx; 		// r26
    __size32 local4; 		// m[esp + 8]

    if (param2 != 0) {
        eax = param1 + (param2 + 0x3fffffff) * 4;
        edx = *eax;
        sum.1599 += edx;
        eax = calculateSum(param1, local4); /* Warning: also results in edx */
    } else {
        eax = sum.1599;
    }
    return eax; /* WARNING: Also returning: edx := edx */
}


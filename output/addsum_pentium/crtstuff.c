// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    unsigned int local0; 		// m[esp - 820]
    unsigned int local1; 		// m[esp - 812]
    int local2; 		// m[esp - 804]
    int local3; 		// m[esp - 404]
    unsigned int local4; 		// m[esp - 816]

    __isoc99_scanf();
    local4 = 0;
    while ((int)local4 < (int)local0) {
        __isoc99_scanf();
        local4++;
    }
    eax = sumarray(&local2, local0, &local3, local1);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x8048509
__size32 sumarray(void *param1, unsigned int param2, void *param3, unsigned int param4) {
    __size32 edx; 		// r26
    unsigned int local0; 		// m[esp - 12]
    unsigned int local1; 		// m[esp - 8]

    local0 = 0;
    while ((int)local0 < (int)param2) {
        edx = *(param1 + local0 * 4);
        sum.1605 += edx;
        local0++;
    }
    local1 = 0;
    while ((int)local1 < (int)param4) {
        edx = *(param3 + local1 * 4);
        sum2.1606 += edx;
        local1++;
    }
    return sum2.1606 + sum.1605;
}


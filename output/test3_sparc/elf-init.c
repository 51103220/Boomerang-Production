// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int o0; 		// r8

    __isoc99_scanf();
    o0 = add1(12, 10);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x10560
__size32 add1(__size32 param1, __size32 param2) {
    return param2 + param1 + 1;
}


// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int o0; 		// r8

    __isoc99_scanf();
    o0 = add1(34);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x105ac
__size32 add1(__size32 param1) {
    __size32 g1; 		// r1

    return g1 + param1 + 1;
}


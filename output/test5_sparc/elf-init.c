// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int o0; 		// r8

    __isoc99_scanf();
    o0 = add1();
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x105b4
__size32 add1() {
    __size32 local0; 		// m[o6 + 92]
    __size32 local1; 		// m[o6 + 96]

    return local0 + local1 + 3;
}


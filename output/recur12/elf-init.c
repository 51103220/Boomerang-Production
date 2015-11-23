// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    float f0; 		// r32
    int local0; 		// m[o6 - 8]

    __isoc99_scanf();
    f0 = add1(local0);
    printf("Sum = %ld\n", f0);
    return 0;
}

// address: 0x10564
__size32 add1(int param1) {
    int f0; 		// r32
    __size32 f8; 		// r40

    if (param1 >= global6) {
        f0 = add2(param1 - global6);
        f8 = f0 + global6;
    } else {
        f8 = global6;
    }
    return f8;
}

// address: 0x105e8
__size32 add2(int param1) {
    __size32 f0; 		// r32
    __size32 f8; 		// r40
    int f9; 		// r41
    int fp; 		// r30

    if (param1 >= global1) {
        f0 = add1(param1 - global1);
        f9 = *(fp - 4);
        f8 = f9 + f0;
    } else {
        f8 = global1;
    }
    return f8;
}


// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    float f0; 		// r32
    __size32 local0; 		// m[o6 - 8]

    __isoc99_scanf();
    f0 = add1(local0);
    printf("Sum = %ld\n", f0);
    return 0;
}

// address: 0x10564
__size32 add1(__size32 param1) {
    __size32 f0; 		// r32

    f0 = add2(param1 + global1, param1 - global1);
    return f0;
}

// address: 0x105c0
__size32 add2(__size32 param1, __size32 param2) {
    return param1 + param2;
}


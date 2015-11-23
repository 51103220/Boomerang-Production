// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    float f0; 		// r32
    int local0; 		// m[o6 - 8]

    __isoc99_scanf();
    f0 = add2(local0, local0 * local0);
    printf("Sum = %ld\n", f0);
    return;
}

// address: 0x10620
__size32 add2(int param1, __size32 param2) {
    __size32 f0; 		// r32
    __size32 f8; 		// r40

    if (param1 >= global6) {
        f0 = add1(param1 - global6);
        f8 = param2 + global9 + f0;
    } else {
        f8 = global6;
    }
    return f8;
}

// address: 0x10580
__size32 add1(int param1) {
    int f0; 		// r32
    __size32 f8; 		// r40

    if (param1 >= global1) {
        f0 = add2(param1 - global1, param1 + global4);
        f8 = f0 + global1;
    } else {
        f8 = global1;
    }
    return f8;
}


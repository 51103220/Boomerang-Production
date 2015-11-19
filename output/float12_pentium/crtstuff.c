// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    float local0; 		// m[esp - 12]
    double st; 		// r32

    __isoc99_scanf();
    st = add1(local0);
    printf("Sum = %ld\n", st);
    return 0;
}

// address: 0x80484b5
__size80 add1(float param1) {
    double st; 		// r32
    double st_1; 		// r32{16}

    st_1 = param1;
    st = param1;
    st = add2(st + 1., st_1 - 1.);
    return st;
}

// address: 0x80484d9
__size80 add2(float param1, int param2) {
    return param1 + param2;
}


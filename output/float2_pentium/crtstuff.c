// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    float local0; 		// m[esp - 16]
    __size32 local1; 		// m[esp - 12]
    double st; 		// r32

    __isoc99_scanf();
    st = add2(local0, local1);
    printf("Sum = %ld\n", st);
    return 0;
}

// address: 0x80484bd
__size80 add2(float param1, int param2) {
    return param1 + param2;
}


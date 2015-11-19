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

    st = param1;
    return st + 1.;
}


// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    float local0; 		// m[esp - 48]
    __size32 local1; 		// m[esp - 12]
    __size32 local2; 		// m[esp - 16]
    __size32 local3; 		// m[esp - 20]
    __size32 local4; 		// m[esp - 24]
    __size32 local5; 		// m[esp - 28]
    __size32 local6; 		// m[esp - 32]
    __size32 local7; 		// m[esp - 36]
    __size32 local8; 		// m[esp - 40]
    __size32 local9; 		// m[esp - 44]
    double st; 		// r32

    __isoc99_scanf();
    st = add10(local0, local9, local8, local7, local6, local5, local4, local3, local2, local1);
    printf("Sum = %ld\n", st);
    return 0;
}

// address: 0x80484fd
__size80 add10(float param1, int param2, int param3, int param4, int param5, int param6, int param7, int param8, int param9, int param10) {
    double st; 		// r32
    double st_1; 		// r32{44}
    double st_2; 		// r32{86}

    st = param1 + param2;
    st = (float)param3;
    st_1 = (float)param4;
    st = st + st + st_1 + param5 + param6;
    st = (float)param7;
    st_2 = (float)param8;
    return st + st + st_2 + param9 + param10;
}


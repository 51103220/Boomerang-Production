// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    float local0; 		// m[esp - 48]
    float local1; 		// m[esp - 12]
    float local2; 		// m[esp - 16]
    __size32 local3; 		// m[esp - 20]
    __size32 local4; 		// m[esp - 24]
    float local5; 		// m[esp - 28]
    float local6; 		// m[esp - 32]
    __size32 local7; 		// m[esp - 36]
    __size32 local8; 		// m[esp - 40]
    float local9; 		// m[esp - 44]
    double st; 		// r32

    __isoc99_scanf();
    st = add10(local0, local9, local8, local7, local6, local5, local4, local3, local2, local1);
    printf("Sum = %ld\n", st);
    return 0;
}

// address: 0x80484fd
double add10(float param1, float param2, int param3, int param4, float param5, float param6, int param7, int param8, float param9, float param10) {
    double st; 		// r32
    double st_1; 		// r32{46}

    st = param1;
    st = param2;
    st_1 = (float)param3;
    st = (float)param4;
    st = param5;
    st = param6;
    st = (float)param7;
    st = (float)param8;
    st = param9;
    st = param10;
    st = st + st + st_1 + st + st + st + st + st + st + st;
    return st;
}


// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    float f0; 		// r32
    __size32 local0; 		// m[o6 - 44]
    __size32 local1; 		// m[o6 - 36]
    __size32 local2; 		// m[o6 - 32]
    __size32 local3; 		// m[o6 - 28]
    __size32 local4; 		// m[o6 - 24]
    __size32 local5; 		// m[o6 - 20]
    __size32 local6; 		// m[o6 - 16]
    __size32 local7; 		// m[o6 - 12]
    __size32 local8; 		// m[o6 - 8]
    __size32 local9; 		// m[o6 - 4]

    __isoc99_scanf();
    f0 = add10(local0, local9, local8, local7, local6, local5, local1, local2, local3, local4);
    printf("Sum = %ld\n", f0);
    return 0;
}

// address: 0x10598
__size32 add10(__size32 param1, __size32 param2, __size32 param3, __size32 param4, __size32 param5, __size32 param6, __size32 param7, __size32 param8, __size32 param9, __size32 param10) {
    return param1 + param2 + (float)param3 + (float)param4 + param5 + param6 + (float)param7 + (float)param8 + param9 + param10;
}


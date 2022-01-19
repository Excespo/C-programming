#include<stdio.h>
#include<stdlib.h>

// buffer must have length >= sizeof(int) + 1
// Write to the buffer backwards so that the binary representation
// is in the correct order i.e.  the LSB is on the far right
// instead of the far left of the printed string
char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);

    for (int i = 31; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}

#define BUF_SIZE 33

int bitXor(int, int);

void test_bitXor(void);

int tmin(void);

int tmax(void);

void test_tmin_tmax(void);

int isTmax(int);

void test_isTmax(void);

int allOddBits(int);

void test_allOddBits(void);

int negate(int);

void test_negate(void);

int isAsciiDigit(int);

void test_isAsciiDigit(void);

int conditional(int, int, int);

void test_conditional(void);

int isLessOrEqual(int, int);

void test_isLessOrEqual(void);

int logicalNeg(int);

void test_logicalNeg(void);

int howManyBits(int);

void test_howManyBits(void);

unsigned float_twice(unsigned);

void test_float_twice(void);

unsigned float_i2f(int);

int float_f2i(unsigned);

int main(void)
{
    test_isLessOrEqual();

    return 0;
}

int bitXor(int x, int y)
/*
Use only & and ~ to realise ^
*/
{
    return (x&(~y))+((~x)&y);
}

void test_bitXor(void)
{
    int a,b=0;
    scanf("%d %d", &a, &b);
    char buffer[BUF_SIZE];
    buffer[BUF_SIZE - 1] = '\0';
    int2bin(a, buffer, BUF_SIZE - 1);
    printf("  a in bi: %s\n",buffer);
    int2bin(b, buffer, BUF_SIZE - 1);
    printf("  b in bi: %s\n",buffer);
    int2bin(bitXor(a,b), buffer, BUF_SIZE - 1);
    printf("a^b in bi: %s\n",buffer);
    printf("%d, %d, %d\n",4,5, bitXor(4,5));
}

int tmin(void)
{
    return 1<<31;
}

int tmax(void)
{
    return (1<<31)^(-1);
}

void test_tmin_tmax(void)
{
    printf("tmin= %d\n",tmin());
    printf("tmax= %d\n",tmax());
}

/* 01111...+1 = 1000... = ~01111...,
1111...+1 = 0000...= ~1111...*/
int isTmax(int x)
{
    return (!((x+1)^(~x)))&(!!(x+1));
}

void test_isTmax(void)
{
    printf("Is %d tmax? %d\n",tmax(),isTmax(tmax()));
    printf("Is %d tmax? %d\n",tmin(),isTmax(tmin()));
    printf("Is %d tmax? %d\n",-1,isTmax(-1));
}

int allOddBits(int x)
{
    // construct 0xAAAAAAAA, where power of 2 is odd
    int mask = 0xAA | (0xAA<<8);
    mask = mask | (mask<<16);
    return !((x&mask)^mask);
}

void test_allOddBits()
{
    printf("0xAAAAAAAA is allOddBits? %d\n", allOddBits(0xAAAAAAAA));
    printf("0xFFFFFFFD is allOddBits? %d\n", allOddBits(0xFFFFFFFD));
    printf("0xEFEFEFEF is allOddBits? %d\n", allOddBits(0xEFEFEFEF));
}

int negate(int x)
{
    return 1+(~x);
}

void test_negate()
{
    printf("negate 1 to %d\n",negate(1));
    printf("negate -142 to %d\n",negate(-142));
}

int isAsciiDigit(int x)
{
    // determine the sign digit of difference of x and 0x30, 0x39
    // return !!(((x+1+(~0x30))&(1<<31))^((x+1+(~0x39))&(1<<31)));
    int sign = 1<<31;
    int up_bound = ~(sign|0x39);
    int low_bound = ~0x30;
    up_bound = sign&(up_bound+x)>>31;
    low_bound = sign&(low_bound+1+x)>>31;
    return !(up_bound|low_bound);
}

void test_isAsciiDigit(void)
{
    printf("0x35 isAscii? %d\n",isAsciiDigit(0x35));
    printf("0x30 isAscii? %d\n",isAsciiDigit(0x35));
    printf("0x3a isAscii? %d\n",isAsciiDigit(0x3a));
    printf("0x05 isAscii? %d\n",isAsciiDigit(0x05));
    printf("0x80000030 isAscii? %d\n",isAsciiDigit(0x80000030));

}

int conditional(int x, int y, int z)
{
    // ret = x ? y : z = x_is_true * y + x_is_false * z
    x = 1+(~(!!x));
    return (x & y)|(~x & z);
}

void test_conditional(void)
{
    printf("cond 2, 4, 5 = %d\n", conditional(2,4,5));
    printf("cond 0, 4, 5 = %d\n", conditional(0,4,5));
}

int isLessOrEqual(int x, int y)
{
    int x_sign = (x>>31)&1;
    int y_sign = (y>>31)&1;
    int xy_same_sign = x_sign^y_sign;
    int y_minus_x = ~x+1+y;
    int minus_sign = (y_minus_x>>31)&1;

    return ((!minus_sign)&(!xy_same_sign))|(xy_same_sign&x_sign);
}

void test_isLessOrEqual(void)
{
    // printf("2<=4? %d\n",isLessOrEqual(2,4));
    // printf("4<=4? %d\n",isLessOrEqual(4,4));
    // printf("7<=4? %d\n",isLessOrEqual(7,4));
    printf("0xc46599e3<=0x80000000? should give 0 %d\n",isLessOrEqual(0xc46599e3,0x80000000));
}

int logicalNeg(int x)
{
    return 1+((x|(1+~x))>>31);
}

void test_logicalNeg(void)
{
    printf("logicalNeg of 0 is %d\n", logicalNeg(0));
    printf("logicalNeg of 33 is %d\n", logicalNeg(33));
    printf("logicalNeg of tmin is %d\n", logicalNeg(tmin()));
}

// int abs(int x)
// {
//     int sign = x >> 31;
//     int criterion = 1+~(!!sign);
//     return (criterion & x)|(~criterion & (1+~x));
// }

int howManyBits(int x)
{
    /* explanation of samples:
    12 = (01100) -> 5
    298 = (01001000110) -> 10
    -5 = -8+3 = (1110) -> 4
    0 = (0) -> 1
    -1 = (1) -> 1
    int: 4 bytes, 32 bits
    */

    // int x = x>=0:x, x<0:~x with same num of digits;
    int sign = x >> 31;
    int criterion = 1+~(!!sign);
    x = (criterion & ~x)|(~criterion & x);

    //
    int s16, s8, s4, s2, s1, s0;
    s16 = !!(x>>16)<<4;
    x = x >> s16;
    s8 = !!(x>>8)<<3;
    x = x >> s8;
    s4 = !!(x>>4)<<2;
    x = x >> s4;
    s2 = !!(x>>2)<<1;
    x = x >> s2;
    s1 = !!(x>>1)<<0;
    x = x >> s1;
    s0 = x;
    return 1+s16+s8+s4+s2+s1+s0;
}

void test_howManyBits(void)
{
    printf("12, howManyBits? %d\n", howManyBits(12));
    printf("298, howManyBits? %d\n", howManyBits(298));
    printf("-5, howManyBits? %d\n", howManyBits(-5));
    printf("0, howManyBits? %d\n", howManyBits(0));
    printf("-1, howManyBits? %d\n", howManyBits(-1));
    printf("-4, howManyBits? %d\n", howManyBits(-4));
}

unsigned float_twice(unsigned uf)
{
    // single-precision, unsigned has 32 bits
    int sign = uf & (1<<31);
    int exp = (uf & 0x7f800000) >> 23;
    // exp + bias(-127) = true_exp
    if (exp == 0) return uf<<1|sign;
    if (exp == 255) return uf;
    exp++;
    if (exp == 255) return sign|(0x7f800000);
    return (uf&0x807fffff)|(exp<<23); 
}

void test_float_twice(void)
{
    printf("0x7f7fffff should give 0x7f800000, %d\n",float_twice(0x7f7fffff));
}

unsigned float_i2f(int x)
{
    int sign, exp, frac, i, frac_mask, carry;
    sign = (x>>31) & 1;
    if (x == 0)
    {
        return 0;
    }
    else if (x == 0x80000000)
    {
        exp = 31+127;
    }
    else
    {
        if (sign)
        {
            x = -x;
        }
        i = 30;
        while(!(x>>i))
        {
            i--;
        }
        exp = i+127;

        x = x<<(31-i);
        frac_mask = 0x007fffff;
        frac = frac_mask & (x>>8);
        carry = frac > 128 || ((x==128) && (frac&0x1));
        frac += carry;
        if (frac>>23)
        {
            exp += 1;
            frac &= frac_mask;
        }
    }
    return sign<<31|exp<<23|frac;
}

int float_f2i(unsigned uf)
{

}
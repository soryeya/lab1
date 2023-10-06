/*
 * SWE2001 Data Lab
 *
 * <SORAYA BINTI HUSSAIN 2023313237>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

// You will provide your solution to the Data Lab by
// editing the collection of functions in this source file.

// INTEGER CODING RULES:
//  
//   Replace the "return" statement in each function with one
//   or more lines of C code that implements the function. Your code 
//   must conform to the following style:
//  
//   int Funct(arg1, arg2, ...) {
//       /* brief description of how your implementation works */
//       int var1 = Expr1;
//       ...
//       int varM = ExprM;

//       varJ = ExprJ;
//       ...
//       varN = ExprN;
//       return ExprR;
//   }

//   Each "Expr" is an expression using ONLY the following:
//   1. Integer constants 0 through 255 (0xFF), inclusive. You are
//       not allowed to use big constants such as 0xffffffff.
//   2. Function arguments and local variables (no global variables).
//   3. Unary integer operations ! ~
//   4. Binary integer operations & ^ | + << >>
//     
//   Some of the problems restrict the set of allowed operators even further.
//   Each "Expr" may consist of multiple operators. You are not restricted to
//   one operator per line.

//   You are expressly forbidden to:
//   1. Use any control constructs such as if, do, while, for, switch, etc.
//   2. Define or use any macros.
//   3. Define any additional functions in this file.
//   4. Call any functions.
//   5. Use any other operations, such as &&, ||, -, or ?:
//   6. Use any form of casting.
//   7. Use any data type other than int.  This implies that you
//      cannot use arrays, structs, or unions.

//  
//   You may assume that your machine:
//   1. Uses 2s complement, 32-bit representations of integers.
//   2. Performs right shifts arithmetically.
//   3. Has unpredictable behavior when shifting if the shift amount
//      is less than 0 or greater than 31.


// EXAMPLES OF ACCEPTABLE CODING STYLE:
//   /*
//    * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
//    */
//   int pow2plus1(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      return (1 << x) + 1;
//   }

//   /*
//    * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
//    */
//   int pow2plus4(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      int result = (1 << x);
//      result += 4;
//      return result;
//   }

// FLOATING POINT CODING RULES

// For the problems that require you to implement floating-point operations,
// the coding rules are less strict.  You are allowed to use looping and
// conditional control.  You are allowed to use both ints and unsigneds.
// You can use arbitrary integer and unsigned constants. You can use any arithmetic,
// logical, or comparison operations on int or unsigned data.

// You are expressly forbidden to:
//   1. Define or use any macros.
//   2. Define any additional functions in this file.
//   3. Call any functions.
//   4. Use any form of casting.
//   5. Use any data type other than int or unsigned.  This means that you
//      cannot use arrays, structs, or unions.
//   6. Use any floating point data types, operations, or constants.


// NOTES:
//   1. Use the dlc (data lab checker) compiler (described in the handout) to 
//      check the legality of your solutions.
//   2. Each function has a maximum number of operations (integer, logical,
//      or comparison) that you are allowed to use for your implementation
//      of the function.  The max operator count is checked by dlc.
//      Note that assignment ('=') is not counted; you may use as many of
//      these as you want without penalty.
//   3. Use the btest test harness to check your functions for correctness.
//   4. Use the BDD checker to formally verify your functions
//   5. The maximum number of ops for each function is given in the
//      header comment for each function. If there are any inconsistencies 
//      between the maximum ops in the writeup and in this file, consider
//      this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  /*A word with all even numbered bits are set to when is expressed as 0x55555555.
    Bitwise AND operator is used between 0x55555555 and x to set all odd-numbered bits to 0.
    Bitwise XOR operator is used to check if the even-numbered bits of x are all 1. 
    If so, 0 is returned.
    Then the negated value is returned.*/
  int even = 0x55555555;
  int evenX = even & x;
  return !(evenX ^ even);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*A word with all odd numbered bits are set to when is expressed as 0xAAAAAAAA.
    Bitwise AND operator is used between 0xAAAAAAAA and x to set all even-numbered bits to 0.
    Bitwise XOR operator is used to check if the odd-numbered bits of x are all 1. 
    If so, 0 is returned.
    Then the negated value is returned.*/
  int oddBits = 0xAAAAAAAA;
  int oddX = oddBits & x;
  int checker = (oddBits ^ oddX);
  return !checker;
}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*Referring to De Morgan's law;
    ~( x & y) = ( ~x | ~y ),
    ~(~(x&y)) = ~( ~x | ~y ) 
    first all bits of x and y are flipped
    and OR operater is used on ~x and ~y,
    final results are flipped then returned. */
  return ~( ~x | ~y );
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /*Referring to De Morgan's law
    ~( x | y) = ( ~x & ~y ),
    ~(~(x|y)) = ~( ~x & ~y )
    first all bits of x and y are flipped
    and AND operater is used on ~x and ~y,
    final results are flipped then returned.*/
  return ~(~x & ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*Using AND operator, get bits that are in x but not in y
  and bits that are in y but not in x.
  Flip both results before passing both between AND operator.
  The bits is flipped again before being returned.*/
  int inXnotY = x & ~y;
  int inYnotX = y & ~x
  return ~(~(inXnotY) & ~(inYnotX));
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/*if x is Tmax, x+1 will result in overflow and become Tmin which is 0.
  0 is then inverted using NOT operator. Then, XOR operator is used on x+1 
  which is Tmin and x which in this case, is Tmax. If x is truly Tmax, XOR
  operator sets all bits to 1. !=0 checks if the result is non-zero so that only 1 is returned.
*/
  int Tmin = x+1;
  return !(Tmin) & ((x ^Tmin) !=0);
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
/*if x is Tmin then ~x is Tmax. ~x+1 is Tmax+1 which will cause overflow to 0.
  using XOR operator will result to 0.
  !x will be 1 if x is 0.
  Tmin +1 oveflows and becomes 0. 0 is then negated and return 1.*/
  return !((x^(~x + 1)) + !x);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
/*shift 1 to 31th bit becomes 10000000000000000000000000000000 which is Tmin.
  NOT operator flips all bits to become Tmax which is 01111111111111111111111111111111.
  */
  return ~(1 << 31);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/*shift 1 to 31th bit becomes 10000000000000000000000000000000 which is Tmin.*/
  return 1 << 31;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/*The negation of the number can be done by inverting all bits using NOT operator
  and adding 1.
*/
  return ~x + 1;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
/*shift x to the left by n and shift x to the right by 32-n.
  Combine the results using bitwise OR operator*/
  return (x<<n)|(x >> (32-n));
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x187654321
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
/*shift x to the right by n and shift x to the left by 32-n.
  Combine the results using bitwise OR operator*/
  return (x>>n)|(x<<(32-n));
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*set lower bound and upper bound. i is the most significant bit.
  Check if x is greater than or equal to '0' by updating low;
  (x is added to ~0x31 use AND operator with i to keep only sign bits.
  Then the result is shifted back to the right by 31 steps.).
  Check if x is less than or equals to '9' by updating low in a similar way.
  OR operator combines the results and ! inverts the results.*/
  int low = ~0x30;
  int i = 1 << 31;
  int up = ~(i|0x39);
  low = i & (low+1+x) >> 31;
  up = i & (up+x) >> 31;
  return !(up | low);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*sign represents the sign bits of uf by shifting uf to the right by 31
    and using AND operator. If sign is 1, uf is negative, else uf is positive or 0.
    AND operator is used to get 8-bit exponent field. To get the exponent value,
    expfield is subtracted by 127(bias). frac holds the 23-bit fraction.
    If exp>31, uf is too large andif exp is<0, uf is 0 to 1 so int is returned as 0.
    Result holds frac shifted to the right by exp subtracted from 23.
    if sign is 1 (negative uf), return -result.*/
  int sign = 1 & (uf>>31);
  int expfield = 0xFF & (uf>>23);
  int exp = expfield - 127;
  int frac = 0X80000000 | (uf & 0x7FFFFF);
   if(exp>31){
    return 0x80000000u;
  }
  if(exp<0){
    return 0;
  }
  int result = frac >> (23-exp);
  if(sign){
    return -result;
  }else{
    return result;
  }
}

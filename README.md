# Line-Encoder

## Program Functionality
* Line coding encoder and scrambler with digital data generator

## Language and Libraries Used
* Language Used : C++
* IDE used : Codeblocks 16.01
* API used : OpenGL
* Libraries : string, stdlib
* Linker settings : GL, GLU ,GLEW, glut

## Assumptions
* User is familiar with Line encoding schemes.
* Data stream is of 14 bits.

## How to run the code ?
1. compile the code .
1. If you want to apply NRZ-I, NRZ-L, Manchester, Di erential-Manchester
and Basic AMI line encoding scheme then choose:
  * completely random sequence.
3. If you want to apply AMI with scrambling i.e B8Z5 & HDB3 line
encoding scheme then choose:
  * A random sequence with fixed sub-sequences.
    * choose 4 zeros for HDB3.
    * choose 8 zeros for B8Z5.
4. Then choose the required line encoding scheme.
5. If you choose AMI then you will be asked whether you want to use
scrambling technique or not, if yes the choose the scrambling technique(HDB3
or B8Z5).

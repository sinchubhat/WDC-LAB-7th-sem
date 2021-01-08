/*
Write a program for error detection using CRC-CCITT (16 bits) using C.
 Aim: To stimulate the polynomial code check sum for CRC - CCITT.
Theory: CRC is a method used the detection of errors when data is being transmitted.
A CRC is a numeric value computed from the bits in the message to be transmitted.
It is appended to the tail of message prior to transmission,
the receiver defects the presence of errors in the received message by computing new CRC.
This technique is based on binary division, the redundant bits used by CPC are derived by dividing the data unit by predetermined division,
the remainder got by division in the CRC which is appended to the end of data unit so that the resulting data unit becomes exactly divisible by the divisor.
At the receiver the incoming data unit is divided by the same no.
If the remainder is zero that data unit is assumed to be intact and it is accepted.
A remainder medicates the data unit has been damaged in transit and therefore must be rejected.

Error detection using CRC(Cyclic Redundant code) Used in data link layer of network communication, used to check a bit error
Procedure
1) Initialize Transmission Data
2) CRC structure
3) CRC bits => N=5 bits
4) CRC bits -> (N-1)= 4 bits
Division
5) CRC bits ( Reminder ) = Data + (N-1) zero/CRC generator
6) Checksum = Data + CRC bits
AT Receiver
CRC generator -> is remainder zero
Checksums is divided by CRC code. If remainder=0 then no error in received data

Ex: - 10010101110
Algorithm:
1. Given a bit string, append 0S to the end of it (the number of 0s is the same as the degree of the generator polynomial) let B(x) be the polynomial corresponding to B.
2. Divide B(x) by some agreed on polynomial G(x) (generator polynomial) and determine the remainder R(x). This division is to be done using Modulo 2 Division.
3. Define T(x) = B(x) –R(x) (T(x)/G(x) => remainder 0)
 4. Transmit T, the bit string corresponding to T(x).
 5. Let T’ represent the bit stream the receiver gets and T’(x) the associated polynomial. The receiver divides T1 (x) by G(x). If there is a 0 remainder, the receiver concludes T = T’ and no error occurred otherwise, the receiver concludes an error occurred and requires a retransmission.
*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N strlen(g)
// N - length of generated bit
// t - transmission bit
// c - checksum bit
// g - generated CRC bit
char t[128], cs[128], g[]="10110"; // transmitted bit
int a, e, c;
void xor() {
 for(c=1;c<N;c++) cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc() {
 for(e=0;e<N;e++) cs[e]=t[e];
 do {
 if(cs[0]=='1') xor();
 for(c=0;c<N-1;c++) cs[c]=cs[c+1];
 cs[c]=t[e++];
 }while(e<=a+N-1);
}
void main() {
 //rscr();
 printf("\nEnter poly : "); scanf("%s",t);
 printf("\nGenerating Polynomial is : %s",g);
 a=strlen(t);
 for(e=a;e<a+N-1;e++) t[e]='0';
 printf("\nModified t[u] is : %s",t);
 crc();
 printf("\nChecksum is : %s",cs);
 for(e=a;e<a+N-1;e++) t[e]=cs[e-a];
 printf("\nFinal Codeword is : %s",t);
 int check,gg;
 printf("\nTest Error detection 0(yes) 1(no) ? ");
 scanf("%d",&check);
 if(check==0){
	 printf("\nEnter position where you want to insert error : ");
	 scanf("%d",&gg);
	 t[gg]=(t[gg]=='1'?'0':'1');
	 printf("\nErrorneous data : %s",t);
	 printf("\nError Detected");
 }
 else{
	 printf("\nno Error Detected");
 }
  getch();
}

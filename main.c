// main.c
// 20 Dec2018, Simpy Parveen
// Inut : Secret key(1024bits = 128 bytes)
//Output : Public Key (512 bits= 64bytes) K2SN has each public key of 576 bits and so we had to XOR 


#include <immintrin.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sha3.h"

// read a hex string, return byte length or -1 on error.

static int test_hexdigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return  ch - '0';
    if (ch >= 'A' && ch <= 'F')
        return  ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f')
        return  ch - 'a' + 10;
    return -1;
}

static int test_readhex(uint8_t *buf, const char *str, int maxbytes)
{
    int i, h, l;

    for (i = 0; i < maxbytes; i++) {
        h = test_hexdigit(str[2 * i]);
        if (h < 0)
            return i;
        l = test_hexdigit(str[2 * i + 1]);
        if (l < 0)
            return i;
        buf[i] = (h << 4) + l;
    }

    return i;
}

// returns zero on success, nonzero + stderr messages on failure

void test_sha3()
{
    int i, fails, msg_len, sha_len;
    uint8_t sha[64], buf[64], msg[128];
    
    //Clearing the memory
       
        memset(buf, 0, sizeof(buf));               //Keeps the hash of the message
        memset(msg, 0, sizeof(msg));               //Original message to be hashed

        msg_len = 128;                            // Input bytes to the hash
        sha_len = 64;                             // Output bytes from the hash
	
	printf("\nMsg length %d \n",msg_len);
	printf("Sha length %d \n",sha_len);

	for(int i=0;i<msg_len;i++)msg[i] = rand()%255;  // Input is taken randomly using rand()
        
    sha3(msg, msg_len, buf, sha_len);             // Calculates Sha3 hash of the msg and saves it into buf
        
	printf("\n\nMessage : ");
	for(int i=0;i<msg_len;i++)printf("%hhu ",msg[i]);
		
	
	printf("\n\nBuffer : ");
	for(int i=0;i<sha_len;i++)printf("%hhu ",buf[i]);
  
}


int main(int argc, char **argv)
{
    test_sha3(); //&& test_shake() == 0)
        printf("\n Finished !\n");
    //test_speed();

    return 0;
}


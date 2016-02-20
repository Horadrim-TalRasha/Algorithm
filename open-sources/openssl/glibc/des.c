#include <stdio.h>
#include <string.h>
#include <openssl/des.h> /*DES算法头文件*/

#define DEBUG_PRINT
 
/*初始化需要加密的数据*/
void init_input(const_DES_cblock input)
{
     input[0] = 0;
     input[1] = 1;
     input[2] = 2;
     input[3] = 3;
     input[4] = 4;
     input[5] = 5;
     input[6] = 6;
     input[7] = 7;
}

int main(void)
{
     int ret = 0;
     int i = 0;
     DES_cblock key; /*密钥*/
     DES_key_schedule key_schedule; /*将密钥转化保存的数据结构，用于加密*/
     DES_key_schedule key_schedule1; /*解密时使用*/
     const_DES_cblock input; /*需要加密的数据*/
     DES_cblock output; /*加密后的数据*/
 
     init_input(input); /*初始化数据*/
     memset(output, 0, 8); /*清零*/

     ret = DES_random_key(&key); /*获得随机密钥*/
     ret = DES_set_key_checked(&key, &key_schedule); /*转化密钥*/
 
     DES_ecb_encrypt(&input, &output, &key_schedule, 1); /*加密数据*/

     memset(input, 0, 8); /*清零*/
     ret = DES_set_key_checked(&key, &key_schedule1); /*转换密钥*/
     DES_ecb_encrypt(&output, &input, &key_schedule1, 0); /*解密*/
 
     return 0;
}

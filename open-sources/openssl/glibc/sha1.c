/*
 *  Code snippet to calculate SHA1sum using openssl libs.
 *   Copyright 2005 Junichi Uekawa, given to public domain.
 *
 *   $ gcc openssltest.c -lssl
 *   $ ./a.out  < ./a.out
 *   eae8189278303caaa78f2d89e6a6ebeb7d37b554
 *   $ sha1sum ./a.out
 *   eae8189278303caaa78f2d89e6a6ebeb7d37b554  ./a.out
 *   */

#include <stdio.h>
#include <openssl/sha.h>

main ()
{
  SHA_CTX s;
  int i, size;
  char c[512];
  unsigned char hash[20];
  
  SHA1_Init(&s);
  while ((size=read (0, c, 512)) > 0)
    SHA1_Update(&s, c, size);
  SHA1_Final(hash, &s);
  
  for (i=0; i < 20; i++)
    printf ("%.2x", (int)hash[i]);
  printf ("\n");
}

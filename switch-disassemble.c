/* Challenge to illuminate disassembly. Displays flag from sequential case statement*/
/* sends "MCA-" plus 8 hex digits to terminal if user enters "012345678" at keyboard */
/* To be provided in executable form only.  Can be made more challenging by randomizing the case order */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>

bool isCorrect(int a[], int n);

int main()
{
  int arr[10] = {0};
  bool pass = 0;
  int i = 0;
  char check;

  puts("Enter ten characters...");
  
  do {
    check = getchar();

    if(isdigit(check) && i < 10)
    {
        arr[i] = atoi(&check);
        i++;
    }

    if(i >= 10)
    {
      for(int j = 0; j < 10; j++)
      {
        switch (arr[j])
        {
          case 0:
            printf("MCA-");
            break;
          case 1:
            printf("B"); 
            break;
          case 2:
            printf("C");
            break;
          case 3:
            printf("0");
            break;
          case 4:
            printf("5");
            break;
          case 5:
            printf("F");
            break;
          case 6:
            printf("1");
            break;
          case 7:
            printf("3");
            break;
          case 8:
            printf("7");
            break;
          case 9:
            printf(" Done\n");
            pass = isCorrect(arr, 9);
            break;
          default:
            printf("What?");
            break;
        }
        
        i = 0;

      }
    }

  }while (pass == 0);

  return(0);
}


bool isCorrect(int a[], int n)
{
  char combo[n+1];
  unsigned char md5sum[MD5_DIGEST_LENGTH];

  for(int i = 0; i < n; i++)
  {
    combo[i] = a[i] + '0';
  }

  MD5(combo, strlen(combo), md5sum);

  if(strcmp(md5sum, "\x08\xf2\x4a\xa4\x7e\xa2\xad\xd2\x7b\x73\xe3\x3b\x0f\x8e\xe2\xf3") == 0)
  {
    puts("Granted!");
    return 1;
  }
  else
  {
    puts("NO");
    return 0;
  }
}

//Key: MCA-5FC91730
//Correct input: 0452168739
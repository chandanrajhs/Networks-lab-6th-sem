#include<stdio.h>
#include<string.h>
char data[50], crc[50];

char gen[] = "10001000000100001"; //G(x): x^16+x^12+x^5+1 for CRC-CCITT 16bit
int len, i, j;
void calc_crc()
{

	for (i = 0; i < strlen(gen); i++)
	crc[i] = data[i];
	 do {

		if (crc[0] == '1')
		{
		for (j = 1; j < strlen(gen); j++)

		crc[j] = ((crc[j] == gen[j]) ? '0' : '1');
		}
		for(j = 0; j < strlen(gen) - 1; j++)
		crc[j] = crc[j + 1];

		crc[j] = data[i++];
	} while (i <= len + strlen(gen) - 1);

}

int main()
{

	printf("Enter Bit string\t: ");
	scanf("%s", data);

	len = strlen(data);
	printf("Generating Polynomial\t: %s\n", gen);

	for (i = len; i < len + strlen(gen) - 1; i++)
	 data[i] = '0';
	printf("Modified Data is\t: %s\n", data);

	calc_crc();
	printf("Checksum is\t\t: %s\n", crc);

	for (i = len; i < len + strlen(gen) - 1; i++)
	data[i] = crc[i - len];
	 printf("Final Codeword is\t: %s\n", data);

	printf("Test Error detection\n1(Yes) / 0(No)? : ");
 	scanf("%d", &i);

	if (i == 1)
	 {

		printf("Enter position to insert an error : ");
		 scanf("%d", &i);
		data[i] = (data[i] == '0') ? '1' : '0';
		 printf("Erroraneous data\t\t: %s\n", data);
	}
	calc_crc();

	for (i = 0; (i < strlen(gen) - 1) && (crc[i] != '1'); i++);

	 if (i < strlen(gen) - 1)
		printf("Error detected.\n");
	 else
		printf("No Error Detected.\n");

	return 0;

}

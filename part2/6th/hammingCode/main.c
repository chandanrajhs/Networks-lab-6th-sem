#include<stdio.h>
char data[4];
int encoded[7], edata[7], syn[3], i = 0;
int hmatrix[3][7] = {1, 0, 0, 0, 1, 1, 1,
0, 1, 0, 1, 0, 1, 1,
0, 0, 1, 1, 1, 0, 1};
int gmatrix[4][7] = {0, 1, 1, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 0,
1, 1, 0, 0, 0, 1, 0,
1, 1, 1, 0, 0, 0, 1};
int main() {
int i, j;
printf("Enter 4 bit data: ");
scanf("%s", data);
printf("Encoded Data: ");
for (i = 0; i < 7; i++) {
for (j = 0; j < 4; j++)
encoded[i] += ((data[j])*(gmatrix[j][i]));
encoded[i] = encoded[i] % 2;
printf("%d ", encoded[i]);
}
printf("\nEnter Encoded bits as received : ");
for (i = 0; i < 7; i++)
scanf("%d", &edata[i]);
for (i = 0; i < 3; i++) { //Generating Syndrome matrix
for (j = 0; j < 7; j++)
syn[i] += (hmatrix[i][j] * edata[j]);
syn[i] = syn[i] % 2;
}
for (i = 0; i < 7; i++) //finding Error Bit
if (syn[0] == hmatrix[0][i]
&& syn[1] == hmatrix[1][i]
&& syn[2] == hmatrix[2][i])
break;
if (i == 7) printf("Data is error free!!\n");
else {
printf("Error in data at bit position: %d\n", i + 1);
edata[i] = !edata[i]; //Complementing the bit value
printf("The Correct data Should be : ");
for (i = 0; i < 7; i++)
printf("%d ", edata[i]);
printf("\n");
}
return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>                        //thư viện kiểu bool
#include <stdlib.h>                       
#include<math.h>
#include<string.h>
#include<time.h>
//tạo struct
struct Chiabai
{
    int hang;
    int cot;
    char name[20];

};

void Docfile(FILE* f1, struct Chiabai S1[53]) {
    int i;          //đọc thông tin từ file

    for (i = 1; i < 53; i++) {
        char tx[5];
        fscanf(f1, "%d", &S1[i].hang);
        fscanf(f1, "%d", &S1[i].cot);
        fgets(S1[i].name, 20, f1);
    }

}
void Sort(int A[]){      // Sắp xếp mảng giá trị
int i,j;
int temp;
for (i = 0; i <12; i++){
    for (j = i + 1; j < 13; j++)
    {
     if (A[i] > A[j])
       {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        }
    }
}
}
void  Tu_Quy(int A[]){                              //Tìm tứ quý bằng mảng vừa sắp xếp

int i,j;
for(i=0;i<=9;i++){
    if(A[i]==A[i+1] && A[i+1]==A[i+2] && A[i+2]==A[i+3]){
        if(A[i]==0){   printf("\nNgười này có tứ Át !! ");}
        if(A[i]==1){   printf("\nNgười này có tứ Hai !! ");}
        if(A[i]==2){   printf("\nNgười này có tứ Ba !! ");}
        if(A[i]==3){   printf("\nNgười này có tứ Bốn !! ");}
        if(A[i]==4){   printf("\nNgười này có tứ Năm !! ");}
        if(A[i]==5){   printf("\nNgười này có tứ Sáu !! ");}
        if(A[i]==6){   printf("\nNgười này có tứ Bảy !! ");}
        if(A[i]==7){   printf("\nNgười này có tứ Tám !! ");}
        if(A[i]==8){   printf("\nNgười này có tứ Chín !! ");}
        if(A[i]==9){   printf("\nNgười này có tứ Mười !! ");}
        if(A[i]==10){   printf("\nNgười này có tứ J !! ");}
        if(A[i]==11){   printf("\nNgười này có tứ Q !! ");}
        if(A[i]==12){   printf("\nNgười này có tứ K !! ");}
            
    }
}
printf("\nNgười này không có tứ quý");
}

void Tao_mang(int x[],int nguoi1[],int nguoi2[],int nguoi3[],int nguoi4[]){
int k;
for(k=1;k<=52;k+=4){
nguoi1[k/4]=x[k]/4;

}
for(k=2;k<=52;k+=4){
nguoi2[k/4]=x[k]/4;

}
for(k=3;k<=52;k+=4){
nguoi3[k/4]=x[k]/4;

}
for(k=4;k<=52;k+=4){
nguoi4[k/4]=x[k]/4;

}
}
int main() {
    int m;
    struct Chiabai S1[53];
    FILE* f1 = fopen("Chia_Bai.txt", "r+");
    Docfile(f1, S1);
  int nguoi1[100],nguoi2[100],nguoi3[100],nguoi4[100];

//--------------------------------
int i=1,j=1;
int x[52];
bool c[13][4];
//khởi tạo giá trị false
for(i=1;i<=13;i++){
    for(j=1;j<=4;j++){
        c[i][j]=false;
    }
}
// sinh số ngẫu nhiên 
srand((int)time(0));
i=1;
while(i<=52){
    x[i]= 0 + rand() % (51 + 1 + 0 );
    if(c[x[i]/4][x[i]%4]==false){
                c[x[i]/4][x[i]%4]=true;
        i++;
    }
}

Tao_mang(x,nguoi1,nguoi2,nguoi3,nguoi4);
Sort(nguoi1);
Sort(nguoi2);
Sort(nguoi3);
Sort(nguoi4);
// for(i=0;i<13;i++){
//     printf("%d ",nguoi1[i]);
// }


// chia bài cho 4 người //

// printf("\nNgười thứ 1           Người thứ 2             Người thứ 3             Người thứ 4 ");
// for(i=1;i<=52;i++){
//     if(i%4==1){
//         printf("\n");
//     }
//     for(j=1;j<=52;j++){

//             if((x[i]/4)==S1[j].hang && (x[i]%4)==S1[j].cot){
//             fflush(stdin);

//         printf("%s",S1[j].name);

//         }

// }


printf("\nNgười chơi thứ nhất sẽ được chia các quân bài : ");
printf("\n");
for(i=1;i<=52;i+=4){
    for(j=1;j<=52;j++){
    if((x[i]/4)==S1[j].hang && (x[i]%4)==S1[j].cot){
            fflush(stdin);

        printf("%s",S1[j].name);

        }
    }
}
Tu_Quy(nguoi1);
//========================================================
printf("\nNgười chơi thứ hai sẽ được chia các quân bài: ");
printf("\n");

for(i=2;i<=52;i+=4){
    for(j=1;j<=52;j++){
    if(x[i]/4==S1[j].hang && (x[i]%4)==S1[j].cot){
            fflush(stdin);

        printf("%s",S1[j].name);

    }
    }
}
Tu_Quy(nguoi2);
//========================================================

printf("\nNgười chơi thứ ba sẽ được chia các quân bài: ");
printf("\n");

for(i=3;i<=52;i+=4){
    for(j=1;j<=52;j++){
    if(x[i]/4==S1[j].hang && (x[i]%4)==S1[j].cot){
                       fflush(stdin);

        printf("%s",S1[j].name);

    }
    }
}
Tu_Quy(nguoi3);
//========================================================

printf("\nNgười chơi thứ tư sẽ được chia các quân bài: ");
printf("\n");

for(i=4;i<=52;i+=4){
    for(j=1;j<=52;j++){
    if(x[i]/4==S1[j].hang && (x[i]%4)==S1[j].cot){
        fflush(stdin);

        printf("%s",S1[j].name);
    }
    }
}
Tu_Quy(nguoi4);
return 0;
}
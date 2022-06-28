#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>

#include "md5.c"

#define MAX 100
#define MAX_HEADER 40
#define true 1
#define false 0

typedef struct
{
    char header[MAX_HEADER];
    char data[MAX];
    char prevHash[MAX_HEADER];
    int nonce;
    int difficulty;
} Block;

typedef struct
{
    Block blocks[MAX];
    int index;
}Blockchain;

void print_bytes(void *p, size_t length){
	uint8_t *pp = (uint8_t *)p;
	for(unsigned int i = 0; i < length; ++i){
		if(i && !(i % 16)){
			printf("\n");
		}
		printf("%02X ", pp[i]);
	}
	printf("\n");
}

void print_hash(uint8_t *p){
	for(unsigned int i = 0; i < 16; ++i){
		printf("%02x", p[i]);

	}
	printf("\n");
}

char* to_string(uint8_t *p)
{
    char buff[1000];
	char* digest = (char*)malloc(1000);
	strcpy(digest,"");
	for(unsigned int i = 0; i < 16; ++i){
		sprintf(buff,"%02x", p[i]);
		strcat(digest,buff);
	}
	return digest;
}

Block khoiTaoBlock()
{
    Block b;
    strcpy(b.data,"");
    strcpy(b.prevHash,"");
    strcpy(b.header,"");
    b.nonce = 0;
    b.difficulty = 0;
    return b;
}

char* createString (int difficulty)
{
    char* tmp = (char*)malloc(difficulty+1);
    for (int i=0; i<difficulty; i++)
        tmp[i] = '0';
    tmp[difficulty] = '\0';
    return tmp;
}

bool isPreSubString (char* string, char* subString)
{
    for (int i=0; i<strlen(subString); i++)
        if (string[i] != subString[i])
            return false;
    return true;
}

Block createBlock (char* data, char* prevHash, int difficult)
{
    Block b = khoiTaoBlock();
    b.nonce = 0;
    b.difficulty = difficult;
    strcpy(b.data,data);
    strcat(b.prevHash,prevHash);




    //Tạo chuỗi có độ dài difficulty toàn số 0 = diffStr
    char* diffStr = createString(b.difficulty);

    while (true)
    {
        //Tính giá trị băm: hash(data + prevHash + nonce)
        char tmp[1000] ="";
        char body[1000] = "";
        char strNonce[50] = "";
        itoa(b.nonce,strNonce,10);
        strcat(body,b.data);
        strcat(body,b.prevHash);
        strcat(body,strNonce);

        strcpy(tmp,to_string(md5String(body)));

        //Kiểm tra giá trị băm liệu có thoả mãn difficulty
        ////strstr(tmp,diffStr) == 0 --> return b
        ////Else: tăng nonce lên 1 và tính lại

        if (isPreSubString(tmp,diffStr))
        {
            strcpy(b.header,tmp);
            return b;
        }

        b.nonce++;

    }


    return b;
}

void printBlock (Block b)
{
    printf("Header = %s\n",b.header);
    printf("Data = %s\n",b.data);
    printf("PreviousHash = %s\n",b.prevHash);
    printf("Nonce = %d\n",b.nonce);
    printf("Difficulty = %d\n\n",b.difficulty);
}

Blockchain khoiTaoBlockchain ()
{
    Blockchain bch;
    bch.index = -1;
    return bch;
}

void addBlock (char* data, Blockchain* bch, int difficult)
{
    char prevHash[100] = "";
    if (bch->index < 0)
        strcpy(prevHash,"0000000000000000000000000000000");
    else
        strcpy(prevHash, bch->blocks[bch->index].header);

    Block b = createBlock(data,prevHash,difficult);
    bch->index++;
    bch->blocks[bch->index] = b;
}

//Verify Blockchain
// this.header == hash (this.body(=data+prevHash))

bool verifyBlock (Block b)
{
    char body[100] = "";
    char hashedBody[100] = "";
    char strNonce[50] = "";
    itoa(b.nonce, strNonce, 10);
    strcat(body,b.data);
    strcat(body,b.prevHash);
    strcat(body,strNonce);
    strcpy(hashedBody,to_string(md5String(body)));

    if (strcmp(hashedBody,b.header)==0)
        return true;
    return false;
}

bool verifyBlockchain (Blockchain bch)
{
    for (int i=0; i<bch.index; i++)
    {
        if (verifyBlock(bch.blocks[i])==false)
            return false;
    }
    return true;
}


int main(int argc, char *argv[]){
    Blockchain bch = khoiTaoBlockchain();
	addBlock("Viet Nam",&bch,4);
	printBlock(bch.blocks[bch.index]);

	addBlock("Ha Noi",&bch,3);
	printBlock(bch.blocks[bch.index]);

	if (verifyBlockchain(bch))
    {
        printf("\tBlockchain chay chinh xac");
    }

}

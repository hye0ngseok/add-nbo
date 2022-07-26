#include <cstdint>
#include <cstdio>
#include <netinet/in.h>

void readme(){
	printf("syntax : add-nbo <file1> <file2>\n");
	printf("sample : add-nbo a.bin c.bin\n\n");
} 

int main(int argc, char* argv[]){
	uint32_t num1, num2, result;
	if(argc <= 2) {
	readme();
	return 0;
	}
	
	FILE *a = fopen(argv[1],"r");
	FILE *b = fopen(argv[2],"r");
	fread(&num1,sizeof(uint32_t),1,a);
	fread(&num2,sizeof(uint32_t),1,b);
	num1 = ntohl(num1);
    	num2 = ntohl(num2);
    	result = num1 + num2;
    	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, result, result);
	fclose(a);
	fclose(b);
	return 0;
}

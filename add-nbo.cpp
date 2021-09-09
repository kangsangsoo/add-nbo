#include <cstdio>
#include <cstdint>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");

	uint32_t a1, a2;
	fread(&a1, 4, 1, fp1);
	fread(&a2, 4, 1, fp2);

	a1 = ntohl(a1);
	a2 = ntohl(a2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a1, a1, a2, a2, a1 + a2, a1 + a2);
	
	fclose(fp1);
	fclose(fp2);
}

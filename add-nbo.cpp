#include <cstdio>
#include <cstdint>

int main(int argc, char* argv[]) {
	uint8_t c1[4], c2[4];
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");

	fread(c1, 4, 4, fp1);
	fread(c2, 4, 4, fp2);

	uint32_t a1 = 0, a2 = 0;

	for (int i = 0; i < 4; i++) {
		a1 += c1[3-i] << (8 * i);
		a2 += c2[3-i] << (8 * i);
	}
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a1, a1, a2, a2, a1 + a2, a1 + a2);
	
	fclose(fp1);
	fclose(fp2);
}

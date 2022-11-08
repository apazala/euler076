#include <stdio.h>
#include <inttypes.h>

int pent[18];
int npent;

int partitions[101];

void init() {
	int p = 0;
	int k = 1;
	while (p <= 110) {
		p = 3 * k*k;
		pent[npent++] = (p - k) / 2;
		p = (p + k) / 2;
		pent[npent++] = p;
		k++;
	}

	partitions[0] = 1;
	for (int i = 1; i <= 100; i++) {
		int index;
		int j = 0;
		int part = 0;
		int sign = 0;
		for (;;) {
			index = i - pent[j];
			j++;
			if (index < 0)break;
			part += (sign) ? -partitions[index] : partitions[index];
			index = i - pent[j];
			j++;
			if (index < 0)break;
			part += (sign) ? -partitions[index] : partitions[index];

			sign = !sign;
		}
		partitions[i] = part;
	}
}

int main()
{
	init();

	printf("%d\n", partitions[100] - 1);
	

	return 0;
}

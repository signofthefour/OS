#include <stdio.h>

void func(unsigned int num) {
	unsigned int local = num;
	printf("%2u-->%p\n", local, &local);
	local--;
	if (local > 0) {
		func(local);
	}
}

int main() {
	func(10);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>


int max(int x, int y){
	if (x > y){
		return x;
	}else{
		return y;
	}
}
int min(int x, int y){
	if (x < y){
		return x;
	}else{
		return y;
	}
}


int main() {
	FILE *file;
	file = fopen("input.txt", "r");
	if (file == NULL){
		printf("Error in opening file!\n");
		return 0;
	}

	int n;
	fscanf(file, "%i", &n);

	int tr[4];
	for (int i = 0; i < n; i++){
		fscanf(file, "%i %i %i %i", &tr[0], &tr[1], &tr[2], &tr[3]);

		if (max(tr[0], tr[1]) < min(tr[2], tr[3]) || min(tr[0], tr[1]) > max(tr[2], tr[3])){
        	printf("NO\n");

		}else{
			printf("YES\n");
		}
	}

	fclose(file);
	return 0;
}

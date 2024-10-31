	#include <stdio.h>
	#include <string.h>

	int main(){
		int A = 0;

		FILE *file;
		file = fopen("input.txt", "r");

		if (file == NULL) {
			printf("Error opening file!\n");
			return 0;
		}
		int n;
		char op[4];

		fscanf(file, "%i", &n);

		for(int i = 0; i< n; i++){

			fscanf(file, " %s", op);
			if(op[0] == '+' || op[2] == '+'){
				A++;
			}else if(op[0] == '-' || op[2] == '-'){
				A--;
			}else{
				A *= A;
			}
		}

		printf("%i", A);
		fclose(file);
		return 0;
	}

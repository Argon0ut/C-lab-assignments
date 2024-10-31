#include <stdio.h>
#include <string.h>

void decode_string(char encoded[], int length) {
	char curr[10000];
	int indexCurr = 0;
	int i = length - 1;
	while (i >= 0){
		if (encoded[i] == '0'){
		    if (i - 2>= 0){
    			int currNUM = ((encoded[i-2] - 48) * 10 + (encoded[i-1] - 48));
    			curr[indexCurr] = (char)(currNUM + 96);
    			i -= 3;
    			indexCurr += 1;
		    }else{
		        break;
		    }

		}else if(encoded[i] >= '1' && encoded[i] <= '9'){
			int currNUM = encoded[i] - 48;
			curr[indexCurr] = (char)(currNUM + 96);
			i-= 1;
			indexCurr += 1;
		}else{
		    i -= 1;
		}


	}
	curr[indexCurr] = '\0';
	for (int j = 0; j < indexCurr / 2; j++){
		char temp = curr[j];
		curr[j] = curr[indexCurr -j - 1];
		curr[indexCurr - j - 1] = temp;
	}

	printf("%s\n", curr);
}

void decode_from_file(char filename[]) {
	 FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file!\n");
		return;
	}

	int length;
	fscanf(file, "%i", &length);

	for (int i = 0; i < length; i++){
		int lenLine;
		fscanf(file, "%i", &lenLine);

		char encoded[10000];
		fscanf(file, "%s", encoded);
		decode_string(encoded, lenLine);
	}
	fclose(file);

}
int main() {

decode_from_file("input.txt");
return 0;
}

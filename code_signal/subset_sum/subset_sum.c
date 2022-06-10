#include <stdio.h>
#include <stdlib.h>

int compare( const void* a, const void* b){
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

int compute_sum(int *arr, int *n){
	int sum = 0;
	for(int i = 0 ; i < *n ; i++){
		sum += arr[i];
	}
	return sum;
}

void solver(int *arr, int *n, int *sum){
	int first = 0, dp[(*n) * (*n)][ (*n) ], count2 = 1;
	for(int i = 0 ; i < (*n) * (*n) ; i++){
		dp[i][1] = -1;
	}
	dp[0][0] = 0, dp[1][0] = arr[0], dp[1][1] = 0, dp[1][2] = -1;
	int count = 2;
	for(int i = 1 ; i < *n ; i++){
		for(int j = 0 ; j < 2 * i ; j++){
			dp[count][0] = arr[i] + dp[j][0];
			
			while(dp[j][count2] != -1){
				dp[count][count2] = dp[j][count2];
				count2++;
			}
			dp[count][count2] = i;
			dp[count][count2 + 1] = -1;
			count2 = 1;

			if(dp[count][0] > *sum){
				printf("No subsets\n");
				return;
			}
			if(dp[count][0] == *sum){
				printf("Subset found!\n");
				for(int k = 0 ; k < (*n) ; k++){
					if(k == dp[count][count2]){
						if(first == 0){
							first = 1;
							printf("%d", arr[k]);
						}
						else if(dp[count][count2 + 1] == -1){
							printf(", %d\n", arr[k]);
							break;
						}
						else printf(", %d", arr[k]);
						count2++;
					}
				}
				first = 0;
				count2 = 1;
				for(int k = 0 ; k < (*n) ; k++){
					if(k != dp[count][count2]){
						if(first == 0){
							first = 1;
							printf("%d", arr[k]);
						}
						else printf(", %d", arr[k]);	
					}
					else{
						count2++;
					}
				}
				return;
			}
			count++;	
		}
	}
}

int main(){
	int n, sum;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);
	sum = compute_sum(arr, &n);
	if(sum % 2 != 0){
		printf("No subsets\n");
	}
	else{
		sum = sum / 2;
	}
	solver(arr, &n, &sum);
}

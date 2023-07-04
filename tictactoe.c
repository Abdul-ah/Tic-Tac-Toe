#include<stdio.h>
#include<stdlib.h>
int i,j;
void print_pattern(char** a,int n) {
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(j==n-1) {
				printf("%c\n",a[i][j]);
			} else if(j==0) {
				printf(" %c | ",a[i][j]);
			} else {
				printf("%c | ",a[i][j]);
			}
		}
		if(i!=n-1) {
			for(j=0; j<4*n; j++) {
				printf("-");
			}
			printf("\n");
		}
	}
}
int isturnavail(char** arr,int n) {
	int flag=0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(arr[i][j]==' ') {
				flag=1;
				break;
			}
		}
	}
	if(flag==0) {
		printf("\nIt's a Draw... -_-");
		exit(0);
	}
	return flag;
}
void check_win(char** arr,int n,char a) {
	int dia=0,idia=0,row,col;
	for(i=0; i<n; i++) {
		row=0;
		col=0;
		for(j=0; j<n; j++) {
			if(i==j && arr[i][j]==a) {
				dia++;
			}
			if((i+j)==(n-1) && arr[i][j]==a) {
				idia++;
			}
			if(arr[i][j]==a) {
				row++;
			}
			if(arr[j][i]==a) {
				col++;
			}
		}
		if(row==n || col==n) {
			printf("\nYahooo!!! %c wins... ^_^",a);
			exit(0);
		}
	}
	if(dia==n || idia==n) {
		printf("\nYahooo!!! %c wins... ^_^",a);
		exit(0);
	}
}
int main() {
	int n,x,y;
	printf("\n\t\t\t\t\tWelcome to Tic Tac Toe Game ^_^\n\nEnter the size of the board: ");
	scanf("%d",&n);
	printf("\n");
	if(n<=2) {
		printf("Not an valid size");
		exit(0);
	}
	char* arr[n];
	for(i=0; i<n; i++) {
		arr[i]=(char*)malloc(n*sizeof(char));
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			arr[i][j]=' ';
		}
	}
	print_pattern(arr,n);
	while(isturnavail(arr,n)) {
		Sleep(300);
		printf("\nYour turn...Enter position of X to be placed(x,y): ");
		scanf("%d,%d",&x,&y);
		while(x>=n || y>=n || arr[x][y]=='x' || arr[x][y]=='o') {
			printf("\nInvalid index is typed... -_-\nEnter an valid position(x,y): ");
			scanf("%d,%d",&x,&y);
		}
		printf("\n");
		arr[x][y]='x';
		print_pattern(arr,n);
		check_win(arr,n,'x');
		if(isturnavail(arr,n)) {
			x=rand()%n;
			y=rand()%n;
			while(arr[x][y]=='x' || arr[x][y]=='o') {
				x=rand()%n;
				y=rand()%n;
			}
			printf("\nAI turn...(%d,%d)\n\n",x,y);
			arr[x][y]='o';
			Sleep(1000);
			print_pattern(arr,n);
			check_win(arr,n,'o');
			Sleep(200);
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//constrain
const int POINT[16]={1, 2, 3, 4, 5, 6, 7, 8, 10, 15, 20, 40, 50, 75, 100, 200};
const int TOTAL_CASE=16;
const int POINT_TO_COIN=50;

void ploop(int much, int x){
	for(int i=0; i<much; i++){
		printf("%lc", x);
	}
}

void cln(){
	system("@cls||clear");
}

void delay(int n){
    clock_t start=clock();
    while (clock()<start+n);
}

struct game_point{
	int point;
	int show; //show=1, hide=0
};

//math
void int_to_char(long int n, char *str){
	int tmp=n;
	int i=0, max=0, z[20]={0}, x=0;
	do{
		z[max]=tmp%10;
		tmp=(tmp-z[max])/10;
		max++;
	}while(tmp>0);
	long int j=(max-1)+((max-1)/3);
	for(i=0; i<max; i++){
		str[j]=z[i]+'0';
		j--;
		if((i+1)%3==0 && (i+1)!=max){
			str[j]='.';
			j--;
		}
	}
}

void generate_random(int *atob, int *btoa){
	int ctr=0, temp[16]={0}, counter=0, i=0;
	srand(time(0));
	while(ctr<16){
		int x=rand()%16;
		if(temp[x]==0){
			temp[x]=ctr+1;
			if(x==0){
				x=16;
			}
			atob[ctr]=x;
			ctr++;	
		}
		else{}
	}
	for(int i=0; i<16; i++){
		temp[atob[i]]=i;
	}
	for(int i=0; i<16; i++){
		atob[i]=temp[i];
		btoa[atob[i]]=i;
	}
}

//display area
void header(){
	ploop(25, ' ');
	printf("%lc", 218);
	ploop(6, 196);
	printf("%lc", 191);
	printf("o");
	printf("%lc", 201);
	ploop(9, 205);
	printf("%lc", 187);
	printf("\n");
	ploop(25, ' ');
	printf("%lc Deal %lc", 179, 179);
	printf(" ");
	printf("%lc No Deal %lc", 186, 186);
	printf("\n");
	ploop(25, ' ');
	printf("%lc", 192);
	ploop(6, 196);
	printf("%lc", 217);
	printf("r");
	printf("%lc", 200);
	ploop(9, 205);
	printf("%lc", 188);
	printf("\n");
	ploop(5, ' ');
	ploop(59, 196);
	printf("\n");
}

void display_start(){
	printf("\n");
	int c1=0;
	for(int i=0; i<=16; i++){
		ploop(5, ' ');//left margin
		if(i==0){
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc", 191);
			ploop(5, ' ');
			printf("%lc", 201);
			ploop(31, 205);
			printf("%lc", 187);
			ploop(5, ' ');
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc\n",191);
		}
		else if(i==16){
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc", 217);
			ploop(5, ' ');
			printf("%lc", 200);
			ploop(31, 205);
			printf("%lc", 188);
			ploop(5, ' ');
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc\n",217);
		}
		else{
			if(i%2!=0){
				printf("%lc %-4d %lc", 179, POINT[c1], 179);
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			ploop(5, ' ');
			printf("%lc", 186);
			if(i==6){
				char text[]={"Welcome to "};
				ploop((31-strlen(text))/2, ' ');
				printf(text);
				ploop((31-strlen(text))/2, ' ');
			}
			else if(i==8){
				char text[]={"Deal Or No Deal"};
				ploop((31-strlen(text))/2, ' ');
				printf(text);
				ploop((31-strlen(text))/2, ' ');
			}
			else if(i==10){
				char text[]={"Press Start"};
				ploop((31-strlen(text))/2, ' ');
				printf(text);
				ploop((31-strlen(text))/2, ' ');
			}
			else{
				ploop(31, ' ');
			}
			printf("%lc", 186);
			ploop(5, ' ');
			if(i%2!=0){
				printf("%lc %-4d %lc", 179, POINT[c1+8], 179);
				c1++;
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			printf("\n");
		}
	}
}

void display_table(struct game_point game[], struct game_point showCase[], int playersCase){
	printf("\n");
	int c1=0, c2=0;
	for(int i=0; i<=16; i++){
		ploop(5, ' ');//left margin
		if(i==0){
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc", 191);
			ploop(5, ' ');
			printf("%lc", 201);
			for(int j=0; j<4; j++){
				ploop(7, 205);
				if(j<3){
					printf("%lc", 203);
				}
			}
			printf("%lc", 187);
			ploop(5, ' ');
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc\n",191);
		}
		else if(i==16){
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc", 217);
			ploop(5, ' ');
			printf("%lc", 200);
			for(int j=0; j<4; j++){
				ploop(7, 205);
				if(j<3){
					printf("%lc", 202);
				}
			}
			printf("%lc", 188);
			ploop(5, ' ');
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc\n",217);
		}
		else{
			if(i%2!=0){
				if(showCase[c1].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			ploop(5, ' ');
			for(int j=0; j<4; j++){
				if(i%4==0){
					if(j==0){
						printf("%lc", 204);
						ploop(7, 205);
						printf("%lc", 206);
					}
					else if(j==3){
						ploop(7, 205);
						printf("%lc", 185);
					}
					else{
						ploop(7, 205);
						printf("%lc", 206);
					}
				}
				else if(i%2==0){
					if(j==0){
						printf("%lc", 186);
					}
					if(game[c2].show==1){
						printf(" %-5d ", game[c2].point);	
					}
					else if(c2==playersCase){
						printf(" OWNED ");
					}
					else{
						printf("   %c   ", c2+'A');
					}
					printf("%lc", 186);
					c2++;
				}
				else{
					if(j==0){
						printf("%lc", 186);
					}
					ploop(7, ' ');
					printf("%lc", 186);
				}
			}
			ploop(5, ' ');
			if(i%2!=0){
				if(showCase[c1+8].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1+8].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
				c1++;
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			printf("\n");
		}
	}
}

void display_open_case(struct game_point showCase[], int point, int selected_case, int user_case){
	printf("\n");
	int c1=0, bank=0;
	for(int i=0; i<=16; i++){
		ploop(5, ' ');//left margin
		if(i==0){
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc", 191);
			ploop(5, ' ');
			printf("%lc", 201);
			ploop(31, 205);
			printf("%lc", 187);
			ploop(5, ' ');
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc\n",191);
		}
		else if(i==16){
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc", 217);
			ploop(5, ' ');
			printf("%lc", 200);
			ploop(31, 205);
			printf("%lc", 188);
			ploop(5, ' ');
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc\n",217);
		}
		else{
			if(i%2!=0){
				if(showCase[c1].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			ploop(5, ' ');
			printf("%lc", 186);
			if(i==5){
				if(selected_case==user_case){
					char text[]={"Your case"};
					ploop((31-strlen(text))/2, ' ');
					printf(text);
					ploop((31-strlen(text))/2, ' ');
				}
				else{
					char text[]={"Case number A"};
					ploop((31-strlen(text))/2, ' ');
					text[12]=selected_case+'A';
					printf(text);
					ploop((31-strlen(text))/2, ' ');
				}
			}
			else if(i>=7 && i<=10){
				if(i==7){
					ploop(8, ' ');
					printf("%lc", 201);
					ploop(13, 205);
					printf("%lc", 187);
					ploop(8, ' ');
				}
				else if(i==9){
					ploop(8, ' ');
					printf("%lc", 200);
					ploop(13, 205);
					printf("%lc", 188);
					ploop(8, ' ');
				}
				else if(i==10){
					ploop(13, ' ');
					printf("Points");
					ploop(12, ' ');
				}
				else{
					ploop(8, ' ');
					if(point>0){
						printf("%lc %-11d %lc", 186, point, 186);
					}
					else{
						printf("%lc             %lc", 186, 186);
					}
					ploop(8, ' ');
				}
			}
			else{
				ploop(31, ' ');
			}
			printf("%lc", 186);
			ploop(5, ' ');
			if(i%2!=0){
				if(showCase[c1+8].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1+8].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
				c1++;
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			printf("\n");
		}
	}
}

void display_bank_offer(struct game_point game[], struct game_point showCase[], int *bank_offer, int prev_bank_offer[], int offer){
	printf("\n");
	int c1=0, n=0;
	for(int i=0; i<=16; i++){
		ploop(5, ' ');//left margin
		if(i==0){
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc", 191);
			ploop(5, ' ');
			printf("%lc", 201);
			ploop(31, 205);
			printf("%lc", 187);
			ploop(5, ' ');
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc\n",191);
		}
		else if(i==16){
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc", 217);
			ploop(5, ' ');
			printf("%lc", 200);
			ploop(31, 205);
			printf("%lc", 188);
			ploop(5, ' ');
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc\n",217);
		}
		else{
			if(i%2!=0){
				if(showCase[c1].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			ploop(5, ' ');
			printf("%lc", 186);
			if(i==1){
				char text[31]={" Prev Offer: "};
				for(int i=0; i<offer; i++){
					char str[3]={0};
					int_to_char(prev_bank_offer[i], str);
					strcat(text, str);
					if(i!=offer-1){
						strcat(text, ", ");
					}
				}
				printf("%s", text);
				ploop(31-strlen(text), ' ');
			}
			else if(i==4){
				char text[]={"Bank Offer:"};
				ploop((31-strlen(text))/2, ' ');
				printf(text);
				ploop((31-strlen(text))/2, ' ');
			}
			else if(i>=6 && i<=9){
				if(i==6){
					ploop(8, ' ');
					printf("%lc", 201);
					ploop(13, 205);
					printf("%lc", 187);
					ploop(8, ' ');
				}
				else if(i==8){
					ploop(8, ' ');
					printf("%lc", 200);
					ploop(13, 205);
					printf("%lc", 188);
					ploop(8, ' ');
				}
				else if(i==9){
					ploop(13, ' ');
					printf("Points");
					ploop(12, ' ');
				}
				else{
					long temp=0;
					for(int i=0; i<TOTAL_CASE; i++){
						if(showCase[i].show==1){
							temp=(showCase[i].point*showCase[i].point)+temp;
							n++;
						}
					}
					int ans=temp/n;
					*bank_offer=sqrt(ans);
					ploop(8, ' ');
					printf("%lc %-11d %lc", 186, *bank_offer, 186);
					ploop(8, ' ');
				}
			}
			else if(i>11 && i<15){
				if(i==12){
					printf("   %lc", 218);
					ploop(6, 196);
					printf("%lc", 191);
					ploop(4, ' ');
					printf("  %lc", 218);
					ploop(9, 196);
					printf("%lc   ", 191);
				}
				else if(i==14){
					printf("   %lc", 192);
					ploop(6, 196);
					printf("%lc", 217);
					ploop(4, ' ');
					printf("  %lc", 192);
					ploop(9, 196);
					printf("%lc   ", 217);
				}
				else{
					printf("   %lc", 179);
					printf(" Deal ");
					printf("%lc", 179);
					ploop(4, ' ');
					printf("  %lc", 179);
					printf(" No Deal ");
					printf("%lc   ", 179);
				}
			}
			else{
				ploop(31, ' ');
			}
			printf("%lc", 186);
			ploop(5, ' ');
			if(i%2!=0){
				if(showCase[c1+8].show==1){
					printf("%lc %-4d %lc", 179, showCase[c1+8].point, 179);
				}
				else{
					printf("%lc ~~~~ %lc", 179, 179);
				}
				c1++;
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			printf("\n");
		}
	}
}
	
void display_win(int win){
	printf("\n");
	int c1=0, bank=0;
	for(int i=0; i<=16; i++){
		ploop(5, ' ');//left margin
		if(i==0){
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc", 191);
			ploop(5, ' ');
			printf("%lc", 201);
			ploop(31, 205);
			printf("%lc", 187);
			ploop(5, ' ');
			printf("%lc", 218);
			ploop(6, 196);
			printf("%lc\n",191);
		}
		else if(i==16){
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc", 217);
			ploop(5, ' ');
			printf("%lc", 200);
			ploop(31, 205);
			printf("%lc", 188);
			ploop(5, ' ');
			printf("%lc", 192);
			ploop(6, 196);
			printf("%lc\n",217);
		}
		else{
			if(i%2!=0){
				printf("%lc %-4d %lc", 179, POINT[c1], 179);
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			ploop(5, ' ');
			printf("%lc", 186);
			if(i==5){
				char text[]={"You Win"};
				ploop((31-strlen(text))/2, ' ');
				printf(text);
				ploop((31-strlen(text))/2, ' ');
			}
			else if(i>=7 && i<=10){
				if(i==7){
					ploop(8, ' ');
					printf("%lc", 201);
					ploop(13, 205);
					printf("%lc", 187);
					ploop(8, ' ');
				}
				else if(i==9){
					ploop(8, ' ');
					printf("%lc", 200);
					ploop(13, 205);
					printf("%lc", 188);
					ploop(8, ' ');
				}
				else if(i==10){
					ploop(13, ' ');
					printf("Points");
					ploop(12, ' ');
				}
				else{
					ploop(8, ' ');
					printf("%lc %-11d %lc", 186, win, 186);
					ploop(8, ' ');
				}
			}
			else{
				ploop(31, ' ');
			}
			printf("%lc", 186);
			ploop(5, ' ');
			if(i%2!=0){
				printf("%lc %-4d %lc", 179, POINT[c1+8], 179);
				c1++;
			}
			else{
				printf("%lc", 195);
				ploop(6, 196);
				printf("%lc", 180);
			}
			printf("\n");
		}
	}
	ploop(23, ' ');
}

//play arena
int game(){
	cln();
	header();
	int playersCase=-1, win_poin=0;
	struct game_point game[TOTAL_CASE+1]; //random cases
	struct game_point showCase[TOTAL_CASE+1]; //all case value
	for(int i=0; i<TOTAL_CASE; i++){
		game[i].point=POINT[i];
		game[i].show=1;
		showCase[i].point=POINT[i];
		showCase[i].show=1;
	}
	display_table(game, showCase, playersCase);
	delay(1000);
	cln();
	
	int atob[TOTAL_CASE]={0}, btoa[TOTAL_CASE]={0};
	generate_random(atob, btoa);
	char x;
	for(int i=0; i<TOTAL_CASE; i++){
		game[i].point=showCase[btoa[i]].point;
		game[i].show=0;
	}
	while(true){
		cln();
		header();
		display_table(game, showCase, playersCase);
		ploop(25, ' ');
		printf("Choose your case number.");
		scanf("%c", &x);
		getchar();
		playersCase=x-'a';
		if((playersCase>=0) && (playersCase<=15)){
			game[playersCase].show=0;
			break;
		}	
	}
	win_poin=game[playersCase].point;
	int prev_bank_offer[5]={0}, offer=0;
	for(int i=5; i>1; i--){
		prev_bank_offer[offer]=-1;
		int open_case=i;
		//player choose case 
		while(open_case>0){
			cln();
			header();
			int choose=0;
			display_table(game, showCase, playersCase);
			ploop(18, ' ');
			printf("You have %d left. Choose case number.", open_case);
			scanf("%c", &x);
			getchar();
			choose=x-'a';
			if(choose>=0 && choose<=15 && game[choose].show!=1 && playersCase!=choose && showCase[btoa[choose]].show!=0){
				cln();
				header();
				display_open_case(showCase, -1, choose, playersCase);
				delay(2000);
				showCase[btoa[choose]].show=0;
				game[choose].show=1;
				cln();
				header();
				display_open_case(showCase, showCase[btoa[choose]].point, choose, playersCase);
				open_case--;
				delay(3000);
			}
		}
		while(true){
			cln();
			header();
			int bank=0;
			display_bank_offer(game, showCase, &bank, prev_bank_offer, offer);
			char yn;
			scanf("%c", &yn);
			getchar();
			if(yn=='y'){
				cln();
				header();
				display_open_case(showCase, -1, playersCase, playersCase);
				delay(2000);
				cln();
				header();
				display_open_case(showCase, showCase[btoa[playersCase]].point, playersCase, playersCase);
				delay(3000);
				return bank;
			}
			else if(yn=='z'){
				prev_bank_offer[offer]=bank;
				offer++;
				break;
			}
		}
	}
	cln();
	header();
	display_open_case(showCase, -1, playersCase, playersCase);
	delay(2000);
	cln();
	header();
	display_open_case(showCase, showCase[btoa[playersCase]].point, playersCase, playersCase);
	delay(3000);
	return win_poin;
}

void start(long int user_point, long int user_coin){
	cln();
	header();
	display_start();
	printf("\n");
	char print_char[2][35]={"Poin : ", "Koin : "};
	char point[10]={0}, coin[10]={0};
	int_to_char(user_point, point);
	int_to_char(user_coin, coin);
	strcat(print_char[0], point);
	strcat(print_char[1], coin);
	for(int i=0; i<2; i++){
		ploop(((31-strlen(print_char[i]))/2)+18, ' ');
		printf("%s\n", print_char[i]);
	}
	//7125=play, 4925=point_to_coin, 5723=insert_coin
	char menu;
	scanf("%c", &menu); getchar();
	switch(menu){
		case('t'):{
			if(user_point>POINT_TO_COIN){
				user_coin=(user_point/POINT_TO_COIN)+user_coin;
				user_point=user_point%POINT_TO_COIN;
			}
			start(user_point, user_coin);
			break;
		}
		case('q'):{
			user_coin++;
			start(user_point, user_coin);
			break;
		}
		case('r'):{
			if(user_coin>0){
				user_coin--;
				int win=0;
				win=game();
				cln();
				header();
				display_win(win);
				delay(5000);
				user_point=user_point+win;
			}
			start(user_point, user_coin);
			break;
		}
		default:{
			start(user_point, user_coin);
			break;
		}
	}
}

int main(){
	long int user_point=0, user_coin=0;
	start(user_point, user_coin);
	return 0;
}


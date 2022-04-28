#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int wth=20,hgt=20;
int x,y,frtx,frty,score,gameover,flg;
int tlx[100],tly[100];
int cnttl=0,score=0;
void setup(){
	gameover=0;
	x=hgt/2;
	y=wth/2;
	label1:
	frtx=rand()%20;
	if(frtx==0)
		goto label1;
	label2:
	frty=rand()%20;
	if(frty==0)
		goto label2;
	score=0;

}
void draw(){
	int i,j,k;
	system("cls");
	for(i=0;i<wth;i++){
		for(j=0;j<hgt;j++){
			if(i==0||i==wth-1||j==0||j==hgt-1){
				printf("*");
			}else{
				if(i==x && j==y){
					printf("0");
				}
				else if(i==frtx && j==frty){
					printf("F");
				}
				else{
					int ch=0;
					for(k=0;k<cnttl;k++){
						if(i==tlx[k] && j==tly[k]){
							printf("o");
							ch=1;
						}
					}
					if(ch==0)
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	printf("SCORE = %d",score);
}
void input(){
	if(kbhit()){
		switch(getch()){
			case 'a': flg=1;
				break;
			case 'd': flg=2;
				break;
			case 'w': flg=3;
				break;
			case 'z':flg=4;
				break;
			case 'x':gameover=1;
				break;
		}
	}
}
void logic(){
	int i;
	int prevx=tlx[0];
	int prevy=tly[0];
	int prev2x,prev2y;
	tlx[0]=x;
	tly[0]=y;
	for(i=1;i<cnttl;i++){
		prev2x=tlx[i];
		prev2y=tly[i];
		tlx[i]=prevx;
		tly[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}

	switch(flg){
		case 1: y--;
			break;
		case 2: y++;
			break;
		case 3: x--;
			break;
		case 4: x++;
			break;
		default: break;
	}
	if(x<0||x>wth||y<0||y>hgt){
		gameover=1;
	}
	for(i=0;i<cnttl;i++){
		if(x==tlx[i] && y==tly[i])
		gameover=1;
	}
	if(x==frtx && y==frty ){
		label3:
		frtx=rand()%20;
		if(frtx==0)
			goto label3;
		label4:
		frty=rand()%20;
		if(frty==0)
			goto label4;
		score+=10;
		cnttl++;
	}
}
void main(){
	int m,n;
	char c;
	clrscr();
	label5:
	setup();

	while(!gameover){
		draw();
		input();
		logic();
		for(m=0;m<1000;m++){
			for(n=0;n<1000;n++){
			}
		}
	}
	printf("\n press y to continue:");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
		 goto label5;
	getch();
}

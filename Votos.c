#include<stdio.h>
#include<stdlib.h>
#include<conio.c>
#include<string.h>
#include<locale.h>

#define NOME_DO_DONO "RONALDO MONA"
#define DEPUTADOS_CODIGO 1101010
#define PASSWORD_REL 1111010

int contcandlog,howuser,howcand,howdeput,vrs;
float porcent;
char vencedor[30];

typedef struct{
	
	char nome[25],namepart[25],password[50];
	int totalvotos,deputados,eleitores,exist,numero;
	float porcentvot;
}user_candidatos;

typedef struct{
	
	char nome[25],candidatovoto[25],nif[25];
	int exist;
	
	
}user_eleitores;

typedef struct{
	
	char nome[25],candidatovoto[25];
	int exist;
	
}user_deputados;

user_candidatos candidatos[11];
user_eleitores eleitores[110];
user_deputados deputados[90];


void criptograpycand(){
	
	int i;
	
	FILE *candidatos=fopen("candidatos.itls.txt","r+");
	fseek(candidatos,0,SEEK_END);
	long space=ftell(candidatos);
	void *putmemori=malloc(space);
	rewind(candidatos);
	fread(putmemori,space,1,candidatos);
	fclose(candidatos);
	
	for(i=0;i<space;i++){
		                    
	*(char *)(putmemori + i)+=1;
	
	}
	
	FILE *candidatpsc=fopen("candidatos.itls.txt","w+");
	fwrite(putmemori,space,1,candidatpsc);
	fclose(candidatpsc);
	
}

void desccriptograpycand(){
	
	int i;
	
	FILE *candidatos=fopen("candidatos.itls.txt","r+");
	fseek(candidatos,0,SEEK_END);
	long space=ftell(candidatos);
	void *putmemori=malloc(space);
	rewind(candidatos);
	fread(putmemori,space,1,candidatos);
	fclose(candidatos);
	
	for(i=0;i<space;i++){
		                    
	*(char *)(putmemori + i)-=1;
	
	}
	
	FILE *candidatpsc=fopen("candidatos.itls.txt","w+");
	fwrite(putmemori,space,1,candidatpsc);
	fclose(candidatpsc);
	
	
}

void savedates(){
	
	FILE *candidatpsc=fopen("candidatos.itls.txt","w+");
	fwrite(candidatos,sizeof(candidatos),1,candidatpsc);
	fclose(candidatpsc);
	
		FILE *eleitore=fopen("eleitores.itls.txt","w+");
	fwrite(eleitores,sizeof(candidatos),1,eleitore);
	fclose(eleitore);
	
		FILE *deputado=fopen("deputados.itls.txt","w+");
	fwrite(candidatos,sizeof(candidatos),1,deputado);
	fclose(deputado);
	
	criptograpycand();
	
}

void getdatessaves(){
	desccriptograpycand();
		FILE *candidatpsc=fopen("candidatos.itls.txt","r+");
	fread(candidatos,sizeof(candidatos),1,candidatpsc);
	fclose(candidatpsc);
	
		FILE *eleitore=fopen("eleitores.itls.txt","r+");
	fread(eleitores,sizeof(candidatos),1,eleitore);
	fclose(eleitore);
	
		FILE *deputado=fopen("deputados.itls.txt","r+");
	fread(candidatos,sizeof(candidatos),1,deputado);
	fclose(deputado);
	
	
}


void  backlog(){
	char value;
	printf("\t\t\t\tDeseja continuar para a pagina de candidatos:");
	scanf("%c",&value);
	fflush(stdin);
	switch(value){
		
		case 's':
			logindecandy();
		break;
		
		case 'n':
		system("cls");
		printf("Volte sempre");
		savedates();
		break;	
		
		default:
		backlog();
		break;	
		
	}
}

void  backini(){
	char value2;
	printf("\t\t\t\tDeseja continuar para a pagina de candidatos s-[sim] n-[não]:");
	scanf("%c",&value2);
	fflush(stdin);
	switch(value2){
		
		case 's':
			fflush(stdin);
			system("color 07");
			pagemain();
		break;
		
		case 'n':
		system("cls");
		printf("Volte sempre");
		savedates();
		break;	
		
		default:
			printf("opção digitada errada só deves escolher s para [sim] e n para [não]\n");
		backini();
		break;	
		
	}
}



int logindecandy (){
	
		int seletion_2;
		
		system("cls");
	textcolor(1);printf("\t\t\t\t\t#");
	textcolor(2);printf("    OPÇÕES PARA CANDIDATOS\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(5);printf("     1-|ENTRAR NA SUA CONTA|\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t");
	textcolor(1);printf("\t\t\t\t\t\t\t\t|\t");
	textcolor(3);printf("2-|CANDIDATAR-SE|");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(8);printf("     3-|VOLTAR|");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(4);printf("\t       OPÇÃO");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(1);printf("\t\t\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	gotoxy(58,11);
	scanf("%i",&seletion_2);
	fflush(stdin);

	
	switch(seletion_2){
		
		case 1:
			system("cls");
			int i2=1,cmpv2;
			char name2[25],chave2[50],valid=3;
			
		textcolor(1);printf("\t\t\t\t\t\tLOGIN PARA CANDIDATOS\n");
	
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t#\t");
	textcolor(2);printf("       LOGIN\t\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(3);printf("    |CANDIDATO|\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t");
	textcolor(1);printf("\t\t\t\t\t\t\t\t|\t");
	textcolor(4);printf("    |PASSWORD|");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	textcolor(1);printf("\t|\t");
	textcolor(5);printf(" PRESSIONA ENTER");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	gotoxy(45,6);
	gets(name2);
	gotoxy(45,9);
	gets(chave2);
	fflush(stdin);
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			
			
		
			
			while(i2<10){
				
				cmpv2=strcmp(name2,candidatos[i2].nome);
				
				if(cmpv2==0){
			
				
				cmpv2=strcmp(chave2,candidatos[i2].password);
					
					if(cmpv2==0){
						
					contcandlog=i2;
					i2=10;
					interfacecandy();
						
					}else{
					system("cls");
					while(valid>0){
						
					printf("password errada tenta novamente:");
					gets(chave2);	
						
					cmpv2=strcmp(chave2,candidatos[i2].password);
					
					if(cmpv2==0){
						
					contcandlog=i2;
					i2=10;
					valid=3;
					interfacecandy();
						
					}
						
						
						valid--;
					}printf("Atingiu o limite de tentativas\n");backlog();
					

						
					}
					
				
					
				}
				
				i2++;
				
			}
			
			if(i2>=10){
					
					printf("\t\t\t\tEste candidato não existe\n");
					backlog();
					
			}
	
		break;	
		
		case 2:
			system("cls");
			int i,control_space=0,cmp1,cmp2,cmp3;
			char name[25],partido[25],chave[50];
			
			for(i=1;i<10;i++){
				if(candidatos[i].exist==1){
					control_space++;
				}
			}
			
			if(control_space >=10){
				
				printf("Já não há espaço para cadastro de eleitores\n");
				backlog();
				
			}
			
			
			
	textcolor(1);printf("\t\t\t\t\t     CADASTRO PARA CANDIDATOS\n");
	
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t#\t");
	textcolor(2);printf("    CADASTRAR-SE\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(3);printf("       |NOME DO CANDIDATO|\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(6);printf("|NOME DO PARTIDO|\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t");
	textcolor(1);printf("\t\t\t\t\t\t\t\t|\t");
	textcolor(4);printf("    |PASSWORD|");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	textcolor(1);printf("\t|\t");
	textcolor(5);printf(" PRESSIONA ENTER");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	gotoxy(45,6);
	gets(name);
	gotoxy(45,9);
	gets(partido);
	gotoxy(45,12);
	gets(chave);
	fflush(stdin);
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			for(i=1;i<10;i++){
			cmp1=strcmp(name,candidatos[i].nome);	
			cmp2=strcmp(partido,candidatos[i].namepart);
			cmp3=strcmp(chave,candidatos[i].password);
				
				if(cmp1==0||cmp2==0||cmp3==0){
					system("cls");
					printf("Uma das características adicionadas já está a  ser utilizada\n");
					backlog();
				}
				
			}
			
			for(i=1;i<10;i++){

				
				if(candidatos[i].exist==0){
					
			strcpy(candidatos[i].nome,name);	
			strcpy(candidatos[i].namepart,partido);
			strcpy(candidatos[i].password,chave);
			howcand++;
			candidatos[i].numero=i;
			candidatos[i].exist=1;
			printf("\t\t\t\tConta cadastrada no sistema com sucesso\n");
			i=10;
			backlog();		
				
				}
				
			}
			
			
		break;	
		
		case 3:
			system("cls");
			pagemain();
		break;		
		
		default:
			
			logindecandy();
			
		break;	
		
	}
	
	return 0;
	
}
	



int pagemain(){
	system("cls");
	fflush(stdin);
	system("color 0");
	int seletion;
	textcolor(1);printf("\t\t\t\t\t#\t");
	textcolor(2);printf("       OPÇÕES\t\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(5);printf("  1-|CANDIDATURA|\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t");
	textcolor(1);printf("\t\t\t\t\t\t\t\t|\t");
	textcolor(3);printf("    2-|VOTAR|");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(8);printf("     3-|VOTAR COMO DEPUTADO|");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
		textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(7);printf("   4-|RELATÓRIO|");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
		textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(6);printf("5-|SAIR E SALVAR|");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(4);printf("\t       OPÇÃO");
	textcolor(1);printf("\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|");
	textcolor(1);printf("\t\t\t\t|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	gotoxy(57.5,15);
	scanf("%i",&seletion);
	fflush(stdin);
	
	switch(seletion){
		
		case 1:
			
			logindecandy();
		break;	
		
		case 2:
			system("cls");
			char name3[25];
			int voto,cont,cont2,cmp4,cmp42;
			
			if(howcand==0){
						printf("\t\t\t\tAINDA NÃO CANDIDATOS PARA VOTAR\n");
						backini();
					}
					
			
					textcolor(1);printf("\t\t\t\t\tPAGINA PARA VOTOS DE ELEITOR\n");
	
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t#\t");
	textcolor(2);printf("       VOTAR\t\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(3);printf("    |ELEITOR|\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(5);printf(" PRESSIONA ENTER");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	gotoxy(45,6);
	gets(name3);
	fflush(stdin);
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			
			
			for(cont=1;cont<109;cont++){
				cmp4=strcmp(name3,eleitores[cont].nome);
				cmp42=strcmp(name3,deputados[cont].nome);
				
				if(cmp4==0 || cmp42==0){
				printf("\t\t\t\tEste utilizador já votou ou tú estás a usar nome errado\n");
				cont=109;
				backini();
				}
			
			}
			
				for(cont=1;cont<109;cont++){
				
				if(eleitores[cont].exist==0){
					eleitores[cont].exist==1;
					strcpy(eleitores[cont].nome,name3);
					howuser++;
					cont=109;
					system("cls");
					//placar para votar
					for(cont2=1;cont2<10;cont2++){
						puts(eleitores[cont].nome);
						if(candidatos[cont2].exist==1){
							textcolor(1);printf("_________________________________\n");	
							textcolor(2);printf("Candidato:%s\n",candidatos[cont2].nome);	
							textcolor(3);printf("Número:%d\n",candidatos[cont2].numero);
							textcolor(4);printf("Partido:%s\n",candidatos[cont2].namepart);
							textcolor(5);printf("Total de votos:%d\n",candidatos[cont2].totalvotos);
							textcolor(6);printf("Deputados:%d\n",candidatos[cont2].deputados);
							textcolor(7);printf("Eleitores:%d\n",candidatos[cont2].eleitores);
							printf("\n");
							
						}
					
						
					}
					
					
					printf("\t\t\t\tDigite o número do candidato que deseja votar:");
					scanf("%d",&voto);
					fflush(stdin);
					
					
					if(candidatos[voto].exist==0){
						printf("Este candidato não existe\n");
						backini();
					};
					
					candidatos[voto].eleitores++;
					strcpy(eleitores[cont].candidatovoto,candidatos[voto].nome);
					backini();
					
				}
				
				
			}
			
			
			
			
			
		break;	
		
		case 3:
			
						system("cls");
						
			char name4[25];
			int voto1,cont1,cont3,cmp5,cmp52,codigo;
			
			if(howcand==0){
						printf("\t\t\t\tAINDA NÃO HÁ CANDIDATOS PARA VOTAR\n");
						backini();
					}
			
			printf("\t\t\t\tDigite o codigo para votar como deputado:");
			scanf("%d",&codigo);
			fflush(stdin);
			if(codigo==DEPUTADOS_CODIGO){
				
				system("cls");
					textcolor(1);printf("\t\t\t\t\tPAGINA PARA VOTOS DE DEPUTADOS\n");
	
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t#\t");
	textcolor(2);printf("       VOTAR\t\t");
	textcolor(1);printf("#\n");
	textcolor(1);printf("\t\t\t\t\t_________________________________\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(3);printf("    |DEPUTADO|\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\t\t\t\t\n");
	textcolor(1);printf("\t\t\t\t\t|\t");
	textcolor(5);printf(" PRESSIONA ENTER");
	textcolor(1);printf("\t|\n");
	textcolor(1);printf("\t\t\t\t\t|\t\t\t\t");
	textcolor(1);printf("|\n");
	textcolor(1);printf("\t\t\t\t\t|_______________________________|\n\t\t\t\t");
	gotoxy(45,6);
	gets(name4);
	fflush(stdin);
	
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			
			
			for(cont1=1;cont1<109;cont1++){
				cmp5=strcmp(name4,deputados[cont1].nome);
				cmp52=strcmp(name4,eleitores[cont1].nome);
				if(cmp5==0 || cmp52==0){
				printf("\t\t\t\tEste utilizador já votou ou tú estás a usar nome errado\n");
				cont1=109;
				backini();
				}
			
			}
			
				for(cont1=1;cont1<109;cont1++){
				
				if(deputados[cont1].exist==0){
					deputados[cont1].exist==1;
					strcpy(deputados[cont1].nome,name4);
					howdeput++;
					cont=109;
					system("cls");
					//placar para votar
					for(cont3=1;cont3<10;cont3++){
						
						if(candidatos[cont3].exist==1){
							textcolor(1);printf("_________________________________\n");	
							textcolor(2);printf("Candidato:%s\n",candidatos[cont3].nome);	
							textcolor(3);printf("Número:%d\n",candidatos[cont3].numero);
							textcolor(4);printf("Partido:%s\n",candidatos[cont3].namepart);
							textcolor(5);printf("Total de votos:%d\n",candidatos[cont3].totalvotos);
							textcolor(6);printf("Deputados:%d\n",candidatos[cont3].deputados);
							textcolor(7);printf("Eleitores:%d\n",candidatos[cont3].eleitores);
							printf("\n");
							
						}
					
						
					}
					
					
					
					printf("\t\t\t\tDigite o número do candidato que deseja votar:");
					scanf("%d",&voto1);
					fflush(stdin);
					
					if(candidatos[voto1].exist==0){
						printf("Este candidato não existe\n");
						backini();
					};
					
					candidatos[voto1].deputados++;
					strcpy(deputados[cont1].candidatovoto,candidatos[voto1].nome);
					backini();
					
				}
				
				
			}
				
				
			}else{
				fflush(stdin);
				system("color 47");
				printf("\t\t\t\tCodigo digitado errado\n");
				backini();
				
			}
			
			
		break;	
		
		case 4:
		system("cls");
		int codr;
		
		porcent=(howdeput+howuser)/100;
		
		printf("Digite o codigo para o relatório:");	
		scanf("%d",&codr);	
		fflush(stdin);
		
		if(codr==PASSWORD_REL){
			
			system("cls");
			
		/*
		
		user_candidatos candidatos[11];
		user_eleitores eleitores[110];
		user_deputados deputados[90];
		
		*/
			
			int show1,show2,show3,showvnc,showvt;
			
			if(howcand>0){
				for(showvt=1;showvt<10;showvt++){
					
					if(candidatos[showvt].exist>0){
						
						candidatos[showvt].totalvotos=candidatos[showvt].deputados+candidatos[showvt].eleitores;
						candidatos[showvt].porcentvot=porcent*candidatos[showvt].totalvotos;
						
					}
					
				}
				
			}
		
		//part1	
			if(howcand >0){
			
			for(show1=1;show1<10;show1++){
				
			if(candidatos[show1].exist>0){
				
				printf("NOME:%s\n",candidatos[show1].nome);
				printf("PARTIDO:%s\n",candidatos[show1].namepart);
				printf("CANDIDATO NÚMERO:%d\n",candidatos[show1].numero);
				printf("DEPUTADOS:%d\n",candidatos[show1].deputados);
				printf("ELEITORES:%d\n",candidatos[show1].eleitores);
				printf("TOTAL DE VOTOS:%d\n",candidatos[show1].totalvotos);
				printf("PORCENTO DE VOTOS:%f\n",candidatos[show1].porcentvot);
				
			}	
				
			}
				
			}else{
				
				printf("NÃO HÁ CANDIDATOS REGISTRADOS\n");
				
			}
			
			fflush(stdout);
			printf("\n\n\n");
			
			//parte 2
			
			if(howuser>0){
			
			for(show2=1;show2<109;show2++){
				
			if(eleitores[show2].exist==1){
				
				printf("NOME:%s\n",eleitores[show2].nome);
				printf("NÚMERO:%d\n",show2);
				printf("CANDIDATO QUE VOTOU:%s\n",eleitores[show2].candidatovoto);
				
			}	
				
			}
				
			}else{
				
				printf("NÃO HÁ ELEITORES REGISTRADOS\n");
				
			}
			
			fflush(stdout);
			printf("\n\n\n");
			//parte3
			
			
			if(howdeput>0){
			
			for(show3=1;show3<90;show3++){
				
			if(deputados[show3].exist==1){
				
				printf("NOME:%s\n",deputados[show3].nome);
				printf("NÚMERO:%d\n",show3);
				printf("CANDIDATO QUE VOTOU:%s\n",deputados[show3].candidatovoto);
				
			}	
				
			}
				
			}else{
				
				printf("NÃO HÁ DEPUTADOS REGISTRADOS\n");
				
			}
			printf("\n\n\n");
			fflush(stdout);
			printf("TOTAL DE PESSOAS:%d\n",howdeput+howuser);
			printf("TOTAL DE CANDIDATOS:%d\n",howcand);
			printf("TOTAL DE ELEITORES:%d\n",howuser);
			printf("TOTAL DE DEPUTADOS:%d\n",howdeput);
			
			for(showvnc=1;showvnc< 10;showvnc++){
				
				if(candidatos[showvnc].totalvotos>candidatos[showvnc+1].totalvotos){
					
					strcpy(vencedor,candidatos[showvnc].nome);
					
				}else{
					
				strcpy(vencedor,candidatos[showvnc+1].nome);	
					
				}
				
			}
			fflush(stdin);
			printf("\n");
			printf("VENCEDOR TEMPORARIO:%s\n",vencedor);
			backini();
			
			
			
		}else{
		fflush(stdin);
				system("color 47");
				system("cls");
				printf("\t\t\t\tCodigo digitado para o acesso ao  relatório errado\n");
				backini();	
		}
		
			
		break;	
		
		case 5:
			savedates();
		break;	
		
		default:
			
			pagemain();
			
		break;	
		
	}
return 0;
}


int interfacecandy(){
	system("cls");
	int contadorcont;
	printf("CANDIDATO CONTA:%s\n",candidatos[contcandlog].nome);
		
		textcolor(3);printf("MEU Número:%d\n",candidatos[contcandlog].numero);
		textcolor(4);printf("MEU Partido:%s\n",candidatos[contcandlog].namepart);
		textcolor(5);printf("Total dos meus votos:%d\n",candidatos[contcandlog].totalvotos);
		textcolor(6);printf("Deputados que me votaram :%d\n",candidatos[contcandlog].deputados);
		textcolor(7);printf("Eleitores que me votaram:%d\n",candidatos[contcandlog].eleitores);
		printf("\n");
	
	for(contadorcont=1;contadorcont<10;contadorcont++){
						
						if(candidatos[contadorcont].exist==1){
							
							if(candidatos[contadorcont].numero == contcandlog){
							continue;
							}else{
							
							textcolor(1);printf("_________________________________\n");	
							textcolor(2);printf("Candidato:%s\n",candidatos[contadorcont].nome);	
							textcolor(3);printf("Número:%d\n",candidatos[contadorcont].numero);
							textcolor(4);printf("Partido:%s\n",candidatos[contadorcont].namepart);
							textcolor(5);printf("Total de votos:%d\n",candidatos[contadorcont].totalvotos);
							textcolor(6);printf("Deputados:%d\n",candidatos[contadorcont].deputados);
							textcolor(7);printf("Eleitores:%d\n",candidatos[contadorcont].eleitores);
							printf("\n");	
								
							}
							
						
							
						}
					
						
					}
					
					contcandlog=0;
					backini();
	
	return 0;	
	
}


int main(int argc,char *argv[]){
	setlocale(LC_ALL,"PORTUGUESE");
		getdatessaves();
	pagemain();
	
	getch();
	return 0;
}

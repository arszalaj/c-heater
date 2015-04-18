// PB_sym.cpp : main project file.

//Graf komunikacyjny
#include "stdafx.h"

#include <string.h>
#include <stdio.h>

//----------------- definicje zmiennych systemowych  ----------------
//
//------------------ NIE WOLNO TU NIC ZMIENIAC !!! ----------------
//

extern char X1, X2, X3, TM;           // stany czujnikow obiektu
extern char Z1, Z2, Z3, GR;           // stany zaworow obiektu

extern char aK1, aK2, aK3, aK4;       // stany klawiszy panelu
extern char L1, L2, L3, L4;           // stany LEDów panelu
extern char line1[80], line2[80];     // bufory dla wyswietlacza LCD

char recv_char();              // znak nades³any z konsoli (0=brak znaków)
void send_char(char cc);       // wyœlij jeden znak ASCII z PB na konsolê
void send_string(char * s);    // wyœlij tekst (string) z PB na konsolê


// ------------------- obs³uga komunikacji ------------------------------

char sym_recv_char(void);
void sym_send_char(char cc);
void sym_send_string(char * s);
void sym_trans_char(char cc);
void sym_trans_string(char * s);


// ----------------- obs³uga komunikatów z obiektu  ---------------------

char stan_s=1;        // stan grafu dla komunikacji z obiektem
char znak_s=0;        // odebrany znak komunikatu z obiektu


void int_sym_znak()   // wywo³ywana przerwaniowo gdy odebrano znak z obiektu
{
	znak_s=sym_recv_char();

	// ------------------------ os³uga kolejnych znaków komunikatu ------
	switch(stan_s) {
	case 1: if (znak_s==':') stan_s=2; else stan_s=1;      // znak ':'
		break;
	case 2: if (znak_s=='1') { stan_s=3; X1=1; }  
			else
				if (znak_s=='0') { stan_s=3; X1=0; }  
				else 
					stan_s=1;                 // b³ad - szukaj od poczatku
		break;
	case 3: if (znak_s=='1') { stan_s=4; X2=1; }  
			else
				if (znak_s=='0') { stan_s=4; X2=0; }  
				else 
					stan_s=1;                 // b³ad - szukaj od poczatku
		break;
	case 4: if (znak_s=='1') { stan_s=5; X3=1; }  
			else
				if (znak_s=='0') { stan_s=5; X3=0; }  
				else 
					stan_s=1;                 // b³ad - szukaj od poczatku
		break;
	case 5: if (znak_s=='1') { stan_s=1; TM=1; }  
			else
				if (znak_s=='0') { stan_s=1; TM=0; }  
				else 
					stan_s=1;                 // b³ad - szukaj od poczatku
		break;
	}
}


void out_sym_val(void)  // wys³anie komunikatu do obiektu (stan zaworów) 
{
	sym_send_char(':');
	sym_send_char(Z1+'0');
	sym_send_char(Z2+'0');        // wyslij komunikat o stanie zaworów 
	sym_send_char(Z3+'0');
	sym_send_char(GR+'0');

	sym_send_char('\r');          // wyœlij dodatkowo znaki CR, LF
	sym_send_char('\n');
}


// ----------------- obs³uga komunikatów z konsoli  ---------------------

char stank=1;        // stan grafu dla komunikacji z konsol¹
char znak=0;        // odebrany znak komunikatu z konsoli
char KL;

char x, y, z,a, cs, T1=50, T2=30, KL1, KL2;
int T3 = 10;


extern char Z1_,Z2_,Z3_,G_, X1_, X2_, X3_ ,TM_, LD;
void int_znak()       // wywo³ywana przerwaniowo gdy odebrano znak z konsoli
{

	znak=recv_char();

	if(znak !=0)
		switch(stank)
		{
		case 1:
			if(znak == ':')
				stank = 2;
			break;
		case 2:
			if(znak == 'A')
				stank=3;
			else if(znak == 'B')
				stank=4; 
			else  if(znak >= '1' && znak <= '9') { stank=5; x=znak-'0';}
			else stank=1;
			break;
		case 3:
			if(znak=='#'){
			cs=(T1/10+T2/10+T3/10)%2;
			send_char(':');
			send_char(T1/10+'0');
			send_char(T2/10+'0');
			send_char(T3/10+'0');
			send_char(cs+'0');
			send_char('#');
			stank=1;
			}
			/*else if(znak >= '0' && znak <= '2')
			{
				x = znak - '0';
				stank = 3;
			}*/
			else 
				stank = 1;
			break;
		case 4:
			if(znak=='#'){
			cs=(4-(Z1+Z2+Z3)%4)%4;
			send_char(':');
			send_char(Z1+'0');
			send_char(Z2+'0');
			send_char(Z3+'0');
			send_char(cs+'0');
			send_char('#');
			stank=1;
			}
			/*else if(znak >= '0' && znak <= '2')
			{
				x = znak - '0';
				stank = 3;
			}*/
			else 
				stank = 1;
			break;
		case 5:
			if(znak >= '0' && znak <= '9')
			{
				y = znak - '0';
				stank = 6;
			}
			else 
				stank = 1;
			break;
		case 6:
			if (znak == '#')
			{
				if ((x >= 1 && x <= 9) && (y >= 0 && y <= 4) && ((x+y)%5==0))
				{
					T1 = x * 10;					
				}
				stank = 1;
			}
			else if(znak >= '0' && znak <= '1')
			{
				z = znak - '0';
				stank = 7;
			}
			else 
				stank = 1;
			break;
		case 7:
			if (znak == '#')
			{
				if ((x >= 1 && x <= 9) && (y >= 1 && y <= 9) && (z >= 0 && z <= 1) && ((x+y+z)%2==0))
				{
					T2 = x * 10;		
					T3 = y * 10;

				}
				stank = 1;
			}
			
			else 
				stank = 1;
			break;
		}


	//L1=LD;
	//KL1 = aK1;
	// if(tim) --tim;	
}

// ------------------------------------------------------------------------

void trans_char(char c);       // wyœlij jeden znak z konsoli do PB  
void trans_string(char * s);   // wyœlij tekst (string) z konsoli do PB  


void klaw_F1(void)      // funkcja wywo³ywana po naciœniêciu F1 na konsoli
{
	trans_char(':');
	trans_char('0');               // wyœlij komunikat ':' '0' '1'
	trans_char('1');
}

void klaw_F2(void)      // funkcja wywo³ywana po naciœniêciu F2 na konsoli
{
	trans_char(':');
	trans_char('0');               // wyœlij komunikat ':' '0' '0'
	trans_char('0');
}

void klaw_F3(void)      // funkcja wywo³ywana po naciœniêciu F3 na konsoli
{
	trans_string(":01");           // wyœlij komunikat ':' '0' '1'
}

void klaw_F4(void)      // funkcja wywo³ywana po naciœniêciu F4 na konsoli
{
}

// ----------------------- inicjowanie zmiennych ------------------------

void inicjuj_kom(void)         // inicjuj zmienne dla komunikacji
{
	stank=1;  stan_s=1;           // inicjuj zmienne
}


//========================= KONIEC =======================================
//========================================================================


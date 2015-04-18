// PB_sym.cpp : main project file.

//G³ówny graf

#include "stdafx.h"

#include <string.h>
#include <stdio.h>

// ========================================================================
//
//-------------------- definicje zmiennych systemowych  -------------------
//
//---------------------- NIE WOLNO TU NIC ZMIENIAC !!! --------------------
//
// ========================================================================

char X1, X2, X3, TM;           // stany czujnikow obiektu
char Z1, Z2, Z3, GR;           // stany zaworow obiektu;
char aK1, aK2, aK3, aK4;       // stany klawiszy panelu
char L1, L2, L3, L4;           // stany LEDów panelu

char line1[80], line2[80];     // bufory dla wyswietlacza LCD

char recv_char();              // znak nades³any z konsoli (0=brak znaków)
void send_char(char cc);       // wyœlij jeden znak ASCII z PB na konsolê
void send_string(char * s);    // wyœlij tekst (string) z PB na konsolê

void out_sym_val(void);        // wyslij do obiektu komunikat o stanie zaworów
void inicjuj_kom(void);        // inicjuj zmienne dla komunikacji


//==========================================================================
//============================= Regulator ==================================
//
//---------------------------  dane robocze  -------------------------------
//
//                   ( tu mozna zmieniac ... )

char stan;
int tim; // zmienne dla grafu automatu
char buf[60];       // bufor roboczy dla sprintf(...)

// Zmienne u¿ytkownika !!
extern char x, y,z, cs, T1, T2, stank, KL1, KL2;
extern int T3;
char Z1_,Z2_,Z3_,G_, X1_, X2_, LD, X3_, TM_;

char pc,xw, st1, st5, st3;
char PS[] = {96,64,32,12,8,18,16,96,16,1,0,18};
char PW[] = {0,1,2,3,4,3,5,6,7,3,7,6};
char PA[] = {0,1,2,3,4,5,8,0,6,9,10,5};
// END Zmienne u¿ytkownika

//--------------------- przyk³adowe zadania --------------------------------

void zad_1(void)      // -------- prosty program na obs³ugê klawiszy i LED-ów
{
/*	L1=aK1;                // dioda œwieci gdy naciœniemy klawisz

	switch (stan) {        // miganie diody
		case 1: L3=1; if (!tim) { stan=2; tim=5;  } break;
		case 2: L3=0; if (!tim) { stan=1; tim=10; } break;
	}
	if (tim) --tim;
*/
	switch(stan)
	{
	case 1:
		LD = 0;
		if(KL1 || KL2)
		{
			tim = 20;
			stan = 2;
		}
		break;
	case 2:
		LD = 0;
		if(!KL1 && !KL2)
			stan = 1;
		else if(KL1 && KL2)
		{
			tim = T1;
			stan = 3;
		}
		else if(!tim)
			stan = 5;
		break;
	case 3:
		LD = 1;
		if(!tim || !KL1 || !KL2)
			stan = 4;
		break;
	case 4:
		LD = 0;
		if(!KL1 && !KL2)
			stan = 1;
		break;
	case 5:
		LD = 0;
		if(KL1 && KL2)
		{
			tim = T2;
			stan = 6;
		}
		else if(!KL1 && !KL2)
			stan = 1;
		break;
	case 6:
		LD = 1;
		if(!tim || !KL1 || !KL2)
			stan = 4;
		break;
	}
	if(tim) --tim;
	//KL1 = aK1;
	//KL2 = aK2;
	L1 = LD;
				
}

void zad_2(void)      // --------  obs³uga obiektu (zbiornika)
{
	switch(stan)
	{
	case 1:
		Z1 = 1; Z3 = 0; GR = 0;
		if(X1)
		{
			tim = 20;
			stan = 2;
		}
		break;
	case 2:
		Z1 = 1; Z3 = 0; GR = 0;
		if(!tim)
		{
			tim = 20;
			stan = 3;
		}
		else if(X2)
		{
			tim = T3;
			stan = 4;
		}
		break;
	case 3:
		Z1 = 0; Z3 = 0; GR = 0;
		if(!tim)
		{
			tim = 20;
			stan = 2;
		}
		break;
	case 4:
		Z1 = 0; Z3 = 0; GR = 1;
		if(TM || !tim)
			stan = 5;
		break;
	case 5:
		Z1 = 0; Z3 = 1; GR = 0;
		if(!X1)
			stan = 1;
		break;
	}
	out_sym_val();        // wyslij do obiektu komunikat o stanie zaworów
	if(tim) --tim;
}

void zad_5(void)      // --------  obs³uga obiektu (zbiornika)
{
	  Z1=(PS[pc]&64)?1:0;
      Z2=(PS[pc]&32)?1:0;
	  Z3=(PS[pc]&16)?1:0;
      GR=(PS[pc]&8)?1:0;
	  st5=(PS[pc]&4)?1:0;
	  st3=(PS[pc]&2)?1:0;
	  st1=(PS[pc]&1)?1:0;
      switch(PW[pc]){
         case 0: xw=X1; break;
         case 1: xw=X2; break;
         case 2: xw=X3; break;
         case 3: xw=1; break;
         case 4: xw=!tim||TM; break;
         case 5: xw=!X1; break;
         case 6: xw=0; break;
		 case 7: xw = !tim; break;
		 
      }

      if(xw)++pc;
      else pc=PA[pc];
      if(st1) tim=T3;
      if(st5) tim=T1;
	  if(st3) tim=T2;
      
	  out_sym_val(); 

	  if(tim) --tim;
}

void zad_4(void)      // --------  obs³uga obiektu (zbiornika)
{
	switch(stan)
	{
	case 1: Z1=1;Z2=1;Z3=0;GR=0;
		if(X2) {tim=20;stan=2;}
		break;
	case 2: Z1=1;Z2=0;Z3=0;GR=0;
		if(!tim) {tim=40;stan=3;}
		else if(X3) {tim=50;stan=4;}
		break;
	case 3: Z1=0;Z2=1;Z3=0;GR=0;
		if(!tim) {tim=20;stan=2;}
		else if(X3) {tim=50;stan=4;}
		break;
	case 4: Z1=0;Z2=0;Z3=0;GR=1;
		if(!tim) {tim=100;stan=5;}
		break;
	case 5: Z1=0;Z2=0;Z3=0;GR=1;
		if(!tim||TM) {stan=6;}
		break;
	case 6: Z1=0;Z2=0;Z3=1;GR=0;
		if(!X1) {stan=1;}
		break;
	
	}
	out_sym_val();        // wyslij do obiektu komunikat o stanie zaworów
	if(tim) --tim;
}


// ========================================================================
// --------------------- nowe zadania (u¿ytkownika) -----------------------
// ========================================================================

void zad_3(void)
{
	// ------------- tu nalezy wstawic program obs³ugi --------------------

	//---------------------------------------------------------------------
}




// ========================================================================
// ----------------------- pêtla g³ówna regulatora ------------------------
// ========================================================================


void inicjuj(void)         // wywo³ywana JEDNORAZOWO na pocz¹tku
{

	stan = 1;        // inicjuj zmienne robocze



	inicjuj_kom();         // inicjuj zmienne dla komunikacji
}


void oblicz(void)          // wywo³ywana co cykl (co 0.1 sek )
{
	// --------- oblicz wyjœcia i kolejny stan (wed³ug grafu zadania)

    zad_5();       // ---->>>-------- wywo³aj program obs³ugi zad_2

	// ------------ wyswietl stan klawiszy i LEDów -----------------------

	sprintf(buf, "Z1=%d Z2=%d X1=%d X2=%d ", (int)Z1, (int)Z2, (int)X1, (int)X2);
	strcpy(line1, buf);
	sprintf(buf, "S=%d pc=%d T3=%dy=%d ", (int)stank, (int)pc, (int)T3, (int)y);
	strcpy(line2, buf);

    // -------------- komunikacja regulatora z konsol¹ -------------------
	// send_char('a');  send_string(":012345\r\n");   // wyœlij znak/komunikat na konsolê
}


//========================================================================
//========================= KONIEC =======================================
//========================================================================

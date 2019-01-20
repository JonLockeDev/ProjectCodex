
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS


#include <string.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>



const long int sz = 100000;
using namespace std;

FILE* accounts = fopen("D:/accounts.txt", "r");
FILE* cities = fopen("D:/cities.txt", "r");
FILE* info = fopen("D:/info.txt", "a+");
FILE* visitors = fopen("D:/visitorsinfo.txt", "a+");
FILE* info2 = fopen("D:/info2.txt", "w");
FILE* drivers = fopen("D:/drivers.txt", "a+");
FILE* manager = fopen("D:/system manager.txt", "a+");
FILE* trips = fopen("D:/trips.txt", "a+");
FILE* accounts2 = fopen("D:/TEMPORARY.txt", "r+");
FILE* specs = fopen("D:/specs.txt", "a+");
FILE* edspecs = fopen("D:/edspecs.txt", "a+");
FILE* sales = fopen("D:/sales.txt", "a+");
FILE* edtrips = fopen("D:/edtrips.txt", "a+");


/*
long int file_size(FILE* a)
{ 

	
		int count = 0;  
		char c;   
		FILE *fp = fopen("D:/cities.txt", "r");
		if (fp == NULL)
		{
			return 0;
		}
		for (c = getc(fp); c != EOF; c = getc(fp))
		{
			if (c == '\n')
				count = count + 1;
		}
		fclose(fp);
		return (count+1);

		
	
}
*/


void gotoxy(int x, int y)
{
		printf("%c[%d;%df", 0x1B, y, x);
		fflush(stdout);
}
void clear_screen()
{
	system("cls");
}
int difference(char t1[],char t2[])
{
	
	if (strcmp(t1, t2) >= 0)
	{
		return (24 * 60  - (((t1[0] * 10 + t1[1]) * 60 + (t1[3] * 10 + t1[4])) - ((t2[0] * 10 + t2[1]) * 60 + (t2[3] * 10 + t2[4])))) / 60;
	}
	else
	{
		return -((((t1[0] * 10 + t1[1]) * 60 + (t1[3] * 10 + t1[4])) - ((t2[0] * 10 + t2[1]) * 60 + (t2[3] * 10 + t2[4])))) / 60;
	}
	
}
bool check_trip(int s, int e)
{
	fclose(trips);
	fopen("D:/trips.txt", "r");
	int temp_s, temp_e,ts1=0,te1=0;
	long int pr;
	int cap;
	long int tcap;
	int tpr;
	long int c,c1=0;
	long int tag, ctag=0;
	char x[20],x1[20]="bnm";
	char y[20],y1[20]="computer";
	char d[20],d1[20]="DEllxop";
	long int k = 0;
	for (int i = 0; i < sz; i++)
	{
		fscanf(trips, "%d\t%d\t%s\t%s\t%ld\t%s%ld\t%d\t%ld", &temp_s, &temp_e, &d, &x, &c, &y,&pr,&cap,&tag);
		if (c == c1 && temp_s == ts1 && temp_e == te1 && strcmp(x, x1) == 0 && strcmp(y, y1) == 0 && strcmp(d, d1) == 0 && tcap==cap && tpr==pr)
		{
			break;
		}
		ts1 = temp_s;
		te1 = temp_e;
		strcpy(d1,d);
		strcpy(x1,x);
		c1 = c;
		strcpy(y1,y);
		tpr = pr;
		tcap = cap;
		ctag = tag;
		if (s == temp_s && e == temp_e && cap!=0)
		{
			k++;
			cout << "\nDate:" << d << "\tTime:" << x << "\tVehicle:" << y << "\tFrom:" << temp_s << "\tTo:" << temp_e<<"\tSeats open:"<<cap;
		}
	}
	cout << "\n___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___\t___";
	if (k == 0)
	{
		cout << "\nNo trip is defined or open for these points";
		return false;

	}
	else
		return true;
}
void it_works()
{
	fclose(info);
	fopen("D:/info.txt", "a+");
}//most important of all
void edit_manager(char un[], char p[], long int ac)
{
	fclose(manager);
	fopen("D:/system manager.txt", "w");
	fprintf(manager, "%s\t%s\t%ld", un, p, ac);
	fclose(manager);
}
void add_to_visitors(char fn[], char ln[], char pn[])
{
	fprintf(visitors, "%s\t%s\t%s\n", fn, ln, pn);
	fclose(visitors);
	fopen("D:/visitorsinfo.txt", "a+");
}
int search_drivers(char id[])
{
	
		char temp_id[81] = { 0 };
		char a1[81], b[81], c[81], vt[81] , temp_p[81];
		fclose(drivers);
		fopen("D:/drivers.txt", "r");
		for (int i = 0; i < 10000; ++i)
		{
			fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &temp_id,&temp_p, &a1, &b, &c, &vt);
			if (strcmp(id , temp_id)==0)
			{
				if (strcmp(vt, "bus") == 0)
				{
					return 3;
				}
				if (strcmp(vt, "train") == 0)
				{
					
					return 2;
				}
				if (strcmp(vt, "airplane") == 0)
				{
					
					return 1;
				}
				
			}
			
		}
		
		
}
void add_to_drivers(char id[],char p[], char fn[], char ln[], char pn[], char vt[])
{
	fprintf(drivers, "%s\t%s\t%s\t%s\t%s\t%s\n", id,p, fn, ln, pn, vt);
	fclose(drivers);
}
void edit_account(long int a, long int p)
{
	fclose(info2);
	fclose(accounts);

	fopen("D:/accounts.txt", "r");
	fopen("D:/info2.txt", "w");
	long int temp_a = { 0 };
	int temp_p = { 0 };
	long int c = { 0 };
	int control_l = 0;
	for (int i = 0; i < 100000; i++)
	{
		fscanf(accounts, "%ld\t%d\t%ld", &temp_a, &temp_p, &c);
		if (temp_a == a)
		{
			c += p;
		}
		fprintf(info2, "%ld\t%d\t%ld\n", temp_a, temp_p, c);
	
	}
	fclose(accounts);
	fopen("D:/accounts.txt", "w");
	fclose(info2);
	fopen("D:/info2.txt", "r");
	for (int i = 0; i < 100000; i++)
	{
		fscanf(info2, "%ld\t%d\t%ld", &temp_a, &temp_p, &c);
		fprintf(accounts, "%ld\t%d\t%ld\n", temp_a, temp_p, c);

	}


fclose(info2);
fopen("D:/info2.txt", "w");
fclose(accounts);
fopen("D:/accounts.txt", "r");
	

}
int search_info(char a1[],char p1[])
{

	char temp_a[81] = { 0 };
	char temp_p[81] = { 0 };
	char x[50] = { 0 };
	char y[50] = { 0 };
	char z[50] = { 0 };
	int control_l = 0;
	for (int i = 0; i < 100000; i++)
	{
		fscanf(info, "%s\t%s\t%s\t%s\t%s", &temp_a, &temp_p, &x, &y, &z);
		if (strcmp(temp_p,p1)==0 && strcmp(temp_a,a1)==0)
		{
			control_l = 5;
			return 1;
			break;
		}
	}
	if (control_l != 5)
		cout << "Password and user name does not match\n";

	fclose(info);
	fopen("D:/info.txt", "a+");

}
float distance(int s, int e)
{
	long int city = { 0 };
	long int cityx = { 0 };
	long int cityy = { 0 };
	long int sx = {0}, sy = { 0 }, ex = { 0 }, ey = { 0 };
	for (int i = 0; i < 300; i++)
	{
		fscanf(cities, "%ld\t%ld\t%ld", &city, &cityx, &cityy);

		if (city == s)
		{
			sx = cityx;
			sy = cityy;
		}
	}
	
	fclose(cities);
	fopen("D:/cities.txt", "r");
	for (int i = 0; i < 300; i++)
	{
		fscanf(cities, "%ld\t%ld\t%ld", &city, &cityx, &cityy);

		if (city == e)
		{
			ex = cityx;
			ey = cityy;
		}

	}
	

	fclose(cities);
	fopen("D:/cities.txt", "r");
	float d = sqrt((ex - sx)*(ex - sx) + (ey - sy)*(ey - sy));
	return d;
}
int search_account(long int a1, int p1)
{
	long int temp_a = { 0 };
	long int temp_p = { 0 };
	long int c = 0;
	int control_l = 0;
	for (int i = 0; i < 100000; i++)
	{
		fscanf(accounts, "%ld\t%d\t%ld", &temp_a, &temp_p, &c);
		if (temp_a == a1 && temp_p == p1)
		{
			control_l = 5;
			return 1;
			break;
		}
	}
	if (control_l != 5)
		cout << "Password and account number does not match Try again\n";
	clear_screen();
	fclose(accounts);
	fopen("D:/accounts.txt", "a+");
	return 0;

}
void add_to_info(char un[],char p[], char fn[], char ln[], char pn[])
{
	fprintf(info, "%s\t%s\t%s\t%s\t%s\n", un, p, fn, ln, pn);
	fclose(info);
}
int check_manager(char un[],char p[])
{
	char temp_un[81];
	char temp_p[81];
	fscanf(manager, "%s\t%s", &temp_un, &temp_p);
	if (strcmp(un,temp_un)==0 && strcmp(temp_p,p)==0)
	{
		return 1;
	}
	else
	{
		cout << "\nUser name and password does not match\nTry again";

	}
	fclose(manager);
	fopen("D:/system manager.txt", "r+");

}
int if_driver_registered(char id[],char p[])
{
	fclose(drivers);
	fopen("D:/drivers.txt", "r");
	char temp_id[81] = { 0 },temp_p[81];
	char a1[81], b[81], c[81], d[81];
	//fclose(drivers);
	for (int i = 0; i < 10000; i++)
	{
		fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &temp_id,&temp_p, &a1, &b, &c, &d);
		if (id == temp_id)
		{
			return 1;
		}
	}
	cout << "\nYou are not registered\nContact system manager";
	fclose(drivers);
	return -1;
}
int search_if_user_name_taken(char un[])
{
	fclose(info);
	fopen("D:/info.txt", "r");
	char temp_un[81];
	char a[81];
	char b[81];
	char c[81];
	char d[81];
	for (int i = 0; i < 100000; i++)
	{
		fscanf(info, "%s\t%s\t%s\t%s\t%s\t", &temp_un, &a, &b, &c, &d);
		if (strcmp(temp_un, un) == 0)
		{
			cout << "\nUser name is taken please try another one";
				return -1;
		}
	}
	fclose(info);
	fopen("D:/info.txt", "a+");
	return 1;
}
void edit_price(char a[] ,float p)
{
	fclose(edspecs);
	fclose(specs);
	fopen("D:/specs.txt", "r");
	fopen("D:/edspecs.txt", "w");
	char temp_n[15] = { 0 };
	int temp_s = { 0 };
	int temp_c = { 0 };
	float temp_p = 0;
	for (int i = 0; i < 3; i++)
	{
		fscanf(specs,"%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c,&temp_p);
		if (strcmp(a,temp_n)== 0)
		{
			temp_p = p;
		}
		fprintf(edspecs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c,temp_p);

	}
	fclose(specs);
	fopen("D:/specs.txt", "w");
	fclose(edspecs);
	fopen("D:/edspecs.txt", "r");


	for (int i = 0; i < 3; i++)
	{
		fscanf(edspecs, "%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c, &temp_p);

		fprintf(specs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c, temp_p);
	}
}
void edit_speed(char a[],int spd)
{
	fclose(edspecs);
	fclose(specs);
	fopen("D:/specs.txt", "r");
	fopen("D:/edspecs.txt", "w");
	char temp_n[15] = { 0 };
	int temp_s = { 0 };
	int temp_c = { 0 };
	float temp_p = 0;
	for (int i = 0; i < 3; i++)
	{
		fscanf(specs, "%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c, &temp_p);
		if (strcmp(a, temp_n) == 0)
		{
			temp_s = spd;
		}
		fprintf(edspecs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c, temp_p);

	}
	fclose(specs);
	fopen("D:/specs.txt", "w");
	fclose(edspecs);
	fopen("D:/edspecs.txt", "r");


	for (int i = 0; i < 3; i++)
	{
		fscanf(edspecs, "%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c, &temp_p);

		fprintf(specs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c, temp_p);
	}
}
void edit_cap(char a[], int cap)
{
	fclose(edspecs);
	fclose(specs);
	fopen("D:/specs.txt", "r");
	fopen("D:/edspecs.txt", "w");
	char temp_n[15] = { 0 };
	int temp_s = { 0 };
	int temp_c = { 0 };
	float temp_p = 0;
	for (int i = 0; i < 3; i++)
	{
		fscanf(specs, "%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c, &temp_p);
		if (strcmp(a, temp_n) == 0)
		{
			temp_c = cap;
		}
		fprintf(edspecs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c, temp_p);

	}
	fclose(specs);
	fopen("D:/specs.txt", "w");
	fclose(edspecs);
	fopen("D:/edspecs.txt", "r");


	for (int i = 0; i < 3; i++)
	{
		fscanf(edspecs, "%s\t%d\t%d\t%f", &temp_n, &temp_s, &temp_c, &temp_p);

		fprintf(specs, "%s\t%d\t%d\t%f\n", temp_n, temp_s, temp_c, temp_p);
	}
}
float tarrif(char vt[])
{
	fclose(specs);
	fopen("D:/specs.txt", "r");
	long int a, b;
	float c;
	char v1[15];
	for (int i = 0; i < 3; i++)
	{
		fscanf(specs, "%s\t%d\t%d\t%f", &v1, &a, &b, &c);
		if (strcmp(vt, v1) == 0)
		{
			return (c*1000);
		}

	
	}
}
void add_to_trips(int s, int e, char d[], char t[], long int an, char vt[])
{
	int a, b;
	float f;
	char str[25];
	fclose(specs);
	fopen("D:/specs.txt", "r");
	fclose(trips);
	fopen("D:/trips.txt", "a+");
	for (int i = 0; i < 100000; i++)
	{
		fscanf(specs, "%s\t%d\t%d\t%f", &str, &a, &b, &f);
		if (strcmp(vt, str) == 0)
		{
			break;
		}
	}
	long int p =( distance(s, e))*tarrif(vt);
	fprintf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", s, e, d, t, an, vt, p,b,time(NULL));
	fclose(trips);
	fclose(specs);
}
void edit_driver_account(long int prc,char d[],char t[],char vt[])
{
	fclose(trips);
	fopen("D:/trips.txt", "r");
	int a, b,c;
	long int x, an;
	char temp_d[25], temp_t[25], temp_vt[25];
	for (int i = 0; i < 100000 ; i++)
	{
		fscanf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d", &a, &b, &temp_d, &temp_t, &an, &temp_vt, &x, &c);
		if (strcmp(d, temp_d) == 0 && strcmp(t, temp_t) == 0 && strcmp(vt, temp_vt) == 0)
		{
			break;
		}
	}
	edit_account(an, (prc * 9) / 10);
	fclose(accounts);
}
void edit_manager_account(long int p)
{

	long int  an,an_manager=0;
	char temp_d[25], temp_t[25];
	for (int i = 0; i < 5; i++)
	{
		fscanf(manager, "%s\t%s\t%ld", &temp_d, &temp_t, &an_manager);
		break;

	}
	edit_account(an_manager,(p/10));
	fclose(manager);
	fclose(accounts);
}
bool check_if_balanced(long int an, long int p)
{
	fclose(accounts);
	fopen("D:/accounts.txt", "r");
	long int temp_a = { 0 };
	long int temp_p = { 0 };
	long int c = 0;
	int control_l = 0;
	for (int i = 0; i < 100000; i++)
	{
		fscanf(accounts,"%ld\t%d\t%ld", &temp_a, &temp_p, &c);
		
		if (temp_a == an)
		{
			
			if (c >= p)
			{
				control_l = 5;
				return true;
				break;
			}
		}
	}
	if (control_l != 5)
		cout << "Account is not balanced\n";
	fclose(accounts);
	fopen("D:/accounts.txt", "a+");
	return false;
}
void edit_trips(int s, int e, char d[], char t[], char vt[])
{

	fclose(trips);
	fopen("D:/trips.txt", "r");
	fclose(edtrips);
	fopen("D:/edtrips.txt", "w");
	int ts, te, tc;
	long int ta, tp;
	long int ca = 1, cp = 0,tag=0;
	char td[25], tt[25], tvt[25];
	char cd[25] = " vc";
	char ct[25] = " cv";
	char cvt[25] = "m ";
	int control_f;
	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/trips.txt", "r");
	if (fp == NULL)
	{
		size= 0;
	}
	for (c = getc(fp); c != EOF ; c = getc(fp))
	{
		if (c == '\n')
		{
				count = count + 1;
		}
	}
	fclose(fp);
	size= count;
	for (int i = 0; i < size; i++)
	{
		fscanf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc,&tag);
		if (s == ts && e == te && strcmp(td, d) == 0 && strcmp(tt, t) == 0 && strcmp(vt, tvt) == 0)
		{
			tc--;
		}
		fprintf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc,tag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "r");
	fclose(trips);
	fopen("D:/trips.txt", "w");

	
	for (int i = 0; i < size; i++)
	{
		fscanf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc,&tag);
	
		fprintf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc,tag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "a+");
	fclose(trips);
	fopen("D:/trips.txt", "a+");
}
void edit_trips_time(int s, int e, char d[],char nt[], char vt[])
{
	fclose(trips);
	fopen("D:/trips.txt", "r");
	fclose(edtrips);
	fopen("D:/edtrips.txt", "w");
	int ts, te, tc;
	long int ta, tp;
	long int ca = 1, cp = 0, tag = 0;
	char td[25], tt[25], tvt[25];
	char cd[25] = " vc";
	char ct[25] = " cv";
	char cvt[25] = "m ";
	int control_f;
	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/trips.txt", "r");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	for (int i = 0; i < size; i++)
	{
		fscanf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc, &tag);
		if (s == ts && e == te && strcmp(td, d) == 0 && strcmp(tt, nt) == 0 && strcmp(vt, tvt) == 0)
		{
			strcpy(tt, nt);
		}
		fprintf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc, tag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "r");
	fclose(trips);
	fopen("D:/trips.txt", "w");


	for (int i = 0; i < size; i++)
	{
		fscanf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc, &tag);

		fprintf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc, tag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "a+");
	fclose(trips);
	fopen("D:/trips.txt", "a+");
}
void add_to_sales(char d[],char t[],int xvt,long int an)
{
	fclose(trips);
	fopen("D:/trips.txt", "r");
	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/trips.txt", "r");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	int ts=0, te=0, tc=0;
	char td[35]="jh", date[35]= "jh", tt[35]= "jh", xtime[35]= "jh", tvt[35]= "jh", vt2[35]= "jh";
	long int tp=0, prc=0, ta=0, ttag=0;
	long int tag2=0, tag=0;
	char vt[20];
	if (xvt == 1)
	{
		strcpy(vt, "airplane");
	}
	if (xvt == 2)
	{
		strcpy(vt, "train");
	}
	if (xvt == 3)
	{
		strcpy(vt, "bus");
	}
	fclose(trips);
	//fopen("D:/trips.txt", "r");
	for (int i = 0; i < size; i++)
	{
		fscanf(trips,"%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc, &tag);
		cout << "\t" << "\t"<<ts << "\t" << tag<<endl;
		if (strcmp(td, d) == 0 && strcmp(tt, t) == 0 && strcmp(vt, tvt) == 0)
		{
			tag2 = tag;
			break;
		}
	}
	fprintf(sales, "%ld\t%ld\n", tag2, an);	
	fclose(trips);
	fopen("D:/trips.txt", "r");
	fclose(sales);
}
void edit_info(char un[], char p[])
{
	char nun[50], np[50], npn[20];
	int check = 0;
	while (check != 1)
	{
		cout << "\nEnter your new user name:";
		scanf("%s", &nun);
		check = search_if_user_name_taken(nun);
	}
	cout << "\nEnter your new password:";
	scanf("%s", &np);
	cout << "\nEnter your new phone number:";
	scanf("%s", &npn);
	fclose(info);
	fopen("D:/info.txt", "r");
	fclose(info2);
	fopen("D:/info2.txt", "w");
	char tun[50], cun[50] = "oled", tp[50], cp[50] = "oled", tfn[20],cfn[20] = "oled",tln[50], cln[50] = "oled", tpn[50],cpn[50] = "oled";
	
	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/info.txt", "r");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	for (int i = 0; i < size; i++)
	{
		fscanf(info, "%s\t%s\t%s\t%s\t%s", &tun, &tp, &tfn, &tln, &tpn);
		
		if (strcmp(tun,un) == 0 )
		{
			strcpy(tun, nun);
			strcpy(tp, np);
			strcpy(tpn, npn);

		}
		fprintf(info2, "%s\t%s\t%s\t%s\t%s\n", tun, tp, tfn, tln, tpn);
	}
	fclose(info);
	fopen("D:/info.txt", "w");
	fclose(info2);
	fopen("D:/info2.txt", "r");
	
	for (int i = 0; i < size; i++)
	{
		fscanf(info2, "%s\t%s\t%s\t%s\t%s", &tun, &tp, &tfn, &tln, &tpn);
	
		fprintf(info, "%s\t%s\t%s\t%s\t%s\n", tun, tp, tfn, tln, tpn);
	}
	fclose(info);
	fopen("D:/info.txt", "a+");
	fclose(info2);
	fopen("D:/info2.txt", "a+");
}
int search_if_id_taken(char id[])
{
	fclose(drivers);
	fopen("D:/drivers.txt", "r");
	char temp_id[81];
	char temp_p[81];
	char a[81];
	char b[81];
	char c[81];
	char d[81];
	for (int i = 0; i < 100000; i++)
	{
		fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &temp_id, &temp_p, &a, &b, &c, &d);
		if (strcmp(temp_id, id) == 0)
		{
			cout << "\nID is taken please try another one";
			return -1;
		}
	}
	fclose(drivers);
	fopen("D:/drivers.txt", "a+");
	return 1;
}
void edit_driver_info(char id[], char p[])
{
	char nid[50], np[50], npn[20];
	int check = 0;
	while (check != 1)
	{
		cout << "\nEnter your new ID:";
		scanf("%s", &nid);
		check = search_if_id_taken(nid);
	}
	cout << "\nEnter your new password:";
	scanf("%s", &np);
	cout << "\nEnter your new phone number:";
	scanf("%s", &npn);
	fclose(drivers);
	fopen("D:/drivers.txt", "r");
	fclose(info2);
	fopen("D:/info2.txt", "w");
	char tid[50], cid[50] = "oled", tp[50], cp[50] = "oled", tfn[20], cfn[20] = "oled", tln[50], cln[50] = "oled", tpn[50], cpn[50] = "oled";
	char tvt[50], cvt[50] = { "oled" };
	/////////////////////

	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/drivers.txt", "r+");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	///////////////
	for (int i = 0; i <size; i++)
	{
		fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &tid, &tp, &tfn, &tln, &tpn,&tvt);
		
		if (strcmp(tid, id) == 0)
		{
			strcpy(tid, nid);
			strcpy(tp, np);
			strcpy(tpn, npn);

		}
		fprintf(info2, "%s\t%s\t%s\t%s\t%s\t%s\n", tid, tp, tfn, tln, tpn,tvt);
	}
	fclose(drivers);
	fopen("D:/drivers.txt", "w");
	fclose(info2);
	fopen("D:/info2.txt", "r");

	for (int i = 0; i < size; i++)
	{
		fscanf(info2, "%s\t%s\t%s\t%s\t%s\t%s", &tid, &tp, &tfn, &tln, &tpn,&tvt);
	
		fprintf(drivers, "%s\t%s\t%s\t%s\t%s\t%s\n", tid, tp, tfn, tln, tpn,tvt);
	}
	fclose(drivers);
	fopen("D:/drivers.txt", "a+");
	fclose(info2);
	fopen("D:/info2.txt", "a+");
}
void sys_edit_driver_info(char id[], char p[])
{
	char nid[50], np[50], npn[20];
	int check = 0;
	while (check != 1)
	{
		cout << "\nEnter driver's new ID:";
		scanf("%s", &nid);
		check = search_if_id_taken(nid);
	}
	cout << "\nEnter driver's new password:";
	scanf("%s", &np);
	cout << "\nEnter driver's new phone number:";
	scanf("%s", &npn);
	fclose(drivers);
	fopen("D:/drivers.txt", "r");
	fclose(info2);
	fopen("D:/info2.txt", "w");
	char tid[50], cid[50] = "oled", tp[50], cp[50] = "oled", tfn[20], cfn[20] = "oled", tln[50], cln[50] = "oled", tpn[50], cpn[50] = "oled";
	char tvt[50], cvt[50] = { "oled" };
	/////////////////////

	long int size;
	int count = 0;
	char c;
	FILE *fp = fopen("D:/drivers.txt", "r+");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	///////////////
	for (int i = 0; i < size; i++)
	{
		fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &tid, &tp, &tfn, &tln, &tpn, &tvt);

		if (strcmp(tid, id) == 0)
		{
			strcpy(tid, nid);
			strcpy(tp, np);
			strcpy(tpn, npn);

		}
		fprintf(info2, "%s\t%s\t%s\t%s\t%s\t%s\n", tid, tp, tfn, tln, tpn, tvt);
	}
	fclose(drivers);
	fopen("D:/drivers.txt", "w");
	fclose(info2);
	fopen("D:/info2.txt", "r");

	for (int i = 0; i < size; i++)
	{
		fscanf(info2, "%s\t%s\t%s\t%s\t%s\t%s", &tid, &tp, &tfn, &tln, &tpn, &tvt);

		fprintf(drivers, "%s\t%s\t%s\t%s\t%s\t%s\n", tid, tp, tfn, tln, tpn, tvt);
	}
	fclose(drivers);
	fopen("D:/drivers.txt", "a+");
	fclose(info2);
	fopen("D:/info2.txt", "a+");
}
int if_driver(char a1[], char p1[])
{
	char temp_a[81] = { 0 },ca[81]="oled";
	char temp_p[81] = { 0 },cp[81]="oled";
	char x[50] = { 0 },cx[81]="oled";
	char y[50] = { 0 },cy[81]="oled";
	char z[50] = { 0 },cz[81]="oled";
	char w[50] = { 0 },cw[81]="oled";
	int control_l = 0;
	for (int i = 0; i < 100000; i++)
	{
		fscanf(drivers, "%s\t%s\t%s\t%s\t%s\t%s", &temp_a, &temp_p, &x, &y, &z,&w);
		if (strcmp(temp_p, p1) == 0 && strcmp(temp_a, a1) == 0)
		{
			
			control_l = 5;
			return 1;
			break;
		}
		if (strcmp(temp_a, ca) == 0 && strcmp(temp_p, cp) == 0)
		{
			
			break;
		}
		
	}
	if (control_l != 5)
		cout << "Password and ID does not match\n";

	fclose(drivers);
	fopen("D:/drivers.txt", "a+");

}
void edit_time()
{
	long int tag;
	char n_time[10];
	cout << "\nEnter the tag for the trip you are delating\n";
	cin >> tag;
	cout << "\nEnter new time in format of hh:mm\n";
	scanf("%s", &n_time);
	fclose(trips);
	long int size;
	long int count = 0;
	char c;
	FILE *fp = fopen("D:/trips.txt", "r");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	fopen("D:/trips.txt", "r");
	int ts, te, tc;
	char td[35],date[35], tt[35],xtime[35], tvt[35],vt[35];
	long int tp,prc, ta,ttag;
	long int tag2;
	int s, e;
	for (int i = 0; i < size; i++)
	{
		fscanf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc, &ttag);
		if (tag == ttag)
		{
			strcpy(tt, n_time);
			prc = tp;
			strcpy(xtime, tt);
			strcpy(date, tt);
			strcpy(vt, tvt);
			tag2 = ttag;
			s = ts;
			e = te;
		}
		fprintf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc,ttag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "r");
	fclose(trips);
	fopen("D:/trips.txt", "w");


	for (int i = 0; i < size; i++)
	{
		fscanf(edtrips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld", &ts, &te, &td, &tt, &ta, &tvt, &tp, &tc, &ttag);

		fprintf(trips, "%d\t%d\t%s\t%s\t%ld\t%s\t%ld\t%d\t%ld\n", ts, te, td, tt, ta, tvt, tp, tc,ttag);
	}
	fclose(edtrips);
	fopen("D:/edtrips.txt", "a+");
	fclose(trips);
	fopen("D:/trips.txt", "a+");
	prc *= 0.05*difference (xtime,n_time);
	it_works();
	edit_driver_account(-prc*9/10,date,n_time, vt);
	edit_manager_account(-(prc/10));
	fp = fopen("D:/sales.txt", "r");
	if (fp == NULL)
	{
		size = 0;
	}
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n')
		{
			count = count + 1;
		}
	}
	fclose(fp);
	size = count;
	fclose(sales);
	fopen("D:/sales.txt", "r");
	long int temp_an, temp_tag;
	it_works();
	for (int i = 0; i < size; i++)
	{
		fscanf(sales, "%ld\t%ld", &temp_an, &temp_tag);
		if (temp_tag == tag2)
		{
			edit_account(temp_an, prc);
		}
	}
	edit_trips_time(s, e, date, n_time, vt);
	
}
void cancel_trip()
{
	long int tag;
	cout << "\nEnter the tag for the trip you intend to cancel\n";
	cin >> tag;
}



int main()
{
main_menu:	cout << "\t\t\t\t\t\t\t\t\t\t\tWelcome!\n";
	cout<<"\n\t\t\t\t\t\tsign up for free enter (1) or if you already have an account log in enter (2) or if you are just visiting enter (3)\n";
	int control;
	int account_password;
	long int account_number=0;
	int check = 0;
	char  first_name[81];
	char  last_name[81];
	char  phone_number[12];
	char  vehicle[12];
	int start, end;
	char date[10] = { 0 };
	char time[5] = { 0 };
	char user_name[81];
	char password[81];
	char ID[85] = { 0 };
	long int price;
	int  c, s;
	float p;
	char vt[20];
	bool result;
	int control_shop;
	int sgn = 1;
	cin >> control;
	clear_screen();
	if (control == 1)//sign up
	{
		cout << "Enter your phone number:\t";
		scanf("%s", &phone_number);
		cout << "\nEnter your first name:\t";
		scanf("%s", &first_name);
		cout << "\nEnter your last name:\t";
		scanf("%s", &last_name);
		check = 0;
		clear_screen();
		while (check != 1)
		{
			cout << "\nEnter your user name:\t";
			scanf("%s", &user_name);
			check=search_if_user_name_taken(user_name);
		}
		check = 0;
		cout << "\nEnter your password:\t";
		scanf("%s", &password);
		clear_screen();
		add_to_info(user_name, password, first_name, last_name, phone_number);
		it_works();
		cout << "\t\t\t\t\t\t\t\t\t\t\tYou signed up sucsessfully\n";
		cout << "\n\t\t\t\t\t\t\t\tIf you want to book a ticket enter (1) or if you want to exit enter(2)\n";
		cin >> control;
		clear_screen();
		if (control == 2)
		{
			goto main_menu;
		}
		if (control == 1)//Shoping
		{
			result = false;


			while (result == false)
			{
				cout << "\nEnter your starting point (between 1 and 300):";
				cin >> start;
				cout << "\nEnter your destination (between 1 and 300):";
				cin >> end;
				clear_screen();
				result = check_trip(start, end);
			}
			cout << "\nIf you want to book a ticket enter (1) or if you don't want these trips enter (2)\n";
			cin >> control;
			if (control == 2)
			{
				goto main_menu;
			}
			if (control == 1)
			{
				cout << "\nWhat day do you want to buy a ticket for (yyyy/mm/dd) choose from above : ";
				scanf("%s", &date);
				cout << "\nWhat time do you want to buy a ticket for (hh:mm) choose from above : ";
				scanf("%s", &time);

			shop_menu:	cout << "\nPlease choose the type of your vehicle:\n1:Airplane\n2:Train\n3:Bus\n";

				cin >> control_shop;
				clear_screen();
				if (control_shop == 1)//Airplane
				{
					strcpy(vt, "airplane");
					check = 0;
					price = distance(start, end)*tarrif(vt);
					price *= 0.9;
					cout << "\nPrice for this trip is:" << price;
					cout << "\nAre you sure you want to pay for the trip YES (1) NO (2):";
					cin >> control;
					clear_screen();
					if (control == 2)
					{
						goto main_menu;
					}
					if (control == 1)
					{
						clear_screen();
						while (check != 1)
						{
							cout << "\nEnter your account number: ";
							scanf("%ld", &account_number);
							cout << "\nEnter your password: ";
							scanf("%d", &account_password);
							check = search_account(account_number, account_password);

						}

						result = check_if_balanced(account_number, price);
						while (result == false)
						{
							cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
							cin >> control;
							if (control == 2)
							{
								goto main_menu;
							}
							if (control == 1)
							{
								check = 0;
								while (check != 1)
								{
									cout << "\nEnter your account number: ";
									scanf("%ld", &account_number);
									cout << "\nEnter your password: ";
									scanf("%d", &account_password);
									check = search_account(account_number, account_password);
								}
							}
							result = check_if_balanced(account_number, price);
						}
						edit_account(account_number, -price);
						edit_trips(start, end, date, time, vt);
						edit_driver_account(price,date, time, vt);
						edit_manager_account(price);
						//add_to_sales(date, time,1, account_number);
					}
				}
			


		}
			if (control_shop == 2)//Train
			{
				strcpy(vt, "train");
				check = 0;
				price = distance(start, end)*tarrif(vt);
				price *= 0.9;
				cout << "\nPrice for this trip is:" << price;
				cout << "\nAre you sure you want to pay for the trip YES (1) NO (2):";
				cin >> control;
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					while (check != 1)
					{
						cout << "\nEnter your account number: ";
						scanf("%ld", &account_number);
						cout << "\nEnter your password: ";
						scanf("%d", &account_password);
						check = search_account(account_number, account_password);

					}
					result = check_if_balanced(account_number, price);
					while (result == false)
					{
						cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
						cin >> control;
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							check = 0;
							while (check != 1)
							{
								cout << "\nEnter your account number: ";
								scanf("%ld", &account_number);
								cout << "\nEnter your password: ";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);
							}
						}
						result = check_if_balanced(account_number, price);
					}
					edit_account(account_number, -price);
					edit_trips(start, end, date, time, vt);
					edit_driver_account(price,date, time, vt);
					edit_manager_account(price);
					//add_to_sales(date, time,2, account_number);
				}
			}
			if (control_shop == 3)//Bus
			{
				strcpy(vt, "bus");
				check = 0;
				price = distance(start, end)*tarrif(vt);
				price *= 0.9;
				cout << "\nPrice for this trip is:" << price;
				cout << "\nAre you sure you want to pay for the trip YES (1) NO (2):";
				cin >> control;
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					while (check != 1)
					{
						cout << "\nEnter your account number: ";
						scanf("%ld", &account_number);
						cout << "\nEnter your password:";
						scanf("%d", &account_password);
						check = search_account(account_number, account_password);

					}
					result = check_if_balanced(account_number, price);
					while (result == false)
					{
						cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
						cin >> control;
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							check = 0;
							while (check != 1)
							{
								cout << "\nEnter your account number: ";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);
							}
						}
						result = check_if_balanced(account_number, price);
					}
					edit_account(account_number, -price);
					edit_trips(start,end,date,time,vt);
					edit_driver_account(price,date, time, vt);
					edit_manager_account(price);
					//add_to_sales(date, time, 3, account_number);
				}
			}
		}





	}//end of sign up




	if (control == 2)//log in
	{
		cout << "\t\t\t\t\tIf you are the system manager enter (1) or if you are a driver/pilot enter (2) or if you are a customer enter (3)\n";
		cin >> control;
		clear_screen();
		if (control == 1)//system manager logging in
		{
			check = 0;
			while (check != 1)
			{
				cout << "\nEnter your user name: ";
				scanf("%s", &user_name);
				cout << "\nEnter your password: ";
				scanf("%s", &password);
				check = check_manager(user_name, password);
			}
			clear_screen();
			cout << "\n\t\t\t\t\t\t\t\t\tIf you want to add/edit/delete drivers/pilots enter (1)";
			cout << "\n\t\t\t\t\t\t\t\t\t\t To see or change trips info enter (2)";
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tTo edit your info enter (3)";
			cout<<"\n\t\t\t\t\t\t\t\t\t To see information about trips and or passengers enter (4)\n";
			cin >> control;
			clear_screen();
			if (control == 1)//system manager editing drivers
			{
				cout << "\nIf you want to add a driver enter (1) or if you want to delete drivers enter (2) or if you want to edit their info enter (3)\n";
				cin >> control;
				clear_screen();
				if (control == 1)//add driver
				{
					check = 0;
					while (check != 1)
					{
						cout << "\nEnter an ID for the driver: ";
						scanf("%s", &ID);
						check = search_if_id_taken(ID);
					}
					cout << "\nEnter driver's first name: ";
					scanf("%s", &first_name);
					cout << "\nEnter driver's last name: ";
					scanf("%s", &last_name);
					cout << "\nEnter driver's phone number: ";
					scanf("%s", &phone_number);
					cout << "\nWhat type of vehicle does the driver have: ";
					scanf("%s", &vehicle);
					add_to_drivers(ID,ID,first_name, last_name, phone_number, vehicle);
				}
				clear_screen();
				if (control == 2)//delete driver
				{

				}
				if (control == 3)//edit driver
				{
					char ID[20];
					char password[20];
					check = 0;
					while (check != 1)
					{
						cout << "\nEnter ID for the driver you are deleting\n";
						cin >> ID;
						cout << "\nEnter password for the driver you are deleting\n";
						cin >> password;
						check = if_driver_registered(ID,password);
					}
					sys_edit_driver_info(ID,password);
				}
				
			}
			if (control == 2)//Editing and trips' info
			{
				cout << "\nIf you want to cancel or delay a trip enter (1) or to set price for various vehicles enter (2)\nTo set capacities and or speed for vehicles enter (3)\n";
				cin >> control;
				if (control == 1)//cancel or delay
				{
					cout << "\nIf you want to cancel a trip enter (1) or to delay a trip enter (2)\n";
					cin >> control;
					if (control == 1)//sys manager canceling
					{
						//delete_trip();
					}
					if (control == 2)//sys manager delaying
					{
						edit_time();
					}
				}
				if (control == 2)//setting price
				{
					cout << "\nWhich type of vehicle do you want to change price\nbus( enter (1) )\ntrain( enter(2) )\nairplane( enter(3) )\n";
					cin >> control;
					if (control == 1)
					{
						cout << "\nEnter the price per kilo meteres: ";
						cin >> p;
						strcpy(vt, "bus");
						edit_price(vt, p);
					}
					if (control == 2)
					{
						cout << "\nEnter the price per kilo meteres: ";
						cin >> p;
						strcpy(vt, "train");
						edit_price(vt, p);
					}
					if (control == 3)
					{
						cout << "\nEnter the price per kilo meteres: ";
						cin >> p;
						strcpy(vt, "airplane");
						edit_price(vt, p);
					}
					
				}
				if (control == 3)//setting
				{
					int spd;
					int cap;
					cout << "\nTo set speed for vehicles enter (1) or to set capacity for vehicles enter (2)\n";
					cin >> control;
					if (control == 1)//speed
					{
						cout<<"\nWhich type of vehicle do you want to change speed\nbus( enter (1) )\ntrain( enter(2) )\nairplane( enter(3) )\n";
						cin >> control;
						if (control == 1)//bus
						{
							cout << "\nEnter the speed in kilo meteres per hour: ";
							cin>>spd;
							strcpy(vt, "bus");
							edit_speed(vt,spd);

						}
						if (control == 2)//train
						{
							cout << "\nEnter the speed in kilo meteres per hour:";
							cin >> spd;
							strcpy(vt, "train");
							edit_speed(vt, spd);
						}
						if (control == 3)//airplane
						{
							cout << "\nEnter the speed in kilo meteres per hour:";
							cin >> spd;
							strcpy(vt, "airplane");
							edit_speed(vt, spd);
						} 
					}
					if (control == 2)//capacity
					{
						cout<<"\nWhich type of vehicle do you want to change capacity for\nbus( enter (1) )\ntrain( enter(2) )\nairplane( enter(3) )\n";
						cin >> control;
						if (control == 1)//bus
						{
							cout << "\nEnter the capacity:";
							cin >> cap;
							strcpy(vt, "bus");
							edit_cap(vt, cap);
						}
						if (control == 2)//train
						{
							cout << "\nEnter the capacity:";
							cin >> cap;
							strcpy(vt, "train");
							edit_cap(vt, cap);
						}
						if (control == 3)//airplane
						{
							cout << "\nEnter the capacity:";
							cin >> cap;
							strcpy(vt, "airplane");
							edit_cap(vt, cap);
						}
					}
				}
			}
			if (control == 3)//editing sys manager's info
			{
				char temp_un[81] = {0};
				char temp_pass[81] = {0};
				long int temp_acc=NULL;
				fclose(manager);
				fopen("D:/system manager.txt", "r");
				fscanf(manager, "%s\t%s\t%ld", &temp_un, &temp_pass, &temp_acc);
				clear_screen();
				cout << "\nYour user name is:" << temp_un;
				cout << "\nIf you want to edit you info enter (1) or if you want to exit enter (2)";
				cin >> control;
				clear_screen();
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					cout << "\nEnter your new user name or add one: ";
					scanf("%s", &user_name);
					cout << "\nEnter your new password or add one: ";
					scanf("%s", &password);
					cout << "\nEnter your new account number or add an account number:";
					scanf("%ld", &account_number);
					clear_screen();
					edit_manager(user_name, password, account_number);

				}
			}
			if (control == 4)//seeing
			{

			}









		}
		if (control == 2)//drivers logging in
		{
			check = 0;
			while (check != 1)
			{
				cout << "\nEnter your ID (given to you by the manager) :";
				scanf("%s", &ID);
				cout << "\nEnter your password (at first it is your ID) :";
				scanf("%s", &password);
				check = if_driver(ID, password);
			}
			if (check == 1)//driver is registered
			{
				clear_screen();
				cout << "\nIf you want to add a new trip enter (1) or to see the details of trips and or edit them or edit your info enter (2)\n";
				cin >> control;
				if (control == 1)//add a trip
				{
					cout << "\nEnter trip's starting point (between 1 and 300): ";
					cin >> start;
					cout << "\nEnter trip's destination (between 1 and 300): ";
					cin >> end;
					cout << "\nEnter trip's date in format of (yyyy/mm/dd) : ";
					scanf("%s", &date);
					cout << "\nEnter trips time in format of (hh:mm) : ";
					scanf("%s", &time);
					cout << "\nEnter your account number with which you get pay for this trip: ";
					scanf("%ld", &account_number);
					control = 0;
					control = search_drivers(ID);
					char vt[15];
					if (control == 3)
					{
						strcpy(vt, "bus");
						add_to_trips(start, end, date, time, account_number,vt);
					}
					if (control == 2)
					{
						strcpy(vt, "train");
						add_to_trips(start, end, date, time, account_number, vt);
					}
					if (control == 1)
					{
						strcpy(vt, "airplane");
						add_to_trips(start, end, date, time, account_number, vt);
					}
					clear_screen();
				}
				if (control == 2)//see or edit
				{
					cout << "\nIf you want to edit your user info enter (1) or to see trips' info enter (2) or to edit trips' info enter (3) \n";
					cin >> control;
					clear_screen();
					if (control == 1)
					{
						edit_driver_info(ID, password);
					}
					if (control == 2)
					{

					}
					if (control == 3)//editing trips by driver
					{
						cout << "\nIf you want to cancel a trip enter (1) or to delay a trip enter (2)\n";
						cin >> control;
						if (control == 1)//driver canceling
						{
							//cancel_trip();
						}
						if (control == 2)//driver delaying
						{
							edit_time();
						}
					}

				}

			}
		}
		if (control == 3)//customer logging in
		{
			check = 0;
			while (check != 1)
			{
				cout << "\nEnter your user name: ";
				scanf("%s", &user_name);
				cout << "\nEnter your password: ";
				scanf("%s", &password);
				check = search_info(user_name, password);
			}
			clear_screen();
				cout << "\nTo book a ticket enter (1) or To cancel a trip enter (2) or To see your travel history enter (3)\nTo edit your user info enter (4)";
				cin >> control;
				clear_screen();
				if (control == 1)//customer booking 
				{
					result = false;
					while (result == false)
					{
						cout << "\nEnter your starting point (between 1 and 300):";
						cin >> start;
						cout << "\nEnter your destination (between 1 and 300):";
						cin >> end;
						result = check_trip(start, end);
					}
					cout << "\nWhat day do you want to buy a ticket for (yyyy/mm/dd) : ";
					scanf("%s", &date);
					cout << "\nWhat time do you want to buy a ticket for (hh:mm) : ";
					scanf("%s", &time);
					cout << "\nPlease choose the type of your vehicle:\n1:Airplane\n2:Train\n3:Bus\n";
					int control_shop;
					cin >> control_shop;
					clear_screen();
					if (control_shop == 1)//Airplane
					{
						strcpy(vt, "airplane");
						check = 0;
						long int price;
						
						price = distance(start, end)*tarrif(vt);
						price *= 0.9;
						cout << "\nPrice for this trip is:" << price;
						cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
						cin >> control;
						clear_screen();
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							result = false;
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);

							}
							result = check_if_balanced(account_number, price);
							while (result == false)
							{
									cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
									cin >> control;
									if (control == 2)
									{
										goto main_menu;
									}
									if (control == 1)
									{
										check = 0;
										while (check != 1)
										{
											cout << "\nEnter your account:";
											scanf("%ld", &account_number);
											cout << "\nEnter your password:";
											scanf("%d", &account_password);
											check = search_account(account_number, account_password);
										}
									}
							result = check_if_balanced(account_number, price);
							}
							edit_account(account_number, -price);
							edit_trips(start, end, date, time, vt);
							edit_driver_account(price,date, time, vt);
							edit_manager_account(price);
							//add_to_sales(date, time,1, account_number);
						}
					}
					if (control_shop == 2)//Train
					{
						strcpy(vt, "train");
						check = 0;
						long int price;
						price = distance(start, end)*tarrif(vt);
						price*=0.9;
						cout << "\nPrice for this trip is:" << price;
						cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
						cin >> control;
						clear_screen();
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);

							}
							result = check_if_balanced(account_number, price);
							while (result == false)
							{
								cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
								cin >> control;
								if (control == 2)
								{
									goto main_menu;
								}
								if (control == 1)
								{
									check = 0;
									while (check != 1)
									{
										cout << "\nEnter your account:";
										scanf("%ld", &account_number);
										cout << "\nEnter your password:";
										scanf("%d", &account_password);
										check = search_account(account_number, account_password);
									}
								}
								result = check_if_balanced(account_number, price);
							}
							edit_account(account_number, -price);
							edit_trips(start, end, date, time, vt);
							edit_driver_account(price,date, time, vt);
							edit_manager_account(price);
							//add_to_sales(date, time,2, account_number);
						}
					}
					if (control_shop == 3)//Bus
					{
						strcpy(vt, "bus");
						check = 0;
						long int price;
						price = distance(start, end)*tarrif(vt);
						price *= 0.9;
						cout << "\nPrice for this trip is:" << price;
						cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
						cin >> control;
						clear_screen();
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);

							}
							result = check_if_balanced(account_number, price);
							while (result == false)
							{
								cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
								cin >> control;
								if (control == 2)
								{
									goto main_menu;
								}
								if (control == 1)
								{
									check = 0;
									while (check != 1)
									{
										cout << "\nEnter your account:";
										scanf("%ld", &account_number);
										cout << "\nEnter your password:";
										scanf("%d", &account_password);
										check = search_account(account_number, account_password);
									}
								}
								result = check_if_balanced(account_number, price);
							}
							edit_account(account_number, -price);
							edit_trips(start, end, date, time, vt);
							edit_driver_account(price,date, time, vt);
							edit_manager_account(price);
							//add_to_sales(date, time, 3, account_number);
						}
					}
				}
				
				if (control == 2)//customer canceling
				{

				}
				if (control == 3)//customer seeing history
				{

				}
				if (control == 4)//customer editing info
				{
					edit_info(user_name, password);
				}

		}
	}//end of log in
	if (control == 3)//visiting
	{
		cout << "\nIf you want to book a ticket enter (1) or if you want to exit enter(2)\n";
		cin >> control;
		clear_screen();
		if (control == 2)
		{
			goto main_menu;
		}
		
		if (control == 1)
		{
			result = false;
			while (result == false)
			{
				cout << "\nEnter your starting point (between 1 and 300): ";
				cin >> start;
				cout << "\nEnter your destination (between 1 and 300): ";
				cin >> end;
				result = check_trip(start, end);
			}

			cout << "\nWhat day do you want to buy a ticket for (yyyy/mm/dd) : ";
			scanf("%s", &date);
			cout << "\nWhat time do you want to buy a ticket for (hh:mm) : ";
			scanf("%s", &time);
			cout << "\nPlease choose the type of your vehicle:\n1:Airplane\n2:Train\n3:Bus\n";
			int control_shop;
			cin >> control_shop;
			clear_screen();
			if (control_shop == 1)//Airplane
			{
				strcpy(vt, "airplane");
				long int price;
				price = distance(start, end)*tarrif(vt);
				cout << "\nPrice for this trip is:" << price;
				cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
				cin >> control;
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					cout << "\nEnter your phone number:";
					scanf("%s", &phone_number);
					cout << "\nEnter your first name:";
					scanf("%s", &first_name);
					cout << "\nEnter your last name:";
					scanf("%s", &last_name);
					clear_screen();
					while (check != 1)
					{
						cout << "\nEnter your account:";
						scanf("%ld", &account_number);
						cout << "\nEnter your password:";
						scanf("%d", &account_password);
						check = search_account(account_number, account_password);

					}
					result = check_if_balanced(account_number, price);
					while (result == false)
					{
						cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
						cin >> control;
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							check = 0;
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);
							}
						}
						result = check_if_balanced(account_number, price);
					}
					
				}
				add_to_visitors(first_name, last_name, phone_number);
				it_works();
				edit_account(account_number,-price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price,date, time, vt);
				edit_manager_account(price);
				//add_to_sales(date, time, 1, account_number);

			}
			if (control_shop == 2)//Train
			{
				strcpy(vt, "train");
				long int price;
				
				price = distance(start, end)*tarrif(vt);
				cout << "\nPrice for this trip is:" << price;
				cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
				cin >> control;
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					cout << "\nEnter your phone number:";
					scanf("%s", &phone_number);
					cout << "\nEnter your first name:";
					scanf("%s", &first_name);
					cout << "\nEnter your last name:";
					scanf("%s", &last_name);
					clear_screen();
					while (check != 1)
					{
						cout << "\nEnter your account:";
						scanf("%ld", &account_number);
						cout << "\nEnter your password:";
						scanf("%d", &account_password);
						check = search_account(account_number, account_password);

					}
					result = check_if_balanced(account_number, price);
					while (result == false)
					{
						cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
						cin >> control;
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							check = 0;
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);
							}
						}
						result = check_if_balanced(account_number, price);
					}
					
				}
				add_to_visitors(first_name, last_name, phone_number);
				it_works();
				edit_account(account_number,-price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price,date, time, vt);
				edit_manager_account(price);
				//add_to_sales(date, time, 2, account_number);
			}
			if (control_shop == 3)//Bus
			{
				strcpy(vt, "bus");
				long int price;
				
				price = distance(start, end)*tarrif(vt);
				cout << "\nPrice for this trip is:" << price;
				cout << "\n\nAre you sure you want to pay for the trip YES (1) NO (2):";
				cin >> control;
				if (control == 2)
				{
					goto main_menu;
				}
				if (control == 1)
				{
					cout << "\nEnter your phone number:";
					scanf("%s", &phone_number);
					cout << "\nEnter your first name:";
					scanf("%s", &first_name);
					cout << "\nEnter your last name:";
					scanf("%s", &last_name);
					while (check != 1)
					{
						cout << "\nEnter your account:";
						scanf("%ld", &account_number);
						cout << "\nEnter your password:";
						scanf("%d", &account_password);
						check = search_account(account_number, account_password);

					}
					result = check_if_balanced(account_number, price);
					while (result == false)
					{
						cout << "\nDo you want to reeinter or try another account YES (1) NO (2):";
						cin >> control;
						if (control == 2)
						{
							goto main_menu;
						}
						if (control == 1)
						{
							check = 0;
							while (check != 1)
							{
								cout << "\nEnter your account:";
								scanf("%ld", &account_number);
								cout << "\nEnter your password:";
								scanf("%d", &account_password);
								check = search_account(account_number, account_password);
							}
						}
						result = check_if_balanced(account_number, price);
					}
					
				}
				add_to_visitors(first_name, last_name, phone_number);
				it_works();
				edit_account(account_number,-price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price,date, time, vt);
				edit_manager_account(price);
				//add_to_sales(date, time, 3, account_number);
			}
		}





	}//end of visiting
	
}//end of main




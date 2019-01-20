
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
#include "Header.h"




using namespace std;


int main()
{
main_menu:	cout << "\t\t\t\t\t\t\t\t\t\t\tWelcome!\n";
	cout << "\n\t\t\t\t\t\tsign up for free enter (1) or if you already have an account log in enter (2) or if you are just visiting enter (3)\n";
	int control;
	int account_password;
	long int account_number = 0;
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
			check = search_if_user_name_taken(user_name);
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
						edit_driver_account(price, date, time, vt);
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
					edit_driver_account(price, date, time, vt);
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
					edit_trips(start, end, date, time, vt);
					edit_driver_account(price, date, time, vt);
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
			cout << "\n\t\t\t\t\t\t\t\t\t To see information about trips and or passengers enter (4)\n";
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
					add_to_drivers(ID, ID, first_name, last_name, phone_number, vehicle);
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
						check = if_driver_registered(ID, password);
					}
					sys_edit_driver_info(ID, password);
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
						cout << "\nWhich type of vehicle do you want to change speed\nbus( enter (1) )\ntrain( enter(2) )\nairplane( enter(3) )\n";
						cin >> control;
						if (control == 1)//bus
						{
							cout << "\nEnter the speed in kilo meteres per hour: ";
							cin >> spd;
							strcpy(vt, "bus");
							edit_speed(vt, spd);

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
						cout << "\nWhich type of vehicle do you want to change capacity for\nbus( enter (1) )\ntrain( enter(2) )\nairplane( enter(3) )\n";
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
				char temp_un[81] = { 0 };
				char temp_pass[81] = { 0 };
				long int temp_acc = NULL;
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
						add_to_trips(start, end, date, time, account_number, vt);
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
						edit_driver_account(price, date, time, vt);
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
						edit_driver_account(price, date, time, vt);
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
						edit_driver_account(price, date, time, vt);
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
				edit_account(account_number, -price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price, date, time, vt);
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
				edit_account(account_number, -price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price, date, time, vt);
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
				edit_account(account_number, -price);
				edit_trips(start, end, date, time, vt);
				edit_driver_account(price, date, time, vt);
				edit_manager_account(price);
				//add_to_sales(date, time, 3, account_number);
			}
		}





	}//end of visiting

}//end of main



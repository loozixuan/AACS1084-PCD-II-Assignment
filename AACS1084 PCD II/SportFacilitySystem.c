#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include <Windows.h>
#include <time.h>
#pragma warning(disable:4996)
int choose();
void addStaff();
void searchStaff();
void modifyStaff();
void displayStaff();
void staffMain(); //Yuen Kuan
void addUser();
void userMain();
void searchUser();
void modifyUser();
void displayUser();//Nicole
void addFacilityRecord();
void searchFacilityRecord();
void modifyFacilityRecord();
void displayFacilityRecord();
void deleteFacilityRecord();
void confirm(char *cont);
int facilityMain();
int choice(); //loo zi xuan
void addBook();
void displayBook();
void searchBook();
void modifyBook();
void leave();
void confirmB(char *confirmation);
int bookingMain();//lee sin meai
void add();
int addA(char att);
void search();
void modify();
void cancellation(char bookingID);
void display();
void facilityUsageMain();
void logo();
typedef struct
{
	char staffID[6], name[30], password[10], phoneNum[15], position[20];

}Staff;
typedef struct
{
	char name[30], id[15], gender, status[10], ic[15], contactNo[15];
}information;
typedef struct
{
	char operationalDay[60], operationHours1[25], restDay[30];
}OperationTimes;

typedef struct
{
	char facilityID[20], types[20], description[20], venue[20];
	int maxUser;
	OperationTimes operation;
}Facility;
struct BookDate //chris
{
	int bookday, bookmonth, bookyear, startbooktime, endbooktime, startbookmin, endbookmin;
};
typedef struct {
	char userId[15], name[30], bookId[6], status[10], ic[15], contactNo[15];
	int bookCondition;
	char bookConditionWord[8];
	int choice;
	struct BookDate bookADate;
	char type[20], faciId[20], venue[20], description[20];
	int numUser;
}Book;

struct FacilityR //facility binary file
{
	char faciId[20], type[20], description[20], venue[20];
	int maxUser;
	OperationTimes operation;
};
typedef struct {
	char name[30], id[15], gender, status[10], ic[15], contactNo[15];
}user;
int main()
{
	Staff staff[1000];
	int mainOption, condition = 0, password = 0;
	char pass[10];
	FILE*passwordptr;
	passwordptr = fopen("staffInfo.txt", "r");
	if (passwordptr == NULL)
	{
		printf("Unable to open the file!");
		exit(-1);
	}
	while (fscanf(passwordptr, "%s\n%[^\n]\n%s\n%s\n%[^\n]\n", &staff[password].staffID, &staff[password].name, &staff[password].password, &staff[password].phoneNum, &staff[password].position) != EOF)
	{
		password++;
	}
	fclose(passwordptr);

	logo();
	printf("Enter staff password: ");
	rewind(stdin);
	scanf("%s", &pass);
	for (int i = 0; i < password; i++)
	{
		if (strcmp(staff[i].password, pass) == 0)
		{
			condition = 1;
			printf("Enter password successfully!!\n\n");
		}
	}
	if (condition == 1)
	{
		do {
			system("CLS");
			logo();
			printf("1.Staff Information Module\n");
			printf("2.Facility Module \n");
			printf("3.User Information Module\n");
			printf("4.Booking Module \n");
			printf("5.Facility Usage Module \n");
			printf("6.Exit\n");
			printf("Enter option: ");
			scanf("%d", &mainOption);
			system("CLS");
			if (mainOption == 1)
			{
				staffMain();
				system("CLS");
			}
			else if (mainOption == 2)
			{
				facilityMain();
				system("CLS");
			}
			else if (mainOption == 3)
			{
				userMain();
				system("CLS");
			}
			else if (mainOption == 4)
			{
				bookingMain();
				system("CLS");
			}
			else if (mainOption == 5)
			{
				facilityUsageMain();
				system("CLS");
			}
		} while (mainOption != 6);
	}
	if (!condition)
	{
		printf("Invalid password!!\n\n");
	}
	system("pause");
}
void logo()
{
	printf("                      _______   _______ ______    __   __  _______   \n");
	printf("	             |       ||   _   ||    _ |  |  | |  ||       |  \n");
	printf("	             |_     _||  |_|  ||   | ||  |  | |  ||       |  \n");
	printf("	               |   |  |       ||   |_||_ |  |_|  ||       |  \n");
	printf("	               |   |  |       ||    __  ||       ||      _|  \n");
	printf("	               |   |  |   _   ||   |  | ||       ||     |_   \n");
	printf("	               |___|  |__| |__||___|  |_||_______||_______|  \n");
	printf(" _______  _______  _______  ______    _______    _______  _______  _______  ___   ___      ___   _______  __   __   \n");
	printf("|       ||       ||       ||    _ |  |       |  |       ||   _   ||       ||   | |   |    |   | |       ||  | |  |  \n");
	printf("|  _____||    _  ||   _   ||   | ||  |_     _|  |    ___||  |_|  ||       ||   | |   |    |   | |_     _||  |_|  |  \n");
	printf("| |_____ |   |_| ||  | |  ||   |_||_   |   |    |   |___ |       ||       ||   | |   |    |   |   |   |  |       |  \n");
	printf("|_____  ||    ___||  |_|  ||    __  |  |   |    |    ___||       ||      _||   | |   |___ |   |   |   |  |_     _|  \n");
	printf(" _____| ||   |    |       ||   |  | |  |   |    |   |    |   _   ||     |_ |   | |       ||   |   |   |    |   |    \n");
	printf("|_______||___|    |_______||___|  |_|  |___|    |___|    |__| |__||_______||___| |_______||___|   |___|    |___|    \n");
	printf("=========================================================================================================================\n\n");
}
int choose()
{
	int choice;

	printf("-------------------------------\n");
	printf("1. Add Staff.\n2. Search Staff.\n3. Modify Staff.\n4. Display Staff.\n5. Exit.\n");
	printf("-------------------------------\n");
	printf("Please make your choice :");
	scanf("%d", &choice);

	return choice;
}

void addStaff()
{
	Staff staff;
	char ans, Staff_ID[6], alpha_1[6] = "S";
	int count = 0, pCount = 0;

	FILE*ptr1;
	ptr1 = fopen("staffInfo.txt", "r");
	if (ptr1 == NULL)
	{
		printf("Unable to open the file!");
		exit(-1);
	}
	while (fscanf(ptr1, "%s\n%s\n%s\n%s\n%s\n\n", staff.staffID, staff.name, staff.password, staff.phoneNum, staff.position) != EOF)
	{
		pCount++;
	}

	fclose(ptr1);

	ptr1 = fopen("staffInfo.txt", "a");
	if (ptr1 == NULL)
	{
		printf("Unable to open the file!\n");
		exit(-1);
	}

	do
	{
		printf("Do you want to add new staff? (Y = yes / N = no) : ");
		rewind(stdin);
		scanf("%c", &ans);
		if (toupper(ans) == 'Y' || toupper(ans) == 'y')
		{
			count += pCount;
			printf("Enter Staff ID : ");
			sprintf(Staff_ID, "%04d", count);
			strcat(alpha_1, Staff_ID);
			strcpy(staff.staffID, alpha_1);
			printf("%s\n", staff.staffID);

			printf("Enter Staff Name : ");
			rewind(stdin);
			scanf("%[^\n]", &staff.name);

			printf("Enter Password (Max. 9 chars): ");
			rewind(stdin);
			scanf("%s", &staff.password);

			printf("Enter Phone Number : ");
			rewind(stdin);
			scanf("%s", &staff.phoneNum);

			printf("Enter Position : ");
			rewind(stdin);
			scanf("%[^\n]", &staff.position);

			printf("\n");
			printf("Successfully!\n\n");

			fprintf(ptr1, "%s\n%s\n%s\n%s\n%s\n\n", staff.staffID, staff.name, staff.password, staff.phoneNum, staff.position);

			fclose(ptr1);
		}
		else
			printf("Invalid input!\n\n");

	} while (ans != 'Y'&&ans != 'y'&&ans != 'N'&&ans != 'n');
}

void searchStaff()
{
	Staff staff2;
	int search = 0;
	char findID[20], ans;

	FILE*ptr2;

	do
	{
		ptr2 = fopen("staffInfo.txt", "r");

		if (ptr2 == NULL)
		{
			printf("Unable to open the file!\n");
			exit(-1);
		}

		printf("Enter Staff ID : ");
		rewind(stdin);
		scanf("%s", &findID);

		while (fscanf(ptr2, "%s\n%[^\n]\n%s\n%s\n%s\n\n", staff2.staffID, staff2.name, staff2.password, staff2.phoneNum, staff2.position) != EOF)
		{
			if (strcmp(findID, staff2.staffID) == 0)
			{
				search++;
				printf("%s %s %s\n", staff2.staffID, staff2.name, staff2.position);
			}

			if (!search)
				printf("No record found! :(\n");
		}

		printf("\nDo you want to search another staff? (Y = yes / N = no) :");
		rewind(stdin);
		scanf("%c", &ans);

		printf("\n");

		fclose(ptr2);
	} while (toupper(ans) == 'Y');
}
void modifyStaff()
{
	Staff staff3[1000], newStaff;
	int count = 0, num;
	char cont;
	char modifyID[6], modifypd[10], pwV[10];

	FILE*ptr3;
	ptr3 = fopen("staffInfo.txt", "r");
	if (ptr3 == NULL)
	{
		printf("Unable to open the file!\n");
		exit(-1);
	}

	while (!feof(ptr3))
	{
		fscanf(ptr3, "%s\n%[^\n]\n%s\n%s\n%[^\n]\n", staff3[count].staffID,
			staff3[count].name, staff3[count].password, staff3[count].phoneNum, staff3[count].position);
		count++;
	}

	fclose(ptr3);

	printf("Do you want to modify? (Y = yes / N = no) : ");
	rewind(stdin);
	scanf("%c", &cont);

	if (cont == 'Y' || cont == 'y')
	{
		do
		{
			int search = 0;
			printf("Enter ID to modify : ");
			rewind(stdin);
			scanf("%s", modifyID);

			for (int i = 0; i < count; i++)
			{
				if (strcmp(modifyID, staff3[i].staffID) == 0)
				{
					printf("Enter Password : ");
					rewind(stdin);
					scanf("%s", modifypd);
					printf("\n");

					if (strcmp(modifypd, staff3[i].password) == 0)
					{
						search = 1;
						printf("===============================\n");
						printf("1. Renewal Staff Name.\n2. Renewal Staff Password.\n3. Renewal Staff Phone Number.\n4. Renewal Position.\n");
						printf("===============================\n");
						printf("Please make your choice :");
						scanf("%d", &num);

						while (num < 1 || num > 4)
						{
							printf("Invalid Input!!!\n");
							printf("Please make your choice :");
							scanf("%d", &num);
						}

						switch (num)
						{
						case 1:
							printf("Enter Staff Name : ");
							rewind(stdin);
							scanf("%[^\n]", newStaff.name);
							strcpy(staff3[i].name, newStaff.name);
							printf("Renewal Successfully!\n\n");
							break;

						case 2:
							printf("Enter Your Current Password : ");
							rewind(stdin);
							scanf("%s", &pwV);
							if (strcmp(pwV, staff3[i].password) == 0)
							{
								printf("Enter Your New Password : ");
								rewind(stdin);
								scanf("%s", newStaff.password);
								strcpy(staff3[i].password, newStaff.password);
								printf("Renewal Successfully!\n\n");
							}
							else
							{
								printf("Wrong Password!\n");
							}
							break;

						case 3:
							printf("Enter Phone Number : ");
							rewind(stdin);
							scanf("%s", newStaff.phoneNum);
							strcpy(staff3[i].phoneNum, newStaff.phoneNum);
							printf("Renewal Successfully!\n\n");
							break;

						default:
							printf("Enter Position : ");
							rewind(stdin);
							scanf("%[^\n]", newStaff.position);
							strcpy(staff3[i].position, newStaff.position);
							printf("Renewal Successfully!\n\n");
						}
					}

					else
						printf("--- Wrong Password! ---\n");
				}

				else
					printf("--- No record found! :( ---\n");
			}

			printf("\nDo you want to continue? (Y = yes / N = no): ");
			rewind(stdin);
			scanf("%c", &cont);

		} while (cont == 'Y' || cont == 'y');
	}

	FILE*ptr4;
	ptr4 = fopen("staffInfo.txt", "w");
	if (ptr4 == NULL)
	{
		printf("Unable to open the file!\n");
		exit(-1);
	}

	for (int i = 0; i < count; i++)
	{
		fprintf(ptr4, "%s\n%s\n%s\n%s\n%s\n", staff3[i].staffID, staff3[i].name, staff3[i].password, staff3[i].phoneNum, staff3[i].position);
	}

	fclose(ptr4);
}

void displayStaff()
{
	Staff staff4;
	char home;

	FILE*ptr4;
	ptr4 = fopen("staffInfo.txt", "r");
	if (ptr4 == NULL)
	{
		printf("Unable to open the file!\n");
		exit(-1);
	}

	printf("_________\t______________\t______________\t__________\t\n");
	printf("STAFF ID \t  NAME \t\t PHONE NUMBER \t POSITION \t\n");
	printf("_________\t______________\t______________\t__________\t\n");

	while (!feof(ptr4))
	{
		fscanf(ptr4, "%s\n%[^\n]\n%s\n%s\n%[^\n]\n\n", staff4.staffID, staff4.name, staff4.password, staff4.phoneNum, staff4.position);
		printf("%s \t\t%s \t %s \t %s\n", staff4.staffID, staff4.name, staff4.phoneNum, staff4.position);
	}

	printf("\n");
	printf("Press any button for returning to the home page.\n");
	rewind(stdin);
	scanf("%c", &home);

	fclose(ptr4);
}
void staffMain()
{
	int ans;
	do
	{
		ans = choose();
		if (ans == 1)
		{
			addStaff();
			system("cls");
		}
		else if (ans == 2)
		{
			searchStaff();
			system("cls");
		}
		else if (ans == 3)
		{
			modifyStaff();
			system("cls");
		}
		else if (ans == 4)
		{
			displayStaff();
			system("cls");
		}

	} while (ans != 5);
}
//zi xuan

int choice()
{
	int choice;
	printf("-------------------\n");
	printf("| SPORT FACILITIES |\n");
	printf("-------------------\n");
	printf("Select Your Choice\n");
	printf("-------------------\n");
	printf("1.\tAdd Facility Record\n");
	printf("2.\tSearch Facility Record\n");
	printf("3.\tModify Facility Record\n");
	printf("4.\tDisplay Facility Record\n");
	printf("5.\tDelete Facility Record\n");
	printf("6.\tEXIT\n");
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("**Program will be automatically terminated if user accidently input CHARACTER**\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("Select one option:");
	scanf("%d", &choice);
	return choice;
}

int facilityMain()
{
	int option;
	do {
		option = choice();
		while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6)
		{
			printf("Invalid Choice!!! \n\n");
			printf("Select One Option: ");
			scanf("%d", &option);
			if (scanf("%d", &option) != 1)
				exit(-1);
		}

		switch (option)
		{
		case 1:
			addFacilityRecord();
			system("cls");
			break;
		case 2:
			searchFacilityRecord();
			system("cls");
			break;
		case 3:
			modifyFacilityRecord();
			system("cls");
			break;
		case 4:
			displayFacilityRecord();
			system("cls");
			break;
		case 5:
			deleteFacilityRecord();
			system("cls");
			break;

		}
	} while (option != 6);
}

void confirm(char *cont)
{
	printf("\nDo you want to continue?(y-Yes/ n-No): ");
	rewind(stdin);
	scanf("%c", &*cont);
}

void addFacilityRecord()
{
	FILE*fptrFacility;
	char answerAdd, confirmAdd;
	char integer_ID[5], alphabet_string[6] = "F";
	int idCount = 1, pCount = 0;
	Facility facility;
	fptrFacility = fopen("facility.bin", "rb");
	if (fptrFacility == NULL)
	{
		printf("Error in opening file!!!");
		exit(-1);
	}
	while (fread(&facility, sizeof(Facility), 1, fptrFacility))
	{
		pCount++;
	}
	fclose(fptrFacility);
	fptrFacility = fopen("facility.bin", "ab");
	if (fptrFacility == NULL)
	{
		printf("Error in opening file!!!");
		exit(-1);
	}

	printf("\n\n**Addition Sport Facility Record**\n");
	printf("======================================\n");
	do {
		printf("Do you want to ADD NEW facility record?(y-yes / n-no) :");
		rewind(stdin);
		scanf("%c", &answerAdd);
		answerAdd = toupper(answerAdd);
		if (answerAdd == 'Y')
		{
			idCount += pCount;
			sprintf(integer_ID, "%04d", idCount);
			strcat(alphabet_string, integer_ID);
			strcpy(facility.facilityID, alphabet_string);
			printf("Facility ID>%6s\n", facility.facilityID);
			printf("Enter Facility Types> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.types);
			printf("Enter Facility Description> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.description);
			printf("Enter venue> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.venue);
			printf("Enter Maximun Allowance User> ");
			scanf("%d", &facility.maxUser);
			if (facility.maxUser == 0)
			{
				printf("-------------------------------------------------------------------\n");
				printf("|INFO: **There is no LIMIT allowance user for this Facility Type**|\n");
				printf("-------------------------------------------------------------------\n");
			}
			printf("Enter Operational Day> ");
			rewind(stdin);
			scanf("%[^\n]", facility.operation.operationalDay);
			printf("Enter Operational Hours> ");
			rewind(stdin);
			scanf("%[^\n]", &facility.operation.operationHours1);
			printf("Enter Rest day> ");
			rewind(stdin);
			scanf("%s", &facility.operation.restDay);
			printf("Are you confirm to add this Facility Record? ");
			rewind(stdin);
			scanf("%c", &confirmAdd);
			if (confirmAdd == 'y' || confirmAdd == 'Y')
			{
				fwrite(&facility, sizeof(Facility), 1, fptrFacility);
				printf("Record successfully ADD.\n\n");
			}
		}

	} while (answerAdd != 'y' && answerAdd != 'Y' && answerAdd == 'n' && answerAdd == 'N');

	fclose(fptrFacility);
	printf("\n");
}

void searchFacilityRecord()
{
	Facility facility;
	int option;
	int found = 0;
	char selection;
	char idSeacrh[10], typeSearch[20], venueSearch[20], cont;
	FILE*fptrFacility;
	do {
		fptrFacility = fopen("facility.bin", "rb");
		if (fptrFacility == NULL)
		{
			printf("Error in opening file.");
			exit(-1);
		}
		printf("\n**Sport Record Searching**\n");
		printf("============================\n");
		printf("##Program will be automatically terminated if user input CHARACTER##\n");
		printf("Options:1.Facility ID\n\t2.Facility Type\n\t3.Venue\n\t4.Exit\n\n");
		printf("Enter an option to search: ");
		scanf("%d", &option);
		while (option != 1 && option != 2 && option != 3)
		{
			printf("\nInvalid input.\n");
			printf("Select your searching option : ");
			scanf("%d", &option);
			if (scanf("%d", &option) != 1)
				exit(-1);
		}

		if (option == 1)
		{
			printf("Enter Facility ID to seacrh:");
			rewind(stdin);
			scanf("%s", &idSeacrh);
			while (fread(&facility, sizeof(Facility), 1, fptrFacility))
			{
				if (strcmp(idSeacrh, facility.facilityID) == 0)
				{
					found = 1;
					printf("Facility ID                    >\t%s\n", facility.facilityID);
					printf("Enter Facility Types           >\t%s\n", facility.types);
					printf("Enter Facility Description     >\t%s\n", facility.description);
					printf("Enter venue                    >\t%s\n", facility.venue);
					printf("Enter Maximun Allowance User   >\t%d\n", facility.maxUser);
					printf("Enter Operational Day          >\t%s\n", facility.operation.operationalDay);
					printf("Enter Operational Hours        >\t%s\n", facility.operation.operationHours1);
					printf("Enter Rest day                 >\t%s\n\n", facility.operation.restDay);

				}
			}

		}
		else if (option == 2)
		{
			printf("Enter Facility Types to search:");
			rewind(stdin);
			scanf("%[^\n]", &typeSearch);
			while (fread(&facility, sizeof(Facility), 1, fptrFacility))
			{
				if (strcmp(typeSearch, facility.types) == 0)
				{
					found = 1;
					printf("Facility ID                    >\t%s\n", facility.facilityID);
					printf("Enter Facility Types           >\t%s\n", facility.types);
					printf("Enter Facility Description     >\t%s\n", facility.description);
					printf("Enter venue                    >\t%s\n", facility.venue);
					printf("Enter Maximun Allowance User   >\t%d\n", facility.maxUser);
					printf("Enter Operational Day          >\t%s\n", facility.operation.operationalDay);
					printf("Enter Operational Hours        >\t%s\n", facility.operation.operationHours1);
					printf("Enter Rest day                 >\t%s\n\n", facility.operation.restDay);

				}

			}

		}
		else if (option == 3)
		{
			printf("Enter Venue to search:");
			rewind(stdin);
			scanf("%[^\n]", &venueSearch);
			while (fread(&facility, sizeof(Facility), 1, fptrFacility))
			{
				if (strcmp(venueSearch, facility.venue) == 0)
				{
					found = 1;
					printf("Facility ID                    >\t%s\n", facility.facilityID);
					printf("Enter Facility Types           >\t%s\n", facility.types);
					printf("Enter Facility Description     >\t%s\n", facility.description);
					printf("Enter venue                    >\t%s\n", facility.venue);
					printf("Enter Maximun Allowance User   >\t%d\n", facility.maxUser);
					printf("Enter Operational Day          >\t%s\n", facility.operation.operationalDay);
					printf("Enter Operational Hours        >\t%s\n", facility.operation.operationHours1);
					printf("Enter Rest day                 >\t%s\n\n", facility.operation.restDay);

				}
			}

		}
		if (!found)
		{
			printf("No record found!\n");
			printf("Please Press y if you want to TRY AGAIN or search facility Record...");
			system("cls");
		}
		printf("Do you want to search another Record?(y-yes / n-No) :");
		rewind(stdin);
		scanf("%c", &cont);
	} while (cont == 'y' || cont == 'Y');

	printf("\n");
	fclose(fptrFacility);
}


void modifyFacilityRecord()
{
	char confirmCont, modifyConfirmation, idSearch[20], selection, modifyConfirm, newTypes[25], newVenue[25], newDescription[25], newOperationalDays[20], newOperationalHour[20], newRestDay[20], cont;
	int newMaxUser, vCount = 0, option;
	int found = 0;
	Facility facility[1000];
	FILE*fptrFacility;
	FILE*fptrFacility2;
	fptrFacility = fopen("facility.bin", "rb");
	if (fptrFacility == NULL)
	{
		printf("Error in opening file.");
		exit(-1);
	}

	while (fread(&facility[vCount], sizeof(Facility), 1, fptrFacility))
	{
		vCount++;
	}
	fclose(fptrFacility);

	printf("\n\n**Sport Facility Modification**\n");
	printf("===================================\n");
	printf("KINDLY REMINDER: *Facility ID cannot be Modified\n");
	printf("##Program will be automatically terminated if user input CHARACTER##\n");
	printf("Options:1.Facility Type\t\n\t2.Facility Description\t\n\t3.Venue\t\n\t4.Maximun Allowance User\t\n\t5.Operational Times(Days/Hours/Rest Day)\t\n\t6.Exit\t\n\n");
	printf("\n");
	printf("\nDo you want to modify record?(y-yes / n-no) :");
	rewind(stdin);
	scanf("%c", &selection);
	if (selection == 'y' || selection == 'Y')
	{
		do {
			printf("Please Enter a facility ID to modify> ");
			rewind(stdin);
			scanf("%[^\n]", &idSearch);
			for (int i = 0; i < vCount; i++)
			{
				if (strcmp(facility[i].facilityID, idSearch) == 0)
				{
					found = 1;
					printf("Enter an option to modify: ");
					scanf("%d", &option);
					while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
					{
						printf("Invalid option.\n");
						printf("Enter an option to modify: ");
						scanf("%d", &option);
						if (scanf("%d", &option) != EOF)
							exit(-1);

					}
					if (option == 1)
					{
						printf("New Facility Type: ");
						rewind(stdin);
						scanf("%[^\n]", &newTypes);
						found++;
						printf("ARE you confirm to modify this record? ");
						rewind(stdin);
						scanf("%c", &modifyConfirmation);
						if (modifyConfirmation == 'y' || modifyConfirmation == 'Y')
						{
							strcpy(facility[i].types, newTypes);
							printf("Record modified successfully.\n");
						}
					}
					else if (option == 2)
					{
						printf("New Facility Description: ");
						rewind(stdin);
						scanf("%[^\n]", &newDescription);
						found++;
						printf("ARE you confirm to modify this record? ");
						rewind(stdin);
						scanf("%c", &modifyConfirmation);
						if (modifyConfirmation == 'y' || modifyConfirmation == 'Y')
						{
							strcpy(facility[i].description, newDescription);
							printf("Record modified successfully.\n");
						}
					}
					else if (option == 3)
					{
						printf("Enter New Venue: ");
						rewind(stdin);
						scanf("%[^\n]", &newVenue);
						found++;
						printf("ARE you confirm to modify this record? ");
						rewind(stdin);
						scanf("%c", &modifyConfirmation);
						if (modifyConfirmation == 'y' || modifyConfirmation == 'Y')
						{
							strcpy(facility[i].venue, newVenue);
							printf("Record modified successfully.\n");
						}
					}
					else if (option == 4)
					{
						printf("Enter New Maximun Allowance User: ");
						scanf("%d", &newMaxUser);
						found++;

						printf("ARE you confirm to modify this record? ");
						rewind(stdin);
						scanf("%c", &modifyConfirmation);
						if (modifyConfirmation == 'y' || modifyConfirmation == 'Y')
						{
							facility[i].maxUser = newMaxUser;
							printf("Record modified successfully.\n");
						}
					}
					else if (option == 5)
					{
						printf("Enter New Operational Days: ");
						rewind(stdin);
						scanf("%[^\n]", &newOperationalDays);
						printf("Enter New Operational Hours: ");
						rewind(stdin);
						scanf("%[^\n]", &newOperationalHour);
						printf("Enter New Rest Day: ");
						rewind(stdin);
						scanf("%[^\n]", &newRestDay);
						printf("ARE you confirm to modify this record? ");
						rewind(stdin);
						scanf("%c", &modifyConfirmation);
						if (modifyConfirmation == 'y' || modifyConfirmation == 'Y')
						{
							strcpy(facility[i].operation.operationalDay, newOperationalDays);
							strcpy(facility[i].operation.operationHours1, newOperationalHour);
							strcpy(facility[i].operation.restDay, newRestDay);
							printf("Record modified successfully.\n");
						}
					}
				}
			}
			if (!found)
			{
				printf("No record found!!!\n");
				printf("Please Press y if you want to TRY AGAIN or continue modify ^^\n");
			}
			confirm(&confirmCont);
		} while (confirmCont == 'y' || confirmCont == 'Y');

	}


	fptrFacility2 = fopen("facility.bin", "wb");
	if (fptrFacility2 == NULL)
	{
		printf("Error in opening file.");
		exit(-1);
	}

	for (int i = 0; i < vCount; i++)
	{
		fwrite(&facility[i], sizeof(Facility), 1, fptrFacility);
	}

	fclose(fptrFacility2);
}

void displayFacilityRecord()
{
	char back;
	Facility facility;
	FILE*fptrFacility;
	fptrFacility = fopen("facility.bin", "rb");
	if (fptrFacility == NULL)
	{
		printf("Error in opening file.");
		exit(-1);
	}

	printf("**Sport Facility Record**\n");
	printf("=========================\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| Facility ID  |    Facility Types    |   Facility Description   |         Venue         | Maximun Allowance User |   Operational Day   | Operational Hours | Rest Day |\n");
	printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	while (fread(&facility, sizeof(Facility), 1, fptrFacility))
	{
		printf("|  %5s       |    %10s        |    %18s    |   %13s   |          %d          |   %12s   |    %10s    |%10s        |\n", facility.facilityID, facility.types, facility.description, facility.venue, facility.maxUser, facility.operation.operationalDay, facility.operation.operationHours1, facility.operation.restDay);
		printf("|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	}

	fclose(fptrFacility);
	printf("\nPress any key to back to previous HOMEPAGES...\n");
	rewind(stdin);
	scanf("%c", &back);
	printf("\n\n");
}

void deleteFacilityRecord()
{
	char deleteID[20], back;
	Facility facility;
	FILE*fptrFacility, *file2;

	printf("\n**Facility Record Deletion**\n");
	printf("============================\n");
	printf("Please Enter Facility ID to delete: ");
	rewind(stdin);
	scanf("%[^\n]", &deleteID);

	fptrFacility = fopen("facility.bin", "rb");
	file2 = fopen("temp.bin", "wb");
	rewind(fptrFacility);

	while (fread(&facility, sizeof(Facility), 1, fptrFacility))
	{
		if (strcmp(facility.facilityID, deleteID) == 0)
		{
			printf("Record successfully be Deleted.");
		}
		else
		{
			fwrite(&facility, sizeof(Facility), 1, file2);
		}

	}
	fclose(fptrFacility);
	fclose(file2);
	remove("facility.bin");
	rename("temp.bin", "facility.bin");
	printf("\nPress any key to back to previous HOMEPAGES...\n");
	rewind(stdin);
	scanf("%c", &back);
	printf("\n\n");
}

void userMain()
{
	int option;


	do
	{
		system("CLS");
		printf("-----------------------------\n");
		printf("1. Add\n");
		printf("2. Search\n");
		printf("3. Modify\n");
		printf("4. Display\n");
		printf("5. Exit\n\n");

		printf("Enter your option: ");
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 1:
			system("CLS");
			addUser(); break;
		case 2:
			system("CLS");
			searchUser(); break;
		case 3:
			system("CLS");
			modifyUser(); break;
		case 4:
			system("CLS");
			displayUser(); break;
		case 5:
			break;
		default:
			printf("Invalid Input\n.");
		}

	} while (option != 5);
}

void addUser()
{
	FILE*userInfo;
	char addUser;

	do
	{
		userInfo = fopen("userInfo.bin", "ab");
		if (userInfo == NULL)
		{
			printf("Error!\n");
			exit(-1);
		}

		information info;
		char comformation;

		printf("==========================================\n");
		printf("Name                          :");
		rewind(stdin);
		scanf("%[^\n]", &info.name);

		printf("Student id / Staff id         :");
		rewind(stdin);
		scanf("%s", &info.id);

		printf("Gender (Male = m, Female = f) :");
		rewind(stdin);
		scanf("%c", &info.gender);

		printf("Student / Staff               :");
		rewind(stdin);
		scanf("%s", &info.status);

		printf("IC number                     :");
		rewind(stdin);
		scanf("%s", &info.ic);

		printf("Contact number                :");
		rewind(stdin);
		scanf("%s", &info.contactNo);
		printf("==========================================\n");

		printf("Comfirm registration ? (Yes = y) :");
		rewind(stdin);
		scanf("%c", &comformation);
		comformation = tolower(comformation);

		if (comformation == 'y')
		{
			fwrite(&info, sizeof(information), 1, userInfo);
		}

		printf("Do you want to add another user? (yes=y): ");
		rewind(stdin);
		scanf("%c", &addUser);
		addUser = tolower(addUser);
		printf("\n");

		fclose(userInfo);
	} while (addUser == 'y');

}

void searchUser()
{
	FILE*userInfo;
	char searchUser, answer, action;

	do
	{
		userInfo = fopen("userInfo.bin", "rb");
		if (userInfo == NULL)
		{
			printf("Error!\n");
			exit(-1);
		}

		information searchInfo, info;
		int option, count = 0;


		printf("Searchng by :\n1. Name\n2. Student ID/Staff ID\n3. Contact number\n");
		printf("Please enter your option: ");
		scanf("%d", &option);
		printf("\n===========================================\n");

		if (option != 1 && option != 2 && option != 3)
		{
			printf("The option you key in is invalid !\n");
			printf("Do you want to re-enter your option (yes=y,no=n): ");
			scanf("%c", &answer);
			if (answer == 'y' || answer == 'Y')
			{
				printf("Enter your option: ");
				scanf("%d", &option);
			}
		}

		if (option == 1)
		{
			printf("\n");
			printf("Enter name: ");
			rewind(stdin);
			scanf("%[^\n]", &searchInfo.name);
			printf("===========================================\n");

			while (fread(&info, sizeof(information), 1, userInfo))
			{
				if (strcmp(searchInfo.name, info.name) == 0)
				{
					printf("+--------------------+---------------+\n");
					printf("|Name                |%-15s|\n", info.name);
					printf("+--------------------+---------------+\n");
					printf("|Status              |%-15s|\n", info.status);
					printf("+--------------------+---------------+\n");
					printf("|Gender              |%-15c|\n", info.gender);
					printf("+--------------------+---------------+\n");
					printf("|IC number           |%-15s|\n", info.ic);
					printf("+--------------------+---------------+\n");
					printf("|Contact number      |%-15s|\n", info.contactNo);
					printf("+--------------------+---------------+\n");
					printf("|student ID/Staff ID |%-15s|\n", info.id);
					printf("+--------------------+---------------+\n");
					count++;
				}
			}
			if (!count)
			{
				printf("No record found.\n");
			}
		}
		else if (option == 2)
		{
			printf("Student ID/Staff ID: ");
			rewind(stdin);
			scanf("%s", &searchInfo.id);
			printf("\n");

			while (fread(&info, sizeof(information), 1, userInfo))
			{
				if (strcmp(searchInfo.id, info.id) == 0)
				{
					printf("+--------------------+---------------+\n");
					printf("|Name                |%-15s|\n", info.name);
					printf("+--------------------+---------------+\n");
					printf("|Status              |%-15s|\n", info.status);
					printf("+--------------------+---------------+\n");
					printf("|Gender              |%-15c|\n", info.gender);
					printf("+--------------------+---------------+\n");
					printf("|IC number           |%-15s|\n", info.ic);
					printf("+--------------------+---------------+\n");
					printf("|Contact number      |%-15s|\n", info.contactNo);
					printf("+--------------------+---------------+\n");
					printf("|student ID/Staff ID |%-15s|\n", info.id);
					printf("+--------------------+---------------+\n");
					count++;
				}
			}
			if (!count)
			{
				printf("No record,\n");
			}
		}
		else if (option == 3)
		{
			printf("Enter contact number: ");
			rewind(stdin);
			scanf("%s", &searchInfo.contactNo);
			printf("\n");

			while (fread(&info, sizeof(information), 1, userInfo))
			{
				if (strcmp(searchInfo.contactNo, info.contactNo) == 0)
				{
					printf("+--------------------+---------------+\n");
					printf("|Name                |%-15s|\n", info.name);
					printf("+--------------------+---------------+\n");
					printf("|Status              |%-15s|\n", info.status);
					printf("+--------------------+---------------+\n");
					printf("|Gender              |%-15c|\n", info.gender);
					printf("+--------------------+---------------+\n");
					printf("|IC number           |%-15s|\n", info.ic);
					printf("+--------------------+---------------+\n");
					printf("|Contact number      |%-15s|\n", info.contactNo);
					printf("+--------------------+---------------+\n");
					printf("|student ID/Staff ID |%-15s|\n", info.id);
					printf("+--------------------+---------------+\n");
					count++;
				}
			}
			if (!count)
			{
				printf("No record.\n");
			}
		}
		printf("Do you want to search another user?(yes=y): ");
		rewind(stdin);
		scanf("%c", &action);
		printf("\n");
	} while (action == 'y' || action == 'Y');
	fclose(userInfo);

}
void modifyUser()
{
	FILE *userInfo;
	information info[100], newInfo;
	char modifyAns, userID[15], comfirmation, modification;
	int num = 0, option;


	userInfo = fopen("userInfo.bin", "rb");
	if (userInfo == NULL)
	{
		printf("Error!\n");
		exit(-1);
	}
	while (fread(&info[num], sizeof(information), 1, userInfo))
	{
		num++;
	}
	fclose(userInfo);
	printf("                Profile modification\n");
	printf("=====================================================\n");
	do {
		printf("Do you want to modify your profile ?(yes=y,no=n): ");
		rewind(stdin);
		scanf("%c", &modifyAns);
		modifyAns = tolower(modifyAns);
		printf("\n");
		int count = 0;
		if (modifyAns == 'y')
		{
			printf("Enter student ID/Staff ID: ");
			rewind(stdin);
			scanf("%s", &userID);
			printf("\n");
			for (int i = 0; i < num; i++)
			{
				if (strcmp(userID, info[i].id) == 0)
				{
					printf("Name                :%s\n", info[i].name);
					printf("Status              :%s\n", info[i].status);
					printf("Gender              :%c\n", info[i].gender);
					printf("IC number           :%s\n", info[i].ic);
					printf("Contact number      :%s\n", info[i].contactNo);
					printf("student ID/Staff ID :%s\n", info[i].id);
					printf("=========================================\n");
					count++;
					printf("Which statement you want to modify?\n");
					printf("1.Name\n2.Gender\n3.Student ID/Staff ID\n4.Contact number\n5.IC number\n6.Status\n");
					printf("Enter your option: ");
					rewind(stdin);
					scanf("%d", &option);
					switch (option)
					{
					case 1:
						printf("Enter your new name: ");
						rewind(stdin);
						scanf("%[^\n]", &newInfo.name);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							strcpy(info[i].name, newInfo.name);
						}
						break;
					case 2:
						printf("Enter your new gender: ");
						rewind(stdin);
						scanf("%c", &newInfo.gender);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							info[i].gender = newInfo.gender;
						}
						break;
					case 3:
						printf("Enter your new student ID/staff ID: ");
						rewind(stdin);
						scanf("%s", &newInfo.id);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							strcpy(info[i].id, newInfo.id);
						}
						break;
					case 4:
						printf("Enter your new contact number: ");
						rewind(stdin);
						scanf("%s", &newInfo.contactNo);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							strcpy(info[i].contactNo, newInfo.contactNo);
						}
						break;
					case 5:
						printf("Enter your new IC number: ");
						rewind(stdin);
						scanf("%s", &newInfo.ic);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							strcpy(info[i].ic, newInfo.ic);
						}
						break;
					case 6:
						printf("Enter your new status: ");
						rewind(stdin);
						scanf("%s", &newInfo.status);
						printf("\n");
						printf("Do you comfirm want to save this new information (yes=y): ");
						rewind(stdin);
						scanf("%c", &comfirmation);
						if (comfirmation == 'y' || comfirmation == 'Y')
						{
							strcpy(info[i].status, newInfo.status);
						}
						break;
					default:
						printf("Enter invalid option.\n");
					}
				}
			}
			if (!count)
			{
				printf("No record found!!!\n");
			}

		}
	} while (modifyAns == 'y' || modifyAns == 'Y');


	userInfo = fopen("userInfo.bin", "wb");
	if (userInfo == NULL)
	{
		printf("Error!\n");
		exit(-1);
	}
	for (int i = 0; i < num; i++)
	{
		fwrite(&info[i], sizeof(information), 1, userInfo);
	}
	fclose(userInfo);
}
void displayUser()
{
	char answer;
	FILE*userInfo;
	do
	{
		userInfo = fopen("userInfo.bin", "rb");
		if (userInfo == NULL)
		{
			printf("Error!\n");
			exit(-1);
		}

		information info;

		printf(" \t\t\t   Display information\n");
		printf("+---------------+----------+----------+-------+---------------+---------------+\n");
		printf("|Name           |ID        |Status    |Gender |IC number      |Contact number |\n");

		while (fread(&info, sizeof(information), 1, userInfo))
		{
			printf("+---------------+----------+----------+-------+---------------+---------------+\n");
			printf("|%-15s|%-10s|%-10s|%-7c|%-15s|%-15s|\n", info.name, info.id, info.status, info.gender, info.ic, info.contactNo);
		}
		printf("+---------------+----------+----------+-------+---------------+---------------+\n");
		printf("Do you want to display again?(yes=y): ");
		rewind(stdin);
		scanf("%c", &answer);

	} while (answer == 'y' || answer == 'Y');
	fclose(userInfo);

}
int bookingMain()
{
	int mainChoice;
	do {
		printf("\tBooking Module\n==============================\n");
		printf("1.Book/Walk In\n");
		printf("2.Search Booking Information\n");
		printf("3.Modify Booking Information\n");
		printf("4.Display Booking \n");
		printf("5.Exit \n\n");
		printf("==============================\n");
		do {
			printf("Enter choice: ");
			scanf("%d", &mainChoice);
			if (mainChoice < 1 || mainChoice>5)
				printf("Invalid Choice!\n");

		} while (mainChoice < 1 || mainChoice>5);

		if (mainChoice == 1)
		{
			addBook();
			system("CLS");
		}
		else if (mainChoice == 2)
		{
			searchBook();
			system("CLS");
		}
		else if (mainChoice == 3)
		{
			modifyBook();
			system("CLS");
		}
		else if (mainChoice == 4)
		{
			displayBook();
			system("CLS");
		}
	} while (mainChoice != 5);
}
void addBook()
{
	SYSTEMTIME t; //time,date,day
	GetLocalTime(&t);
	time_t tt = time(NULL);  //today Day
	struct tm *tm = localtime(&tt);
	char s[10], integer_string[5], other_string[6] = "B", registedUser, confirmBook, home;
	int condition = 0, errorCount = 0, found = 0, maxDay, maxMonth = 12, minStart = 9, maxEnd = 21, count = 1, pCountUser = 0, pFaci = 0, pBookRead = 0; //date condition
	Book bookRead[1000];
	Book bookDetails;
	user userdetail[1000];
	struct FacilityR faciBin[1000]; //xuan xuan file- facility
	FILE *userptr, *bookptr, *faciptr;
	userptr = fopen("userInfo.bin", "rb");
	bookptr = fopen("booking.bin", "ab+");
	faciptr = fopen("facility.bin", "rb");
	if (userptr == NULL || bookptr == NULL || faciptr == NULL)
	{
		printf("File does not exist. \n");
		exit(-1);
	}
	while (fread(&bookRead[pBookRead], sizeof(Book), 1, bookptr))
	{

		pBookRead++;
	}
	while (fread(&userdetail[pCountUser], sizeof(user), 1, userptr))
	{
		pCountUser++;
	}
	while (fread(&faciBin[pFaci], sizeof(struct FacilityR), 1, faciptr))
	{
		pFaci++;
	}
	system("CLS");
	printf("Students and staff must register as a user before booking facility. \n");
	printf("Are you a registed user(y-Yes / n-No): ");
	rewind(stdin);
	scanf("%c", &registedUser);
	registedUser = toupper(registedUser);
	if (registedUser == 'Y')
	{
		printf("Today date&time: %d-%d-%d %02d:%02d ", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
		strftime(s, sizeof(s), "%A", localtime(&tt));
		printf("%s\n", s);
		printf("\n================================================================\n");
		do {
			printf("Student/Staff ID     : ");
			rewind(stdin);
			scanf("%s", &bookDetails.userId);
			for (int i = 0; i < pCountUser; i++)
			{
				if (strcmp(bookDetails.userId, userdetail[i].id) == 0)
				{
					strcpy(bookDetails.name, userdetail[i].name);
					printf("Student/Staff Name   :%s\n", bookDetails.name);
					found = 1;
					strcpy(bookDetails.status, userdetail[i].status);
					printf("Status               :%s\n", bookDetails.status);
					strcpy(bookDetails.ic, userdetail[i].ic);
					printf("IC                   :%s\n", bookDetails.ic);
					strcpy(bookDetails.contactNo, userdetail[i].contactNo);
					printf("Contact Number       :%s \n", bookDetails.contactNo);
					sprintf(integer_string, "%04d", count + pBookRead);
					strcat(other_string, integer_string);
					strcpy(bookDetails.bookId, other_string);
					printf("Booking ID/Walk In ID:%s\n", bookDetails.bookId);
					printf("\n================================================================\n");
					printf("Facility Opening hours: Monday ~ Saturday 0900-2100 \n");
					printf("College Facility close on Sunday. \n");
					printf("GYM and Swimming Pool only allow walk in.\n");
					printf("\nAvailable Facility \n");
					printf("1.Badminton\n");
					printf("2.Basketball \n");
					printf("3.Football\n");
					printf("4.Swimming \n");
					printf("5.Volleyball \n");
					printf("6.Ping-pong \n");
					printf("7.Tennis \n");
					printf("8.Gymnastics \n\n");
					do {
						printf("Enter choice in number: ");
						scanf("%d", &bookDetails.choice);
					} while (bookDetails.choice > 8 || bookDetails.choice < 1);
					do {
						printf("Book-1 / Walk In-2    : ");
						scanf("%d", &bookDetails.bookCondition);
					} while (bookDetails.bookCondition > 2 || bookDetails.bookCondition < 1);
					if (bookDetails.bookCondition == 1)
					{
						do {
							strcpy(bookDetails.bookConditionWord, "Booked");
							printf("\nPlease book at least one day in advance. \n");
							printf("College Facility close on Sunday.\n");
							printf("Booking Date (01-01-2020 as dd-mm-yyyy): ");
							scanf("%d %d %d", &bookDetails.bookADate.bookday, &bookDetails.bookADate.bookmonth, &bookDetails.bookADate.bookyear);
							printf("%d", bookDetails.bookADate.bookmonth);
							if (bookDetails.bookADate.bookyear % 4 == 0 && bookDetails.bookADate.bookyear % 100 != 0 || bookDetails.bookADate.bookyear % 400 == 0)
							{
								if (bookDetails.bookADate.bookmonth == 2)
									maxDay = 29;
								else if (bookDetails.bookADate.bookmonth == 1 || bookDetails.bookADate.bookmonth == 3 || bookDetails.bookADate.bookmonth == 5 || bookDetails.bookADate.bookmonth == 7 || bookDetails.bookADate.bookmonth == 8 || bookDetails.bookADate.bookmonth == 10 || bookDetails.bookADate.bookmonth == 12)
									maxDay = 31;
								else
									maxDay = 30;
							}
							else
							{
								if (bookDetails.bookADate.bookmonth == 2)
									maxDay = 28;
								else if (bookDetails.bookADate.bookmonth == 1 || bookDetails.bookADate.bookmonth == 3 || bookDetails.bookADate.bookmonth == 5 || bookDetails.bookADate.bookmonth == 7 || bookDetails.bookADate.bookmonth == 8 || bookDetails.bookADate.bookmonth == 10 || bookDetails.bookADate.bookmonth == 12)
									maxDay = 31;
								else
									maxDay = 30;
							}
							if (bookDetails.bookADate.bookyear == t.wYear)
							{
								if ((bookDetails.bookADate.bookday<1 || bookDetails.bookADate.bookday>maxDay) || (bookDetails.bookADate.bookmonth > maxMonth || bookDetails.bookADate.bookmonth < t.wMonth) || (bookDetails.bookADate.bookmonth = t.wMonth&& bookDetails.bookADate.bookday <= t.wDay))
								{
									printf("\nThis is invalid date.\n");
									condition = -1;
								}
								else
									condition = 1;
							}
							else if (bookDetails.bookADate.bookyear > t.wYear)
							{
								if ((bookDetails.bookADate.bookday<1 || bookDetails.bookADate.bookday>maxDay) || (bookDetails.bookADate.bookmonth > maxMonth || bookDetails.bookADate.bookmonth < 1))
								{
									printf("\nThis is invalid date.\n");
									condition = -1;
								}
								else
									condition = 1;
							}
						} while (condition < 0);
					}
					else if (bookDetails.bookCondition == 2)
					{
						strcpy(bookDetails.bookConditionWord, "Walk In");
						printf("Date of walk in: %d-%d-%d \n\n", t.wDay, t.wMonth, t.wYear);
						bookDetails.bookADate.bookday = t.wDay;
						bookDetails.bookADate.bookmonth = t.wMonth;
						bookDetails.bookADate.bookyear = t.wYear;
					}
					switch (bookDetails.choice)
					{
					case 1:
					{
						strcpy(bookDetails.type, "Badminton");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
						}
						printf("\nNumber of Users : ");
						scanf("%d", &bookDetails.numUser);
						printf("One user only can book 1 court.\n");
						printf("Facility Type: %s\n", bookDetails.type);
						printf("Enter the court you choose(exp:Badminton Court 1): ");
						rewind(stdin);
						scanf("%[^\n]", &bookDetails.description);
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(bookDetails.description, faciBin[i].description) == 0)
							{
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue       : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 2:
					{
						strcpy(bookDetails.type, "Basketball");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
						}
						printf("\nNumber of Users : ");
						scanf("%d", &bookDetails.numUser);
						printf("One user only can book 1 court.\n");
						printf("Facility Type    : %s\n", bookDetails.type);
						printf("Enter the court you choose(exp:Basketball Court 1): ");
						rewind(stdin);
						scanf("%[^\n]", &bookDetails.description);
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(bookDetails.description, faciBin[i].description) == 0)
							{
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue       : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 3:
					{
						strcpy(bookDetails.type, "Football");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
							{
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
								printf("\nNumber of Users: ");
								scanf("%d", &bookDetails.numUser);
								printf("Facility Type    : %s\n", bookDetails.type);
								strcpy(bookDetails.description, faciBin[i].description);
								printf("Description      : %s\n", bookDetails.description);
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID      : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue            : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 4:
					{
						strcpy(bookDetails.type, "Swimming");
						printf("\nWalked In \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
							{
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
								printf("\nNumber of Users : ");
								scanf("%d", &bookDetails.numUser);
								strcpy(bookDetails.description, faciBin[i].description);
								printf("Description       : %s\n", bookDetails.description);
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID       : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue             : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 5:
					{
						strcpy(bookDetails.type, "Volleyball");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
						}
						printf("\nNumber of Users  : ");
						scanf("%d", &bookDetails.numUser);
						printf("One user only can book 1 court.\n");
						printf("Enter the court you choose(exp:Volleyball Court 1): ");
						rewind(stdin);
						scanf("%[^\n]", &bookDetails.description);
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(bookDetails.description, faciBin[i].description) == 0)
							{
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID  : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue        : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 6:
					{
						strcpy(bookDetails.type, "Ping-pong");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
							{
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
								printf("\nNumber of Users : ");
								scanf("%d", &bookDetails.numUser);
								strcpy(bookDetails.description, faciBin[i].description);
								printf("Description       :%s\n", bookDetails.description);
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID       : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue             : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 7:
					{
						strcpy(bookDetails.type, "Tennis");
						printf("\nBooked \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
							{
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
								printf("\nNumber of Users : ");
								scanf("%d", &bookDetails.numUser);
								strcpy(bookDetails.description, faciBin[i].description);
								printf("Description       :%s\n", bookDetails.description);
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID       : %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue             : %s\n", bookDetails.venue);
							}
						}break;
					}
					case 8:
					{
						strcpy(bookDetails.type, "Gymnastics");
						printf("\nWalked In \n");
						printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
						printf("---------------------------------------------------------------------\n");
						for (int i = 0; i < pBookRead; i++)
						{
							if ((strcmp(bookRead[i].type, bookDetails.type) == 0) && (bookRead[i].bookADate.bookday == bookDetails.bookADate.bookday&&bookRead[i].bookADate.bookmonth == bookDetails.bookADate.bookmonth&&bookRead[i].bookADate.bookyear == bookDetails.bookADate.bookyear))
								printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", bookRead[i].faciId, bookRead[i].description, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
						}
						printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
						printf("____________________________________________________________________ \n");
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(faciBin[i].type, bookDetails.type) == 0)
								printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
						}
						printf("\nNumber of Users : ");
						scanf("%d", &bookDetails.numUser);
						printf("Enter the court you choose(exp:GYM 1): ");
						rewind(stdin);
						scanf("%[^\n]", &bookDetails.description);
						for (int i = 0; i < pFaci; i++)
						{
							if (strcmp(bookDetails.description, faciBin[i].description) == 0)
							{
								strcpy(bookDetails.faciId, faciBin[i].faciId);
								printf("Facility ID: %s\n", bookDetails.faciId);
								strcpy(bookDetails.venue, faciBin[i].venue);
								printf("Venue      : %s\n", bookDetails.venue);
							}
						}break;
					}
					default:
						printf("Invalid choice. \n"); break;
					}
					if (bookDetails.bookCondition == 1)
					{
						do {
							printf("\nOpening Hours:0900-2100\n");
							printf("Maximum booking hour: 2 hour\n");
							printf("Enter the start booking time (exp:13:00): ");
							scanf("%d:%d", &bookDetails.bookADate.startbooktime, &bookDetails.bookADate.startbookmin);
							printf("Enter the end booking time (exp:15:00)  : ");
							scanf("%d:%d", &bookDetails.bookADate.endbooktime, &bookDetails.bookADate.endbookmin);
						} while ((bookDetails.bookADate.startbooktime < minStart || bookDetails.bookADate.startbooktime >= maxEnd) || (bookDetails.bookADate.endbooktime <= minStart || bookDetails.bookADate.endbooktime < bookDetails.bookADate.startbooktime || bookDetails.bookADate.endbooktime > maxEnd || bookDetails.bookADate.endbooktime > bookDetails.bookADate.startbooktime + 2));
					}
					else if (bookDetails.bookCondition == 2)
					{
						do {
							errorCount++;
							printf("\nOpening Hours:0900-2100\n");
							printf("Maximum booking hour : 2 hour\n");
							printf("Walked in Time                  :%02d:%02d \n", t.wHour, t.wMinute);
							printf("Enter walk out time (exp: 15:00): ");
							scanf("%d:%d", &bookDetails.bookADate.endbooktime, &bookDetails.bookADate.endbookmin);
							if (errorCount > 1)
								leave();
						} while (bookDetails.bookADate.endbooktime <= minStart || bookDetails.bookADate.endbooktime > t.wHour + 2 || bookDetails.bookADate.endbooktime <= t.wHour || bookDetails.bookADate.endbooktime > maxEnd);
						bookDetails.bookADate.startbooktime = t.wHour;
						bookDetails.bookADate.startbookmin = t.wMinute;
					}
					confirmB(&confirmBook);
				}
			}
			if (!found)
			{
				errorCount++;
				if (errorCount > 2)
					leave();
				else
					printf("\nPlease enter correct user ID. \n\n");
			}
		} while (!found);
		if (confirmBook == 'Y')
			fwrite(&bookDetails, sizeof(Book), 1, bookptr);
	}
	else
	{
		printf("Only user can book the facility\nPlease register before you book.Thank you\nPress any button for returning to the home page.\n");
		rewind(stdin);
		scanf("%c", &home);
	}
	fclose(faciptr);
	fclose(userptr);
	fclose(bookptr);
}
void searchBook()
{
	system("CLS");
	char searchId[20], searchAgain = 'n';
	int option, d, m, y, pSearch = 0, found = 0;
	FILE*bookptr3;
	bookptr3 = fopen("booking.bin", "rb");
	if (bookptr3 == NULL)
	{
		printf("File does not exist. \n");
		exit(-1);
	}
	Book bookSearch[1000];
	while (fread(&bookSearch[pSearch], sizeof(Book), 1, bookptr3))
	{
		pSearch++;
	}
	do {
		printf("Search Booking Information \n");
		printf("========================== \n");
		printf("1.Individual Booking Information \n");
		printf("2.Booking and Walk In of the Day \n");
		printf("3.Exit \n");
		printf("Enter option (exp:1): ");
		scanf("%d", &option);
		do {
			if (option == 1)
			{
				system("CLS");
				printf("Enter the User ID: ");
				rewind(stdin);
				scanf("%[^\n]", &searchId);
				for (int i = 0; i < pSearch; i++)
				{
					if (strcmp(searchId, bookSearch[i].userId) == 0)
					{
						found = 1;
						printf("\nStudent Name                 : %s\n", bookSearch[i].name);
						printf("Status                       : %s\n", bookSearch[i].status);
						printf("IC                           : %s\n", bookSearch[i].ic);
						printf("Contact Number               : %s\n", bookSearch[i].contactNo);
						printf("Book ID                      : %s\n", bookSearch[i].bookId);
						printf("Booking/ Walk in             : %s\n", bookSearch[i].bookConditionWord);
						printf("Booking date (dd-mm-yy)      : %02d%02d%04d\n", bookSearch[i].bookADate.bookday, bookSearch[i].bookADate.bookmonth, bookSearch[i].bookADate.bookyear);
						printf("Booking/Walk In Time(start)  : %02d:%02d\n", bookSearch[i].bookADate.startbooktime, bookSearch[i].bookADate.startbookmin);
						printf("Booking/Walk out Time(end)   : %02d:%02d\n", bookSearch[i].bookADate.endbooktime, bookSearch[i].bookADate.endbookmin);
						printf("Facility Type                : %s\n", bookSearch[i].type);
						printf("Facility Court               : %s\n", bookSearch[i].description);
						printf("Facility ID                  : %s\n", bookSearch[i].faciId);
						printf("Venue                        : %s\n", bookSearch[i].venue);
						printf("Number of Users              : %d\n\n", bookSearch[i].numUser);
					}
				}
				if (!found)
				{
					printf("Invalid User ID! \n\n");
				}
				printf("Continue Search?(Yes-y/No-n): ");
				rewind(stdin);
				scanf("%c", &searchAgain);
				searchAgain = toupper(searchAgain);
				system("CLS");
			}
		} while (searchAgain == 'Y');

		do {
			if (option == 2)
			{
				system("CLS");
				printf("Enter the date for search (dd-mm-yy): ");
				scanf("%d %d %d", &d, &m, &y);
				printf("Booking \n=======\n");
				printf("------------------------------------------------------------------------------------------------------------\n");
				printf("|Booking ID| User ID  |      Name    |     Facility ID-Type-Description    |    Venue    |Users| Book Time |\n");
				printf("------------------------------------------------------------------------------------------------------------\n");
				for (int i = 0; i < pSearch; i++)
				{
					if (d == bookSearch[i].bookADate.bookday && m == bookSearch[i].bookADate.bookmonth && y == bookSearch[i].bookADate.bookyear && (strcmp(bookSearch[i].bookConditionWord, "Booked") == 0))
					{
						printf("|%-10s|%10s|%14s|%5s-%-10s -%-18s |%13s| %2d  |%02d:%02d-%02d:%02d| \n", bookSearch[i].bookId, bookSearch[i].userId, bookSearch[i].name, bookSearch[i].faciId, bookSearch[i].type, bookSearch[i].description, bookSearch[i].venue, bookSearch[i].numUser, bookSearch[i].bookADate.startbooktime, bookSearch[i].bookADate.startbookmin, bookSearch[i].bookADate.endbooktime, bookSearch[i].bookADate.endbookmin);
						found = 1;
					}
				}
				printf("------------------------------------------------------------------------------------------------------------\n");
				printf("Walked In \n=======\n");
				printf("------------------------------------------------------------------------------------------------------------\n");
				printf("|Booking ID| User ID  |      Name    |     Facility ID-Type-Description    |    Venue    |Users| Book Time |\n");
				printf("------------------------------------------------------------------------------------------------------------\n");
				for (int i = 0; i < pSearch; i++)
				{
					if (d == bookSearch[i].bookADate.bookday && m == bookSearch[i].bookADate.bookmonth && y == bookSearch[i].bookADate.bookyear && (strcmp(bookSearch[i].bookConditionWord, "Walk In") == 0))
					{
						printf("|%-10s|%10s|%14s|%5s-%-10s -%-18s |%13s| %2d |%02d:%02d-%02d:%02d| \n", bookSearch[i].bookId, bookSearch[i].userId, bookSearch[i].name, bookSearch[i].faciId, bookSearch[i].type, bookSearch[i].description, bookSearch[i].venue, bookSearch[i].numUser, bookSearch[i].bookADate.startbooktime, bookSearch[i].bookADate.startbookmin, bookSearch[i].bookADate.endbooktime, bookSearch[i].bookADate.endbookmin);
						found = 1;
					}
				}
				printf("------------------------------------------------------------------------------------------------------------\n");
				if (!found)
				{
					printf("\n< No record! > \n\n");
				}
				printf("Continue Search?(Yes-y/No-n): ");
				rewind(stdin);
				scanf("%c", &searchAgain);
				searchAgain = toupper(searchAgain);
				system("CLS");
			}
		} while (searchAgain == 'Y');
	} while (option != 3);
	fclose(bookptr3);
}
void modifyBook()
{
	FILE*modifyptr, *faciptr;
	modifyptr = fopen("booking.bin", "rb");
	faciptr = fopen("facility.bin", "rb");
	if (modifyptr == NULL || faciptr == NULL)
	{
		printf("File does not exist.\n");
		exit(-1);
	}
	int pModify = 0, choiceModify = 0, d, m, y, starthour, startmin, endhour, endmin, updateUser, found = 0, pFaci = 0;
	Book modify[1000];
	struct FacilityR faciBin[1000];
	char modifySearch[6], confirmation = 'n', facilityType[20], faciDescription[20];
	while (fread(&modify[pModify], sizeof(Book), 1, modifyptr))
	{
		pModify++;
	}
	while (fread(&faciBin[pFaci], sizeof(struct FacilityR), 1, faciptr))
	{
		pFaci++;
	}
	fclose(modifyptr);
	fclose(faciptr);
	system("CLS");
	printf("Modify Booking\n");
	printf("==============\n");
	printf("Enter the Booking ID: ");
	rewind(stdin);
	scanf("%[^\n]", &modifySearch);
	do {
		for (int i = 0; i < pModify; i++)
		{
			if (strcmp(modifySearch, modify[i].bookId) == 0)
			{
				found = 1;
				printf("\nCurrent Booking Information \n");
				printf("=========================== \n");
				printf("User ID             : %s\n", modify[i].userId);
				printf("Name                : %s\n", modify[i].name);
				printf("Status              : %s\n", modify[i].status);
				printf("IC                  : %s\n", modify[i].ic);
				printf("Contact Number      : %s\n", modify[i].contactNo);
				printf("Book ID             : %s\n", modify[i].bookId);
				printf("Book Date           : %02d%02d%04d \n", modify[i].bookADate.bookday, modify[i].bookADate.bookmonth, modify[i].bookADate.bookyear);
				printf("Booking Time(start) : %d:%d \n", modify[i].bookADate.startbooktime, modify[i].bookADate.startbookmin);
				printf("Booking Time(end)   : %d:%d \n", modify[i].bookADate.endbooktime, modify[i].bookADate.endbookmin);
				printf("Facility ID         : %s\n", modify[i].faciId);
				printf("Facility Type       : %s\n", modify[i].type);
				printf("Facility Description: %s\n", modify[i].description);
				printf("Venue               : %s\n", modify[i].venue);
				printf("Number of Users     : %d\n", modify[i].numUser);
				printf("\nUpdate Information\n------------------\n");
				printf("1.Modify Booking\n");
				printf("2.Exit \n");
				do {
					printf("Enter choice: ");
					scanf("%d", &choiceModify);
				} while (choiceModify < 1 || choiceModify>2);
				if (choiceModify == 1)
				{
					printf("\nUpdate Booking Date(dd-mm-yy): ");
					scanf("%d %d %d", &d, &m, &y);
					printf("Update Facility Type: ");
					rewind(stdin);
					scanf("%s", &facilityType);
					printf("\nBooked \n");
					printf("========\n");
					printf("Facility ID       Description \t    Booking Date\tBooking Time\n");
					printf("---------------------------------------------------------------------\n");
					for (int i = 0; i < pModify; i++)
					{
						if ((strcmp(facilityType, modify[i].type) == 0) && (modify[i].bookADate.bookday == d && modify[i].bookADate.bookmonth == m && modify[i].bookADate.bookyear == y))
							printf("%-15s %15s    %02d%02d%04d\t\t %02d:%02d-%02d:%02d\n", modify[i].faciId, modify[i].description, modify[i].bookADate.bookday, modify[i].bookADate.bookmonth, modify[i].bookADate.bookyear, modify[i].bookADate.startbooktime, modify[i].bookADate.startbookmin, modify[i].bookADate.endbooktime, modify[i].bookADate.endbookmin);
					}
					printf("\nFacility ID \t\tCourt \t\t Venue \t\t Maximum Users\n");
					printf("_____________________________________________________________________ \n");
					for (int i = 0; i < pFaci; i++)
					{
						if (strcmp(faciBin[i].type, facilityType) == 0)
							printf("%-15s %15s  %15s \t  %2d\n", faciBin[i].faciId, faciBin[i].description, faciBin[i].venue, faciBin[i].maxUser);
					}
					printf("\nUpdate Facility Description: ");
					rewind(stdin);
					scanf("%[^\n]", &faciDescription);
					printf("Update Booking Time(start) : ");
					scanf("%d:%d", &starthour, &startmin);
					printf("Update Booking Time(end)   : ");
					scanf("%d:%d", &endhour, &endmin);
					printf("Update Number of User      : ");
					scanf("%d", &updateUser);
					confirmB(&confirmation);
					if (confirmation == 'Y')
					{
						modify[i].bookADate.bookday = d;
						modify[i].bookADate.bookmonth = m;
						modify[i].bookADate.bookyear = y;
						modify[i].bookADate.startbooktime = starthour;
						modify[i].bookADate.startbookmin = startmin;
						modify[i].bookADate.endbooktime = endhour;
						modify[i].bookADate.endbookmin = endmin;
						strcpy(modify[i].type, facilityType);
						strcpy(modify[i].description, faciDescription);
						modify[i].numUser = updateUser;
						for (int a = 0; a < pFaci; a++)
						{
							if (strcmp(faciBin[a].description, faciDescription) == 0)
							{
								strcpy(modify[i].venue, faciBin[a].venue);
								strcpy(modify[i].faciId, faciBin[a].faciId);
							}
						}
					}
					system("CLS");
				}
				if (confirmation == 'Y')
				{
					modifyptr = fopen("booking.bin", "wb");
					if (modifyptr == NULL)
					{
						printf("File does not exist.\n");
						exit(-1);
					}
					for (int i = 0; i < pModify; i++)
					{
						fwrite(&modify[i], sizeof(Book), 1, modifyptr);
					}
					fclose(modifyptr);
				}
			}
		}
		if (!found)
		{
			printf("Invalid Booking ID.\n");
			leave();
		}
	} while (choiceModify != 2);
}
void confirmB(char *confirmation)
{
	printf("Confirm(Y = Yes) ? : ");
	rewind(stdin);
	scanf("%c", &*confirmation);
	*confirmation = toupper(*confirmation);
}
void leave()
{
	int quitFile;
	printf("See System Admin for help and Press 1 to EXIT. \n\n");
	scanf("%d", &quitFile);
	if (quitFile == 1)
		exit(-1);
}
void displayBook()
{
	char home;
	int pRead = 0;
	FILE*bookptr5;
	Book bookRead[1000];
	bookptr5 = fopen("booking.bin", "rb");
	if (bookptr5 == NULL)
	{
		printf("File does not exist. \n");
		exit(-1);
	}
	while (fread(&bookRead[pRead], sizeof(Book), 1, bookptr5))
	{
		pRead++;
	}
	system("CLS");
	printf("Booking \n=======\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("|Booking ID| User ID  |     Name     |    Facility ID-Type-Description     |    Venue    |Users|  Book Date | Book Time |\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < pRead; i++)
	{
		if (strcmp(bookRead[i].bookConditionWord, "Booked") == 0)
		{
			printf("|%-10s|%10s|%14s|%5s-%-10s -%-18s |%13s| %2d  | %02d%02d%04d |%02d:%02d-%02d:%02d| \n", bookRead[i].bookId, bookRead[i].userId, bookRead[i].name, bookRead[i].faciId, bookRead[i].type, bookRead[i].description, bookRead[i].venue, bookRead[i].numUser, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
		}
	}
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\nWalk In \n=======\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("|Booking ID| User ID  |     Name     |    Facility ID-Type-Description     |    Venue    |Users|  Book Date | Book Time |\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < pRead; i++)
	{
		if (strcmp(bookRead[i].bookConditionWord, "Walk In") == 0)
		{
			printf("|%-10s|%10s|%14s|%5s-%-10s -%-18s |%13s| %2d  | %02d%02d%04d |%02d:%02d-%02d:%02d| \n", bookRead[i].bookId, bookRead[i].userId, bookRead[i].name, bookRead[i].faciId, bookRead[i].type, bookRead[i].description, bookRead[i].venue, bookRead[i].numUser, bookRead[i].bookADate.bookday, bookRead[i].bookADate.bookmonth, bookRead[i].bookADate.bookyear, bookRead[i].bookADate.startbooktime, bookRead[i].bookADate.startbookmin, bookRead[i].bookADate.endbooktime, bookRead[i].bookADate.endbookmin);
		}
	}
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("Press any button for returning to the home page.\n");
	rewind(stdin);
	scanf("%c", &home);
	fclose(bookptr5);
}
void facilityUsageMain()
{
	int choice;
	do
	{
		printf("Select a number to view / edit :\n");
		printf("1. Check-in \n");
		printf("2. Search Facility Usage \n");
		printf("3. Cancellation booking \n");
		printf("4. Today's facility usage. \n");
		printf("5. None\n");
		rewind(stdin);
		scanf("%d", &choice);

		system("CLS");
		switch (choice)
		{
		case 1: add(); break;
		case 2: search(); break;
		case 3: modify(); break;
		case 4: display(); break;
		}

	} while (choice != 5);

}

void add()
{
	char att;
	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	printf("Today's date %2d-%2d-%4d\n", clock.tm_mday, clock.tm_mon + 1, clock.tm_year + 1900);
	printf("Would you like to check-in for the user? (Y - Yes / N - No) : ");
	rewind(stdin);
	scanf("%c", &att);
	addA(att);
}

int addA(char att)
{
	int pCount = 0;
	Book usage[1000];
	FILE* fptr1;
	FILE* fptr;
	FILE* fp_tmp;
	fptr = fopen("facUsage", "a");
	fptr1 = fopen("booking.bin", "rb");
	if (fptr1 == NULL || fptr == NULL)
	{
		printf("Error opening the file.");
		exit(-1);
	}
	while (fread(&usage[pCount], sizeof(Book), 1, fptr1))
	{
		pCount++;
	}

	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	char userID[15], name[30], ic[15];
	int day, month, year, max, a = 0;
	int found = 0;

	if (att == 'Y' || att == 'y')
	{
		printf("Enter user's ID : ");
		rewind(stdin);
		scanf("%s", userID);

		for (int i = 0; i < pCount; i++)
		{
			if (strcmp(userID, usage[i].userId) == 0 && (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900))
			{
				found = 1;
			}

			if (found == 1)
			{
				found = 1;
				fprintf(fptr, "%s - %s  %d:%d to %d:%d  %s-%s \n", usage[i].faciId, usage[i].description, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin, strcpy(usage[i].bookConditionWord, "Checked-in"));
				printf("=======================================================================\n");
				printf("||                             CHECK - IN                            ||\n");
				printf("=======================================================================\n");
				printf("|| %5s - %12s || %2d:%2d to %2d:%2d || %10s - %10s ||\n", usage[i].faciId, usage[i].description, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin, usage[i].userId, strcpy(usage[i].bookConditionWord, "Checked-in"));
				printf("=======================================================================\n\n");
			}
		}

		if (!found)
		{
			printf("=======================================================================\n");
			printf("||                         CHECK - IN                                ||\n");
			printf("=======================================================================\n");
			printf("||          INVALID USER ID // INCORRECT USER'S BOOKING DATE         ||\n");
			printf("=======================================================================\n\n");
		}
	}
	else
	{
		printf("\n ------ BACK TO MENU ------ \n\n");
	}

	fclose(fptr);
	fclose(fptr1);
}

void search()
{
	int pCount = 0;
	char facilityID[6];
	Book usage[1000];

	FILE* fptr1;
	fptr1 = fopen("booking.bin", "rb");
	if (fptr1 == NULL)
	{
		printf("Error opening the file.");
		exit(-1);
	}

	while (fread(&usage[pCount], sizeof(Book), 1, fptr1))
	{
		pCount++;
	}

	int day, month, year, maxD, state = 0;
	int sTimeH, sTimeM, eTimeH, eTimeM;
	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	int i = 0;

	printf("Search usage of the facility of the day\n");
	printf("Enter facility ID : ");
	rewind(stdin);
	scanf("%s", &facilityID);

	do
	{
		printf("Enter which date to view facility usage of the day (dd-mm-yyyy) \n");
		printf("Side Note : Please enter the date properly. Alphabets input would consider as NO RECORD! \n");
		scanf("%2d-%2d-%4d", &day, &month, &year);
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			if (month == 2)
				maxD = 29;
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				maxD = 31;
			else
				maxD = 30;
		}
		else
		{
			if (month == 2)
				maxD = 28;
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				maxD = 31;
			else
				maxD = 30;
		}

		if (year == clock.tm_year)
		{
			if ((day < 1 || day > maxD) || (month < 1 || month > 12) || (year < 1 || year < clock.tm_year + 1900))
			{
				printf("\n Invalid Date.\n\n");
				state = 2;
			}
			else
			{
				state = 1;
			}
		}
		if (year > clock.tm_year)
		{
			if ((day < 1 || day > maxD) || (month < 1 || month > 12) || (year < 1 || year < clock.tm_year + 1900))
			{
				printf("\n Invalid Date.\n\n");
				state = 2;
			}
			else
			{
				state = 1;
			}
		}

	} while (state == 2);

	int a = 0;

	for (int i = 0; i < pCount; i++)
	{
		if ((strcmp(usage[i].faciId, facilityID) == 0) && (day == usage[i].bookADate.bookday && month == usage[i].bookADate.bookmonth && year == usage[i].bookADate.bookyear))
		{
			a = 1;

		}
	}
	if (a == 1)
	{
		printf("==================================================================================\n");
		printf("||      User ID        ||        Time Booked        ||      Booking Conditon    ||\n");
		printf("==================================================================================\n");
		printf("||    %10s       ||       %2d:%2d to %2d:%2d      ||   %12s           ||\n", usage[i].userId, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin, usage[i].bookConditionWord);
		printf("==================================================================================\n");
	}
	if (!a)
	{
		printf("==================================================================================\n");
		printf("||      User ID        ||        Time Booked        ||      Booking Conditon    ||\n");
		printf("==================================================================================\n");
		printf("||                                NO RECORD                                     ||\n");
		printf("==================================================================================\n");
	}
	printf("\n");
	fclose(fptr1);
}

void modify()
{
	char bookingID;
	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	printf("Cancellation of today's booking (%2d-%2d-%4d)\n", clock.tm_mday, clock.tm_mon + 1, clock.tm_year + 1900);
	printf("Enter user's book ID : ");
	rewind(stdin);
	scanf("%c", &bookingID);
	cancellation(bookingID);
}

void cancellation(char bookingID)
{
	int day, month, year, maxD, state = 0, pCount = 0;
	char court[20];
	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	Book usage[1000];

	FILE* fptr1;
	FILE* fptr;
	fptr1 = fopen("booking.bin", "rb");
	fptr = fopen("facUsage", "a");
	if (fptr1 == NULL)
	{
		printf("Error opening the file.");
		exit(-1);
	}
	while (fread(&usage[pCount], sizeof(Book), 1, fptr1))
	{
		pCount++;
	}

	int b = 0;
	for (int i = 0; i < pCount; i++)
	{
		if (bookingID == usage[i].bookId && (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900))
		{
			b = 1;
		}
		if (b == 1)
		{
			if (((usage[i].bookADate.startbookmin + 10) <= clock.tm_min) || ((usage[i].bookADate.startbooktime + 1) <= clock.tm_hour))
			{
				strcpy(usage[i].bookConditionWord, "Cancelled");
				printf("\n%s 's booking is cancelled! - Reason : late for more than 10 minutes\n", usage[i].userId);
			}
			else
			{
				printf("\n%s still has the time before cancellation.\n", usage[i].userId);
			}
		}
	}
	if (!b)
	{
		printf("\nInvalid booking ID // This user booking is not today.\n");
	}
	printf("\n");
	fclose(fptr);
	fclose(fptr1);
}

void display()
{
	FILE* fptr;
	FILE* fptr1;
	fptr = fopen("facUsage.txt", "a");
	fptr1 = fopen("booking.bin", "rb");
	if (fptr == NULL || fptr1 == NULL)
	{
		printf("Error opening the file.");
		exit(-1);
	}

	time_t timeNow = time(NULL);
	struct tm clock = *localtime(&timeNow);
	Book usage[1000];
	int answer4;
	int pCount = 0;
	while (fread(&usage[pCount], sizeof(Book), 1, fptr1))
	{
		pCount++;
	}

	do
	{
		int i = 0;
		printf("Today's date %2d-%2d-%4d\n", clock.tm_mday, clock.tm_mon + 1, clock.tm_year + 1900);
		printf("Choose a number to view today's booked or walked-in\n");
		printf("1. Booked\n");
		printf("2. Walked-in\n");
		scanf("%d", &answer4);

		if (answer4 == 1)
		{
			if (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900)
			{
				while (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900)
				{
					if (usage[i].bookCondition == 1)
					{
						fprintf(fptr, "%s\t", usage[i].userId);
						fprintf(fptr, "%s\t", usage[i].bookId);
						fprintf(fptr, "%s\t", usage[i].bookConditionWord);
						fprintf(fptr, "%2d/%2d/%4d  %2d:%2d to %2d:%2d\t", usage[i].bookADate.bookday, usage[i].bookADate.bookmonth, usage[i].bookADate.bookyear, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin);
						fprintf(fptr, "%s\t", usage[i].faciId);
						fprintf(fptr, "%s\t", usage[i].venue);
						fprintf(fptr, "%s\t", usage[i].description);
						fprintf(fptr, "%d\n", usage[i].numUser);

						printf("=================================================================================================================================================================\n");
						printf("||   USER ID   ||   BOOK ID  ||  BOOKING CONDITION  ||  BOOKING DATE  ||   BOOKING TIME   || FACILITY ID ||      VENUE      ||      DESCRIPTION     || NO. USER ||\n");
						printf("=================================================================================================================================================================\n");
						printf("|| %10s  || %10s || %19s ||   %2d-%2d-%4d   ||  %2d:%2d to %2d:%2d  || %11s || %15s || %20s || %8d ||\n", usage[i].userId, usage[i].bookId, usage[i].bookConditionWord, usage[i].bookADate.bookday, usage[i].bookADate.bookmonth, usage[i].bookADate.bookyear, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin, usage[i].faciId, usage[i].venue, usage[i].description, usage[i].numUser);
						printf("=================================================================================================================================================================\n\n");
					}
					i++;
				}
			}
			else
			{
				printf("=================================================================================================================================================================\n");
				printf("||   USER ID   ||   BOOK ID  ||  BOOKING CONDITION  ||  BOOKING DATE  ||   BOOKING TIME   || FACILITY ID ||      VENUE      ||      DESCRIPTION     || NO. USER ||\n");
				printf("=================================================================================================================================================================\n");
				printf("||                                                                     No RECORD!                                                                               ||\n");
				printf("=================================================================================================================================================================\n\n");
			}
		}
		else if (answer4 == 2)
		{
			if (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900)
			{
				while (usage[i].bookADate.bookday == clock.tm_mday && usage[i].bookADate.bookmonth == clock.tm_mon + 1 && usage[i].bookADate.bookyear == clock.tm_year + 1900)
				{
					if (usage[i].bookCondition == 2)
					{
						fprintf(fptr, "%s\t", usage[i].userId);
						fprintf(fptr, "%s\t", usage[i].bookId);
						fprintf(fptr, "%s\t", usage[i].bookConditionWord);
						fprintf(fptr, "%2d/%2d/%4d  %2d:%2d to %2d:%2d\t", usage[i].bookADate.bookday, usage[i].bookADate.bookmonth, usage[i].bookADate.bookyear, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin);
						fprintf(fptr, "%s\t", usage[i].faciId);
						fprintf(fptr, "%s\t", usage[i].venue);
						fprintf(fptr, "%s\t", usage[i].description);
						fprintf(fptr, "%d\n", usage[i].numUser);

						printf("=================================================================================================================================================================\n");
						printf("||   USER ID   ||   BOOK ID  ||  BOOKING CONDITION  ||  BOOKING DATE  ||   BOOKING TIME   || FACILITY ID ||      VENUE      ||      DESCRIPTION     || NO. USER ||\n");
						printf("=================================================================================================================================================================\n");
						printf("|| %10s  || %10s || %19s ||   %2d-%2d-%4d   ||  %2d:%2d to %2d:%2d  || %11s || %15s || %20s || %8d ||\n", usage[i].userId, usage[i].bookId, usage[i].bookConditionWord, usage[i].bookADate.bookday, usage[i].bookADate.bookmonth, usage[i].bookADate.bookyear, usage[i].bookADate.startbooktime, usage[i].bookADate.startbookmin, usage[i].bookADate.endbooktime, usage[i].bookADate.endbookmin, usage[i].faciId, usage[i].venue, usage[i].description, usage[i].numUser);
						printf("=================================================================================================================================================================\n\n");
					}
					i++;
				}
			}
			else
			{
				printf("=================================================================================================================================================================\n");
				printf("||   USER ID   ||   BOOK ID  ||  BOOKING CONDITION  ||  BOOKING DATE  ||   BOOKING TIME   || FACILITY ID ||      VENUE      ||      DESCRIPTION     || NO. USER ||\n");
				printf("=================================================================================================================================================================\n");
				printf("||                                                                     No RECORD!                                                                               ||\n");
				printf("=================================================================================================================================================================\n\n");
			}
		}
		else
		{
			printf("Invalid number. Please type again.\n\n");
		}

	} while (answer4 > 2 || answer4 < 1);

	fclose(fptr);
	fclose(fptr1);
}

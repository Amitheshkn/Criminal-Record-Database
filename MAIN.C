
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//#include<string.h>
//#include<ctype.h>
//#include<malloc.h>
struct account {
	int number;

	char name[100];

	char sex[100];
	char dob[100];
	char father_name[100];
	char offense[100];
    char blood_group[40];
    float height;
    float weight;
    char under_section[50];
	char date[100];
	//char date1[100];
struct account *next;
struct account *prev;
}customer;
struct account *head=NULL,*temp,*disp,*add,*trav,*del,*hnext,*hprev;
 long fileSize;
 int numEntries,loop;
 //for searching a client

 void PrintList(struct account *start)
{
	struct account *current = start;
	int count = 0;
	char nam[100];
	struct account *ahead = NULL;
	struct account *behind = NULL;
	while(current != NULL) {
		count++;
		ahead = current->next;
		behind = current->prev;
	   printf("        Name     :%s\n",current->name);
	   printf("         sex     :%s\n",current->sex);
	   printf("         dob     :%s\n",current->dob);
	   printf(" father_name     :%s\n",current->father_name);
	   printf("     offense     :%s\n",current->offense);
	   printf(" blood_group     :%s\n",current->blood_group);
	   printf("      height     :%.f\n",current->height);
	   printf("      weight     :%.f\n",current->weight);
	   printf(" under_section   :%s\n",current->under_section);
	   printf("         date    :%s\n",current->date);
	   printf("\n Press any key to continue\n");
	   getchar();


		current = current->next;
		ahead   = NULL;
		behind  = NULL;
	}}


       void WriteListToNewFile(struct account *start)
   {
	FILE *pt;
	pt= fopen("pq.dat", "ab+");

	if(pt != NULL)
	{
	trav=start;
		hnext = NULL;
		hprev = NULL;

		while(trav != NULL)
		 {
			hnext = trav->next;
			hprev = trav->prev;

			trav->next = NULL;
			trav->prev = NULL;

			fseek(pt, 0, SEEK_END);
			fwrite(trav, sizeof(struct account), 1, pt);

			printf("Writing:%s to file\n",trav->name);

			trav->next = hnext;
			trav->prev = hprev;

			hnext = NULL;
			hprev = NULL;
			trav = trav->next;
		}
		fclose(pt);
		pt= NULL;
		}
		else
		{
		printf("FILE OPEN ERROR\n");
		}
		}
  void WriteListToFile(struct account *start)
   {
	FILE *pF;
	pF = fopen("pp.dat", "ab+");
	if(pF != NULL)
	{
		trav=start;
		hnext = NULL;
		hprev = NULL;
		while(trav != NULL)
		 {
			hnext = trav->next;
			hprev = trav->prev;
			trav->next = NULL;
			trav->prev = NULL;
			fseek(pF, 0, SEEK_END);
			fwrite(trav, sizeof(struct account), 1, pF);

			printf("Writing:%s to file\n",trav->name);

			trav->next = hnext;
			trav->prev = hprev;

			hnext = NULL;
			hprev = NULL;

			trav = trav->next;
		}
		fclose(pF);
		pF= NULL;
	} else {
		printf("FILE OPEN ERROR\n");
	}

}

struct account *ReadNextFromFile(struct account *start, FILE *pF) {
	size_t returnValue;
	struct account *index,*new;
	if(start == NULL) {
		start = malloc(sizeof(struct account));
		returnValue = fread(start, sizeof(struct account), 1, pF);
		start->next = NULL;
		start->prev= NULL;
		return start;
	} else {
		index = start;
	    new = malloc(sizeof(struct account));
		while(index->next != NULL) {
			index = index->next;
		}
		returnValue = fread(new, sizeof(struct account), 1, pF);
		index->next = new;
		new->next = NULL;
		new->prev = index;
		return new;
	}
}

struct account *ReadListIn(int choice)
 {

	FILE *pF;
      int recsize=sizeof(struct account);
	pF = fopen("pp.dat", "rb");
	if(pF != NULL)
	{
	     struct account *start = NULL;
		char nam[50];
		fseek(pF, 0, SEEK_END);
		fileSize = ftell(pF);
		rewind(pF);
		numEntries = (int)(fileSize / (sizeof(struct account)));
		printf("numEntries:%d\n",numEntries);
		loop = 0;
		if(choice==50)
		{
		for(loop = 0; loop < numEntries;++loop)
		       {
			fseek(pF, (sizeof(struct account) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pF);
		      PrintList(start);
			}}
			if(choice==53)
		      {
		      printf("enter name\n");
		      gets(nam);
			for(loop = 0; loop < numEntries;++loop)
		       {
			fseek(pF, (sizeof(struct account) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pF);
		      if(strcmp(start->name,nam)==0)
		      {
		   PrintList(start);
		      }}}
	  // }
	   if(choice==52)
	   {
	   printf("enter name\n");
		      gets(nam);
			for(loop = 0; loop < numEntries;++loop)
		       {
			fseek(pF, (sizeof(struct account) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pF);
		      if(strcmp(start->name,nam)!=0)
		      {
			WriteListToNewFile(start);
		      }}
		      fclose(pF);
		      remove("pp.dat");
		      rename("pq.dat ","pp.dat");
		      pF=fopen("prapul.dat","rb+");

	   }
		if(choice==51)
		{
		 printf("enter the name\n");
		 gets(nam);
			for(loop = 0; loop < numEntries;++loop)
		       {
			fseek(pF, (sizeof(struct account)*loop), SEEK_SET);
			start=ReadNextFromFile(start,pF);
		      if(strcmp(start->name,nam)==0)
		      {
	  printf("enter the fields\n");
	  printf("\n  crminal details:");
	  printf("\n          Name:");
	  gets(start->name);
	  fflush(stdin);
	  printf("\n           dob:");
	  fflush(stdin);
	  scanf("%s",start->dob);
	  printf("             sex:");
	  fflush(stdin);
	   scanf("%s",start->sex);
	  fflush(stdin);
	  printf("     father_name:");
	  fflush(stdin);
	  scanf("%s",start->father_name);
	  fflush(stdin);
	  printf("          offense:");
	  scanf("%s",start->offense);
	  printf("  date dd/mm/yyyy:");
	  scanf("%s",start->date);
	  fflush(stdin);
	  printf("      blood_group:");
	  fflush(stdin);
	  scanf("%s",start->blood_group);
	  printf("           height:");
	  fflush(stdin);
	  scanf("%f",&start->height);
	  fflush(stdin);
	  printf("           weight:");
	  scanf("%f",&start->weight);
	  fflush(stdin);
	  printf("           under_section");
	  scanf("%s",start->under_section);
	  pF = fopen("pp.dat", "r+");
	  if(pF != NULL)
	  {
		trav=start;
		hnext = NULL;
		hprev = NULL;
		while(trav != NULL)
		 {
			hnext = trav->next;
			hprev = trav->prev;
			trav->next = NULL;
			trav->prev = NULL;
			fseek(pF,recsize*loop, SEEK_CUR);
			fwrite(trav, sizeof(struct account),1,pF);
			printf("Writing:%s to file\n",trav->name);
			trav->next = hnext;
			trav->prev = hprev;
			hnext = NULL;
			hprev = NULL;
			trav = trav->next;
		}
		fclose(pF);
		pF= NULL;
	} else {
		printf("FILE OPEN ERROR\n");
		}}}}

		if(choice==44)
		{
		 printf("enter the name\n");
		 gets(nam);
			for(loop = 0; loop < numEntries;++loop)
		       {
			fseek(pF, (sizeof(struct account) * loop), SEEK_SET);
			start=ReadNextFromFile(start,pF);
		       if(strcmp(start->name,nam)==0)
		       {

	//  printf("             item value: %.f\n",start->name);
	//  printf("          token advance: %.f\n",start->name);
	//  printf("     balance to be paid: %.f\n",start->name);
	//  printf("enter the amount received at delivery time :");
	//  fflush(stdin);
	  scanf("%f",&customer.height);
	 // start->height=start->weight;
	 // start->height=start->weight;



       pF = fopen("pp.dat", "r+");
	if(pF != NULL)
	{
		  trav=start;
		hnext = NULL;
		hprev = NULL;
		while(trav != NULL)
		 {
			hnext = trav->next;
			hprev = trav->prev;
			trav->next = NULL;
			trav->prev = NULL;
			fseek(pF,recsize*loop, SEEK_CUR);
			fwrite(trav, sizeof(struct account), 1, pF);
			printf("Writing:%s to file\n",trav->name);
			trav->next = hnext;
			trav->prev = hprev;
			hnext = NULL;
			hprev = NULL;
			trav = trav->next;
		}
		fclose(pF);
		pF= NULL;
	} else {
		printf("FILE OPEN ERROR\n");
		}}}}
		}
		}
  main()
  {
  FILE *fp,*ft,*source,*target;
  char name1[100];
  char target_file[100];
  char another,choice,nam[50],ch;
  long int recsize;
  int password=1234;
  int password1=NULL;
  int num,i;
  system("cls");
  home :
  gotoxy(30,9);
  printf(" WELCOME USER\n");
  gotoxy(25,10);
  printf("Enter passward to login: ");
  scanf("%d",&password1);
  if(password==password1)
  {
  fp=fopen("prapul.txt","r+");
  if(fp==NULL)
  {
  fp=fopen("prapul.txt","w+");
  }
  while(1)
  {
  system("cls");
  printf("                          =========================\n");
  printf("                          CRIMINAL RECORD DATABASE \n");
  printf("                          =========================\n");
  printf("1.Add criminal details\n");
  printf("2.List criminal details\n");
  printf("3.Modify criminal details\n");
  printf("4.Delete criminal details\n");
  printf("5.Search by name\n");
  printf("6.create back up\n");
  printf("0.Exit\n");
  printf("Your choice\n");

  choice=getche();
  switch(choice)
  {
  case '1':
  system("cls");
  fseek(fp,0,SEEK_END);
  another='y';
  while(another=='y')
  {
	  add=(struct account*)malloc(sizeof(struct account));
	  printf("enter the fields\n");
	  fflush(stdin);
	  printf("\n         Name:");
	  gets(add->name);
	  fflush(stdin);
	  printf("\n          dob:");
	  fflush(stdin);
	  scanf("%s",add->dob);
	  printf("            sex:");
	  fflush(stdin);
	   scanf("%s",add->sex);
	  fflush(stdin);
	  printf("    father_name:");
	  gets(add->father_name);
	  fflush(stdin);
	  printf("        offense:");
	  gets(add->offense);
	  fflush(stdin);
	  printf(" date dd/mm/yyyy:");
	  scanf("%s",add->date);
	  fflush(stdin);
	  printf("     blood_group:");
	  scanf("%s",add->blood_group);
	  fflush(stdin);
	  printf("          height:");
	  scanf("%f",&add->height);
	  fflush(stdin);
	  printf("          weight:");
	  scanf("%f",&add->weight);
	  fflush(stdin);
	  printf("   under_section:");
	  scanf("%s",add->under_section);
	  fflush(stdin);
	  if (head==NULL)
	  {
	  head=add;
	  add->next=NULL;
	  add->prev=NULL;
	  temp=add;

      }
      else
      {
	 temp->next=add;
	 add->prev=temp;
	 add->next=NULL;
	 temp=add;
      }
	 WriteListToFile(add);


    printf("\n Would you like to enter another criminal details(y\\n): \n");
    another = getchar();
    fflush(stdin);
	  }
break;

case '2':
	 system("cls");
	 ReadListIn(choice);
	 getch();
break;

case '3':
  system("cls");
  ReadListIn(choice);
  getch();
break;

case '4':
ReadListIn(choice);
getch();
break;
case '5':
	fflush(stdin);
	ReadListIn(choice);
	getch();
	break;

case '6' :
      system("cls");
       fflush(stdin);
   source = fopen("pp.dat", "rb");
   if( source == NULL )
   {
      printf("Press any key to exit...\n");
   }
   printf("Enter name of backup file\n");
   gets(target_file);
   target = fopen(target_file, "wb");
   if( target == NULL )
   {
      fclose(source);
      printf("Press any key to exit...\n");
   }
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);

   printf("back up successfully created\n");

   fclose(source);
   fclose(target);
   getch();
 break;

case '0':
fclose(fp);
exit(0);
}}}
else
{
printf("\n                        invalid password..enter again!\n");
goto home;
}}

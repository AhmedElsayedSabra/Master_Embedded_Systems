/*
 * Main_Student_Function.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A7MED
 */
#include "Main_Student_Function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
Student_Buffer_Status Student_Buffer_Init(Fifo_Buffer_t* Student_Buffer_Info , Element_Type* Student_Buffer)
{
	Student_Buffer_Info->Base   = Student_Buffer ;
	Student_Buffer_Info->Head   = Student_Buffer ;
	Student_Buffer_Info->Tail   = Student_Buffer ;
	Student_Buffer_Info->Length = Student_Number ;
	Student_Buffer_Info->Count  = 0 ;
	DPRINTF("[INFO] Student FIFO Buffer INIT <=======> Done \n") ;
	return Student_Buffer_No_Error ;
}
Student_Buffer_Status Check_Roll_Number (Fifo_Buffer_t* Student_Buffer_Info , uint32_t Temp_Roll_Number)
{
	Element_Type* checker_Temp = Student_Buffer_Info->Tail ;
	Fifo_Buffer_t* Student_Buffer_Info_Temp = Student_Buffer_Info ;
	int i = 1 ;
	while ( i <= Student_Buffer_Info_Temp->Count )
	{
		if (checker_Temp->Roll_number == Temp_Roll_Number)
		{
			DPRINTF("[ERROR] Roll Number Is Taken Before, Can't Be Added \n");
			return Roll_Number_Taken ;
		}
		else
		{
			if(checker_Temp == Student_Buffer_Info_Temp->Base + (Student_Buffer_Info_Temp->Length*sizeof(Element_Type)))
			{
				checker_Temp = Student_Buffer_Info_Temp->Base ;
				i++;
			}
			else
			{
				checker_Temp++ ;
				i++;
			}
		}
	}
	DPRINTF("[INFO] Roll Number Is Available && Not Taken Before\n");
	return Roll_Number_Not_Taken ;
}
Student_Buffer_Status Add_Students_From_File(Fifo_Buffer_t* Student_Buffer_Info)
{
	FILE* Pointer_To_File = fopen(File_Name,Read_Mode) ;
	uint8_t Text_Record[Length_Of_One_Record] ;
	const char* Token ;
	Element_Type Temp_Student_Item ;
	if(Pointer_To_File == NULL)
	{
		DPRINTF("[ERROR] Could Not Open the File %s\n" ,File_Name);
		return Data_Base_File_Cant_Open ;
	}
	// Get or fill the first Record from the file
	while(fgets((char* )Text_Record,Length_Of_One_Record,Pointer_To_File) != NULL)
	{
		Token = strtok((char*)Text_Record,",");
		// extract the First token and put it Into Roll Number And So on
		Temp_Student_Item.Roll_number = atoi(Token);
		// Extract the second token and put it into First Name [10]
		strcpy((char*)Temp_Student_Item.F_Name ,strtok(NULL,","));
		// Extract the Third token and put it into Last Name[10]
		strcpy((char*)Temp_Student_Item.L_Name , strtok(NULL,","));
		// Extract the Fourth token and put it into GPA "Float Number"
		Token =strtok(NULL,",") ;
		Temp_Student_Item.GPA = atof(Token);
		// Extract the Fifth token and put it into Course_ID[5] - integer Number - BY for loop
		Token =strtok(NULL,",") ;
		int i = 0 ;
		while(Token != NULL )
		{
			Temp_Student_Item.Course_ID[i]= atoi(Token);
			Token =strtok(NULL,",") ;
			i++ ;
		}
		Token = strtok(NULL,"\n");
		Add_Student_Manually(Student_Buffer_Info ,Temp_Student_Item );
	}
	fclose(Pointer_To_File);
	return Data_Base_File_Empty ;
}
Student_Buffer_Status Add_Student_Manually (Fifo_Buffer_t* Student_Buffer_Info ,Element_Type Student_Buffer)
{
	if (FIFO_Buffer_Is_Exist(Student_Buffer_Info) == Student_Buffer_Null)
		return Student_Buffer_Null ;
	else if (FIFO_Buffer_Is_Full(Student_Buffer_Info) == Student_Buffer_Full)
		return Student_Buffer_Full ;
	else if (Check_Roll_Number(Student_Buffer_Info ,Student_Buffer.Roll_number) == Roll_Number_Taken)
		return Roll_Number_Taken ;
	else
	{
		*Student_Buffer_Info->Head = Student_Buffer ;
		Student_Buffer_Info->Count++ ;
		// If the Head point to last element In Queue -> Then make the head point to base again
		if(Student_Buffer_Info->Head == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			Student_Buffer_Info->Head = Student_Buffer_Info->Base ;
		else
			Student_Buffer_Info->Head++ ;
		DPRINTF("[INFO] Record Student Added Successfully\n");
		return Student_Buffer_No_Error ;
	}
}
Student_Buffer_Status Find_Student_By_Roll_Number (Fifo_Buffer_t* Student_Buffer_Info , uint32_t Roll_Number)
{
	Element_Type* Temp = Student_Buffer_Info->Tail ;
	int i = 0 ;
	while ( i < Student_Buffer_Info->Count )
	{
		if (Temp->Roll_number == Roll_Number)
		{
			DPRINTF("[INFO] The Student Is Exist && Roll Number Is Taken Before\n");
			DPRINTF("[INFO] The Student Info Is 							  :\n");
			DPRINTF(" %d\t%s \t%s \t %2.2f \t ",Temp->Roll_number , Temp->F_Name , Temp->L_Name,Temp->GPA );
			for (int j= 0 ; j < 5 ; j++ )
				DPRINTF("%d , " , Temp->Course_ID[j]);
			DPRINTF("\n");
			return Roll_Number_Taken ;
		}
		else
		{
			if(Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			{
				Temp = Student_Buffer_Info->Base ;
				i++;
			}
			else
			{
				Temp++ ;
				i++;
			}
		}
	}
	DPRINTF("[ERROR] The Student Is Exist Not Exist && Roll Number Is Not Taken Before\n");
	return Roll_Number_Not_Taken ;
}
void   Find_Student_By_First_Name (Fifo_Buffer_t* Student_Buffer_Info )
{
	uint8_t F_Name_Temp[Length_Of_Names]; int Count = 0 ;
	DPRINTF("[Take-INFO] Enter The First Name of Student = ");
	scanf("%s",F_Name_Temp);
	Element_Type* Temp = Student_Buffer_Info->Tail ;
	for(int i = 0 ; i < Student_Buffer_Info->Count ;i++)
	{
		if ( stricmp((char* )Temp->F_Name,(char* )F_Name_Temp) == 0 )
		{
			DPRINTF("[INFO] The student Details That has The First Name\"%s\" are = \n", F_Name_Temp);
			DPRINTF("The First name is   : %s\n",Temp->F_Name);
			DPRINTF("Student last  name  : %s\n",Temp->L_Name);
			DPRINTF("Student roll  number: %d\n",Temp->Roll_number);
			DPRINTF("Student GPA         : %2.2f\n",Temp->GPA);
			DPRINTF("course ID           : ");
			for(int j=0 ;j < Course_Number; ++j)
				DPRINTF(" %d ,",Temp->Course_ID[j]);
			DPRINTF("\n");
			Count++;
		}
		if(Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			Temp = Student_Buffer_Info->Base ;
		else
			Temp++ ;
	}
	if(Count != 0 ){
		DPRINTF("[INFO] Total Student Who Have The Same First Name\"%s\"Is : %d\n",F_Name_Temp ,Count);
		DPRINTF("[INFO] The Total Number of Student is %d\n", Student_Buffer_Info->Count);}
	else
	{DPRINTF("[ERROR] First Name \" %s \" Not Found\n",F_Name_Temp);}
}
void  Find_Student_By_Course_ID (Fifo_Buffer_t* Student_Buffer_Info)
{
	Element_Type* Temp = Student_Buffer_Info->Tail ;
	uint32_t Course_ID_Temp ; int Count = 0 ;
	DPRINTF("[Take-INFO] Enter the Course ID To Searching = ");
	scanf("%d",&Course_ID_Temp);
	for (int i = 0 ; i < Student_Buffer_Info->Count ; i++)
	{
		for (int j = 0 ; j < Course_Number ; j++)
		{
			if (Course_ID_Temp == Temp->Course_ID[j] )
			{
				DPRINTF("[INFO] The student\"%d\"Details That Has Enrolled In The Same Course ID\"%d\"are\n" , i+1 ,Course_ID_Temp );
				DPRINTF("The First name is   : %s\n",Temp->F_Name);
				DPRINTF("Student last  name  : %s\n",Temp->L_Name);
				DPRINTF("Student roll  number: %d\n",Temp->Roll_number);
				DPRINTF("Student GPA         : %2.2f\n",Temp->GPA);
				Count++ ;
			}
		}
		if(Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			Temp = Student_Buffer_Info->Base ;
		else
			Temp++ ;
	}
	DPRINTF("[INFO] Total Number of Students Enrolled In This Course Is : %d\n",Count);
	DPRINTF("[INFO] The total number of student is %d\n",Student_Buffer_Info->Count);
	DPRINTF("[INFO] Total Number of Students That Not Enrolled  In This Course Is %d\n",Student_Buffer_Info->Count - Count);
}
void  Find_Total_Number_Student (Fifo_Buffer_t* Student_Buffer_Info)
{
	DPRINTF("[INFO] The total number of student is %d\n",Student_Buffer_Info->Count);
	DPRINTF("[INFO] You can add up to 50 students\n");
	DPRINTF("[INFO] You can add %d more students\n",Student_Number - Student_Buffer_Info->Count);
}
void  Delete_Student_By_Roll_Number	(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number)
{
	Element_Type* Temp ; Element_Type* Temp_Next ;
	Temp = Student_Buffer_Info->Tail ;
	Temp_Next = Temp + 1 ;
	uint32_t Flag  = 0 ;
	for (int i = 0 ; i <Student_Buffer_Info->Count ; i++)
	{
		if (Temp->Roll_number == Roll_Number)
		{
			Flag = 1 ;
			*Temp = *Temp_Next ;
			for(int j = 0 ; j < Student_Buffer_Info->Count ; j++)
			{
				*Temp = *Temp_Next ;
				if(Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type))){
					Temp = Student_Buffer_Info->Base ;
					Temp_Next = Temp+1 ; }
				else{
					Temp++ ;
					Temp_Next++ ;}
			}
			// If Head Point to Base -> Wrong head-- but it should be point to top
			if(Student_Buffer_Info->Head == Student_Buffer_Info->Base)
				Student_Buffer_Info->Head = Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type));
			else
				Student_Buffer_Info->Head-- ;
			Student_Buffer_Info->Count-- ;
		}
		else
		{
			if(Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type))){
				Temp = Student_Buffer_Info->Base ;
				Temp_Next = Temp+1 ;}
			else{
				Temp++ ;
				Temp_Next++ ;}
		}
	}
	if(Flag == 1){
		DPRINTF("[INFO] The Roll Number is removed successfully\n");}
	else{
		DPRINTF("[ERROR] This Roll Number\"%d\" Is Not Found\n",Roll_Number);}
}

Student_Buffer_Status Update_Student_By_Roll_Number	(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number)
{
	Element_Type* checker_Temp = Student_Buffer_Info->Tail ;
	uint8_t Temp_String[10];
	int i = 0 ; int Choice ;
	while ( i < Student_Buffer_Info->Count && Student_Buffer_Info->Count != 0 )
	{
		if (checker_Temp->Roll_number == Roll_Number)
		{
			DPRINTF("1. Update first name\n");
			DPRINTF("2. Update last name\n");
			DPRINTF("3. Update  GPA\n");
			DPRINTF("4. Update courses ID \n");
			DPRINTF("[Take INFO] Enter The Choice To Update the Information of student= ");
			scanf("%d",&Choice);
			switch(Choice)
			{
			case 1:
				DPRINTF("[Take INFO] Enter the new first name: ");
				gets((char* )checker_Temp->F_Name);
				break;
			case 2:
				DPRINTF("[Take INFO] Enter the new last name: ");
				gets((char* )checker_Temp->L_Name);fflush(stdin);
				break;
			case 3:
				DPRINTF("[Take INFO] Enter the new GPA: ");
				gets((char* )Temp_String);fflush(stdin);
				checker_Temp->GPA = atof((char*)Temp_String);
				break;
			case 4:
				DPRINTF("[Take INFO] Enter the New Course ID of each course:\n");
				for(int i=0; i<Course_Number; ++i)
				{
					DPRINTF("Course %d ID: ",i+1);
					gets((char* )Temp_String);fflush(stdin);
					checker_Temp->Course_ID[i]= atoi((char*)Temp_String);
				}
				break;
			default :
				DPRINTF("[ERROR] Wrong Choice:\n");
				return Student_Not_Found ;
				break ;
			}
			DPRINTF("[INFO] UPDATED the Students Details by Roll Number SUCCESSFULLY.\n");
			return Student_Updated ;
		}
		else
		{
			if(checker_Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			{
				checker_Temp = Student_Buffer_Info->Base ;
				i++;
			}
			else
			{
				checker_Temp++ ;
				i++;
			}
		}
	}
	DPRINTF("[ERROR] Roll Number Is Not Found  OR Student Not Found, [Advice] Check the Roll Number \n");
	return Student_Not_Found ;
}
Student_Buffer_Status  Show_All_info	(Fifo_Buffer_t* Student_Buffer_Info)
{
	Element_Type* Temp ;
	if (FIFO_Buffer_Is_Exist(Student_Buffer_Info) == Student_Buffer_Null)
	{
		DPRINTF("[ERROR] Student FIFO Buffer Is Not Exist \n") ;
		return Student_Buffer_Null ;
	}
	if (FIFO_Buffer_Is_Empty(Student_Buffer_Info) == Student_Buffer_Empty)
	{
		DPRINTF("[INFO] Student FIFO Buffer Is Empty \n") ;
		return Student_Buffer_Empty ;
	}
	Temp = Student_Buffer_Info->Tail ;
	DPRINTF("[INFO] Student FIFO Buffer (Static Allocation) Printing Item  = \n");
	for (int i = 0 ; i < Student_Buffer_Info->Count ; i++)
	{
		DPRINTF(" %d\t%s \t%s \t %2.2f \t ",Temp->Roll_number , Temp->F_Name , Temp->L_Name,Temp->GPA );
		for (int j= 0 ; j < 5 ; j++ )
			DPRINTF("%d , " , Temp->Course_ID[j]);
		if (Temp == Student_Buffer_Info->Base + (Student_Buffer_Info->Length*sizeof(Element_Type)))
			Temp = Student_Buffer_Info->Base ;
		else
			Temp++ ;
		printf("\n");
	}
	return Student_Buffer_No_Error ;
}
Student_Buffer_Status FIFO_Buffer_Is_Full  (Fifo_Buffer_t* Student_Buffer_Info)
{

	if (FIFO_Buffer_Is_Exist(Student_Buffer_Info) == Student_Buffer_Null)
		return Student_Buffer_Null ;
	else
	{
		if (Student_Buffer_Info->Count >= Student_Buffer_Info->Length)
			return Student_Buffer_Full ;
		return Student_Buffer_No_Error ;
	}
}
Student_Buffer_Status FIFO_Buffer_Is_Exist  (Fifo_Buffer_t* Student_Buffer_Info)
{
	if (Student_Buffer_Info == NULL)
		return Student_Buffer_Null ;
	else
		return Student_Buffer_No_Error ;
}
Student_Buffer_Status FIFO_Buffer_Is_Empty  (Fifo_Buffer_t* Student_Buffer_Info)
{
	if (FIFO_Buffer_Is_Exist(Student_Buffer_Info) == Student_Buffer_Null)
		return Student_Buffer_Null ;
	else
	{
		if (Student_Buffer_Info->Count == 0)
			return Student_Buffer_Empty ;
		else
			return Student_Buffer_No_Error ;
	}
}

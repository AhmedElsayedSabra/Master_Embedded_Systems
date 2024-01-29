/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmed Elsayed Sabra
 */
#include <stdio.h>
#include <stdlib.h>
#include "Main_Student_Function.h"
#include <string.h>
//Reserve Student Static FIFO Buffer to Student DataBase
Element_Type Student_Buffer[Student_Number];
int main(void)
{
	Fifo_Buffer_t Student_Buffer_Info ;
	Element_Type	Temp_Item ;
	uint32_t Choice ;
	Student_Buffer_Init(&Student_Buffer_Info , Student_Buffer) ;
	DPRINTF("[INFO] Welcome to the student Management System\n");
	while (1)
	{
		DPRINTF("Choose The Task that you want to perform\n");
		DPRINTF("1. Add the student Details Manually\n");
		DPRINTF("2. Add the student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Students Details by Roll Number\n");
		DPRINTF("8. Update the Students Details by Roll Number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("[Take-INFO] Enter your choice to perform the task: ");
		scanf("%d",&Choice);fflush(stdin);
		switch(Choice)
		{
		case 1 :
			DPRINTF("==================================================================\n");
			DPRINTF("1. Add the student Details Manually\n");
			DPRINTF("Show The Student Buffer Before Adding the student Details Manually \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("[Take-INFO] Enter The Roll Number Of Student : ");
			scanf("%d",&Temp_Item.Roll_number);fflush(stdin);
			DPRINTF("[Take-INFO] Enter The Student First Name     : ");
			gets((char*)Temp_Item.F_Name);fflush(stdin);
			DPRINTF("[Take-INFO] Enter The Student Last Name      : ");
			gets((char*)Temp_Item.L_Name);fflush(stdin);
			DPRINTF("[Take-INFO] Enter The GPA Number Of Student  : ");
			scanf("%f",&Temp_Item.GPA);fflush(stdin);
			DPRINTF("[Take-INFO] Enter Course IDs Of Each Student : ");
			for (int i = 0 ; i <Course_Number; i++)
				scanf("%d",&Temp_Item.Course_ID[i]) ;
			Add_Student_Manually(&Student_Buffer_Info ,Temp_Item);
			DPRINTF("Show The Student Buffer After Adding the student Details Manually \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 2 :
			DPRINTF("=======================================================================\n");
			DPRINTF("2. Add the student Details From Text File\n");
			DPRINTF("Show The Student Buffer Before Adding the student Details From Text File \n");
			Show_All_info(&Student_Buffer_Info);
			Add_Students_From_File(&Student_Buffer_Info);
			DPRINTF("Show The Student Buffer After Adding the student Details From Text File \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("========================================================================\n");
			break ;
		case 3 :
			DPRINTF("==================================================================\n");
			DPRINTF("3. Find the Student Details by Roll Number\n");
			DPRINTF("Show The Student Buffer Before The Searching by Roll Number \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("[Take-INFO] Enter the Roll Number Of Student You Want Find It : ");
			scanf("%d",&Temp_Item.Roll_number);
			Find_Student_By_Roll_Number(& Student_Buffer_Info , Temp_Item.Roll_number);
			DPRINTF("==================================================================\n");
			break ;
		case 4 :
			DPRINTF("=====================================================================\n");
			DPRINTF("4. Find the Student Details by First Name\n");
			DPRINTF("Show The Student Buffer Before Find the Student Details by First Name\n");
			Show_All_info(&Student_Buffer_Info);
			Find_Student_By_First_Name(&Student_Buffer_Info);
			DPRINTF("======================================================================\n");
			break ;
		case 5 :
			DPRINTF("==================================================================\n");
			DPRINTF("5. Find the student Details by Course ID\n");
			DPRINTF("Show The Student Buffer Before Find the Student Details by First Name\n");
			Show_All_info(&Student_Buffer_Info);
			Find_Student_By_Course_ID(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 6 :
			DPRINTF("==================================================================\n");
			DPRINTF("6. Find the Total number of Students \n");
			DPRINTF("Show The Student Buffer Before Calculate the Number Of Student  \n");
			Show_All_info(&Student_Buffer_Info);
			Find_Total_Number_Student(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 7 :
			DPRINTF("==================================================================\n");
			DPRINTF("7. Delete the Students Details by Roll Number\n");
			DPRINTF("Show The Student Buffer Before Delete Student By Roll Number  \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("[Take-INFO] Enter the Roll Number Of Student You Want Delete : ");
			scanf("%d",&Temp_Item.Roll_number);
			Delete_Student_By_Roll_Number(&Student_Buffer_Info , Temp_Item.Roll_number);
			DPRINTF("Show The Student Buffer After Delete Student By Roll Number  \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 8 :
			DPRINTF("==================================================================\n");
			DPRINTF("8. Update the Students Details by Roll Number\n");
			DPRINTF("Show The Student Buffer Before Update Student By Roll Number  \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("[Take-INFO] Enter the Roll Number Of Student you Want To Update: ");
			scanf("%d",&Temp_Item.Roll_number);
			Update_Student_By_Roll_Number(&Student_Buffer_Info , Temp_Item.Roll_number);
			DPRINTF("Show The Student Buffer After Update Student By Roll Number  \n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 9 :
			DPRINTF("==================================================================\n");
			DPRINTF("9. Show all information\n");
			Show_All_info(&Student_Buffer_Info);
			DPRINTF("==================================================================\n");
			break ;
		case 10 :
			exit(1);
			break ;
		default :
			DPRINTF("[ERROR] WRONG CHOICE.\n");
			break ;
		}
	}
	return 0 ;
}

/*
 * Main_Student_Function.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A7MED
 */

#ifndef MAIN_STUDENT_FUNCTION_H_
#define MAIN_STUDENT_FUNCTION_H_
// Include And Define
#include "Platform_Type.h"
#define DPRINTF(...) 		{fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
// User Configuration
#define Student_Number 55
#define Course_Number 5
#define Length_Of_Names 10
#define Element_Type Student_Buffer_Info_t
#define File_Name "StudentDataBase.txt"				// you can write the name of file or Path of the file here
#define Length_Of_One_Record 100
#define Read_Mode "r"
#define Write_mode "w"


// Data Type definition

typedef struct
{

	unsigned int  Roll_number;
	uint8_t F_Name[Length_Of_Names];
	uint8_t L_Name[Length_Of_Names];
	float GPA ;
	uint32_t Course_ID[Course_Number] ;
}Student_Buffer_Info_t;

typedef enum
{
	Student_Buffer_No_Error,
	Student_Buffer_Empty ,
	Student_Buffer_Null,
	Student_Buffer_Full,
	Roll_Number_Taken,
	Roll_Number_Not_Taken,
	Data_Base_File_Open,
	Data_Base_File_Cant_Open ,
	Data_Base_File_Empty,
	Student_Exist,
	Student_Not_Exist,
	Delete_Successfully,
	Student_Updated,
	Student_Not_Found
}Student_Buffer_Status;

typedef struct
{
	Element_Type* Head ;
	Element_Type* Tail ;
	Element_Type* Base ;
	uint32_t Length ;
	uint32_t Count ;
}Fifo_Buffer_t;

// API ProtoTYpe

Student_Buffer_Status Student_Buffer_Init			(Fifo_Buffer_t* Student_Buffer_Info , Element_Type* Student_Buffer);
Student_Buffer_Status Add_Students_From_File			(Fifo_Buffer_t* Student_Buffer_Info );
Student_Buffer_Status Add_Student_Manually 			(Fifo_Buffer_t* Student_Buffer_Info , Element_Type Student_Buffer);
Student_Buffer_Status Find_Student_By_Roll_Number 	(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number);
void 				  Find_Student_By_First_Name 	(Fifo_Buffer_t* Student_Buffer_Info);
void				  Find_Student_By_Course_ID 	(Fifo_Buffer_t* Student_Buffer_Info);
void 				  Find_Total_Number_Student 	(Fifo_Buffer_t* Student_Buffer_Info);
void 				  Delete_Student_By_Roll_Number	(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number);
Student_Buffer_Status Update_Student_By_Roll_Number	(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number);
Student_Buffer_Status Show_All_info					(Fifo_Buffer_t* Student_Buffer_Info);
Student_Buffer_Status Check_Roll_Number				(Fifo_Buffer_t* Student_Buffer_Info, uint32_t Roll_Number);
Student_Buffer_Status FIFO_Buffer_Is_Full   		(Fifo_Buffer_t* Student_Buffer_Info);
Student_Buffer_Status FIFO_Buffer_Is_Exist  		(Fifo_Buffer_t* Student_Buffer_Info);
Student_Buffer_Status FIFO_Buffer_Is_Empty  		(Fifo_Buffer_t* Student_Buffer_Info);

// External Variable

#endif /* MAIN_STUDENT_FUNCTION_H_ */

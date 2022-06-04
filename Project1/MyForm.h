#pragma once
#include<string>
#include<fstream>
#include<msclr\marshal_cppstd.h>
#include<iostream>

using namespace msclr;
using namespace interop;
using namespace std;

ifstream in;
ofstream out;

struct courses{
	int id;
	string name;
	string instructorName;
	int enrolledStudents = 0;
};
struct students{
	int id;
	string name;
	int age;
	string address;
	int Course_id;
	int grade;
};
struct enroll{
	int courseID;
	int studentID;
	int grade;
};
int student_num = 0;
int course_num = 0;
int enroll_num = 0;

students student[50];
courses course[50];
enroll enrollment[100];
students displaystudent[50];
courses displaycourse[50];

int id_edit = 0; 
int id_delete = 0;
int id_search = 0;
int idstudent_unenroll = 0;
int idcourse_unenroll = 0;

void loud_course()
{
	in.open("Course.txt");
	while (!in.eof()) {
		in >> course[course_num].id;
		if (course[course_num].id == 0)
			break;
		getline(in, course[course_num].name, ',');
		getline(in, course[course_num].instructorName, ',');
		in >> course[course_num].enrolledStudents;
		course_num++;
	}
	in.close();
}
void loud_student()
{
	in.open("Students.txt");
	while (!in.eof()) {
		in >> student[student_num].id;
		if (student[student_num].id == 0)
			break;
		getline(in, student[student_num].name, ',');
		in >> student[student_num].age;
		getline(in, student[student_num].address);
		student_num++;
	}
	in.close();
}
void loud_enroll()
{
	in.open("Enrollments.txt");
	for (int i = 0; !in.eof(); i++){
		in >> enrollment[i].courseID;
		if (enrollment[i].courseID == 0)
			break;
		in >> enrollment[i].studentID;
		in >> enrollment[i].grade;
		enroll_num++;
	}
	in.close();
}

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_addSudent;
	protected:
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::Panel^  panel_buttons;
	private: System::Windows::Forms::Button^  btn_displayStudents;



	private: System::Windows::Forms::Button^  btn_addCourse;
	private: System::Windows::Forms::Button^  btn_editStudent;


	private: System::Windows::Forms::Button^  btn_displayCourses;
	private: System::Windows::Forms::Button^  btn_editCourse;
	private: System::Windows::Forms::Button^  btn_unenrollStudent;



	private: System::Windows::Forms::Button^  btn_searchCourse;
	private: System::Windows::Forms::Button^  btn_searchStudent;


	private: System::Windows::Forms::Button^  btn_deleteCourse;

	private: System::Windows::Forms::Button^  btn_deleteStudent;
	private: System::Windows::Forms::Panel^  panel_addStudent;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  lbl_IDCourse;
	private: System::Windows::Forms::Label^  lbl_Address;
	private: System::Windows::Forms::Label^  lbl_Age;
	private: System::Windows::Forms::TextBox^  txt_Grade;
	private: System::Windows::Forms::TextBox^  txt_IdCourse;
	private: System::Windows::Forms::TextBox^  txt_address;
	private: System::Windows::Forms::TextBox^  txt_Age;
	private: System::Windows::Forms::TextBox^  txt_ID;
	private: System::Windows::Forms::TextBox^  txt_Name;
	private: System::Windows::Forms::Label^  lbl_ID;
	private: System::Windows::Forms::Button^  btn_subAddStudent;

	private: System::Windows::Forms::Label^  lbl_Name;
	private: System::Windows::Forms::TextBox^  txt_listcourse;
	private: System::Windows::Forms::Panel^  panel_addCourse;
	private: System::Windows::Forms::Button^  btn_subAddCourse;
	private: System::Windows::Forms::Label^  lbl_EnrolledStudents;
	private: System::Windows::Forms::Label^  lbl_InstructorName;
	private: System::Windows::Forms::TextBox^  txt_enrolledStudNewC;
	private: System::Windows::Forms::TextBox^  txt_instructorNewC;
	private: System::Windows::Forms::TextBox^  txt_idNewC;
	private: System::Windows::Forms::TextBox^  txt_nameNewC;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Panel^  panel_displaySC;

	private: System::Windows::Forms::TextBox^  txt_display;
	private: System::Windows::Forms::Panel^  panel_editStudent;
	private: System::Windows::Forms::Label^  lbl_test;
	private: System::Windows::Forms::GroupBox^  grb_box;
	private: System::Windows::Forms::Button^  btn_submitEdit;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txt_EditAddress;
	private: System::Windows::Forms::TextBox^  txt_EditAge;
	private: System::Windows::Forms::TextBox^  txt_editIdStudent;
	private: System::Windows::Forms::Label^  lbl;

	private: System::Windows::Forms::Button^  btn_checkEditStudent;
	private: System::Windows::Forms::Panel^  panel_editCourse;
	private: System::Windows::Forms::Label^  lbl_checkEditCourse;

	private: System::Windows::Forms::GroupBox^  grb_editCourse;
	private: System::Windows::Forms::Button^  btn_submit;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  txt_editEnrolled;
	private: System::Windows::Forms::TextBox^  txt_editInstructor;
	private: System::Windows::Forms::TextBox^  txt_editIDCourse;
	private: System::Windows::Forms::Label^  lbl_EdittoidCourse;

	private: System::Windows::Forms::Button^  btn_checkeditCourse;
private: System::Windows::Forms::Panel^  panel_deleteStudent;
private: System::Windows::Forms::TextBox^  txt_deleteIdStudent;
private: System::Windows::Forms::Label^  lbl_deleteS;


private: System::Windows::Forms::Button^  btn_deleteS;
private: System::Windows::Forms::Panel^  panel_deleteCourse;
private: System::Windows::Forms::TextBox^  txt_deleteIdCourse;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Button^  btn_deleteC;
public protected: System::Windows::Forms::Panel^  panel_home;
private: System::Windows::Forms::Panel^  panel_search;
public protected:

private: System::Windows::Forms::TextBox^  txt_listSearch;
private: System::Windows::Forms::Button^  btn_searchS;

public protected:




public protected:


private: System::Windows::Forms::TextBox^  txt_search;

private: System::Windows::Forms::Label^  lbl_searchID;
private: System::Windows::Forms::Label^  lbl_NameSearch;
private: System::Windows::Forms::Button^  btn_searchC;
private: System::Windows::Forms::Panel^  panel_unenrolledStudent;
private: System::Windows::Forms::Label^  lbl_checkInCourse;

private: System::Windows::Forms::GroupBox^  grb_idCourse;
private: System::Windows::Forms::Label^  lbl_unenrollIDCourse;
private: System::Windows::Forms::TextBox^  txt_unenrollIDCourse;
private: System::Windows::Forms::Button^  btn_;
private: System::Windows::Forms::GroupBox^  grb_idStudent;
private: System::Windows::Forms::Label^  lbl_unenrollIDStudent;
private: System::Windows::Forms::TextBox^  txt_unenrollIDStudent;
private: System::Windows::Forms::Button^  btn_unrollIDStudent;
private: System::Windows::Forms::Button^  btn_unenroll;

private: System::Windows::Forms::Label^  lbl_nameCourse;
private: System::Windows::Forms::Label^  lbl_nameStudent;
private: System::Windows::Forms::Label^  label3;

private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label10;



private:









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel_addCourse = (gcnew System::Windows::Forms::Panel());
			this->btn_subAddCourse = (gcnew System::Windows::Forms::Button());
			this->lbl_EnrolledStudents = (gcnew System::Windows::Forms::Label());
			this->lbl_InstructorName = (gcnew System::Windows::Forms::Label());
			this->txt_enrolledStudNewC = (gcnew System::Windows::Forms::TextBox());
			this->txt_instructorNewC = (gcnew System::Windows::Forms::TextBox());
			this->txt_idNewC = (gcnew System::Windows::Forms::TextBox());
			this->txt_nameNewC = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel_addStudent = (gcnew System::Windows::Forms::Panel());
			this->lbl_Age = (gcnew System::Windows::Forms::Label());
			this->txt_Grade = (gcnew System::Windows::Forms::TextBox());
			this->txt_IdCourse = (gcnew System::Windows::Forms::TextBox());
			this->txt_address = (gcnew System::Windows::Forms::TextBox());
			this->txt_Age = (gcnew System::Windows::Forms::TextBox());
			this->txt_ID = (gcnew System::Windows::Forms::TextBox());
			this->txt_Name = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ID = (gcnew System::Windows::Forms::Label());
			this->btn_subAddStudent = (gcnew System::Windows::Forms::Button());
			this->lbl_Name = (gcnew System::Windows::Forms::Label());
			this->txt_listcourse = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbl_Address = (gcnew System::Windows::Forms::Label());
			this->lbl_IDCourse = (gcnew System::Windows::Forms::Label());
			this->btn_addSudent = (gcnew System::Windows::Forms::Button());
			this->title = (gcnew System::Windows::Forms::Label());
			this->panel_buttons = (gcnew System::Windows::Forms::Panel());
			this->btn_unenrollStudent = (gcnew System::Windows::Forms::Button());
			this->btn_searchCourse = (gcnew System::Windows::Forms::Button());
			this->btn_searchStudent = (gcnew System::Windows::Forms::Button());
			this->btn_deleteCourse = (gcnew System::Windows::Forms::Button());
			this->btn_deleteStudent = (gcnew System::Windows::Forms::Button());
			this->btn_editCourse = (gcnew System::Windows::Forms::Button());
			this->btn_editStudent = (gcnew System::Windows::Forms::Button());
			this->btn_displayCourses = (gcnew System::Windows::Forms::Button());
			this->btn_displayStudents = (gcnew System::Windows::Forms::Button());
			this->btn_addCourse = (gcnew System::Windows::Forms::Button());
			this->panel_displaySC = (gcnew System::Windows::Forms::Panel());
			this->txt_display = (gcnew System::Windows::Forms::TextBox());
			this->panel_editStudent = (gcnew System::Windows::Forms::Panel());
			this->lbl_test = (gcnew System::Windows::Forms::Label());
			this->grb_box = (gcnew System::Windows::Forms::GroupBox());
			this->btn_submitEdit = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_EditAddress = (gcnew System::Windows::Forms::TextBox());
			this->txt_EditAge = (gcnew System::Windows::Forms::TextBox());
			this->txt_editIdStudent = (gcnew System::Windows::Forms::TextBox());
			this->lbl = (gcnew System::Windows::Forms::Label());
			this->btn_checkEditStudent = (gcnew System::Windows::Forms::Button());
			this->panel_editCourse = (gcnew System::Windows::Forms::Panel());
			this->lbl_checkEditCourse = (gcnew System::Windows::Forms::Label());
			this->grb_editCourse = (gcnew System::Windows::Forms::GroupBox());
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txt_editEnrolled = (gcnew System::Windows::Forms::TextBox());
			this->txt_editInstructor = (gcnew System::Windows::Forms::TextBox());
			this->txt_editIDCourse = (gcnew System::Windows::Forms::TextBox());
			this->lbl_EdittoidCourse = (gcnew System::Windows::Forms::Label());
			this->btn_checkeditCourse = (gcnew System::Windows::Forms::Button());
			this->panel_deleteStudent = (gcnew System::Windows::Forms::Panel());
			this->txt_deleteIdStudent = (gcnew System::Windows::Forms::TextBox());
			this->lbl_deleteS = (gcnew System::Windows::Forms::Label());
			this->btn_deleteS = (gcnew System::Windows::Forms::Button());
			this->panel_deleteCourse = (gcnew System::Windows::Forms::Panel());
			this->txt_deleteIdCourse = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btn_deleteC = (gcnew System::Windows::Forms::Button());
			this->panel_home = (gcnew System::Windows::Forms::Panel());
			this->panel_search = (gcnew System::Windows::Forms::Panel());
			this->btn_searchC = (gcnew System::Windows::Forms::Button());
			this->lbl_NameSearch = (gcnew System::Windows::Forms::Label());
			this->txt_listSearch = (gcnew System::Windows::Forms::TextBox());
			this->btn_searchS = (gcnew System::Windows::Forms::Button());
			this->txt_search = (gcnew System::Windows::Forms::TextBox());
			this->lbl_searchID = (gcnew System::Windows::Forms::Label());
			this->panel_unenrolledStudent = (gcnew System::Windows::Forms::Panel());
			this->lbl_checkInCourse = (gcnew System::Windows::Forms::Label());
			this->grb_idCourse = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_unenrollIDCourse = (gcnew System::Windows::Forms::Label());
			this->txt_unenrollIDCourse = (gcnew System::Windows::Forms::TextBox());
			this->btn_ = (gcnew System::Windows::Forms::Button());
			this->grb_idStudent = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_unenrollIDStudent = (gcnew System::Windows::Forms::Label());
			this->txt_unenrollIDStudent = (gcnew System::Windows::Forms::TextBox());
			this->btn_unrollIDStudent = (gcnew System::Windows::Forms::Button());
			this->btn_unenroll = (gcnew System::Windows::Forms::Button());
			this->lbl_nameCourse = (gcnew System::Windows::Forms::Label());
			this->lbl_nameStudent = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel_addCourse->SuspendLayout();
			this->panel_addStudent->SuspendLayout();
			this->panel_buttons->SuspendLayout();
			this->panel_displaySC->SuspendLayout();
			this->panel_editStudent->SuspendLayout();
			this->grb_box->SuspendLayout();
			this->panel_editCourse->SuspendLayout();
			this->grb_editCourse->SuspendLayout();
			this->panel_deleteStudent->SuspendLayout();
			this->panel_deleteCourse->SuspendLayout();
			this->panel_home->SuspendLayout();
			this->panel_search->SuspendLayout();
			this->panel_unenrolledStudent->SuspendLayout();
			this->grb_idCourse->SuspendLayout();
			this->grb_idStudent->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_addCourse
			// 
			this->panel_addCourse->AutoSize = true;
			this->panel_addCourse->BackColor = System::Drawing::Color::Gold;
			this->panel_addCourse->Controls->Add(this->label16);
			this->panel_addCourse->Controls->Add(this->btn_subAddCourse);
			this->panel_addCourse->Controls->Add(this->lbl_EnrolledStudents);
			this->panel_addCourse->Controls->Add(this->lbl_InstructorName);
			this->panel_addCourse->Controls->Add(this->txt_enrolledStudNewC);
			this->panel_addCourse->Controls->Add(this->txt_instructorNewC);
			this->panel_addCourse->Controls->Add(this->txt_idNewC);
			this->panel_addCourse->Controls->Add(this->txt_nameNewC);
			this->panel_addCourse->Controls->Add(this->label1);
			this->panel_addCourse->Controls->Add(this->label2);
			this->panel_addCourse->Location = System::Drawing::Point(181, 71);
			this->panel_addCourse->Name = L"panel_addCourse";
			this->panel_addCourse->Size = System::Drawing::Size(573, 420);
			this->panel_addCourse->TabIndex = 4;
			this->panel_addCourse->Visible = false;
			// 
			// btn_subAddCourse
			// 
			this->btn_subAddCourse->Location = System::Drawing::Point(218, 298);
			this->btn_subAddCourse->Name = L"btn_subAddCourse";
			this->btn_subAddCourse->Size = System::Drawing::Size(142, 48);
			this->btn_subAddCourse->TabIndex = 38;
			this->btn_subAddCourse->Text = L"Submit";
			this->btn_subAddCourse->UseVisualStyleBackColor = true;
			this->btn_subAddCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_subAddCourse_Click);
			// 
			// lbl_EnrolledStudents
			// 
			this->lbl_EnrolledStudents->AutoSize = true;
			this->lbl_EnrolledStudents->Location = System::Drawing::Point(105, 213);
			this->lbl_EnrolledStudents->Name = L"lbl_EnrolledStudents";
			this->lbl_EnrolledStudents->Size = System::Drawing::Size(94, 13);
			this->lbl_EnrolledStudents->TabIndex = 37;
			this->lbl_EnrolledStudents->Text = L"#EnrolledStudents";
			// 
			// lbl_InstructorName
			// 
			this->lbl_InstructorName->AutoSize = true;
			this->lbl_InstructorName->Location = System::Drawing::Point(105, 187);
			this->lbl_InstructorName->Name = L"lbl_InstructorName";
			this->lbl_InstructorName->Size = System::Drawing::Size(82, 13);
			this->lbl_InstructorName->TabIndex = 36;
			this->lbl_InstructorName->Text = L"Instrcutor Name";
			// 
			// txt_enrolledStudNewC
			// 
			this->txt_enrolledStudNewC->Location = System::Drawing::Point(255, 209);
			this->txt_enrolledStudNewC->Name = L"txt_enrolledStudNewC";
			this->txt_enrolledStudNewC->Size = System::Drawing::Size(218, 20);
			this->txt_enrolledStudNewC->TabIndex = 35;
			// 
			// txt_instructorNewC
			// 
			this->txt_instructorNewC->Location = System::Drawing::Point(255, 183);
			this->txt_instructorNewC->Name = L"txt_instructorNewC";
			this->txt_instructorNewC->Size = System::Drawing::Size(218, 20);
			this->txt_instructorNewC->TabIndex = 34;
			// 
			// txt_idNewC
			// 
			this->txt_idNewC->Location = System::Drawing::Point(255, 157);
			this->txt_idNewC->Name = L"txt_idNewC";
			this->txt_idNewC->Size = System::Drawing::Size(218, 20);
			this->txt_idNewC->TabIndex = 33;
			// 
			// txt_nameNewC
			// 
			this->txt_nameNewC->Location = System::Drawing::Point(255, 131);
			this->txt_nameNewC->Name = L"txt_nameNewC";
			this->txt_nameNewC->Size = System::Drawing::Size(218, 20);
			this->txt_nameNewC->TabIndex = 32;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(105, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 31;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(105, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 30;
			this->label2->Text = L"Name";
			// 
			// panel_addStudent
			// 
			this->panel_addStudent->AutoSize = true;
			this->panel_addStudent->BackColor = System::Drawing::Color::Gold;
			this->panel_addStudent->Controls->Add(this->label17);
			this->panel_addStudent->Controls->Add(this->lbl_Age);
			this->panel_addStudent->Controls->Add(this->txt_Grade);
			this->panel_addStudent->Controls->Add(this->txt_IdCourse);
			this->panel_addStudent->Controls->Add(this->txt_address);
			this->panel_addStudent->Controls->Add(this->txt_Age);
			this->panel_addStudent->Controls->Add(this->txt_ID);
			this->panel_addStudent->Controls->Add(this->txt_Name);
			this->panel_addStudent->Controls->Add(this->lbl_ID);
			this->panel_addStudent->Controls->Add(this->btn_subAddStudent);
			this->panel_addStudent->Controls->Add(this->lbl_Name);
			this->panel_addStudent->Controls->Add(this->txt_listcourse);
			this->panel_addStudent->Controls->Add(this->label4);
			this->panel_addStudent->Controls->Add(this->lbl_Address);
			this->panel_addStudent->Controls->Add(this->lbl_IDCourse);
			this->panel_addStudent->Location = System::Drawing::Point(181, 71);
			this->panel_addStudent->Name = L"panel_addStudent";
			this->panel_addStudent->Size = System::Drawing::Size(573, 420);
			this->panel_addStudent->TabIndex = 3;
			this->panel_addStudent->Visible = false;
			// 
			// lbl_Age
			// 
			this->lbl_Age->AutoSize = true;
			this->lbl_Age->Location = System::Drawing::Point(22, 164);
			this->lbl_Age->Name = L"lbl_Age";
			this->lbl_Age->Size = System::Drawing::Size(26, 13);
			this->lbl_Age->TabIndex = 22;
			this->lbl_Age->Text = L"Age";
			// 
			// txt_Grade
			// 
			this->txt_Grade->Location = System::Drawing::Point(143, 239);
			this->txt_Grade->Name = L"txt_Grade";
			this->txt_Grade->Size = System::Drawing::Size(146, 20);
			this->txt_Grade->TabIndex = 21;
			// 
			// txt_IdCourse
			// 
			this->txt_IdCourse->Location = System::Drawing::Point(143, 213);
			this->txt_IdCourse->Name = L"txt_IdCourse";
			this->txt_IdCourse->Size = System::Drawing::Size(146, 20);
			this->txt_IdCourse->TabIndex = 20;
			// 
			// txt_address
			// 
			this->txt_address->Location = System::Drawing::Point(143, 187);
			this->txt_address->Name = L"txt_address";
			this->txt_address->Size = System::Drawing::Size(146, 20);
			this->txt_address->TabIndex = 19;
			// 
			// txt_Age
			// 
			this->txt_Age->Location = System::Drawing::Point(143, 161);
			this->txt_Age->Name = L"txt_Age";
			this->txt_Age->Size = System::Drawing::Size(146, 20);
			this->txt_Age->TabIndex = 18;
			// 
			// txt_ID
			// 
			this->txt_ID->Location = System::Drawing::Point(143, 135);
			this->txt_ID->Name = L"txt_ID";
			this->txt_ID->Size = System::Drawing::Size(146, 20);
			this->txt_ID->TabIndex = 17;
			// 
			// txt_Name
			// 
			this->txt_Name->Location = System::Drawing::Point(143, 109);
			this->txt_Name->Name = L"txt_Name";
			this->txt_Name->Size = System::Drawing::Size(146, 20);
			this->txt_Name->TabIndex = 16;
			// 
			// lbl_ID
			// 
			this->lbl_ID->AutoSize = true;
			this->lbl_ID->Location = System::Drawing::Point(22, 138);
			this->lbl_ID->Name = L"lbl_ID";
			this->lbl_ID->Size = System::Drawing::Size(18, 13);
			this->lbl_ID->TabIndex = 15;
			this->lbl_ID->Text = L"ID";
			// 
			// btn_subAddStudent
			// 
			this->btn_subAddStudent->Location = System::Drawing::Point(80, 304);
			this->btn_subAddStudent->Name = L"btn_subAddStudent";
			this->btn_subAddStudent->Size = System::Drawing::Size(157, 60);
			this->btn_subAddStudent->TabIndex = 14;
			this->btn_subAddStudent->Text = L"Submit";
			this->btn_subAddStudent->UseVisualStyleBackColor = true;
			this->btn_subAddStudent->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// lbl_Name
			// 
			this->lbl_Name->AutoSize = true;
			this->lbl_Name->Location = System::Drawing::Point(22, 112);
			this->lbl_Name->Name = L"lbl_Name";
			this->lbl_Name->Size = System::Drawing::Size(35, 13);
			this->lbl_Name->TabIndex = 13;
			this->lbl_Name->Text = L"Name";
			// 
			// txt_listcourse
			// 
			this->txt_listcourse->Enabled = false;
			this->txt_listcourse->Location = System::Drawing::Point(295, 109);
			this->txt_listcourse->Multiline = true;
			this->txt_listcourse->Name = L"txt_listcourse";
			this->txt_listcourse->ReadOnly = true;
			this->txt_listcourse->Size = System::Drawing::Size(262, 269);
			this->txt_listcourse->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Grade";
			// 
			// lbl_Address
			// 
			this->lbl_Address->AutoSize = true;
			this->lbl_Address->Location = System::Drawing::Point(22, 190);
			this->lbl_Address->Name = L"lbl_Address";
			this->lbl_Address->Size = System::Drawing::Size(45, 13);
			this->lbl_Address->TabIndex = 23;
			this->lbl_Address->Text = L"Address";
			// 
			// lbl_IDCourse
			// 
			this->lbl_IDCourse->AutoSize = true;
			this->lbl_IDCourse->Location = System::Drawing::Point(22, 216);
			this->lbl_IDCourse->Name = L"lbl_IDCourse";
			this->lbl_IDCourse->Size = System::Drawing::Size(99, 13);
			this->lbl_IDCourse->TabIndex = 24;
			this->lbl_IDCourse->Text = L"ID Course To Enroll";
			// 
			// btn_addSudent
			// 
			this->btn_addSudent->BackColor = System::Drawing::Color::Yellow;
			this->btn_addSudent->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_addSudent->Location = System::Drawing::Point(0, 0);
			this->btn_addSudent->Name = L"btn_addSudent";
			this->btn_addSudent->Size = System::Drawing::Size(158, 33);
			this->btn_addSudent->TabIndex = 0;
			this->btn_addSudent->Text = L"Add Student";
			this->btn_addSudent->UseVisualStyleBackColor = false;
			this->btn_addSudent->Click += gcnew System::EventHandler(this, &MyForm::btn_addSudent_Click);
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Gold;
			this->title->Font = (gcnew System::Drawing::Font(L"Snap ITC", 33.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::ControlText;
			this->title->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->title->ImageKey = L"(none)";
			this->title->Location = System::Drawing::Point(9, 10);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(759, 58);
			this->title->TabIndex = 1;
			this->title->Text = L"Course Management System";
			this->title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel_buttons
			// 
			this->panel_buttons->BackColor = System::Drawing::Color::Gold;
			this->panel_buttons->Controls->Add(this->btn_unenrollStudent);
			this->panel_buttons->Controls->Add(this->btn_searchCourse);
			this->panel_buttons->Controls->Add(this->btn_searchStudent);
			this->panel_buttons->Controls->Add(this->btn_deleteCourse);
			this->panel_buttons->Controls->Add(this->btn_deleteStudent);
			this->panel_buttons->Controls->Add(this->btn_editCourse);
			this->panel_buttons->Controls->Add(this->btn_editStudent);
			this->panel_buttons->Controls->Add(this->btn_displayCourses);
			this->panel_buttons->Controls->Add(this->btn_displayStudents);
			this->panel_buttons->Controls->Add(this->btn_addCourse);
			this->panel_buttons->Controls->Add(this->btn_addSudent);
			this->panel_buttons->Location = System::Drawing::Point(12, 69);
			this->panel_buttons->Name = L"panel_buttons";
			this->panel_buttons->Size = System::Drawing::Size(158, 423);
			this->panel_buttons->TabIndex = 2;
			this->panel_buttons->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_buttons_Paint);
			// 
			// btn_unenrollStudent
			// 
			this->btn_unenrollStudent->BackColor = System::Drawing::Color::Yellow;
			this->btn_unenrollStudent->Font = (gcnew System::Drawing::Font(L"Forte", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_unenrollStudent->Location = System::Drawing::Point(-1, 390);
			this->btn_unenrollStudent->Name = L"btn_unenrollStudent";
			this->btn_unenrollStudent->Size = System::Drawing::Size(159, 33);
			this->btn_unenrollStudent->TabIndex = 10;
			this->btn_unenrollStudent->Text = L"UnEnroll Student";
			this->btn_unenrollStudent->UseVisualStyleBackColor = false;
			this->btn_unenrollStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_unenrollStudent_Click);
			// 
			// btn_searchCourse
			// 
			this->btn_searchCourse->BackColor = System::Drawing::Color::Yellow;
			this->btn_searchCourse->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_searchCourse->Location = System::Drawing::Point(0, 353);
			this->btn_searchCourse->Name = L"btn_searchCourse";
			this->btn_searchCourse->Size = System::Drawing::Size(158, 33);
			this->btn_searchCourse->TabIndex = 9;
			this->btn_searchCourse->Text = L"Search Course";
			this->btn_searchCourse->UseVisualStyleBackColor = false;
			this->btn_searchCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_searchCourse_Click);
			// 
			// btn_searchStudent
			// 
			this->btn_searchStudent->BackColor = System::Drawing::Color::Yellow;
			this->btn_searchStudent->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_searchStudent->Location = System::Drawing::Point(0, 314);
			this->btn_searchStudent->Name = L"btn_searchStudent";
			this->btn_searchStudent->Size = System::Drawing::Size(158, 33);
			this->btn_searchStudent->TabIndex = 8;
			this->btn_searchStudent->Text = L"Search Student";
			this->btn_searchStudent->UseVisualStyleBackColor = false;
			this->btn_searchStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_searchStudent_Click);
			// 
			// btn_deleteCourse
			// 
			this->btn_deleteCourse->BackColor = System::Drawing::Color::Yellow;
			this->btn_deleteCourse->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_deleteCourse->Location = System::Drawing::Point(0, 275);
			this->btn_deleteCourse->Name = L"btn_deleteCourse";
			this->btn_deleteCourse->Size = System::Drawing::Size(158, 33);
			this->btn_deleteCourse->TabIndex = 7;
			this->btn_deleteCourse->Text = L"Delete Course";
			this->btn_deleteCourse->UseVisualStyleBackColor = false;
			this->btn_deleteCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_deleteCourse_Click);
			// 
			// btn_deleteStudent
			// 
			this->btn_deleteStudent->BackColor = System::Drawing::Color::Yellow;
			this->btn_deleteStudent->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_deleteStudent->Location = System::Drawing::Point(0, 236);
			this->btn_deleteStudent->Name = L"btn_deleteStudent";
			this->btn_deleteStudent->Size = System::Drawing::Size(158, 33);
			this->btn_deleteStudent->TabIndex = 6;
			this->btn_deleteStudent->Text = L"Delete Student";
			this->btn_deleteStudent->UseVisualStyleBackColor = false;
			this->btn_deleteStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_deleteStudent_Click);
			// 
			// btn_editCourse
			// 
			this->btn_editCourse->BackColor = System::Drawing::Color::Yellow;
			this->btn_editCourse->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_editCourse->Location = System::Drawing::Point(-1, 197);
			this->btn_editCourse->Name = L"btn_editCourse";
			this->btn_editCourse->Size = System::Drawing::Size(158, 33);
			this->btn_editCourse->TabIndex = 5;
			this->btn_editCourse->Text = L"Edit Course";
			this->btn_editCourse->UseVisualStyleBackColor = false;
			this->btn_editCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_editCourse_Click);
			// 
			// btn_editStudent
			// 
			this->btn_editStudent->BackColor = System::Drawing::Color::Yellow;
			this->btn_editStudent->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_editStudent->Location = System::Drawing::Point(-1, 158);
			this->btn_editStudent->Name = L"btn_editStudent";
			this->btn_editStudent->Size = System::Drawing::Size(158, 33);
			this->btn_editStudent->TabIndex = 4;
			this->btn_editStudent->Text = L"Edit Student";
			this->btn_editStudent->UseVisualStyleBackColor = false;
			this->btn_editStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_editStudent_Click);
			// 
			// btn_displayCourses
			// 
			this->btn_displayCourses->BackColor = System::Drawing::Color::Yellow;
			this->btn_displayCourses->Font = (gcnew System::Drawing::Font(L"Forte", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_displayCourses->Location = System::Drawing::Point(-1, 119);
			this->btn_displayCourses->Name = L"btn_displayCourses";
			this->btn_displayCourses->Size = System::Drawing::Size(159, 33);
			this->btn_displayCourses->TabIndex = 3;
			this->btn_displayCourses->Text = L"Display Courses";
			this->btn_displayCourses->UseVisualStyleBackColor = false;
			this->btn_displayCourses->Click += gcnew System::EventHandler(this, &MyForm::btn_displayCourses_Click);
			// 
			// btn_displayStudents
			// 
			this->btn_displayStudents->BackColor = System::Drawing::Color::Yellow;
			this->btn_displayStudents->Font = (gcnew System::Drawing::Font(L"Forte", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_displayStudents->Location = System::Drawing::Point(-1, 78);
			this->btn_displayStudents->Name = L"btn_displayStudents";
			this->btn_displayStudents->Size = System::Drawing::Size(159, 33);
			this->btn_displayStudents->TabIndex = 2;
			this->btn_displayStudents->Text = L"Display Students";
			this->btn_displayStudents->UseVisualStyleBackColor = false;
			this->btn_displayStudents->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btn_addCourse
			// 
			this->btn_addCourse->BackColor = System::Drawing::Color::Yellow;
			this->btn_addCourse->Font = (gcnew System::Drawing::Font(L"Forte", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_addCourse->Location = System::Drawing::Point(0, 39);
			this->btn_addCourse->Name = L"btn_addCourse";
			this->btn_addCourse->Size = System::Drawing::Size(157, 33);
			this->btn_addCourse->TabIndex = 1;
			this->btn_addCourse->Text = L"Add Course";
			this->btn_addCourse->UseVisualStyleBackColor = false;
			this->btn_addCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_addCourse_Click);
			// 
			// panel_displaySC
			// 
			this->panel_displaySC->AutoSize = true;
			this->panel_displaySC->BackColor = System::Drawing::Color::Gold;
			this->panel_displaySC->Controls->Add(this->label15);
			this->panel_displaySC->Controls->Add(this->txt_display);
			this->panel_displaySC->Location = System::Drawing::Point(181, 71);
			this->panel_displaySC->Name = L"panel_displaySC";
			this->panel_displaySC->Size = System::Drawing::Size(573, 420);
			this->panel_displaySC->TabIndex = 6;
			this->panel_displaySC->Visible = false;
			// 
			// txt_display
			// 
			this->txt_display->Enabled = false;
			this->txt_display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_display->Location = System::Drawing::Point(100, 105);
			this->txt_display->Multiline = true;
			this->txt_display->Name = L"txt_display";
			this->txt_display->Size = System::Drawing::Size(375, 269);
			this->txt_display->TabIndex = 0;
			this->txt_display->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// panel_editStudent
			// 
			this->panel_editStudent->BackColor = System::Drawing::Color::Gold;
			this->panel_editStudent->Controls->Add(this->label14);
			this->panel_editStudent->Controls->Add(this->lbl_test);
			this->panel_editStudent->Controls->Add(this->grb_box);
			this->panel_editStudent->Controls->Add(this->txt_editIdStudent);
			this->panel_editStudent->Controls->Add(this->lbl);
			this->panel_editStudent->Controls->Add(this->btn_checkEditStudent);
			this->panel_editStudent->Location = System::Drawing::Point(181, 71);
			this->panel_editStudent->Name = L"panel_editStudent";
			this->panel_editStudent->Size = System::Drawing::Size(573, 420);
			this->panel_editStudent->TabIndex = 7;
			this->panel_editStudent->Visible = false;
			// 
			// lbl_test
			// 
			this->lbl_test->AutoSize = true;
			this->lbl_test->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_test->Location = System::Drawing::Point(259, 173);
			this->lbl_test->Name = L"lbl_test";
			this->lbl_test->Size = System::Drawing::Size(30, 15);
			this->lbl_test->TabIndex = 24;
			this->lbl_test->Text = L"text";
			this->lbl_test->Visible = false;
			// 
			// grb_box
			// 
			this->grb_box->Controls->Add(this->btn_submitEdit);
			this->grb_box->Controls->Add(this->label5);
			this->grb_box->Controls->Add(this->label6);
			this->grb_box->Controls->Add(this->txt_EditAddress);
			this->grb_box->Controls->Add(this->txt_EditAge);
			this->grb_box->Location = System::Drawing::Point(108, 218);
			this->grb_box->Name = L"grb_box";
			this->grb_box->Size = System::Drawing::Size(332, 171);
			this->grb_box->TabIndex = 23;
			this->grb_box->TabStop = false;
			this->grb_box->Text = L"Edit Student";
			this->grb_box->Visible = false;
			// 
			// btn_submitEdit
			// 
			this->btn_submitEdit->Location = System::Drawing::Point(110, 116);
			this->btn_submitEdit->Name = L"btn_submitEdit";
			this->btn_submitEdit->Size = System::Drawing::Size(101, 25);
			this->btn_submitEdit->TabIndex = 4;
			this->btn_submitEdit->Text = L"Submit";
			this->btn_submitEdit->UseVisualStyleBackColor = true;
			this->btn_submitEdit->Click += gcnew System::EventHandler(this, &MyForm::btn_submitEdit_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(52, 81);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Edit Address";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(52, 39);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 13);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Edit Age";
			// 
			// txt_EditAddress
			// 
			this->txt_EditAddress->Location = System::Drawing::Point(161, 78);
			this->txt_EditAddress->Name = L"txt_EditAddress";
			this->txt_EditAddress->Size = System::Drawing::Size(100, 20);
			this->txt_EditAddress->TabIndex = 1;
			// 
			// txt_EditAge
			// 
			this->txt_EditAge->Location = System::Drawing::Point(161, 36);
			this->txt_EditAge->Name = L"txt_EditAge";
			this->txt_EditAge->Size = System::Drawing::Size(100, 20);
			this->txt_EditAge->TabIndex = 0;
			// 
			// txt_editIdStudent
			// 
			this->txt_editIdStudent->Location = System::Drawing::Point(218, 119);
			this->txt_editIdStudent->Name = L"txt_editIdStudent";
			this->txt_editIdStudent->Size = System::Drawing::Size(142, 20);
			this->txt_editIdStudent->TabIndex = 22;
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Location = System::Drawing::Point(64, 122);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(90, 13);
			this->lbl->TabIndex = 21;
			this->lbl->Text = L"ID Student to edit";
			// 
			// btn_checkEditStudent
			// 
			this->btn_checkEditStudent->Location = System::Drawing::Point(420, 111);
			this->btn_checkEditStudent->Name = L"btn_checkEditStudent";
			this->btn_checkEditStudent->Size = System::Drawing::Size(95, 35);
			this->btn_checkEditStudent->TabIndex = 20;
			this->btn_checkEditStudent->Text = L"Check";
			this->btn_checkEditStudent->UseVisualStyleBackColor = true;
			this->btn_checkEditStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_checkEditStudent_Click);
			// 
			// panel_editCourse
			// 
			this->panel_editCourse->BackColor = System::Drawing::Color::Gold;
			this->panel_editCourse->Controls->Add(this->label13);
			this->panel_editCourse->Controls->Add(this->lbl_checkEditCourse);
			this->panel_editCourse->Controls->Add(this->grb_editCourse);
			this->panel_editCourse->Controls->Add(this->txt_editIDCourse);
			this->panel_editCourse->Controls->Add(this->lbl_EdittoidCourse);
			this->panel_editCourse->Controls->Add(this->btn_checkeditCourse);
			this->panel_editCourse->Location = System::Drawing::Point(181, 71);
			this->panel_editCourse->Name = L"panel_editCourse";
			this->panel_editCourse->Size = System::Drawing::Size(573, 420);
			this->panel_editCourse->TabIndex = 7;
			this->panel_editCourse->Visible = false;
			// 
			// lbl_checkEditCourse
			// 
			this->lbl_checkEditCourse->AutoSize = true;
			this->lbl_checkEditCourse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_checkEditCourse->Location = System::Drawing::Point(265, 165);
			this->lbl_checkEditCourse->Name = L"lbl_checkEditCourse";
			this->lbl_checkEditCourse->Size = System::Drawing::Size(30, 15);
			this->lbl_checkEditCourse->TabIndex = 28;
			this->lbl_checkEditCourse->Text = L"text";
			this->lbl_checkEditCourse->Visible = false;
			// 
			// grb_editCourse
			// 
			this->grb_editCourse->Controls->Add(this->btn_submit);
			this->grb_editCourse->Controls->Add(this->label8);
			this->grb_editCourse->Controls->Add(this->label9);
			this->grb_editCourse->Controls->Add(this->txt_editEnrolled);
			this->grb_editCourse->Controls->Add(this->txt_editInstructor);
			this->grb_editCourse->Location = System::Drawing::Point(121, 195);
			this->grb_editCourse->Name = L"grb_editCourse";
			this->grb_editCourse->Size = System::Drawing::Size(318, 173);
			this->grb_editCourse->TabIndex = 27;
			this->grb_editCourse->TabStop = false;
			this->grb_editCourse->Text = L"Edit Course";
			this->grb_editCourse->Visible = false;
			// 
			// btn_submit
			// 
			this->btn_submit->Location = System::Drawing::Point(110, 116);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(101, 25);
			this->btn_submit->TabIndex = 4;
			this->btn_submit->Text = L"Submit";
			this->btn_submit->UseVisualStyleBackColor = true;
			this->btn_submit->Click += gcnew System::EventHandler(this, &MyForm::btn_submit_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(29, 81);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 13);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Edit #Enrolled Students";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(29, 39);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(103, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Edit Instructor Name";
			// 
			// txt_editEnrolled
			// 
			this->txt_editEnrolled->Location = System::Drawing::Point(161, 78);
			this->txt_editEnrolled->Name = L"txt_editEnrolled";
			this->txt_editEnrolled->Size = System::Drawing::Size(100, 20);
			this->txt_editEnrolled->TabIndex = 1;
			// 
			// txt_editInstructor
			// 
			this->txt_editInstructor->Location = System::Drawing::Point(161, 36);
			this->txt_editInstructor->Name = L"txt_editInstructor";
			this->txt_editInstructor->Size = System::Drawing::Size(100, 20);
			this->txt_editInstructor->TabIndex = 0;
			// 
			// txt_editIDCourse
			// 
			this->txt_editIDCourse->Location = System::Drawing::Point(229, 117);
			this->txt_editIDCourse->Name = L"txt_editIDCourse";
			this->txt_editIDCourse->Size = System::Drawing::Size(100, 20);
			this->txt_editIDCourse->TabIndex = 26;
			// 
			// lbl_EdittoidCourse
			// 
			this->lbl_EdittoidCourse->AutoSize = true;
			this->lbl_EdittoidCourse->Location = System::Drawing::Point(78, 120);
			this->lbl_EdittoidCourse->Name = L"lbl_EdittoidCourse";
			this->lbl_EdittoidCourse->Size = System::Drawing::Size(86, 13);
			this->lbl_EdittoidCourse->TabIndex = 25;
			this->lbl_EdittoidCourse->Text = L"ID Course to edit";
			// 
			// btn_checkeditCourse
			// 
			this->btn_checkeditCourse->Location = System::Drawing::Point(419, 109);
			this->btn_checkeditCourse->Name = L"btn_checkeditCourse";
			this->btn_checkeditCourse->Size = System::Drawing::Size(95, 35);
			this->btn_checkeditCourse->TabIndex = 24;
			this->btn_checkeditCourse->Text = L"Check";
			this->btn_checkeditCourse->UseVisualStyleBackColor = true;
			this->btn_checkeditCourse->Click += gcnew System::EventHandler(this, &MyForm::btn_checkeditCourse_Click);
			// 
			// panel_deleteStudent
			// 
			this->panel_deleteStudent->BackColor = System::Drawing::Color::Gold;
			this->panel_deleteStudent->Controls->Add(this->label12);
			this->panel_deleteStudent->Controls->Add(this->txt_deleteIdStudent);
			this->panel_deleteStudent->Controls->Add(this->lbl_deleteS);
			this->panel_deleteStudent->Controls->Add(this->btn_deleteS);
			this->panel_deleteStudent->Location = System::Drawing::Point(181, 71);
			this->panel_deleteStudent->Name = L"panel_deleteStudent";
			this->panel_deleteStudent->Size = System::Drawing::Size(573, 420);
			this->panel_deleteStudent->TabIndex = 7;
			this->panel_deleteStudent->Visible = false;
			// 
			// txt_deleteIdStudent
			// 
			this->txt_deleteIdStudent->Location = System::Drawing::Point(305, 136);
			this->txt_deleteIdStudent->Name = L"txt_deleteIdStudent";
			this->txt_deleteIdStudent->Size = System::Drawing::Size(113, 20);
			this->txt_deleteIdStudent->TabIndex = 24;
			// 
			// lbl_deleteS
			// 
			this->lbl_deleteS->AutoSize = true;
			this->lbl_deleteS->Location = System::Drawing::Point(140, 139);
			this->lbl_deleteS->Name = L"lbl_deleteS";
			this->lbl_deleteS->Size = System::Drawing::Size(104, 13);
			this->lbl_deleteS->TabIndex = 23;
			this->lbl_deleteS->Text = L"ID Student to Delete";
			// 
			// btn_deleteS
			// 
			this->btn_deleteS->Location = System::Drawing::Point(234, 223);
			this->btn_deleteS->Name = L"btn_deleteS";
			this->btn_deleteS->Size = System::Drawing::Size(110, 50);
			this->btn_deleteS->TabIndex = 22;
			this->btn_deleteS->Text = L"Delete";
			this->btn_deleteS->UseVisualStyleBackColor = true;
			this->btn_deleteS->Click += gcnew System::EventHandler(this, &MyForm::btn_deleteS_Click);
			// 
			// panel_deleteCourse
			// 
			this->panel_deleteCourse->BackColor = System::Drawing::Color::Gold;
			this->panel_deleteCourse->Controls->Add(this->label11);
			this->panel_deleteCourse->Controls->Add(this->txt_deleteIdCourse);
			this->panel_deleteCourse->Controls->Add(this->label7);
			this->panel_deleteCourse->Controls->Add(this->btn_deleteC);
			this->panel_deleteCourse->Location = System::Drawing::Point(181, 71);
			this->panel_deleteCourse->Name = L"panel_deleteCourse";
			this->panel_deleteCourse->Size = System::Drawing::Size(573, 420);
			this->panel_deleteCourse->TabIndex = 7;
			this->panel_deleteCourse->Visible = false;
			// 
			// txt_deleteIdCourse
			// 
			this->txt_deleteIdCourse->Location = System::Drawing::Point(308, 162);
			this->txt_deleteIdCourse->Name = L"txt_deleteIdCourse";
			this->txt_deleteIdCourse->Size = System::Drawing::Size(113, 20);
			this->txt_deleteIdCourse->TabIndex = 24;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(146, 168);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(100, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"ID Course to Delete";
			// 
			// btn_deleteC
			// 
			this->btn_deleteC->Location = System::Drawing::Point(242, 239);
			this->btn_deleteC->Name = L"btn_deleteC";
			this->btn_deleteC->Size = System::Drawing::Size(101, 49);
			this->btn_deleteC->TabIndex = 22;
			this->btn_deleteC->Text = L"Delete";
			this->btn_deleteC->UseVisualStyleBackColor = true;
			this->btn_deleteC->Click += gcnew System::EventHandler(this, &MyForm::btn_deleteC_Click);
			// 
			// panel_home
			// 
			this->panel_home->BackColor = System::Drawing::Color::Gold;
			this->panel_home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_home.BackgroundImage")));
			this->panel_home->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel_home->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel_home->Controls->Add(this->label19);
			this->panel_home->Controls->Add(this->label18);
			this->panel_home->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel_home->Location = System::Drawing::Point(184, 71);
			this->panel_home->Name = L"panel_home";
			this->panel_home->Size = System::Drawing::Size(573, 420);
			this->panel_home->TabIndex = 7;
			// 
			// panel_search
			// 
			this->panel_search->BackColor = System::Drawing::Color::Gold;
			this->panel_search->Controls->Add(this->label10);
			this->panel_search->Controls->Add(this->btn_searchC);
			this->panel_search->Controls->Add(this->lbl_NameSearch);
			this->panel_search->Controls->Add(this->txt_listSearch);
			this->panel_search->Controls->Add(this->btn_searchS);
			this->panel_search->Controls->Add(this->txt_search);
			this->panel_search->Controls->Add(this->lbl_searchID);
			this->panel_search->Location = System::Drawing::Point(181, 71);
			this->panel_search->Name = L"panel_search";
			this->panel_search->Size = System::Drawing::Size(573, 420);
			this->panel_search->TabIndex = 8;
			this->panel_search->Visible = false;
			// 
			// btn_searchC
			// 
			this->btn_searchC->Location = System::Drawing::Point(413, 84);
			this->btn_searchC->Name = L"btn_searchC";
			this->btn_searchC->Size = System::Drawing::Size(117, 36);
			this->btn_searchC->TabIndex = 5;
			this->btn_searchC->Text = L"Search Course";
			this->btn_searchC->UseVisualStyleBackColor = true;
			this->btn_searchC->Click += gcnew System::EventHandler(this, &MyForm::btn_searchC_Click);
			// 
			// lbl_NameSearch
			// 
			this->lbl_NameSearch->AutoSize = true;
			this->lbl_NameSearch->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_NameSearch->Location = System::Drawing::Point(181, 140);
			this->lbl_NameSearch->Name = L"lbl_NameSearch";
			this->lbl_NameSearch->Size = System::Drawing::Size(50, 21);
			this->lbl_NameSearch->TabIndex = 4;
			this->lbl_NameSearch->Text = L"Text";
			this->lbl_NameSearch->Visible = false;
			// 
			// txt_listSearch
			// 
			this->txt_listSearch->BackColor = System::Drawing::SystemColors::HighlightText;
			this->txt_listSearch->Location = System::Drawing::Point(185, 203);
			this->txt_listSearch->Multiline = true;
			this->txt_listSearch->Name = L"txt_listSearch";
			this->txt_listSearch->ReadOnly = true;
			this->txt_listSearch->Size = System::Drawing::Size(184, 168);
			this->txt_listSearch->TabIndex = 3;
			this->txt_listSearch->Visible = false;
			// 
			// btn_searchS
			// 
			this->btn_searchS->Location = System::Drawing::Point(413, 84);
			this->btn_searchS->Name = L"btn_searchS";
			this->btn_searchS->Size = System::Drawing::Size(117, 36);
			this->btn_searchS->TabIndex = 2;
			this->btn_searchS->Text = L"Search Student";
			this->btn_searchS->UseVisualStyleBackColor = true;
			this->btn_searchS->Click += gcnew System::EventHandler(this, &MyForm::btn_searchS_Click);
			// 
			// txt_search
			// 
			this->txt_search->Location = System::Drawing::Point(216, 93);
			this->txt_search->Name = L"txt_search";
			this->txt_search->Size = System::Drawing::Size(132, 20);
			this->txt_search->TabIndex = 1;
			// 
			// lbl_searchID
			// 
			this->lbl_searchID->AutoSize = true;
			this->lbl_searchID->Location = System::Drawing::Point(79, 96);
			this->lbl_searchID->Name = L"lbl_searchID";
			this->lbl_searchID->Size = System::Drawing::Size(58, 13);
			this->lbl_searchID->TabIndex = 0;
			this->lbl_searchID->Text = L"ID Student";
			// 
			// panel_unenrolledStudent
			// 
			this->panel_unenrolledStudent->BackColor = System::Drawing::Color::Gold;
			this->panel_unenrolledStudent->Controls->Add(this->label3);
			this->panel_unenrolledStudent->Controls->Add(this->lbl_checkInCourse);
			this->panel_unenrolledStudent->Controls->Add(this->grb_idCourse);
			this->panel_unenrolledStudent->Controls->Add(this->grb_idStudent);
			this->panel_unenrolledStudent->Controls->Add(this->btn_unenroll);
			this->panel_unenrolledStudent->Controls->Add(this->lbl_nameCourse);
			this->panel_unenrolledStudent->Controls->Add(this->lbl_nameStudent);
			this->panel_unenrolledStudent->Location = System::Drawing::Point(181, 71);
			this->panel_unenrolledStudent->Name = L"panel_unenrolledStudent";
			this->panel_unenrolledStudent->Size = System::Drawing::Size(573, 420);
			this->panel_unenrolledStudent->TabIndex = 9;
			this->panel_unenrolledStudent->Visible = false;
			this->panel_unenrolledStudent->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_unenrolledStudent_Paint);
			// 
			// lbl_checkInCourse
			// 
			this->lbl_checkInCourse->AutoSize = true;
			this->lbl_checkInCourse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_checkInCourse->Location = System::Drawing::Point(225, 297);
			this->lbl_checkInCourse->Name = L"lbl_checkInCourse";
			this->lbl_checkInCourse->Size = System::Drawing::Size(51, 13);
			this->lbl_checkInCourse->TabIndex = 11;
			this->lbl_checkInCourse->Text = L"in Course";
			this->lbl_checkInCourse->Visible = false;
			// 
			// grb_idCourse
			// 
			this->grb_idCourse->Controls->Add(this->lbl_unenrollIDCourse);
			this->grb_idCourse->Controls->Add(this->txt_unenrollIDCourse);
			this->grb_idCourse->Controls->Add(this->btn_);
			this->grb_idCourse->Location = System::Drawing::Point(49, 203);
			this->grb_idCourse->Name = L"grb_idCourse";
			this->grb_idCourse->Size = System::Drawing::Size(476, 58);
			this->grb_idCourse->TabIndex = 10;
			this->grb_idCourse->TabStop = false;
			this->grb_idCourse->Text = L"ID Course to UnEnroll";
			this->grb_idCourse->Visible = false;
			// 
			// lbl_unenrollIDCourse
			// 
			this->lbl_unenrollIDCourse->AutoSize = true;
			this->lbl_unenrollIDCourse->Location = System::Drawing::Point(40, 26);
			this->lbl_unenrollIDCourse->Name = L"lbl_unenrollIDCourse";
			this->lbl_unenrollIDCourse->Size = System::Drawing::Size(54, 13);
			this->lbl_unenrollIDCourse->TabIndex = 1;
			this->lbl_unenrollIDCourse->Text = L"ID Course";
			// 
			// txt_unenrollIDCourse
			// 
			this->txt_unenrollIDCourse->Location = System::Drawing::Point(172, 24);
			this->txt_unenrollIDCourse->Name = L"txt_unenrollIDCourse";
			this->txt_unenrollIDCourse->Size = System::Drawing::Size(120, 20);
			this->txt_unenrollIDCourse->TabIndex = 3;
			// 
			// btn_
			// 
			this->btn_->Location = System::Drawing::Point(374, 21);
			this->btn_->Name = L"btn_";
			this->btn_->Size = System::Drawing::Size(75, 23);
			this->btn_->TabIndex = 5;
			this->btn_->Text = L"Check";
			this->btn_->UseVisualStyleBackColor = true;
			this->btn_->Click += gcnew System::EventHandler(this, &MyForm::btn__Click);
			// 
			// grb_idStudent
			// 
			this->grb_idStudent->Controls->Add(this->lbl_unenrollIDStudent);
			this->grb_idStudent->Controls->Add(this->txt_unenrollIDStudent);
			this->grb_idStudent->Controls->Add(this->btn_unrollIDStudent);
			this->grb_idStudent->Location = System::Drawing::Point(49, 122);
			this->grb_idStudent->Name = L"grb_idStudent";
			this->grb_idStudent->Size = System::Drawing::Size(476, 65);
			this->grb_idStudent->TabIndex = 9;
			this->grb_idStudent->TabStop = false;
			this->grb_idStudent->Text = L"ID Student To UnEnroll";
			// 
			// lbl_unenrollIDStudent
			// 
			this->lbl_unenrollIDStudent->AutoSize = true;
			this->lbl_unenrollIDStudent->Location = System::Drawing::Point(40, 33);
			this->lbl_unenrollIDStudent->Name = L"lbl_unenrollIDStudent";
			this->lbl_unenrollIDStudent->Size = System::Drawing::Size(58, 13);
			this->lbl_unenrollIDStudent->TabIndex = 0;
			this->lbl_unenrollIDStudent->Text = L"ID Student";
			// 
			// txt_unenrollIDStudent
			// 
			this->txt_unenrollIDStudent->Location = System::Drawing::Point(172, 30);
			this->txt_unenrollIDStudent->Name = L"txt_unenrollIDStudent";
			this->txt_unenrollIDStudent->Size = System::Drawing::Size(120, 20);
			this->txt_unenrollIDStudent->TabIndex = 2;
			// 
			// btn_unrollIDStudent
			// 
			this->btn_unrollIDStudent->Location = System::Drawing::Point(374, 28);
			this->btn_unrollIDStudent->Name = L"btn_unrollIDStudent";
			this->btn_unrollIDStudent->Size = System::Drawing::Size(75, 23);
			this->btn_unrollIDStudent->TabIndex = 4;
			this->btn_unrollIDStudent->Text = L"Check";
			this->btn_unrollIDStudent->UseVisualStyleBackColor = true;
			this->btn_unrollIDStudent->Click += gcnew System::EventHandler(this, &MyForm::btn_unrollIDStudent_Click);
			// 
			// btn_unenroll
			// 
			this->btn_unenroll->Location = System::Drawing::Point(224, 359);
			this->btn_unenroll->Name = L"btn_unenroll";
			this->btn_unenroll->Size = System::Drawing::Size(75, 23);
			this->btn_unenroll->TabIndex = 8;
			this->btn_unenroll->Text = L"UnEnroll";
			this->btn_unenroll->UseVisualStyleBackColor = true;
			this->btn_unenroll->Visible = false;
			this->btn_unenroll->Click += gcnew System::EventHandler(this, &MyForm::btn_unenroll_Click);
			// 
			// lbl_nameCourse
			// 
			this->lbl_nameCourse->AutoSize = true;
			this->lbl_nameCourse->Font = (gcnew System::Drawing::Font(L"Cooper Black", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nameCourse->Location = System::Drawing::Point(336, 292);
			this->lbl_nameCourse->Name = L"lbl_nameCourse";
			this->lbl_nameCourse->Size = System::Drawing::Size(129, 21);
			this->lbl_nameCourse->TabIndex = 7;
			this->lbl_nameCourse->Text = L"nameCourse";
			this->lbl_nameCourse->Visible = false;
			// 
			// lbl_nameStudent
			// 
			this->lbl_nameStudent->AutoSize = true;
			this->lbl_nameStudent->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nameStudent->Location = System::Drawing::Point(15, 290);
			this->lbl_nameStudent->Name = L"lbl_nameStudent";
			this->lbl_nameStudent->Size = System::Drawing::Size(137, 27);
			this->lbl_nameStudent->TabIndex = 6;
			this->lbl_nameStudent->Text = L"NameStudent";
			this->lbl_nameStudent->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(115, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(341, 40);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Unenroll Student";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(43, 14);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(455, 40);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Search Student / Course";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(147, 32);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(271, 40);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Delete Course";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(147, 41);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(292, 40);
			this->label12->TabIndex = 25;
			this->label12->Text = L"Delete Student";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(183, 32);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(228, 40);
			this->label13->TabIndex = 29;
			this->label13->Text = L"Edit Course";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(166, 27);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(249, 40);
			this->label14->TabIndex = 25;
			this->label14->Text = L"Edit Student";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(54, 37);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(503, 40);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Display Students / Courses";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(189, 54);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(220, 40);
			this->label16->TabIndex = 39;
			this->label16->Text = L"Add Course";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(177, 37);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(241, 40);
			this->label17->TabIndex = 26;
			this->label17->Text = L"Add Student";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Wide Latin", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(25, 30);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(534, 79);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Welcome";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Magneto", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(12, 298);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(540, 88);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Credits:\r\n Mahmoud Mostafa Desoky";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Gold;
			this->ClientSize = System::Drawing::Size(780, 504);
			this->Controls->Add(this->panel_unenrolledStudent);
			this->Controls->Add(this->panel_search);
			this->Controls->Add(this->panel_deleteCourse);
			this->Controls->Add(this->panel_deleteStudent);
			this->Controls->Add(this->panel_editCourse);
			this->Controls->Add(this->panel_editStudent);
			this->Controls->Add(this->panel_displaySC);
			this->Controls->Add(this->panel_addCourse);
			this->Controls->Add(this->panel_addStudent);
			this->Controls->Add(this->panel_home);
			this->Controls->Add(this->title);
			this->Controls->Add(this->panel_buttons);
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Course Mangement System";
			this->panel_addCourse->ResumeLayout(false);
			this->panel_addCourse->PerformLayout();
			this->panel_addStudent->ResumeLayout(false);
			this->panel_addStudent->PerformLayout();
			this->panel_buttons->ResumeLayout(false);
			this->panel_displaySC->ResumeLayout(false);
			this->panel_displaySC->PerformLayout();
			this->panel_editStudent->ResumeLayout(false);
			this->panel_editStudent->PerformLayout();
			this->grb_box->ResumeLayout(false);
			this->grb_box->PerformLayout();
			this->panel_editCourse->ResumeLayout(false);
			this->panel_editCourse->PerformLayout();
			this->grb_editCourse->ResumeLayout(false);
			this->grb_editCourse->PerformLayout();
			this->panel_deleteStudent->ResumeLayout(false);
			this->panel_deleteStudent->PerformLayout();
			this->panel_deleteCourse->ResumeLayout(false);
			this->panel_deleteCourse->PerformLayout();
			this->panel_home->ResumeLayout(false);
			this->panel_home->PerformLayout();
			this->panel_search->ResumeLayout(false);
			this->panel_search->PerformLayout();
			this->panel_unenrolledStudent->ResumeLayout(false);
			this->panel_unenrolledStudent->PerformLayout();
			this->grb_idCourse->ResumeLayout(false);
			this->grb_idCourse->PerformLayout();
			this->grb_idStudent->ResumeLayout(false);
			this->grb_idStudent->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void panel_buttons_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

public: System::Void btn_addSudent_Click(System::Object^  sender, System::EventArgs^  e) {
			panel_addStudent->Visible = true;
			panel_addCourse->Visible = false;
			panel_displaySC->Visible = false;
			panel_editStudent->Visible = false;
			panel_editCourse->Visible = false;
			panel_deleteStudent->Visible = false;
			panel_deleteCourse->Visible = false;
			 panel_addStudent->BringToFront() ;
			 txt_listcourse->Text = "";
			 txt_listcourse->Text = "ID ~ Name Course ~ Instructor Name  \r\n";
			 txt_listcourse->Text += "__________________________________________ \r\n";
			 in.open("Course.txt");
			 for (int i = 0; !in.eof();i++)
			 {
				 in >> displaycourse[i].id;
				 if (displaycourse[i].id == 0)
					 break;
				 getline(in, displaycourse[i].name, ',');
				 getline(in, displaycourse[i].instructorName, ',');
				 in >> displaycourse[i].enrolledStudents;
				 txt_listcourse->Text += displaycourse[i].id + " ~ " + gcnew String(displaycourse[i].name.c_str()) + " ~ " + gcnew String(displaycourse[i].instructorName.c_str()) + "\r\n";
			 }
			 in.close();
			 
}

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 int id_student,id_course;
			 id_student = Convert::ToInt32(txt_ID->Text);
			 id_course = Convert::ToInt32(txt_IdCourse->Text);
			 /*if (id_student <= 0||id_course<=0)
				 //MessageBox("Error\n\nPlease Enter again");
			 else
			 {
				 out.open("Students.txt", ios::app);
				 out << marshal_as<string>(txt_ID->Text) << marshal_as<string>(txt_Name->Text) << "," <<
					 marshal_as<string>(txt_Age->Text) << " " << marshal_as<string>(txt_address->Text) << "\n";
				 out.close();
				 out.open("Enrollments.txt", ios::app);
				 out << marshal_as<string>(txt_IdCourse->Text) << " " << marshal_as<string>(txt_ID->Text) << " "
					 << marshal_as<string>(txt_Grade->Text) << "\n";
				 out.close();
				 MessageBox::Show("Enrolled Successful ", "Add Student");
			 }
			 */
			 panel_addStudent->Visible = false;

			 

}
private: System::Void btn_addCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = true;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_addCourse->BringToFront();
}
private: System::Void btn_subAddCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 out.open("Course.txt", ios::app);
			 out << marshal_as<string>(txt_idNewC->Text) << marshal_as<string>(txt_nameNewC->Text) << ","
				 << marshal_as<string>(txt_instructorNewC->Text) << "," << marshal_as<string>(txt_enrolledStudNewC -> Text)<< "\n";
			 out.close();
			 MessageBox::Show("Enrolled Successful", "Add Course");
			 panel_addCourse->Visible = false;
}
private: System::Void panel_home_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_displaySC->Visible = true;
			 panel_addStudent->Visible = true;
			 panel_addCourse->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_displaySC->BringToFront();
			 txt_display->Text = "";
				  txt_display->Text = "ID ~ Name ~ Age ~ Address \r\n";
				  txt_display->Text += "__________________________________________\r\n";
				  in.open("Students.txt", ios::app);
				  for (int s = 0; !in.eof(); s++)
				  {
					  in >> displaystudent[s].id;
					  if (displaystudent[s].id == 0)
						  break;
					  getline(in, displaystudent[s].name, ',');
					  in >> displaystudent[s].age;
					  getline(in, displaystudent[s].address);
					  txt_display->Text += displaystudent[s].id + " ~ " + gcnew String(displaystudent[s].name.c_str()) + " ~ " + displaystudent[s].age + " ~ " + gcnew String(displaystudent[s].address.c_str()) + "\r\n";
				  }
				  in.close();
	}
private: System::Void btn_displayCourses_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_displaySC->Visible = true;
			 panel_addStudent->Visible = true;
			 panel_addCourse->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_displaySC->BringToFront();
			 txt_display->Text = "";
			 txt_display->Text = "ID ~ Name Course ~ Instructor Name ~ #EnrolledStudents \r\n";
			 txt_display->Text += "_________________________________________________ \r\n";
			 in.open("Course.txt");
			 for (int i = 0; !in.eof(); i++)
			 {
				 in >> displaycourse[i].id;
				 if (displaycourse[i].id == 0)
					 break;
				 getline(in, displaycourse[i].name, ',');
				 getline(in, displaycourse[i].instructorName, ',');
				 in >> displaycourse[i].enrolledStudents;
				 txt_display->Text += displaycourse[i].id + " ~ " + gcnew String(displaycourse[i].name.c_str()) + " ~ " + gcnew String(displaycourse[i].instructorName.c_str()) + " ~ " + displaycourse[i].enrolledStudents + "\r\n";

			 }
			 in.close();
}
public: System::Void btn_editStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 panel_editStudent->Visible = true;
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_editStudent->BringToFront();
			 
			 

}
public: System::Void btn_checkEditStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			in.open("Students.txt");
			student_num = 0;
			while (!in.eof()) {
				in >> student[student_num].id;
				if (student[student_num].id == 0)
					break;
				getline(in, student[student_num].name, ',');
				in >> student[student_num].age;
				getline(in, student[student_num].address);
				student_num+=1;
			}
			in.close();

			
			bool c = false;
			int b;
			 id_edit = Convert::ToInt32(txt_editIdStudent->Text);
			 for (int a = 0; a < student_num; a++)
			 {
				 if (id_edit == student[a].id)
				 {
					 c = true;
					 b = a;
					 break;


				 }
				 else
					 c = false;
			 }
			 if (c == true){
				 lbl->Visible = false;
				 txt_editIdStudent->Visible = false;
				 btn_checkEditStudent->Visible = false;
				 lbl_test->Visible = true;
				 lbl_test->Text = gcnew String(student[b].name.c_str());
				 grb_box->Visible = true;

			 }
			 else
			 {
				 MessageBox::Show("ID Undefined \r\n Enter Again", "Edit Student");
				 txt_editIdStudent->Text = "";
				 lbl_test->Visible = true;
				 lbl_test->Text = "ID Undefinded";
				 grb_box->Visible = false;

			 }

}
private: System::Void btn_submitEdit_Click(System::Object^  sender, System::EventArgs^  e) {
			 out.open("Students.txt");
			 for (int q = 0; q < student_num; q++){
				 if (id_edit == student[q].id)
				 {
					 out << student[q].id << student[q].name << "," << marshal_as<string>(txt_EditAge->Text) << " " << marshal_as<string>(txt_EditAddress->Text) << "\n";
					 continue;
				 }
				 out << student[q].id << student[q].name << "," << student[q].age << student[q].address << "\n";
			 }
			 out.close();
			 MessageBox::Show("Edited Successful", "Edit Student");
			 panel_editStudent->Visible = false;
			 panel_displaySC->Visible = false;
}
private: System::Void btn_editCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_editCourse->Visible = true;
			 panel_addStudent->Visible = true;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_editCourse->BringToFront();

}
public: System::Void btn_checkeditCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 in.open("Course.txt");
			 course_num = 0;
			 while (!in.eof()) {
				 in >> course[course_num].id;
				 if (course[course_num].id == 0)
					 break;
				 getline(in, course[course_num].name, ',');
				 getline(in, course[course_num].instructorName, ',');
				 in >> course[course_num].enrolledStudents;
				 course_num++;
			 }
			 in.close();
			 bool c = false;
			 int b;
			 id_edit = Convert::ToInt32(txt_editIDCourse->Text);
			 for (int a = 0; a < course_num; a++)
			 {
				 if (id_edit == course[a].id)
				 {
					 c = true;
					 b = a;
					 break;
				 }
				 else
					 c = false;
			 }
			 if (c == true){
				 lbl_EdittoidCourse->Visible = false;
				 txt_editIDCourse->Visible = false;
				 btn_checkeditCourse->Visible = false;
				 lbl_checkEditCourse->Visible = true;
				 lbl_checkEditCourse->Text = gcnew String(course[b].name.c_str());
				 grb_editCourse->Visible = true;
			 }
			 else
			 {
				 MessageBox::Show("ID Undefined \r\n Enter Again", "Edit Course");
				 txt_editIDCourse->Text = "";
				 lbl_checkEditCourse->Visible = true;
				 lbl_checkEditCourse->Text = "ID Undefinded";
				 grb_editCourse->Visible = false;
			 }
}
private: System::Void btn_submit_Click(System::Object^  sender, System::EventArgs^  e) {
			 out.open("Course.txt");
			 for (int q = 0; q < course_num; q++){
				 if (id_edit == course[q].id)
				 {
					 out << course[q].id << course[q].name << "," << marshal_as<string>(txt_editInstructor->Text) << "," << marshal_as<string>(txt_editEnrolled->Text) << "\n";
					 continue;
				 }
				 out << course[q].id << course[q].name << "," << course[q].instructorName << "," << course[q].enrolledStudents << "\n";
			 }
			 out.close();
			 MessageBox::Show("Edit Successful", "Edit Course");
			 panel_editCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 
			
}
private: System::Void btn_deleteStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_deleteStudent->Visible = true;
			 panel_addStudent->Visible = true;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_deleteStudent->BringToFront();

}
private: System::Void btn_deleteS_Click(System::Object^  sender, System::EventArgs^  e) {
			 in.open("Students.txt");
			 student_num = 0;
			 enroll_num = 0;
			 while (!in.eof()) {
				 in >> student[student_num].id;
				 if (student[student_num].id == 0)
					 break;
				 getline(in, student[student_num].name, ',');
				 in >> student[student_num].age;
				 getline(in, student[student_num].address);
				 student_num += 1;
			 }
			 in.close();
			 
			 in.open("Enrollments.txt");
			 for (int i = 0; !in.eof(); i++){
				 in >> enrollment[i].courseID;
				 if (enrollment[i].courseID == 0)
					 break;
				 in >> enrollment[i].studentID;
				 in >> enrollment[i].grade;
				 enroll_num+=1;
			 }
			 in.close();

			 id_delete = Convert::ToInt32(txt_deleteIdStudent->Text);
			 out.open("Students.txt");
			 bool c = false;
			 for (int a = 0; a < student_num; a++)
			 {
				 if (id_delete == student[a].id)
				 {
					 c = true;
					 continue;
				 }

				 out << student[a].id << student[a].name << "," << student[a].age << student[a].address << "\n";
			 }
			 out.close();
			 if (c == true){
				 out.open("Enrollments.txt");
				 for (int u = 0; u < enroll_num; u++){
					 if (id_delete == enrollment[u].studentID)
						 continue;
					 out << enrollment[u].courseID << " " << enrollment[u].studentID << " " << enrollment[u].grade << endl;

				 }
				 out.close();
				 MessageBox::Show("Deleted Successful", "Delete Student");
				 panel_deleteStudent->Visible = false;
			 }
			 else 
				 MessageBox::Show("ID is Undefined\r\nEnter Again", "Delete Student");
			 
}
private: System::Void btn_deleteCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_deleteCourse->Visible = true;
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_deleteCourse->BringToFront();
}
private: System::Void btn_deleteC_Click(System::Object^  sender, System::EventArgs^  e) {
			 in.open("Course.txt");
			 course_num = 0;
			 while (!in.eof()) {
				 in >> course[course_num].id;
				 if (course[course_num].id == 0)
					 break;
				 getline(in, course[course_num].name, ',');
				 getline(in, course[course_num].instructorName, ',');
				 in >> course[course_num].enrolledStudents;
				 course_num++;
			 }
			 in.close();

			 in.open("Enrollments.txt");
			 for (int i = 0; !in.eof(); i++){
				 in >> enrollment[i].courseID;
				 if (enrollment[i].courseID == 0)
					 break;
				 in >> enrollment[i].studentID;
				 in >> enrollment[i].grade;
				 enroll_num += 1;
			 }
			 in.close();

			 id_delete = Convert::ToInt32(txt_deleteIdCourse->Text);
			 out.open("Course.txt");
			 bool c = false;
			 for (int p = 0; p < course_num; p++)
			 {
				 if (id_delete == course[p].id)
				 {
					 c = true;
					 continue;
				 }
				 
				 out << course[p].id << course[p].name << "," << course[p].instructorName << "," << course[p].enrolledStudents << "\n";
			 }
			 out.close();
			 if (c == true){
				 out.open("Enrollments.txt");
				 for (int u = 0; u < enroll_num; u++){
					 if (id_delete == enrollment[u].courseID)
						 continue;
					 out << enrollment[u].courseID << " " << enrollment[u].studentID << " " << enrollment[u].grade << endl;
				 }
				 out.close();
				 MessageBox::Show("Deleted Successful", "Delete Course");
				 

				 panel_deleteCourse->Visible = false;
				 panel_displaySC->Visible = false;
			 }
			 else
				 MessageBox::Show("ID is Undefined\r\nEnter Again", "Delete Course");
			 
			 
}
		
private: System::Void btn_searchStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_search->Visible=true;
			 panel_deleteCourse->Visible = false;
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_search->BringToFront();
			 txt_search->Text = "";
			 lbl_NameSearch->Visible = false;
			 txt_listSearch->Visible = false;
			 lbl_searchID->Text = "ID Student";
			 btn_searchS->Visible = true;
			 btn_searchC->Visible = false;

}
private: System::Void btn_searchS_Click(System::Object^  sender, System::EventArgs^  e) {
			 student_num = 0;
			 course_num = 0;
			 enroll_num = 0;
			 loud_course();
			 loud_student();
			 loud_enroll();

			 id_search = Convert::ToInt32(txt_search->Text);
			 bool c = false;
			 int i = 0;
			 for (int u = 0; u < student_num; u++)
			 {
				 if (id_search == student[u].id)
				 {
					 lbl_NameSearch->Visible = true;
					 lbl_NameSearch->Text = gcnew String(student[u].name.c_str());
					 c = true;
					 break;
				 }
				
			 }
			 if (c == false)
			 {
				 MessageBox::Show("UnDefined\r\nPlease Enter Again", "Search Student");
			 }
			 else
			 {
				 txt_listSearch->Visible = true;
				 txt_listSearch->Text = "";
				 txt_listSearch->Text = "Name Course ~ Grade \r\n__________________________\r\n";
				 for (int j = 0; j < enroll_num; j++)
				 {
					 if (id_search == enrollment[j].studentID)
					 {
						 for (int k = 0; k < course_num; k++)
						 {
							 if (enrollment[j].courseID == course[k].id){
								 txt_listSearch->Text += gcnew String(course[k].name.c_str()) + " ~ " + enrollment[j].grade + "\r\n";
								 break;
							 }
						 }
					 }
				 }
			 }
}
private: System::Void btn_searchCourse_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_search->Visible = true;
			 panel_deleteCourse->Visible = false;
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_search->BringToFront();
			 txt_search->Text = "";
			 lbl_NameSearch->Visible = false;
			 txt_listSearch->Visible = false;
			 lbl_searchID->Text = "ID Course";
			 btn_searchS->Visible = false;
			 btn_searchC->Visible = true;
}
private: System::Void btn_searchC_Click(System::Object^  sender, System::EventArgs^  e) {
			 student_num = 0;
			 course_num = 0;
			 enroll_num = 0;
			 loud_course();
			 loud_student();
			 loud_enroll();

			 id_search = Convert::ToInt32(txt_search->Text);
			 bool c = false;
			 int i = 0;
			 for (int u = 0; u < course_num; u++){
				 if (id_search == course[u].id)
				 {
					 lbl_NameSearch->Visible = true;
					 lbl_NameSearch->Text = gcnew String(course[u].name.c_str());
					 c = true;
					 break;
				 }
			 }
			 if (c == false)
			 {
				 MessageBox::Show("UnDefined\r\nPlease Enter Again", "Search Course");
			 }
			 else
			 {
				 txt_listSearch->Visible = true;
				 txt_listSearch->Text = "";
				 txt_listSearch->Text = "Name Student ~ Grade \r\n__________________________\r\n";
				 for (int j = 0; j < enroll_num; j++)
				 {
					 if (id_search == enrollment[j].courseID)
					 {
						 for (int k = 0; k < student_num; k++)
						 {
							 if (enrollment[j].studentID == student[k].id)
							 {
								 txt_listSearch->Text += gcnew String(student[k].name.c_str()) + " ~ " + enrollment[j].grade + "\r\n";
								 break;
							 }

						 }
					 }
				 }
			 }

}
private: System::Void panel_unenrolledStudent_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void btn_unenrollStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel_unenrolledStudent->Visible = true;
			 panel_search->Visible = false;
			 panel_deleteCourse->Visible = false;
			 panel_addStudent->Visible = false;
			 panel_addCourse->Visible = false;
			 panel_displaySC->Visible = false;
			 panel_editStudent->Visible = false;
			 panel_editCourse->Visible = false;
			 panel_deleteStudent->Visible = false;
			 panel_unenrolledStudent->BringToFront();
			 
}
public: System::Void btn_unrollIDStudent_Click(System::Object^  sender, System::EventArgs^  e) {
			student_num = 0;
			course_num = 0;
			enroll_num = 0;
			loud_course();
			loud_student();
			loud_enroll();
			
			idstudent_unenroll = Convert::ToInt32(txt_unenrollIDStudent->Text);
			bool c = false;
			for (int j = 0; j < student_num; j++)
			{
				if (idstudent_unenroll == student[j].id)
				{
					lbl_nameStudent->Visible = true;
					lbl_nameStudent->Text = gcnew String(student[j].name.c_str());
					c = true;
					grb_idCourse->Visible = true;
					break;
				}
			}
			if (c == false)
				MessageBox::Show("UnDefined ID\r\nPlease Enter Again");
}
public: System::Void btn__Click(System::Object^  sender, System::EventArgs^  e) {
			 idcourse_unenroll = Convert::ToInt32(txt_unenrollIDCourse->Text);
			 bool c = false;
			 for (int i = 0; i < course_num; i++)
			 {
				 if (idcourse_unenroll == course[i].id)
				 {
					 lbl_nameCourse->Visible = true;
					 lbl_nameCourse->Text = gcnew String(course[i].name.c_str());
					 c = true;
					 break;
				 }
			 }
			 if (c==false)
				 MessageBox::Show("UnDefined ID\r\nPlease Enter Again");
			 bool found = false;
			 for (int a = 0; a < enroll_num; a++)
			 {
				 if (idstudent_unenroll == enrollment[a].studentID&&idcourse_unenroll == enrollment[a].courseID)
				 {
					 found = true;
					 lbl_checkInCourse->Visible = true;
					 btn_unenroll->Visible = true;
					 lbl_checkInCourse->Text = "in This Course";
				 }
			 }
			 if (found == false)
			 {
				 lbl_checkInCourse->Visible = true;
				 lbl_checkInCourse->Text = "Not in this Course";
				 btn_unenroll->Visible = false;
			 }
}
public: System::Void btn_unenroll_Click(System::Object^  sender, System::EventArgs^  e) {
			out.open("Enrollments.txt");
			for (int i = 0; i < enroll_num; i++)
			{
				if (idstudent_unenroll == enrollment[i].studentID&&idcourse_unenroll == enrollment[i].courseID)
				{
					MessageBox::Show("UnEnrolled Successful", "UnEnrolled Student");
					panel_unenrolledStudent->Visible = false;
					//panel_home->Visible = true;
					//panel_home->BringToFront();
					continue;
				}
				out << enrollment[i].courseID << " " << enrollment[i].studentID << " " << enrollment[i].grade << endl;
			}
			out.close();
}
};
}

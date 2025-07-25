#include<iostream>
#include<vector>  // For Vector Array 
#include<conio.h> // For getch()
#include<fstream> // To store and retrieve data from a file

using namespace std;

struct Appointment
{
string patient_name;
string doctor_name;
string date;
string time;
};

void Delete_Patient(int a);
void Delete_Doctor(int a);
void View_Patient();
void View_Doctor();
void Appointmentset();
void Edit_Patient();
void Edit_Doctor();

int main()
{
 int choice,choice1;
 char password[8];
 char saved_password[8];
 string user_name,saved_username;
 ofstream Signup;
 ifstream Login;
 do
   {
        system("cls");
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|*********************************************|"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|                  1. SignUp                  |"<<endl;
        cout<<"|                  2. Login                   |"<<endl;
        cout<<"|                  3. Exit                    |"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"|*********************************************|"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1: // Signup
        {
            system("cls");
            Signup.open("SignUp.txt");
            cout<<"|----------------------------------------------------------|"<<endl;
            cout<<"|**********************************************************|"<<endl;
            cout<<"|----------------------------------------------------------|"<<endl;
            cout<<"               Enter UserName: ";
            cin.ignore();
            getline(cin, user_name);
            cout << "             Enter 8-character Password: ";
            for (int k=0;k<8;k++)
            {
                password[k]=getch();
                cout<<"*";
            }
            cout<<endl;
            cout<<"|              Signup Successfully                         |"<<endl;
            cout<<"|              Press 'Enter' to Continue                   |"<<endl;
            cout<<"|----------------------------------------------------------|"<<endl;
            cout<<"|**********************************************************|"<<endl;
            cout<<"|----------------------------------------------------------|"<<endl;
            Signup<<user_name<<"\n";
            for (int k=0;k<8;k++)
            {
                Signup<<password[k];
            }
            Signup << endl;
            Signup.close();
            system("pause");
            break;
        }
        case 2: // Login
        {
            system("cls");
            Login.open("SignUp.txt");
            if(!Login)
            {
                cout<<"No data found. Please sign up first!"<<endl;
                system("pause");
                break;
            }
            cout<<"|----------------------------------------------------------|"<<endl;
            cout<<"|**********************************************************|"<<endl;
            cout<<"|----------------------------------------------------------|"<<endl;
            cout << "           Enter your name: ";
            cin.ignore();
            getline(cin, user_name);

            cout << "           Enter your password: ";
	     	for(int i=0;i<8;i++)
	     	   {
	     	   	 password[i]=getch();
	     	   	 cout<<"*";
	           }
            cout << endl;
	     	 getline(Login,saved_username);
	     	 for(int i=0;i<8;i++)
	     	   {
	     	   	 Login>>saved_password[i];
			   }
			 
			 bool pass=true;
			 for(int i=0;i<8;i++)
			   {
			 	 if(password[i]!=saved_password[i])
			 	 {
			 	 pass=false;
			 	 break;
			     }
			   }
			 Login.close();

            if(user_name==saved_username&&pass)
            {
                cout<<"           Login successful!" << endl;
                cout<<"|----------------------------------------------------------|"<<endl;
                cout<<"|**********************************************************|"<<endl;
                cout<<"|----------------------------------------------------------|"<<endl;
                system("pause");
            do
            {
                system("cls");
                cout << "|------------------------------------------------------|" << endl;
                cout << "|******************************************************|" << endl;
                cout << "|------------------------------------------------------|" << endl;
                cout << "|                  1. Add  Patient                     |" << endl;
                cout << "|                  2. Add Doctor                       |" << endl;
                cout << "|                  3. Admin Menu                       |" << endl;
                cout << "|                  4. Back                             |" << endl;
                cout << "|------------------------------------------------------|" << endl;
                cout << "|******************************************************|" << endl;
                cout << "|------------------------------------------------------|" << endl;
                cout << "Enter Your Choice: ";
                cin >> choice1;

                switch (choice1)
                {
                case 1: // To add Patients
                {
                    char ch1;
                    system("cls");
                    int max_patient = 100;
                    string patient_name[max_patient];
                    string patient_disease[max_patient];
                    string blood[max_patient];
                    ofstream patients;
                    int i = 0;
                    int count=0;
                    patients.open("Patients.txt",ios::app);
                    do
                    {
                        if (i >= max_patient)
                        {
                            cout << "The limit to add patients is reached." << endl;
                            break;
                        }
                        cin.ignore();
                        cout << "Enter patient Name: ";
                        getline(cin, patient_name[i]);
                        cout << "Enter patient disease: ";
                        getline(cin, patient_disease[i]);
                        cout<<"Enter Patient Blood Group: ";
                        getline(cin,blood[i]);
                        i++;
                        cout << "Do you want to add more patients (Y/N): ";
                        cin >> ch1;
                    } while (ch1 == 'Y' || ch1 == 'y');

                    for (int j=0;j<i;j++)
                    {
                        patients<<patient_name[j]<<" "<<patient_disease[j]<<" "<<blood[j]<<endl;
                        count++;
                    }
                    if(patients)
                    {
                     cout<<"Patient data is successfully saved to file."<<endl;
                    }
                    patients.close();
                    system("pause");
                    break;
                }
                case 2: // To add Doctors
                {
                    char ch2;
                    system("cls");
                    int max_doctor = 100;
                    string doctor[max_doctor];
                    string speciality[max_doctor];
                    ofstream doctors;
                    int d=0;
                    doctors.open("Doctor.txt",ios::app);
                    do
                    {
                        if(d>=max_doctor)
                        {
                         cout<<"The limit to add doctors is reached."<<endl;
                         break;
                        }
                     cin.ignore();
                     cout<<"Enter Doctor Name: ";
                     getline(cin,doctor[d]);
                     cout<<"Enter The Doctor Type: ";
                     getline(cin, speciality[d]);
                     d++;
                     cout<<"Do you want to add more? (Y/N): ";
                     cin>>ch2;
                    } 
					while(ch2=='Y' || ch2=='y');

                    for(int j=0;j<d;j++)
                    {
                     doctors<<doctor[j]<<" "<<speciality[j]<<endl;
                    }
                    if(doctors)
                    {
                     cout<<"Your data is successfully saved to file."<<endl;
                    }
                    doctors.close();
                    system("pause");
                    break;
                }

                case 3: // Provide more Menus
                {
                	ifstream save_pat;
                	int choice2;
                	do
                   {
					 system("cls");
                	   cout<<"|----------------------------------------------------|"<<endl;
                     cout<<"|****************************************************|"<<endl;
                     cout<<"|----------------------------------------------------|"<<endl;
                     cout<<"|              1. View Patients Records              |"<<endl;
                     cout<<"|              2. View Doctors Records               |"<<endl;
                     cout<<"|              3. Delete Patient Record              |"<<endl;
                     cout<<"|              4. Delete Doctor Record               |"<<endl;
                     cout<<"|              5. Appointment                        |"<<endl;
                     cout<<"|              6. Edit Patient Record                |"<<endl;
                     cout<<"|              7. Edit Doctor Record                 |"<<endl;
                     cout<<"|              8. Back                               |"<<endl;
                     cout<<"|----------------------------------------------------|"<<endl;
                     cout<<"|****************************************************|"<<endl;
                     cout<<"|----------------------------------------------------|"<<endl;
                     cout<<"Enter Your Choice: ";
                     cin>>choice2;
                     switch(choice2)
                       {
                         case 1: // To show All stored patients records at current time
					       {
					          View_Patient();
                              break;
						   }
						 case 2:  // To show all stored Doctors records at current time
						   {
						   	 View_Doctor();
						   	 break;
						   }
						 case 3: // Update or Delete Patient Record
						   {
						   	 system("cls");
						   	 ifstream record_patient;
						   	 record_patient.open("Patients.txt");
						   	 if(!record_patient)
						   	   {
						   	   	 cout<<"No patient Record Found!\nPlease Enter Patient Record First."<<endl;
						   	   	 system("pause");
						   	   	 break;
							   }
						   	 string line;
						   	 int record_num=1;
						   	 cout<<"|-------------List Of Patients---------------|"<<endl;
						   	 while(getline(record_patient,line))
						   	   {
						   	   	 cout<<record_num<<". "<<line<<endl;
							     record_num++; 
							   }
							 record_patient.close();
							 if(record_num==1)
							   {
							   	 cout<<"No patient record available to Delete!"<<endl;
							   	 system("pause");
							   	 break;
							   }
							 int delete_pat;
							 cout<<"Enter the patient record number to delete: ";
							 cin>>delete_pat;
							 Delete_Patient(delete_pat);
							   
							 break;
						   }
						 case 4: // Update or Delete Doctor Records
						   {
						   	 system("cls");
							 ifstream record_doctor;
							 record_doctor.open("Doctor.txt");
							 if(!record_doctor)
						   	  {
						   	   	 cout<<"No Doctor Record Found!\nPlease Enter Doctor Record First.";
						   	   	 system("pause");
						   	   	 break;
							    }
							 string line;
						   	 int record_num=1;
						   	 cout<<"|-------------List Of Doctors---------------|"<<endl;
						   	 while(getline(record_doctor,line))
						   	 {
						   	   cout<<record_num<<". "<<line<<endl;
								   record_num++;	   	 
							   }
							 record_doctor.close();
							 if(record_num==1)
							   {
							   	 cout<<"No doctor record available to Delete!"<<endl;
							   	 system("pause");
							   	 break;
							   }
						     int delete_doc;
							 cout<<"Enter the doctor number to delete: ";
							 cin>>delete_doc;
							 Delete_Doctor(delete_doc);  
							 break;
						   }
             case 5:  //Appointment
               {
              	 Appointmentset();
                 break;
               }
             case 6:
               {
               	 Edit_Patient();
               	 break;
			         }
             case 7:
              {
                Edit_Doctor();
              }
					   }
				   }
					while(choice2!=8);
					
					break; 
				}
	
				
                case 4: // Back
                {
                	cout<<"Exiting Menu..."<<endl;
                    break;
                }
                default:
                    cout<<"Invalid choice!"<<endl;
                }
            }
            while(choice1!=4);
            }
            else
            {
                cout<<"|              Wrong Username or Password!                 |"<<endl;
                cout<<"|----------------------------------------------------------|"<<endl;
                cout<<"|**********************************************************|"<<endl;
                cout<<"|----------------------------------------------------------|"<<endl;
                getchar();
            }
            break;
        }
        case 3: // Exit
        {
            cout<<"Exiting Program..."<<endl;
            break;
        }
        default:
            cout<<"Invalid choice! Please try again."<<endl;
            system("pause");
        }
   }
    while(choice!=3);

return 0;
}

void View_Patient()
{
system("cls");
ifstream s_pat;
s_pat.open("Patients.txt");
if(!s_pat)
{
cout<<"No data Found!\nPlease Add Patients Record First....\n";
system("pause");
return;
}
string line;
int n=1;
cout<<"|-------------List Of Patients---------------|"<<endl;
while(getline(s_pat,line))
{ 
cout<<n<<" "<<line<<endl;
n++;
}
s_pat.close();
system("pause");
}

void View_Doctor()
{
system("cls");
ifstream save_doc;
save_doc.open("Doctor.txt");
if(!save_doc)
{
cout<<"No data Found!\nPlease Add Doctors Record First....\n";
system("pause");
return;
}
string line;
int n=1;
cout<<"|-------------List Of Doctors---------------|"<<endl;
while(getline(save_doc,line))
{
cout<<n<<". "<<line<<endl;
n++;
}
system("pause");
}


void Delete_Patient(int a)
{
ifstream infile("Patients.txt");
ofstream temp("Temp.txt");
int record_n=1;
string l;
while(getline(infile,l))
   {
	 if(record_n!=a)
	   {
		 temp<<l<<endl;
	   }
	 record_n++;
   }
infile.close();
temp.close();
remove("Patients.txt");
rename("Temp.txt","Patients.txt");
cout<<"Update Delete Data Successfully!"<<endl;
							 
system("pause");							 	
}

void Delete_Doctor(int a)
{
ifstream infile;
infile.open("Doctor.txt");
ofstream temp("Temp.txt");
int record_n=1;
string l;
while(getline(infile,l))
   {
	 if(record_n!=a)
	   {
		 temp<<l<<endl;
	   }
	 record_n++;
   }
infile.close();
temp.close();
remove("Doctor.txt");
rename("Temp.txt","Doctor.txt");
cout<<"Update Delete Data Successfully!"<<endl;
							 
system("pause");
		
}

void Edit_Patient()
{
system("cls");
ifstream infile;
infile.open("Patients.txt");
vector<string> record_p;
string line;
int record_n=1;
while(getline(infile,line))
   {
     cout<<record_n<<". "<<line<<endl;
     record_p.push_back(line);
     record_n++;
   }
infile.close();
if(record_p.empty())
   {
  	 cout<<"No record to edit."<<endl;
  	 system("pause");
  	 return;
   }
int n;
cout<<"Enter the patient record number to edit: ";
cin>>n;
string new_name,new_disease,new_blood;
cout<<"Enter new Pateint name: ";
cin.ignore();
getline(cin,new_name);
cout<<"Enter new Pateint disease: ";
getline(cin,new_disease);
cout<<"Enter new Pateint blood: ";
getline(cin,new_blood);

record_p[n-1]=new_name+" "+new_disease+" "+new_blood;

ofstream outfile;
outfile.open("Temp.txt");
for(const auto& record: record_p)
   {
   	 outfile<<record<<endl;
   }
outfile.close();

remove("Patients.txt");
rename("Temp.txt","Patients.txt");
system("pause");
}


void Edit_Doctor()
{
system("cls");
ifstream infile;
infile.open("Doctor.txt");
vector<string> record_d;
string line;
int record_n=1;
while(getline(infile,line))
   {
     cout<<record_n<<". "<<line<<endl;
     record_d.push_back(line);
     record_n++;
   }
infile.close();
if(record_d.empty())
   {
  	 cout<<"No record to edit."<<endl;
  	 system("pause");
  	 return;
   }
int n;
cout<<"Enter the patient record number to edit: ";
cin>>n;
string new_name,new_special;
cout<<"Enter new Doctor name: ";
cin.ignore();
getline(cin,new_name);
cout<<"Enter new Doctor Speciality: ";
getline(cin,new_special);

record_d[n-1]=new_name+" "+new_special;

ofstream outfile;
outfile.open("Temp.txt");
for(const auto& record: record_d)
   {
   	 outfile<<record<<endl;
   }
outfile.close();

remove("Doctor.txt");
rename("Temp.txt","Doctor.txt");
system("pause");
}

void Appointmentset()
{
system("cls");
ofstream AppointmentFile;
vector<Appointment> appointment;
Appointment newappointment;
AppointmentFile.open("Appointment.txt",ios::app);
cout<<"Enter the name of the Patient: ";
cin.ignore();
getline(cin,newappointment.patient_name);
cout<<"Enter the name of the Doctor: ";
cin.ignore();
getline(cin,newappointment.doctor_name);
cout<<"Enter the date [YYYY MM DD]: ";
cin.ignore();
getline(cin,newappointment.date);	
cout<<"Enter the time [HH MM]: ";
cin.ignore();
getline(cin,newappointment.time);
AppointmentFile<<newappointment.patient_name<<", "<<newappointment.doctor_name<<", "<<newappointment.date<<", "<<newappointment.time<<endl;
appointment.push_back(newappointment);
AppointmentFile.close();
}
#include <iostream>
using namespace std;

void addStudent (int ID[],string StudentName[],int Age[],int &counter ){

    cout<<"Enter Student ID : ";

    int tmp;
    cin>>tmp;
    for (int i=0;i<counter;i++){
        if (tmp==ID[i]){
            cout<<"This ID Is Already Registerd\n========================\n";
            return ;
        }
    }
    
    ID[counter]=tmp;

    cout<<"Enter Student Name : ";
    cin.ignore(100,'\n'); 
    getline (cin,StudentName[counter]);

    cout<<"Enter Student Age : ";
    cin>>Age[counter];
    cout<<"Student Added Successfully!\n===========================\n";
    cout<<'\n';


    counter++;

}

void ShowAll(int counter,int ID[],string StudentName[],int Age[],int Average[],int status[]){

    cout<<"============ All Students ============\n";

    for (int i=0;i<counter;i++){
        cout<<"ID : "<<ID[i]<<" | "<<StudentName[i]<<" | "<<"Age : "<<Age[i];

        if (status[i]!=-1){  
        cout<<" | "<<"Average : "<<Average[i]<<" | ";
        if (status[i]){
            cout<<"Passed";
        }
        else cout<<"Failed";
    }
        cout<<'\n';
    }

    cout<<"======================================\n";
    cout<<'\n';

}

void SearchFor(int ID[],int counter,string studentName[],int average[],int status[]){

    int tmp;
    cout<<"Enter ID : ";
    cin>>tmp;
    bool found=0;

    for (int i=0;i<counter;i++){
        if (tmp==ID[i]){
            tmp=i;
            found=1;
        }
    }
    if (!found){
        cout<<"Incorrect ID \n";
        return ;
    }

    cout<<"Student Found ! \n===================\n";
    cout<<"ID : "<<ID[tmp]<<"\nStudent Name : "<<studentName[tmp];

    if (status[tmp]!=-1){ 

    cout<<"\nHas Average : "<<average[tmp]<<" | ";

    if (status[tmp]){
        cout<<"Passed";
    }
    else cout<<"Failed";
    }
    cout<<"\n====================\n";
    cout<<'\n';

}


void enterGrades (int ID[],int MathGrade[],int DBGrade[],int ProgGrade[],int status[],int counter,int Average[]){

    int tmp;
    cout<<"Enter Student ID : ";
    cin>>tmp;
    bool found=0;

    for (int i=0;i<counter;i++){
        if (tmp==ID[i]){
            tmp=i;
            found=1;
        }

    }

    if (!found){
        cout<<"ID Not Found\n============\n ";
        return ;
    }

    if (status[tmp]!=-1){  
        cout<<"The Grades have Already been added\n";
        return ;
    }

    status[tmp]=1; 

    cout<<"Enter Programing Grade : ";
    cin>>ProgGrade[tmp];

    while (ProgGrade[tmp]>100||ProgGrade[tmp]<0){ 
        cout<<"Error , Grade Must Be Between 0-100 , Re-Enter The Grade Again \n";
        cin>>ProgGrade[tmp];
    }

    if (ProgGrade[tmp]<50){
        status[tmp]=0;
    }

    cout<<"Enter DataBase Grade : ";
    cin>>DBGrade[tmp];

    while (DBGrade[tmp]>100||DBGrade[tmp]<0){ 
        cout<<"Error , Grade Must Be Between 0-100 , Re-Enter The Grade Again \n";
        cin>>DBGrade[tmp];
    }

    if (DBGrade[tmp]<50){
        status[tmp]=0;
    }

    cout<<"Enter Math Grade : ";
    cin>>MathGrade[tmp];

    while (MathGrade[tmp]>100||MathGrade[tmp]<0){ 
        cout<<"Error , Grade Must Be Between 0-100 , Re-Enter The Grade Again \n";
        cin>>MathGrade[tmp];
    }

    if (MathGrade[tmp]<50){
        status[tmp]=0;
    }

    Average[tmp]=(ProgGrade[tmp]+DBGrade[tmp]+MathGrade[tmp])/3;

    cout<<"Grades Added Successfully !\n===========================\n";
    cout<<'\n';

}

void calculateAverage(int ID[],int ProgGrade[],int DBGrade[],int MathGrade[],int Average[],int counter){

  int targetID;
  cout<<"Enter Student ID : ";
  cin>>targetID;

  bool found=false;
  int index;

  for(int i=0;i<counter;i++){
     if(ID[i]==targetID){
        found=true;
        index=i;
        break;
     }
  }

  if(!found){
      cout<<"Student ID Not found";
      return;
  }

  cout << "Programming: " << ProgGrade[index] << endl;
    cout << "Database: " << DBGrade[index] << endl;
    cout << "Mathematics: " << MathGrade[index] << endl;
    cout << "Average: " << Average[index] << endl;  
    cout<<"=============================\n";
    cout<<'\n';

}

void determinePassFail(int ID[],int status[],int counter) {

    int targetID;
    cout << "Enter Student ID : ";
    cin >> targetID;
    int foundIndex = -1;

    for (int i = 0; i < counter; i++) {

    if (ID[i] == targetID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {

        if (status[foundIndex]==-1){ 
        cout<<"You Must Enter Grades For This Student First \n";
        }

        else if (status[foundIndex] == 1){
            cout << "Student Status: Passed" << endl;
        } 

        else {
            cout << "Student Status: Failed" << endl;
        }

    } 

    else {
        cout << "Student ID not found " << endl; 
    }

    cout<<"======================\n";
    cout<<'\n';

}

void showTopstudent (int counter,int iD[],string name[],int average[],int status[]){

    if (counter==0){
    cout << "There are no students in the system\n";
    return;
    }

    int topIndix=-1;
    for (int i=0; i<counter;i++){

    if (status[i]!=-1) 

        if (average[i]>average[topIndix])
            topIndix = i;
    }

    if (topIndix!=-1){

       cout << "======== TOP STUDENT ========\n";
       cout << "Student ID: " << iD[topIndix] << "\n";
       cout << "Name: " << name[topIndix] << "\n";
       cout << "Average: " << average[topIndix] << "\n";
       cout << "=============================\n";}

       else cout<<"There is No top student Yet\n============================\n";

       cout<<'\n';

}

void showPassedStudents(int counter, int ID[], string name[], int average[],int status[]){

    cout<<"============ Passed Students ============\n";

    for (int i = 0; i < counter; i++)
    {
        if (average[i] >= 50&& status[i] ){

            cout << "Student ID: " << ID[i] << "\n";
            cout << "Name: " << name[i] << "\n";
            cout << "Average: " << average[i] << "\n";
            cout << "-------------------\n";
        }
    }

    cout<<"=========================================\n";
    cout<<'\n';

}


int main(){

    int counter=0;
    int ID[1000]; 
    string StudentName[1000];
    int Age[1000];
    int ProgGrade[1000];
    int DBGrade [1000];
    int MathGrade[1000];
    int Average[1000];
    int status[1000];  
    for (int i=0;i<1000;i++){
        status[i]=-1; 
    }

    cout<<"Welcome In Student Mangment System \n";

    while (true){

        int diss;
        cout<<"Choose From The Following \n1-Add Student\n2-Show All Students\n3-Search For Students\n4-Enter Grades\n5-Calculate Average\n6-Determine Pass / Fail\n7-Show Top Students\n8-Show Passed Students\n9-Exit\nChoice --> : ";
        cin>>diss;
        cout<<'\n';

        switch (diss){
            case 1:  addStudent(ID,StudentName,Age,counter); break;
            case 2:  ShowAll(counter,ID,StudentName,Age,Average,status); break;
            case 3:  SearchFor(ID,counter,StudentName,Average,status); break;
            case 4:  enterGrades(ID,MathGrade,DBGrade,ProgGrade,status,counter,Average); break;
            case 5:  calculateAverage(ID,ProgGrade,DBGrade,MathGrade,Average,counter); break;
            case 6:  determinePassFail(ID,status,counter); break;
            case 7:  showTopstudent(counter,ID,StudentName,Average,status); break;
            case 8:  showPassedStudents(counter,ID,StudentName,Average,status); break;
            case 9:  cout<<"Thank you for using Student Management System! \n==============================================\n";
            return 0; 

            default : cout<<"Erorr : Enter Numbers Only From (1-9) From The List \n"; break;

        }

    }

}

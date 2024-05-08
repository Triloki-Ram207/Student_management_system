#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;
int ID;             // To keep the account of how many students' data has been entered
class student       // creating student class
{
    public :
        int id;
        string name;
        int age;
        string course;

    void addStudent()                 // To add a new student
    {
        cin.ignore();                 // Clearing buffer
        cout<<"Enter name:";
        getline(cin,name);            // Taking name of student
        cout<<"Enter age:";
        cin>>age;                     //Taking age of student
        cout<<"Enter course:";
        cin>>course;                  // Taking stream of student
        ID++;
        ofstream fout;
        fout.open("E:/file/student.txt",ios::app);  //Opening file for writing into student.txt
        if(!fout)
        {
            cout<<"File not found"<<endl;
            return;
        }
        fout<<ID<<"\n";                //Writing data into the file
        fout<<name<<"\n";
        fout<<age<<"\n";
        fout<<course<<"\n";
        fout.close();

        fout.open("E:/file/id.txt",ios::app); //Opening file for writing in id.txt file
        fout<<ID<<"\n";
        fout.close();
        //system("cls");
        cout<<endl<<"Record Added Successfully"<<endl;
    }
     void get_data(ifstream &fin)
    {
        fin>>id;
        fin.ignore();
        getline(fin,name);
        fin>>age;
        fin>>course;
    }
    void printAllStudent()
    {
        int flag=0;
        ifstream fin;
        fin.open("E:/file/student.txt");
        if(!fin)
        {
            cout<<"File not found OR file not created"<<endl;
            return;
        }
      get_data(fin);
          while(!fin.eof())
        {
            flag=1;
            print();
            get_data(fin);
        }
        fin.close();
        if(flag==0)
            cout<<"File is Empty"<<endl;
    }
    void print()
    {
        cout<<" ID= "<<id<<endl;
        cout<<" Name= "<<name<<endl;
        cout<<" Age= "<<age<<endl;
        cout<<" course= "<<course<<endl;
        cout<<"__________________________"<<endl<<endl;
    }

    void searchStudent(int id)         //To search record of a student
    {
        //system("cls");
        ifstream fin;
        fin.open("E:/file/student.txt");
        get_data(fin);
        while(!fin.eof())
        {
           if(this->id==id)
           {
               cout<<"Record found:"<<endl<<endl;
               print();
               return;
           }
           get_data(fin);
        }
        //system("cls");
        cout<<"Record not found"<<endl;
        fin.close();
    }
    void deleteStudent(int id)         //Deleting record a student
    {
        ifstream fin;
        fin.open("E:/file/student.txt",ios::in);

        ofstream fout;
        fout.open("E:/file/temp.txt",ios::app);
        if(!fout)
        {
           cout<<"File not created"<<endl;
           return;
        }
        get_data(fin);
        while(!fin.eof())
         {
           if(this->id!= id)
           {
            fout<<this->id<<"\n";
            fout<<name<<"\n";
            fout<<age<<"\n";
            fout<<course<<"\n";
           }
           get_data(fin);
        }
        fin.close();
        fout.close();
        remove("E:/file/student.txt");
        rename("E:/file/temp.txt","E:/file/student.txt");
        //system("cls");
        cout<<"Record Deleted Successfully"<<endl<<endl;
    }
     void updateStudent(int id)                //Updating records of an existing student
     {
         int flag=0;
        ifstream fin;
        fin.open("E:/file/student.txt");

        ofstream fout;
        fout.open("E:/file/temp.txt",ios::app);
        if(!fout)
        {
           cout<<"File not created"<<endl;
           return;
        }
        get_data(fin);
        while(!fin.eof())
         {
           if(this->id!= id)
           {
            fout<<this->id<<"\n";
            fout<<name<<"\n";
            fout<<age<<"\n";
            fout<<course<<"\n";
           }
           else
           {
               flag=1;
               cin.ignore();
               cout<<"Enter name:";
               getline(cin,name);
               cout<<endl;
               cout<<"Enter age:";
               cin>>age;
               cout<<endl;
               cout<<"Enter course:";
               cin>>course;
               cout<<endl;
                fout<<id<<"\n";
                fout<<name<<"\n";
                fout<<age<<"\n";
                fout<<course<<"\n";
           }
           get_data(fin);
        }
        if(flag==0)
        {
               cin.ignore();
               cout<<"Enter name:";
               getline(cin,name);
               cout<<endl;
               cout<<"Enter age:";
               cin>>age;
               cout<<endl;
               cout<<"Enter course:";
               cin>>course;
               cout<<endl;
               fout<<id<<"\n";
               fout<<name<<"\n";
               fout<<age<<"\n";
               fout<<course<<"\n";
        }
        fin.close();
        fout.close();
        remove("E:/file/student.txt");
        rename("E:/file/temp.txt","E:/file/student.txt");
        //system("cls");
        cout<<"Record updated Successfully"<<endl<<endl;
     }

};
int main()                              //Driver code
{
    int flag=0;
   int choice;
   ifstream fin;                       // creating ifstream object to read from a file
   ofstream fout;                      // creating ofstream object to write into a file
   fin.open("E:/file/id.txt",ios::in); // open file in reading mode

   if(!fin)                           // checking whether file exists or not
   {
       cout<<"File Not Found"<<endl;
       fout.open("E:/file/id.txt",ios::app);   // creating file if it does not exits
       if(!fout)
       {
           cout<<"File not created"<<endl;
       }
       else
       {
           cout<<"File created successfully"<<endl;
           flag=1;
           fout.close();
       }
       }
    if(flag==0)
     while(!fin.eof())
     {
       fin>>ID;        //Updating the last value of ID to proceed further
     }
   fin.close();
   cout<<"ID = "<<ID<<endl;  //It will show current id(how many records have been stored)
   while(1)
   {
       cout<<"---------------------------"<<endl;
       cout<<"Student Management System |"<<endl;
       cout<<"---------------------------"<<endl;
       cout<<"1. Add Student            |"<<endl;
       cout<<"2. Print all the students |"<<endl;
       cout<<"3. Search a student       |"<<endl;
       cout<<"4. Update a student       |"<<endl;
       cout<<"5. Delete a student       |"<<endl;
       cout<<"6. Exit                   |"<<endl;
       cout<<"__________________________|"<<endl<<endl;
       cout<<"Enter Your choice:";
       cin>>choice;
        cout<<endl;     //Accepting user choice
       student s;
       int id;
       //system("cls"); // to clear screen
       switch(choice)
       {
           case 1 :
                    s.addStudent();
                    break;
           case 2 :
                    s.printAllStudent();
                    break;
           case 3 :
                    cout<<"Enter student id:";
                    cin>>id;
                    s.searchStudent(id);
                    break;

           case 4 :
                    cout<<"Enter student id:";
                    cin>>id;
                    s.updateStudent(id);
                    break;

           case 5 :
                    cout<<"Enter student id:";
                    cin>>id;
                    s.deleteStudent(id);
                    break;
           case 6:
                exit(0);
           default :
               cout<<"Invalid choice"<<endl;
       }
   }
   return 0;
}


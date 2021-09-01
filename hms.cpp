                                                             CODE
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
class patient
{
     public:
     int  year,date,month;
     int bno;
     char na[20],city[20],street[20],sex[20];
     patient()
      {
             bno=0;
             year=0;
             date=0;
             month=0;
             strcpy(na,NULL);
             strcpy(city,NULL);
             strcpy(street,NULL);
             strcpy(sex,NULL);
      }
    void enterdata()
     {
             cout<<"\nENTER THE NAME OF THE PATIENT \t\t-----\t\t";gets(na);
             cout<<"\nENTER GENDER\t\t\t\t-----\t\t";gets(sex);
             cout<<"\nASSIGN A UNIQUE BED NO. \t\t-----\t\t"; cin>>bno;
             cout<<"\nDATE OF BIRTH\nDATE  \t\t\t\t\t-----\t\t";cin>>date;
             cout<<"\nMONTH  \t\t\t\t\t-----\t\t";cin>>month;
             cout<<"\nYEAR  \t\t\t\t\t-----\t\t";cin>>year;
             cout<<"\nENTER STREET  \t\t\t\t-----\t\t";gets(street);
             cout<<"\nENTER CITY  \t\t\t\t-----\t\t";gets(city);

     }


    void showdata()
     {
       clrscr();
       cout<<" \t\t\tINFORMATION OF THE PATIENT\n";
       for(int vg=0;vg<78;vg++)
             cout<<"-";
       cout<<"\n";
       for(vg=0;vg<78;vg++)
             cout<<"-";
       cout<<"\n\n\t\t\tBED NO \t\t:-\t"<<bno;
       cout<<"\n\n\t\t\tNAME   \t\t:-\t"<<na;
       cout<<"\n\n\t\t\tGENDER \t\t:-\t"<<sex;
       cout<<"\n\n\t\t\tSTREET \t\t:-\t"<<street;
       cout<<"\n\n\t\t\tCITY   \t\t:-\t"<<city;
     }

            ~patient()
              {
                bno=0;
                year=0000;
                date=00;
                month=00;
                strcpy(na,NULL);
                strcpy(city,NULL);
                strcpy(street,NULL);
                strcpy(sex,NULL);
              }


};

  void main()
  {
    patient p,p1;
    char ch,cna[20];
    xy:
    do
      {
            ofstream ofile;
            ofile.open("file1.dat",ios::app|ios::binary);
            ifstream ifile;
            ifile.open("file1.dat",ios::in|ios::binary);
            ofstream temp;
            temp.open("temp1.dat",ios::app|ios::binary);
            clrscr();
            cout<<"\n\t\t\t***HOSPITAL MANAGEMENT SOFTWARE***"<<"\n";
            cout<<"\n\t\t\t  **Hospital Management Tasks**"<<"\n\n";
            for(int st=0;st<80;st++)
              cout<<"-";
            for(st=0;st<80;st++)
              cout<<"|";
            for(st=0;st<80;st++)
              cout<<"-";
            cout<<"\n\n";
            cout<<"\t\t\tPlease  select a task to do...."<<"\n\n";
            cout<<"\t\t\t1. Enter a new patient information ."<<"\n\n";
            cout<<"\t\t\t2. View detail of existing patient ."<<"\n\n";
            cout<<"\t\t\t3. Emergency"<<"\n\n";
            cout<<"\t\t\t4. Discharge patient"<<"\n\n";
            cout<<"\t\t\t5. Exit from the program ."<<"\n\n";
            cout<<"\t\t\t6.ADMIN MODE"<<"\n\n";
            cout<<"\t\t\tEnter your task serial :"<<"\n\n\t\t\t";
            ch=getche();
            switch(ch)
             {
               case '1': clrscr();
                  p.enterdata();
                  ofile.write((char*)&p,sizeof(p));
                  getch();
                  break;
               case '2':
                  clrscr();
                  int k=0,cbno=0;
                  if(!ifile)
                        {
                          cout<<"\n unable to open file\n";
                          getch();
                        }
                        else
                        {
                          cout<<"\n ENTER THE NAME OF PATIENT\t\t\t-----\t\t";gets(cna);
                          cout<<"\n ENTER BED NUMBER\t\t\t\t-----\t\t";cin>>cbno;
                          ifile.clear();
                          ifile.seekg(0,ios::beg);
                          while(!ifile.eof())
                           {
                             ifile.read((char*)&p,sizeof(p));
                             if(cbno==p.bno)
                              {
                                     if(strcmpi(cna,p.na)==0)
                                       {
                                         p.showdata();
                                         getch();
                                         k=1;
                                         break;
                                       }
                              }
                           }
                          if(k!=1)
                          cout<<"\n NO SUCH RECORD PRESENT\n";
                          getch();
                        }
                  ifile.close();
                  temp.close();
                  break;
               case '3':
                  clrscr();
                  temp.clear();
                  temp.seekp(0,ios::beg);
                  ifile.clear();
                  ifile.seekg(0,ios::beg);
                  p.enterdata();
                  temp.write((char*)&p,sizeof(p));
                  while(!ifile.eof())
                        {
                          ifile.read((char*)&p,sizeof(p));
                          temp.write((char*)&p,sizeof(p));
                        }
                  ifile.close();
                  temp.close();
                  remove("file1.dat");
                  rename("temp1.dat","file1.dat");
                  break;

               case '4' : clrscr();
                              char choice;
                              int check=0;
                              cout<<"\n\n ENTER THE NAME OF THE PATIENT : ";
                              gets(cna);
                              cout<<"\n\n ENTER THE BED NO. :";
                              cin>>cbno;
                              temp.clear();
                              temp.seekp(0,ios::beg);
                              ifile.clear();
                              ifile.seekg(0,ios::beg);
                              while(!ifile.eof())
                              {
                                     ifile.read((char*)&p1,sizeof(p1));
                                     if(strcmpi(cna,p1.na)==0&&cbno==p1.bno)
                                       { err:  check=1;
                                         p1.showdata();
cout<<"\n\n\t!!!!!ARE YOU SURE TO DELETE THE FOLLOWING RECORD ?(y/n)!!!!!\n\t     ";
                                         choice=getche();
                                         if(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                                          {
                                           cout<<"\n\t!!!!!WRONG CHOICE!!!!! \n";getch();
                                           goto err;
                                          }
                                         if(choice=='n'||choice=='N')
                                          temp.write((char*)&p1,sizeof(p1));

                                       }
                                     else
                                       {
                                         temp.write((char*)&p1,sizeof(p1));
                                       }
                              }
                              if(check==0)
                               {
                                      cout<<"\n\nt!!!!! NO SUCH RECORD PRESENT !!!!! ";
                                      getch();
                               }
                              ifile.close();
                              temp.close();
                              remove("file1.dat");
                              rename("temp1.dat","file1.dat");
                              break;
               case '5':
                            break;


               case '6':
                 char id[5];
                 clrscr();
                 cout<<"\n ENTER THE ADMIN ID\t\t----    ";
                 gets(id);
                 if(strcmp(id,"70176")==0)
                  {
                        cout<<"\n\n\n\t\t\t VERIFICATION SUCCESSFUL ";
                        getch();
                        if(!ifile)
                         {
                            cout<<"unable to open file";
                            getch();
                         }
                         else
                         {
                           ifile.clear();
                           ifile.seekg(0,ios::beg);
                            while(!ifile.eof())
                              {
                                    ifile.read((char*)&p1,sizeof(p1));
                                    p1.showdata();
                                    getch();
                               }
                          }
                  ifile.close();
                  temp.close();
                   }
                   else
                   {
                        cout<<"\n\n\t\t\t!!!!!! FAILED TO VERIFY!!!!!!\n"; getch();}
                        break;
               default :
               cout<<"\n ERROR \n";
               cout<<"\a";
               getch();
               break;
               }
               }
    while(ch!='5');
  }

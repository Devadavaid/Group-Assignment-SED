#include <iostream>
#include "GroupBeautifulCoders_Header.h"

int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    
    System Sys;
    House house; 
    Admin admin("admin", "12345");
    Sys.LoadDatabase();

    cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    cout << "VACATION HOUSE EXCHANGE APPLICATION\n\n";
    cout << "Instructor: Mr. Linh Tran\n";
    cout << "Group: BeautifulCoders\n";
    cout << "s3927112, Nguyen Tuong Khang\n";
    cout << "s3912105, Le Duy Quang\n";
    cout << "s3926823, Do Phuong Linh\n";
    cout << "s3915181, Nguyen Phan Duc Anh\n\n";

    //Use the app as Guest
    WelcomeScreen();
    int run = 1;
    string choice;
    while(1)
    {
        
        if(ExitProgram == true)
        {
            cout << "\nThank You for using Trading House App!\n";
            Sys.UpdateDataBase();
            return -1;
        }
        else if(Guest_choice == true)
        {
            cout << "\nThis is your menu: \n";
            cout << "0. Exit\n";
            cout << "1. View all house details\n";
            cout << "2. Register\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if(choice == "0")
            {
                Guest_choice = false;
                isLog = true;
                WelcomeScreen();
                Sys.UpdateDataBase();                
            }
            else if(choice == "1")
            {   
                Sys.ShowHouseDataBase();
                Sys.UpdateDataBase();
            }   
            else if(choice == "2")
            {
                Member *mem = new Member;
                House *house = new House;
                Member *OccupyMem = new Member;
                House *houseOccupy = new House;
                Sys.SignUp(mem, house, OccupyMem, houseOccupy);
                Sys.UpdateDataBase();
            }
            else
                cout << "Syntax error!\n";
            Sys.UpdateDataBase();
        }
        else if(Member_choice == true)
        {
            Member *add = new Member;
            if(add->LogIn() == true)
            {
                int loop = 1;
                while(loop == 1)
                {
                    cout << "\nThis is your menu: \n";
                    cout << "0. Exit\n";
                    cout << "1. View Informations detail\n";
                    cout << "2. Put your house for occupying\n";
                    cout << "3. View house for occupied menu\n";
                    cout << "4. Show list of requests\n";
                    cout << "5. Show your house reviews\n";
                    cout << "6. Return your occupied house\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if(choice == "0")
                    {
                        Member_choice = false;
                        loop = 2;
                        WelcomeScreen();
                        Sys.UpdateDataBase();
                    }
                    else if(choice == "1")
                    {
                        add->ShowInfo();
                        Sys.UpdateDataBase();
                    }
                    else if (choice == "2") 
                    {
                        add->PutHouseToRent();
                        Sys.UpdateDataBase(); 
                    } 
                    else if (choice == "3") 
                    {
                        while(true){
                            string choice1;
                            cout << "\nThis is your menu: \n";
                            cout << "0. Exit\n";
                            cout << "1. Show list of houses are available for renting\n";
                            cout << "2. Show all the suitable house for user requirements\n";
                            cout << "Enter your choice: ";
                            cin >> choice1;
                            if(choice1 == "0")
                            {
                                break;
                                Sys.UpdateDataBase();
                            }
                            else if(choice1 == "1")
                            {
                                add->showHouseAvailable();
                                Sys.UpdateDataBase();
                            }
                            else if(choice1 == "2")
                            {
                                add->SuitableHouse();
                                Sys.UpdateDataBase();
                            }   
                            else
                            {
                                Member_choice = false;
                                isLog = true;
                                cout << "Syntax error!\n";
                                Sys.UpdateDataBase();
                            }
                        }

                    } 
                    else if (choice == "4") {
                        add->ShowListRequest(); 
                        Sys.UpdateDataBase(); 
                    }
                    else if(choice == "5")
                    {
                
                        add->ShowListOfReviews();
                        Sys.UpdateDataBase();
                    }
                    else if(choice == "6")
                    {
                        add->ReturnHouse();
                        Sys.UpdateDataBase();
                    }
                    else
                    {
                        cout << "Syntax error!\n";
                        Sys.UpdateDataBase();
                    }
                }
            }
            else
            {
                Member_choice = false;
                WelcomeScreen();
                Sys.UpdateDataBase();
            }
        }
        else if(Admin_choice == true)
        {
            admin.Admin_Login(&admin);
            if(Admin_Success == true)

            {
                admin.ShowDatabase();
                Admin_choice = false;
                Sys.UpdateDataBase();
                WelcomeScreen();
            }
            else
            {
                Admin_choice = false;
                WelcomeScreen();
            }
        }
    }
 
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Item
{
    string item_name;
    int product_number;
    double discount;
    double price;
    int quantity;

};

void Menu()
{
    cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\t\t\tPress 1 to ADD PRODUCT Item";
	cout<<"\n\t\t\tPress 2 to DISPLAY ALL PRODUCTS ";
	cout<<"\n\t\t\tPress 3 to Search ";
	cout<<"\n\t\t\tPress 4 to DELETE PRODUCT";
	cout<<"\n\t\t\tPress 0 to EXIT";
	cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout<<" \tYour option: ";
}

void intro() {
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t@################                                  #################\n";
	cout<<"\t@#############                                       ###############\n";
	cout<<"\t@##########                                            #############\n";
	cout<<"\t@########                                               ############\n";
	cout<<"\t@######          Simple Supermarket System In C++         ##########\n";
	cout<<"\t@########                                               ############\n";
	cout<<"\t@##########                                          ###############\n";
	cout<<"\t@#############                                     #################\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

}

void add_item(Item I[], int n) // Function to ACCECPT INPUT and WRITE INTO FILE
{
    ofstream f("data.txt", ios::app); // Creates A Text File or Opens An Existing File and Appends
    cout<<"Input Product details hereunder...\n";

    for(int i=1; i< n+1; i++) // Loop to Insert Records
    {

	    cout<<"\n\nProduct "<<i<<"\n";
	    cout<<"++++++++++++++++++++++\n";

	    cout << "\tItem : ";
	    cin.get();getline(cin, I[i].item_name); // Get's a string with White Spaces

	    cout << "\tProduct Number: ";
	    cin >>I[i].product_number;

	    cout << "\tPrice : ";
	    cin >>I[i].price;

	    cout << "\tQuantity : ";
	    cin>>I[i].quantity;

	    cout << "\tDiscount : ";
	    cin>>I[i].discount;

    }

    for(int i=1; i< n+1; i++) // Loop For SAVING/WRITING RECORDS INTO the TEXT FILE
    {
    	f<<I[i].product_number<<"\t"<<I[i].item_name <<"\t"<<I[i].price<<"\t"<<I[i].quantity<<"\t"<<I[i].discount <<"\n";
    }

    cout <<"\n Product Item(s) Saved Successfully \n";
    f.close(); // CLOSES the PREVIOUSLY OPENED TEXT FILE
}

void header(){

	cout << "\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t| Prod No. |     Item |    Price  |   Quantity |    Discount |\n";
    cout << "\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

}

void read_from_file() //Function to READ FROM THE TEXT FILE and PRINT OUT to CONSOLE
{
    ifstream f("data.txt"); // OPENS THE TEXT FILE With the NAME " "

    char line[50];  // HOLDS a LINE of STRINGS UPTO '50' CHARACTERS

    header();
    while(f) // Loops THROUGH the TEXT FILE to PRINT OUT ALL THE RECORDS
    {
        f.getline(line, 50);  // GET's STRING LINE by LINE
        cout <<"\n\t " <<line;
    }
	f.close(); // CLOSES the PREVIOUSLY OPENED TEXT FILE
}

void search() // Function to SEARCH FROM THE TEXT FILE and PRINT OUT to CONSOLE
{
    string line;
    int A = -1;
    char Key[10]; // HOLDS '10' CHARACTERS of SEARCH KEY STRING

    ifstream f("data.txt"); // OPENS THE TEXT FILE With the NAME " "

    //read_from_file(M); // Function Calling

    cout << "\n Enter The Search key - ";
    cin >>Key;

    header();

    while(f) // Loop for SEARCHING THROUGH FILE
    {
        getline(f,line); // GET'S a SINGLE LINE FROM the FILE
        if((line.find(Key, 0)) !=string::npos) // COPMPARES the LINE with the SEARCH KEY
        {
            cout << "\n\t " <<line ; // PRINTS OUT SEARCH RESULT ONLY IF SEARCH KEY MATCHES WITH a STRING FROM the FILE
            cout << "\n\t-------------------------------------------------------------------------";
        }
    }

	f.close();
}

void _delete()
{
    string line, num;

    fstream f("data.txt"); //OPENS THE TEXT FILE WHICH HOLDS THE RECORDS
    ofstream temp("temp.txt"); //CREATES a NEW TEMPORARY TEXT FILE

    cout <<"\n\n Insert Product Number of the item to be deleted: ";
    cin >> num;

    while(f) // Loop THROUGH FILE to DELETE THE REQUESRED RECORD
    {
        getline(f,line); // GET'S a SINGLE LINE FROM the FILE
        if (line.substr(0, num.size()) != num) // SUBSTRING a LINE FROM THE file
            temp << line <<endl;
    }

    cout <<"\n Record Deleted \n";

    f.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

int main()
{
    Item I[1000]; //Object of Struct
    int i,n;
    int option;
    int loop;

    intro();
    cout<<loop;
	while(loop != 0) // Loop Main Function
	{
	    Menu(); // Function Calling
	    cin >> option;

	    while (cin.good() == false) // Input Validation
	    {
	        cout <<"\nInvalid Input Try Again !!!\n";
	        cin.clear();

	        Menu();
	        cin >>option;
	    }

	    if(option == 1) // Cases to Call Functions
	    {
	        cout <<"\n How Many Items Do You Want to Add?";
	        cin >>n;
	        add_item(I, n);
	    }

	    else if (option == 2)
	    	read_from_file();

	    else if (option == 3)
	    	search();

	    else if (option == 4)
	    	_delete();

	    else if (option == 0)
	    	return 0;

	    else
	    {
	        cout <<"\nInvalid Input Try Again !!! \n";
	        main();
	    }

	    cout <<"\n Enter 1 to Continue or 0 to Exit the Program . . . ";
	    cin >>loop;
	}
}

#include <iostream> //for basic input and output functions
#include <string>
#include <cstring>
using namespace std;

//Using Arrays to make customer & Book Record

struct customerRecord
{
    string PID;
    string PName;
    string Phone;
    int BorrowNo;
    int ReturnNo;
    string BorrowingBook[3][5];
    string ReturningBook[15][5];
    customerRecord* Next;
};
struct BookRecord
{
    string bID;
    string btitle;
    string category;
    string genre;
    bool availability;
    BookRecord* Next2;
};



customerRecord* Head = NULL;
BookRecord* Head2 = NULL;
int place = 0, place2 = 0, posi = 0;
char choice, option1, option2;
int position;

string Booktitle;
string bcateg;
string bgenre;
string borrowdate;
string bkid;
string pid;

string PIDInput;
string PNameInput;
string PhoneInput;
string BorrowingBookInput[3][5];
string ReturningBookInput[15][5];
int BorrowNoInput;

string bIDInput;
string btitleInput;
string categoryInput;
string genreInput;
bool availabilityInput;

//Declaring the Genres

string genre1    = "Fantasy";
string genre2    = "Science";
string genre3    = "Historical";
string genre4    = "Realistic";
string genre5    = "Fan";
string genre6    = "Narrative";
string genre7    = "Biography";
string genre8    = "Periodicals";
string genre9    = "Self-help";
string genre10   = "Reference";
string category1 = "Fiction";
string category2 = "Non-Fiction";

//Declaring the Functions

void Login();
void AddBook();
void Addcustomer();
void DisplayBook(BookRecord* Head);
void DisplayBookA(BookRecord* Head);
void SearchBook( BookRecord* Head);
bool SearchP(string pid, customerRecord* Head);
bool Searchb(string bid, BookRecord* Head);
void returnbook();
void borrowBook(string biD, BookRecord* Head2);
void borrowBookp(string biD, customerRecord* Head);
void SearchPRecord(customerRecord* Head);
void PLastBorrowedB(customerRecord* Head);
BookRecord* UpdateBook(string biD, BookRecord* Head);
void UpdatePInfo();
void Displaycustomers(customerRecord* Head);
void InsertArbitraryp(string customerid, string pname, string phone, int index);
void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index);

//Declaring the Functions

void InsertArbitraryp(string customerid, string pname, string phone, int index)
{
    customerRecord* New_node = new customerRecord;
    New_node->PID = customerid;
    New_node->PName = pname;
    New_node->Phone = phone;
    New_node->BorrowNo = 0;
    New_node->ReturnNo = 0;
    if (index <= place)
    {
        if (index == 0)
        {
            customerRecord* Position = new customerRecord;
            Position->PID = customerid;
            Position->PName = pname;
            Position->Phone = phone;
            Position->BorrowNo = 0;
            Position->ReturnNo = 0;
            Position->Next = Head;
            Head = Position;
        }
        else if (index == place)
        {
            customerRecord* Position2 = new customerRecord;
            Position2->PID = customerid;
            Position2->PName = pname;
            Position2->Phone = phone;
            Position2->BorrowNo = 0;
            Position2->ReturnNo = 0;
            Position2->Next = NULL;
            if (Head == NULL)
                Head = Position2;
            else
            {
                customerRecord* MyCurrent1 = Head;
                while (MyCurrent1->Next != NULL)
                {
                    MyCurrent1 = MyCurrent1->Next;
                }
                MyCurrent1->Next = Position2;
            }
        }
        else
        {
            customerRecord* new_record = new customerRecord;
            new_record->PID = customerid;
            new_record->PName = pname;
            new_record->Phone = phone;
            new_record->BorrowNo = 0;
            new_record->ReturnNo = 0;
            customerRecord* prev = Head;
            for (int i = 0; i < index - 1; i++)
                prev = prev->Next;
            new_record->Next = prev->Next;
            prev->Next = new_record;
        }
    }
    else if (index > place)
    {
        customerRecord* Position2 = new customerRecord;
        Position2->PID = customerid;
        Position2->PName = pname;
        Position2->Phone = phone;
        Position2->BorrowNo = 0;
        Position2->ReturnNo = 0;
        Position2->Next = NULL;
        if (Head == NULL)
        {
            Head = Position2;
        }
        else
        {
            customerRecord* MyCurrent1 = Head;
            while (MyCurrent1->Next != NULL)
            {
                MyCurrent1 = MyCurrent1->Next;
            }
            MyCurrent1->Next = Position2;
        }
    }
}

/*insert arbitrary book*/
void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index)
{
    // create new node
    BookRecord* New_node = new BookRecord;
    New_node->bID = bid;
    New_node->btitle = Btitle;
    New_node->category = bcategory;
    New_node->genre = bgerne;
    New_node->availability = avaiable;
    //if the given position less than the linked list size
    if (index <= place2)
    {
        //when the linked list still empty- insert at the begnning
        if (index == 0)
        {
            BookRecord* Position = new BookRecord;
            Position->bID = bid;
            Position->btitle = Btitle;
            Position->category = bcategory;
            Position->genre = bgerne;
            Position->availability = avaiable;
            Position->Next2 = Head2;
            Head2 = Position;
        }
        //if the given position is equal the linked list size: insert at the end
        else if (index == place2)
        {
            //create new node
            BookRecord* Position2 = new BookRecord;
            Position2->bID = bid;
            Position2->btitle = Btitle;
            Position2->category = bcategory;
            Position2->genre = bgerne;
            Position2->availability = avaiable;
            // assign the next of the position to NULL
            Position2->Next2 = NULL;
            if (Head2 == NULL)
                // insert at the beginning of the linked list
                Head2 = Position2;
            //insert at the end of the linked list
            else
            {
                //create new node that equal the head
                BookRecord* MyCurrent1 = Head2;
                //while will work until it reaches the NULL(end of linked list)
                while (MyCurrent1->Next2 != NULL)
                {
                    // move from position to the next one until reach the end of the linked list
                    MyCurrent1 = MyCurrent1->Next2;
                }
                // my last position->next in the linked list ->
                //-> will be equal the position that the new record will be saved at
                MyCurrent1->Next2 = Position2;
            }
        }
        /*insert at the given position*/
        else
        {
            // create new node
            BookRecord* new_record = new BookRecord;
            new_record->bID = bid;
            new_record->btitle = Btitle;
            new_record->category = bcategory;
            new_record->genre = bgerne;
            new_record->availability = avaiable;
            //create new node and assgin it to the head of the linked list
            BookRecord* prev = Head2;
            for (int i = 0; i < index - 1; i++)
                prev = prev->Next2;
            new_record->Next2 = prev->Next2;
            prev->Next2 = new_record;
        }
    }
    /*when the linked list size is bigger than the given position*/
    else if (index > place2)
    {
        // create new record
        BookRecord* Position2 = new BookRecord;
        Position2->bID = bid;
        Position2->btitle = Btitle;
        Position2->category = bcategory;
        Position2->genre = bgerne;
        Position2->availability = avaiable;
        Position2->Next2 = NULL;
        if (Head2 == NULL)
        {
            // insert at the beginning of the linked list
            Head2 = Position2;
        }
        else
        {
            //insert at the end of the linked list
            BookRecord* MyCurrent1 = Head2;
            //while will work until it reaches the NULL(end of linked list)
            while (MyCurrent1->Next2 != NULL)
            {
                MyCurrent1 = MyCurrent1->Next2;
            }
            MyCurrent1->Next2 = Position2;
        }
    }
}

/*display record information*/
void DisplayBook(BookRecord* Head)
{
    BookRecord* MyCurrent1 = Head;
    //checking if the linked list is empty or not
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." << endl;

    }
    cout << "|------------------------------------------------------------------|";
    while (MyCurrent1 != NULL)
    {
        //displaying the inserted nodes
        cout << "1. Book ID           : " << MyCurrent1->bID << endl;
        cout << "2. Book title        : " << MyCurrent1->btitle << endl;
        cout << "3. Book category     : " << MyCurrent1->category << endl;
        cout << "4. Book Genre        : " << MyCurrent1->genre << endl;
        cout << "5. Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
        cout << "|------------------------------------------------------------------|" << endl;
        // go to next
        MyCurrent1 = MyCurrent1->Next2;
    }
}
//display customers records with the active borrowed books
void Displaycustomers(customerRecord* Head)
{
    customerRecord* MyCurrent1 = Head;
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." << endl;
    }
    cout << "|------------------------------------------------------------------|";
    while (MyCurrent1 != NULL)
    {
        cout << "1. customer ID              : " << MyCurrent1->PID << endl;
        cout << "2. customer Name            : " << MyCurrent1->PName << endl;
        cout << "3. customer Phone NO        : " << MyCurrent1->Phone << endl;
        cout << "4. Number of borrowed book: " << MyCurrent1->BorrowNo << endl;

        for (int i = 0; i < MyCurrent1->BorrowNo; i++)
        {
            cout << "1. Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
            cout << "2. Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
            cout << "3. Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
            cout << "4. Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
            cout << "5. Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
            cout << "|------------------------------------------------|" << endl;
        }
        // go to next
        MyCurrent1 = MyCurrent1->Next;
    }
}
//display last 10 borrowed book
void PLastBorrowedB(customerRecord* Head)
{
    customerRecord* MyCurrent1 = Head;
    string name;
    cout << "\nEnter customer Name or ID: ";
    cin >> name;
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." << endl;
    }
    while (MyCurrent1 != NULL)
    {
        if (name == MyCurrent1->PName || name == MyCurrent1->PID)
        {
            cout << "1. customer ID              : " << MyCurrent1->PID << endl;
            cout << "2. customer Name            : " << MyCurrent1->PName << endl;
            cout << "3. customer Phone NO        : " << MyCurrent1->Phone << endl;
            cout << "4. Number of borrowed book: " << MyCurrent1->BorrowNo << endl;

            for (int i = 0; i < MyCurrent1->ReturnNo; i++)
            {
                //to display only the last 10 borrowed books
                if (i ==10)
                {
                    break;
                }
                cout << "1. Book ID                : " << MyCurrent1->ReturningBook[i][0] << endl;
                cout << "2. Book title             : " << MyCurrent1->ReturningBook[i][1] << endl;
                cout << "3. Book category          : " << MyCurrent1->ReturningBook[i][2] << endl;
                cout << "4. Book Genre             : " << MyCurrent1->ReturningBook[i][3] << endl;
                cout << "5. Borrow Date            : " << MyCurrent1->ReturningBook[i][4] << endl;
                cout << "|------------------------------------------------|" << endl;
            }
            break;
        }
        else
        {
            // go to next
            MyCurrent1 = MyCurrent1->Next;
        }
    }
}

/*search customer record*/
void SearchPRecord(customerRecord* Head)
{
    customerRecord* MyCurrent1 = Head;
    string sname;
    cout << "\nEnter customer Name or ID: ";
    cin >> sname;
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..."
             << endl;
    }
    while (MyCurrent1 != NULL)
    {
        if (sname == MyCurrent1->PName || sname == MyCurrent1->PID)
        {
            cout << " customer ID              : "
                 << MyCurrent1->PID << endl;
            cout << " customer Name            : "
                 << MyCurrent1->PName << endl;
            cout << " customer Phone NO        : "
                 << MyCurrent1->Phone << endl;
            cout << " Number of borrowed book: "
                 << MyCurrent1->BorrowNo << endl;
            cout << " The borrowed books: \n" << endl;
            for (int i = 0; i < MyCurrent1->BorrowNo; i++)
            {
                cout << " Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
                cout << " Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
                cout << " Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
                cout << " Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
                cout << " Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
                cout << "|------------------------------------------------|" << endl;
            }
            break;
        }
        else
        {
            // go to next
            MyCurrent1 = MyCurrent1->Next;
        }
    }
}

/*display the avaiable books*/
void DisplayBookA(BookRecord* Head)
{
    BookRecord* MyCurrent1 = Head;
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." << endl;
    }
    while (MyCurrent1 != NULL)
    {
        if (MyCurrent1->availability == true)
        {

            cout << " Book ID           : " << MyCurrent1->bID << endl;
            cout << " Book title        : " << MyCurrent1->btitle << endl;
            cout << " Book category     : " << MyCurrent1->category << endl;
            cout << " Book Genre        : " << MyCurrent1->genre << endl;
            cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
        }
        cout << "|-------------------------------------------------------------------------|" << endl;
        // go to next
        MyCurrent1 = MyCurrent1->Next2;
    }
}

/*search book*/
void SearchBook(BookRecord* Head)
{
    string title;
    cout<<"Enter Book ID OR Name : ";
    cin>>title;
    BookRecord* MyCurrent = Head;
    if (MyCurrent == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." << endl;
    }
    else{

    while (MyCurrent!= NULL)
    {
        if (MyCurrent->btitle == title|| MyCurrent->bID == title )
        {
            cout << " Book ID           : "
                 << MyCurrent->bID << endl;
            cout << " Book title        : "
                 << MyCurrent->btitle << endl;
            cout << " Book category     : "
                 << MyCurrent->category << endl;
            cout << " Book Genre        : "
                 << MyCurrent->genre << endl;
            cout << " Book availability(1=True & 0= False) : "
                 << MyCurrent->availability << endl;
            cout << "|-------------------------------------------------------------------------|" << endl;
           // return MyCurrent;
           break;
        }
        else
        {
            //go to next record
            MyCurrent = MyCurrent->Next2;
        }
      }
      return;
    }
    cout<<"\nNo records Found.....!!!!";
    //return NULL;
}

/*search the avaiability*/
bool Searchb(string bid, BookRecord* Head)
{
    BookRecord* MyCurrent = Head;
    while (MyCurrent != NULL)
    {
        if (MyCurrent->bID == bid)
        {
            return true;
        }
        else
        {
            //go to next record
            MyCurrent = MyCurrent->Next2;
        }
    }
    return false;
}

/*search function for customer */
bool SearchP(string pid, customerRecord* Head)
{
    customerRecord* MyCurrent = Head;
    while (MyCurrent != NULL)
    {
        if (MyCurrent->PID == pid)
        {
            return true;
        }
        else
        {
            //go to next record
            MyCurrent = MyCurrent->Next;
        }

    }
    return false;
}

/*update the book record*/
BookRecord* UpdateBook(string biD, BookRecord* Head)
{
    BookRecord* MyCurrent1 = Head;
    string Booktitle, bcategory, bgenre;
    while (MyCurrent1 != NULL)
    {
        if (MyCurrent1->bID == biD)
        {
            getchar();
            cout << "Enter Book title: ";
            getline(cin, Booktitle, '\n');
            cout << "Enter Book Category"<<endl;
            cout << "1. Fiction"<<endl;
            cout << "2. Non-Fiction"<<endl;
            cout << "Enter your choice : ";
            //cout << "Enter Book Category(1. Fiction  2. Non-Fiction): ";
            cin >> option1;
            if (option1 == '1')
            {
                bcategory = category1;
                //cout << "\nBook genres: ";
                cout << "\nEnter Book genre: "<<endl;
                cout << "1. Fantasy"<<endl;
                cout << "2. Science "<<endl;
                cout << "3. Historical"<<endl;
                cout << "4. Realistic "<<endl;
                cout << "5. Fan "<<endl;
                cout << "Enter one option : ";
                cin >> option2;
                if (option2 == '1')
                {
                    bgenre = genre1;
                }
                else if (option2 == '2')
                {
                    bgenre = genre2;
                }
                else if (option2 == '3')
                {
                    bgenre = genre3;
                }
                else if (option2 == '4')
                {
                    bgenre = genre4;
                }
                else
                {
                    bgenre = genre5;
                }
            }
            else
            {
                bcategory = category2;
                cout << "\nEnter Book genre: "<<endl;
                cout << "1. Narrative"<<endl;
                cout << "2. Biography "<<endl;
                cout << "3. Periodicals"<<endl;
                cout << "4. Self-help"<<endl;
                 cout << "5. Refrences"<<endl;
                cout << "Enter one option : ";
                cin >> option2;
                if (option2 == '1')
                {
                    bgenre = genre6;
                }
                else if (option2 == '2')
                {
                    bgenre = genre7;
                }
                else if (option2 == '3')
                {
                    bgenre = genre8;
                }
                else if (option2 == '4')
                {
                    bgenre = genre9;
                }
                else
                {
                    bgenre = genre10;
                }
            }
            MyCurrent1->btitle = Booktitle;
            MyCurrent1->category = bcategory;
            MyCurrent1->genre = bgenre;
            cout << "The New Details" << endl;
            cout << " Book ID           : "
                 << MyCurrent1->bID << endl;
            cout << " Book title        : "
                 << MyCurrent1->btitle << endl;
            cout << " Book category     : "
                 << MyCurrent1->category << endl;
            cout << " Book Genre        : "
                 << MyCurrent1->genre << endl;
            cout << " Book availability(1=True & 0= False) : "
                 << MyCurrent1->availability << endl;
            cout << "|-------------------------------------------------------------------------|\n" << endl;
            return MyCurrent1;
        }
        else
        {
            MyCurrent1 = MyCurrent1->Next2;
        }
    }
    return NULL;
}

/*update customer info*/
void UpdatePInfo()
{
    customerRecord* MyCurrent = Head;
    cout << "Enter customer ID: ";
    /*getting the customer record*/
    cin >> PIDInput;
    while (MyCurrent != NULL)
    {
        if (MyCurrent->PID == PIDInput)
        {
            /*find the customer record*/
            cout << "\nPlease fill up The new info: \n" << endl;
            getchar();
            cout << "Enter customer Name: ";
            getline(cin, PNameInput, '\n');
            cout << "Enter Phone No   : ";
            getline(cin, PhoneInput, '\n');
            /*assigning the new data*/
            MyCurrent->PName = PNameInput;
            MyCurrent->Phone = PhoneInput;
            break;
        }
        else
        {
            //go to next record
            MyCurrent = MyCurrent->Next;
        }
    }
    return;
}
/*borrow a book*/
void borrowBookp(string piD, customerRecord* Head)
{
    customerRecord* MyCurrent2 = Head;
    while (MyCurrent2 != NULL)
    {
        if (MyCurrent2->BorrowNo >=3)
            /*if the number of the borrow book is equal or less than 3 will be allowed*/
        {
            cout << " <!>  The customer has reached the maximum number of borrowing books(which is 3 books)<!>";
            cout<<endl;
            cout << "\nNoted: The customer may return one of the borrowed book to be able to borrow a new book";
            cout<<endl;
            return;
            break;
        }
        if (MyCurrent2->PID == pid)
        {
            cout << "\nNote: return the book within 15 days after the borrowing date!";
            cout<<endl;
            cout << "Enter borrowing date(Y/M/D): ";
            cin >> borrowdate;
            for (int i = MyCurrent2->BorrowNo; i < MyCurrent2->BorrowNo+1; i++)
            {
                /*copying the book detail into borrowbook array*/
                MyCurrent2->BorrowingBook[i][0] = bkid;
                MyCurrent2->BorrowingBook[i][1] = Booktitle;
                MyCurrent2->BorrowingBook[i][2] = bcateg;
                MyCurrent2->BorrowingBook[i][3] = bgenre;
                MyCurrent2->BorrowingBook[i][4] = borrowdate;
            }
            MyCurrent2->BorrowNo += 1;
            /*increase the number of the borrow books*/
            /*displaying the borrow book details*/
            cout << "|-------------------------------------------------------------------------|"<<endl ;
            cout << "\t\t\tThe Borrowing Details"<<endl;
            cout << "|-------------------------------------------------------------------------|"<<endl ;
            cout << "\n|-------------------------------------------------------------------------|"<<endl ;
            cout<<endl;
            cout << " customer ID         : " << MyCurrent2->PID ;
            cout<<endl;
            cout << " customer Name       : " << MyCurrent2->PName ;
            cout<<endl;
            cout << " Book ID           : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo-1][0] ;
            cout<<endl;
            cout << " Book title        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][1] ;
            cout<<endl;
            cout << " Book category     : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][2] ;
            cout<<endl;
            cout << " Book Genre        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][3] ;
            cout<<endl;
            cout << " Borrow Date       : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][4] ;
            cout<<endl;
            cout << "|-------------------------------------------------------------------------|\n" ;
            cout<<endl;
            break;
        }
        else
            /*go to the next record*/
            MyCurrent2 = MyCurrent2->Next;
    }
}
void borrowBook(string biD,BookRecord* Head2)
{
    BookRecord* MyCurrent1 = Head2;
    while (MyCurrent1 != NULL)
    {
        if (MyCurrent1->bID == biD && MyCurrent1->availability == true)
        {
            /*getting the book details*/
            bkid= MyCurrent1->bID;
            Booktitle = MyCurrent1->btitle;
            bcateg = MyCurrent1->category;
            bgenre = MyCurrent1->genre;
            cout << "Enter customer ID: ";
            cin >> pid;
            /*checking the customer id*/
            if (SearchP(pid, Head) == false)
            {
                cout << "\nThis ID is not avaiable yet. Pls try again with new ID\n";
                cout<<endl;
                break;
            }
            else
            {
                borrowBookp(pid,Head);
                /*calling the borrow function*/
                MyCurrent1->availability = false;
                /*set the borrowed book to not available*/
                break;
            }
        }
        else
            MyCurrent1 = MyCurrent1->Next2;
    }
}

/*return the book*/
void returnbook()
{
    customerRecord* MyCurrent1 = Head;
    string customerid,bid;
    cout << "\nEnter customer ID: ";
    cin >> customerid;
    cout << "\nEnter Book ID to return it: ";
    cin >> bid;
    if (MyCurrent1 == NULL)
    {
        cout << "NO record yet!!, please insert new records first..." ;
        cout<<endl;
    }
    while (MyCurrent1 != NULL)
    {
        if (customerid == MyCurrent1->PID)
        {
            for (int i = 0; i < MyCurrent1->BorrowNo; i++)
            {
                if (MyCurrent1->BorrowingBook[i][0] == bid)
                {
                    for (int ii = MyCurrent1->ReturnNo; ii < MyCurrent1->ReturnNo+1; ii++)
                    {
                        /*copy the date from the borrow book array into the returning book array*/
                        MyCurrent1->ReturningBook[ii][0] = MyCurrent1->BorrowingBook[ii][0];
                        MyCurrent1->ReturningBook[ii][1] = MyCurrent1->BorrowingBook[ii][1];
                        MyCurrent1->ReturningBook[ii][2] = MyCurrent1->BorrowingBook[ii][2];
                        MyCurrent1->ReturningBook[ii][3] = MyCurrent1->BorrowingBook[ii][3];
                        MyCurrent1->ReturningBook[ii][4] = MyCurrent1->BorrowingBook[ii][4];
                    }
                    /*making the book avaiable again*/
                    BookRecord* reader = Head2;
                    while (reader->Next2!= NULL)
                    {
                        if (reader->bID == bid)
                        {
                            reader->availability = true;
                            break;
                        }
                        reader = reader->Next2;
                    }
                    /*deleting the returning book from the borrow book array*/
                    int a, j, k;
                    int NoColumn = 5;
                    int NORows = 3;
                    for (a = 0; a < NORows; a++)
                    {
                        for (k = a; k < NORows - 1; k++)
                        {
                            for (j = 0; j < NoColumn; j++)
                            {
                                MyCurrent1->BorrowingBook[k][j] = MyCurrent1->BorrowingBook[k + 1][j];
                            }
                        }
                        a--;
                        NORows--;
                    }
                }
            }
            /*increase the number of the returning book*/
            MyCurrent1->ReturnNo += 1;
            /*decreasing the number of the borrowed book*/
            MyCurrent1->BorrowNo -= 1;
            cout << "\n <!> The book has been returned successfully  <!>\n";
            break;
        }
        else
        {
            // go to next
            MyCurrent1 = MyCurrent1->Next;
        }
    }
}
/*function to store the book details such as id, title, categorey, genre, avaiability*/
void AddBook()
{
    cout << "\nPlease fill up the following requirements: \n" << endl;
    cout << "Enter Book ID: ";
    cin >> bIDInput;
    while(Searchb(bIDInput, Head2) == true)
    {
        cout << "\n This ID has been used before !!\n" << endl;
        cout << "Enter Book ID: ";
        cin >> bIDInput;
    }
        getchar();
        cout << "Enter Book Title: ";
        getline(cin, btitleInput, '\n');
        cout << "Enter Book Category"<<endl;
        cout << "1. Fiction"<<endl;
        cout << "2. Non-Fiction"<<endl;
        cout << "Enter your choice : ";
        cin >> option1;
        if (option1 == '1')
        {
            categoryInput = category1;
            cout << "\nEnter Book genre: "<<endl;
            cout << "1. Fantasy"<<endl;
            cout << "2. Science "<<endl;
            cout << "3. Historical"<<endl;
            cout << "4. Realistic "<<endl;
             cout << "5. Fan "<<endl;
            cout << "Enter one option : ";
            cin  >> option2;

            if (option2 == '1')
            {
                genreInput = genre1;
            }
            else if (option2 == '2')
            {
                genreInput = genre2;
            }
            else if (option2 == '3')
            {
                genreInput = genre3;
            }
            else if (option2 == '4')
            {
                genreInput = genre4;
            }
            else
            {
                genreInput = genre5;
            }
        }
        else
        {
            categoryInput = category2;
            cout << "\nEnter Book genre: "<<endl;
            cout << "1. Narrative"<<endl;
            cout << "2. Biography "<<endl;
            cout << "3. Periodicals"<<endl;
            cout << "4. Self-help "<<endl;
            cout << "Enter one option : ";
            cin  >> option2;
            if (option2 == '1')
            {
                genreInput = genre6;
            }
            else if (option2 == '2')
            {
                genreInput = genre7;
            }
            else if (option2 == '3')
            {
                genreInput = genre8;
            }
            else if (option2 == '4')
            {
                genreInput = genre9;
            }
            else
            {
                genreInput = genre10;
            }
        }
        availabilityInput = true;
        cout << "Enter the position you want to save the record: ";
        cin >> position;
        InsertArbitraryb(bIDInput, btitleInput, categoryInput, genreInput, availabilityInput, position);
        place2++;

    return;
}

/*add customer account*/
void Addcustomer()
{
    cout << "\nPlease fill up the following requirements: \n" << endl;
    cout << "Enter customer ID: ";
    cin  >> PIDInput;
    while(SearchP(PIDInput, Head) == true)
    {
        cout << "\n This ID has been used before !!\n" << endl;
        cout << "Enter customer ID: ";
        cin  >> PIDInput;
    }
        getchar();
        cout << "Enter customer Name: ";
        getline(cin, PNameInput, '\n');
        cout << "Enter Phone No: ";
        getline(cin, PhoneInput, '\n');
        cout << "Enter the position you want to save the record: ";
        cin >> position;
        InsertArbitraryp(PIDInput, PNameInput, PhoneInput, position);
        place++;
    return;
}

void Login()
{
    string pin;
    cout <<"\t\t\t\t\t\t***************************************************************\n";
    cout <<"\t\t\t\t\t\t***************************************************************\n";
    cout <<"\n\t\t\t\t\t\t       <=======>  WELCOME TO OUR SMART LIBRARY  <=======>\n";
    cout <<"\n\t\t\t\t\t\t***************************************************************\n";
    cout <<"\t\t\t\t\t\t***************************************************************\n";

    cout << "\nEnter Password PIN To Access: ";
    cin >> pin;
    while(pin != "1234")
    {
        cout << "\n  <> Wrong PIN <>\n";
         cout << "\nEnter Password PIN To Access: ";
        cin>>pin;
    }
        cout << "\n  <>  Correct PIN <> \n";
        system("pause");
        system("cls");
}

/*the main function of the system */
int main()
{
    string sbtitle;
    string bookid, borrowid;
    Login();
    //system("color 2");
    /*changing the color to green*/

    do
    {
        cout <<"\t\t\t\t\t\t***************************************************************\n";
        cout <<"\t\t\t\t\t\t***************************************************************\n";
        cout <<"\n\t\t\t\t\t\t       <=======>  WELCOME TO OUR SMART LIBRARY  <=======>\n";
        cout <<"\n\t\t\t\t\t\t***************************************************************\n";
        cout <<"\t\t\t\t\t\t***************************************************************\n";
        cout << "1. Book Services"<<endl;
        cout << "2. customers Services"<<endl;
        cout << "3. Exit"<<endl;
        cout << " Enter one choice: ";
        cin  >> choice;
        switch (choice)
        {
        case '1':
            do
            {
                system("cls");
                cout <<"\t\t\t\t\t\t***************************************************************\n";
                cerr <<"\n\t\t\t\t\t\t\t      <=======>  Book Service  <=======>\n";
                cout <<"\n\t\t\t\t\t\t***************************************************************\n";
                cout << "1. Add New Book"<<endl;
                cout << "2. Display Books"<<endl;
                cout << "3. Search Book"<<endl;
                cout << "4. Borrow BooK"<<endl;
                cout << "5. Update Book Information"<<endl;
                cout << "6. Back" << endl;
                cout << "Enter one choice: ";
                cin >> choice;
                switch (choice)
                {
                case '1':
                    AddBook();
                    break;
                case '2':
                    cout << "\n1. Display all books."<<endl;
                    cout << "2. Display the avaiable books only."<<endl;
                    cout << "Enter one option: ";
                    cin >> choice;
                    if (choice == '1')
                    {
                        DisplayBook(Head2);
                    }
                    else
                    {
                        DisplayBookA(Head2);
                    }
                    cout << "\nDo you want to borrow any book:"<<endl;
                    cout << "YES (Press 1) "<<endl;
                    cout << "NO (Press 2) "<<endl;
                    cout << " Choice:";
                    cin >> choice;
                    if (choice == '1')
                    {

                        cout << "Enter Book ID: ";
                        cin >> borrowid;
                        borrowBook(borrowid, Head2);
                    }
                    else
                    {
                        cout << "\n Backing to the main menu....\n" << endl;
                    }
                    break;
                case '3':
                    getchar();
                    // cout << "\nEnter the book title or category or genre to search: ";
                    // cin>>sbtitle;
                    SearchBook(Head2);
                    //cout << "\nDo you want to borrow any book: (1. Yes  2. NO): ";
                    cout << "\nDo you want to borrow any book:"<<endl;
                    cout << "YES (Press 1) "<<endl;
                    cout << "NO (Press 2) "<<endl;
                    cout << "Choice:";
                    cin>> choice;
                    if (choice == '1')
                    {

                        cout << "Enter Book ID: ";
                        cin >> borrowid;
                        borrowBook(borrowid, Head2);
                    }
                    else
                    {
                        cout << "\n Backing to the main menu....\n" << endl;
                    }
                    break;
                case '4':
                        cout << "\nEnter Book ID: ";
                        cin >> borrowid;
                        borrowBook(borrowid, Head2);
                        break;
                case '5':
                    cout << "\nEnter Book ID to update: ";
                    cin >> bookid;
                    UpdateBook(bookid, Head2);
                    break;
                case '6':
                    cout << "\n Backing to the main menu....\n" << endl;
                    break;
                default:
                    cerr << "\n\n <!!!>    Wrong Choice   <!!!>" << endl;
                    break;
                }
                system("pause");
                system("cls");
            }
            while (choice != '6');
            break;
        case '2':
            do
            {
                system("cls");
                cout <<"\t\t\t\t\t\t***************************************************************\n";
                cerr <<"\n\t\t\t\t\t\t\t      <=======>  Customer Service  <=======>\n";
                cout <<"\n\t\t\t\t\t\t***************************************************************\n";
                //cerr << "\n\n       <=======>  customers Service  <=======>\n"
                cout <<"  1. Add New customer"<<endl;
                cout <<"  2. Display the last 10 books borrowed by a customer"<<endl;
                cout <<"  3. Search customer"<<endl;
                cout <<"  4. Update customer Info"<<endl;
                cout <<"  5. Return a Borrowed book"<<endl;
                cout <<"  6. View all customers with active book borrowed."<<endl;
                cout <<"  7. Back" << endl;
                cout <<"  Enter one choice: ";
                cin >> choice;
                switch (choice)
                {
                case '1':
                    Addcustomer();
                    break;
                case '2':
                    PLastBorrowedB(Head);
                    break;
                case '3':
                    SearchPRecord(Head);
                    break;
                case '4':
                    UpdatePInfo();
                    break;
                case '5':
                    returnbook();
                    break;
                case '6':
                    Displaycustomers(Head);
                    break;
                case '7':
                    cout << "\n Backing to the main menu....\n" << endl;
                    break;
                default:
                    cerr << " <!!!>    Wrong Choice   <!!!>" << endl;
                    break;
                }
                system("pause");
                system("cls");
            }
            while (choice != '7');
            break;
        case '3':
            cout <<"\n <***>  See You Soon ! :)    <***>\n"<<endl;
            break;
        default:
            cerr << "\n\n <!!!>    Wrong Choice   <!!!>"<<endl;
            break;
        }
       // system("pause");/*pause the screen until the user press a key*/
        system("cls");/*clean the old displayed menu*/
    }
    while (choice != '3');
    return 0;
}

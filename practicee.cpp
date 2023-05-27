#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class product
{
    int cost;

    public:
       product(int c=10)
       {
           cost = c;
       }
       product operator +(product const& obj)
       {
           product p;
           p.cost = cost + obj.cost;
           return p;
       }
         product operator -(product const& obj)
       {
           product p;
           p.cost = cost - obj.cost;
           return p;
       }
       void edit();
       void add();
       int cal()
       {
           return cost;
       }

};
class brand : public product
{
    float vat;
public:
    brand(int r){vat=r;}
    float extra()
    {
        return cal()*vat;

    }
    void show_cost()
    {
         cout << "According to the Brand the total cost comes:"<<extra()<<endl<<endl;
    }
};
class s_customer
{
public:
    s_customer(){cout<<"          \t\t\t\t WELCOME TO PUBLIX\n\n\n";}
       void receipt();
       void customer();
};

class supermarket :public s_customer
{
    int pcode;
    float price;
    float dis;
    string pname;
public:
    void administrator();
    void listt();
    void manu();
    void receipt();
    void customer();
    void edit();
    void add();
    void exist()
    {
        cout<< "EXSIT!!!!!";
    }

};
void supermarket :: manu()
{
    m:
        int choice;
        string email;
        string password;

        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t       Supermarket Main Manue             \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|        1)Administrator                   \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|        2)Customer                       \n";
        cout << "\t\t\t\t                                          \n";
        cout << "\t\t\t\t|        4)Exist                          \n";
        cout << "\t\t\t\t                                          \n";

        cout<<"\n\t\t Please Select:";
        cin >> choice;

        switch(choice)
        {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email:";
        cin >> email;
        cout<<"\n\t\t\t Password:";
        cin >> password;

        if(email=="publix@gmail.com" && password=="#ihateCSE!")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password";
        }
        break;

    case 2:
        {
           customer();
        }

    case 3:
        {
            exist();
        }
    default:
        {
           cout << "Please Select From The Given Options:";
        }
    }
    goto m;

}
void supermarket::administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Adminstrator Manue";
    cout<<"\n\t\t\t______1)Add Product____________|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t______2)Modify The Product_____|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t______3)Delete The Product_____|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t______4)Bact To The Main Manue_|";
    cout<<"\n\t\t\t|                              |";

    cout <<"\n\n\t Please Enter Your Choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        manu();
        break;
    default:
        cout <<"Invalid Choice";
}
goto m;
}
void supermarket::customer()
{
    m:
    int choice;
    cout<<"\t\t\t  Customer   \n";
    cout <<"\t\t\t____________\n";
    cout <<"                  \n";
    cout<<"\t\t\t1)Buy Product\n";
    cout <<"                  \n";
    cout<<"\t\t\t2)Go Back    \n";
    cout<<"\n\t\t\t Enter your Choice:";
    cin >> choice;
    switch(choice)
    {
    case 1:
        receipt();
        break;
     case 2:
        manu();
     default:
        cout<<"Invalid Choice";

    }
    goto m;


}
void supermarket :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout <<"\n\n\t\t\t Add New product:";
    cout << "\n\n\t Product Code Of The Product: ";
    cin >> pcode;
    cout << "\n\n\t Name Of The Product:";
    cin >> pname;
    cout << "\n\n\t Price Of The Product:";
    cin >> price;
    cout << "\n\n\t Discount On Product:";
    cin >> dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<< " "<<pname<< " " << price<< " "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<< " "<<pcode<< " "<<pname<< " "<<price<< " "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted! ";

}
void supermarket :: edit()
{
    m:
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout <<"\n\t\t\t Modify The record";
    cout <<"\n\t\t\t Product code:    ";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist";
    }
    else {
        data1.open("database1.txt",ios::in|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product New Code:";
                cin >>c;
                cout<<"\n\t\t Name Of The Product:";
                cin >>n;
                cout<<"\n\t\t price:";
                cin >>p;
                cout<<"\n\t\t Discount:";
                cin >>d;
                data1<< " "<<c<< " "<<n<< " "<<p<< " "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited!";
                token++;
            }
            else
            {
                 data1<< " "<<pcode<< " "<<pname<< " "<<price<< " "<<dis<<"\n";
            }
             data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not Found. SORRY!";
        }
    }

}
void supermarket:: listt()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_____________________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n_____________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"t/t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void supermarket :: receipt()
{
    m:
    fstream data;
    string choice;
    int a[100];
    int a1[100];
    char c=0;
    float amount =0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else
    {
        data.close();

        listt();
        cout<<"\n__________________________________________\n";
        cout<<"\n                                          \n";
        cout<<"\n         Please Place The Order           \n";
        cout<<"\n                                          \n";
        cout<<"\n__________________________________________\n";
        do
        {
            cout<<"\n\nEnter Product Code :";
            cin >> a[c];
            cout<<"\n\nEnter Product Quantity :";
            cin >>a1[c];
            for(int i =0;i<c;i++)
            {
                if(a[c]==a[i])
                {
                    cout<<"\n\n Duplicate Product code.Please Try Again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do YOu Want To Buy Another Product? If you then press yes else no";
            cin >>choice;
        }
        while(choice == "yes");
        cout<<"\n\n\t\t\t_____________________RECEIPT____________________\n";
        cout << "\nProduct No\t Product Quantity\Tprice\tAmount With Discount\n";

        for(int i =0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
              if(pcode==a[i])
                {
                    amount=price*a1[i];
                    dis=amount-(amount*dis/100);
                    total=total +dis;
                    cout<<"\n"<<pcode<<"\t\t"<<a1[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_________________________________________________";
    cout<<"\n Total Amount :" << total;

}

int main()
{
   product p;
    brand b(4.0);
    b.show_cost();

    supermarket s;
    s.manu();
    return 0;
}


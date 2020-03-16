#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int getWhatYouWant();
void displayItems(int x);

int main()
{
    int whatYouWant;
    whatYouWant = getWhatYouWant();
    while(whatYouWant !=0){
      switch(whatYouWant){
        case 1:
          displayItems(1);
          break;
        case 2:
          displayItems(2);
          break;
        case 3:
          displayItems(3);
          break;
      }
      whatYouWant = getWhatYouWant();
  }
}

//getWhatYouWant Function
int getWhatYouWant(){
  int choice;

  cout << "\n   AzCorp Mart    " << endl;
  cout << "\n1 - Login" << endl;
  cout << "2 - Food items" << endl;
  cout << "0 - quit program\n" << endl;
  cout << endl;

  cin >> choice;
  return choice;
}

//display items Function
void displayItems(int x){

  ifstream objectItemsFiles("objects.txt");
  int idNum;
  string itemsName;
  string companyName;
  double price;
  string issueDate;
  string expireDate;
  int categoryNum;

  string userName ="zain";
  string userPassword = "password01";
  string iUserName;
  string iUserPassword;
  int loginAttempt = 0;

  if(x==1){
    while (loginAttempt < 5)
    {
        cout << "\nPlease enter your user name: ";
        cin >> iUserName;
        cout << "Please enter your user password: ";
        cin >> iUserPassword;

        if (iUserName == userName && iUserPassword == userPassword )
        {
          cout << "Welcome!\n";
          break;
        }else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
    }
    cout << "Thank you for logging in.\n";
  }

  if(x==2){
    while(objectItemsFiles >> idNum >> itemsName >> companyName >> price >> issueDate >> expireDate >> categoryNum ){
      cout << "\n" << idNum << "    " << itemsName << "    " << companyName << "    " << price << "    " << issueDate << "    " << expireDate << endl;
    }
  } 
}

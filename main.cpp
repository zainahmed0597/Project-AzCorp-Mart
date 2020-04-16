#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product{
    int pNo; double price; string warranty, companyName, type, productName;
    
    public:
    void createProduct(){
        cout << "\n Please enter the Product No: ";     cin >> pNo;
        cout << "\n Please enter the Product Name: ";     cin >> productName;
        cout << "\n Please enter the Product Company Name: ";     cin >> companyName;
        cout << "\n Please enter the Product Price: ";     cin >> price;
        cout << "\n Please enter the Product Warranty: ";     cin >> warranty;
        cout << "\n Please enter the Product Type: ";     cin >> type;

        ofstream objWrite ("product.txt", ios::app | ios::out);
        objWrite << "\n"<<  pNo << "\t" <<  productName << "\t" << companyName << "\t" << price << "\t" <<  warranty << "\t" << type;
        objWrite.close();   
    }

    void showProduct(){
        ifstream productFileObj;
        productFileObj.open("product.txt", ios::in);

        int pNo1; double price1; string warranty1, companyName1, type1, productName1; 

        if(!productFileObj){
        cout<<"Error in opening file!!!"<<endl;
        }cout<<"File is opening successfully."<<endl;
        
        while(!productFileObj.eof()){
                productFileObj >> pNo1 >> productName1 >> companyName1 >>  price1 >> warranty1 >> type1;
                                 
                cout << "\n" << pNo1 << "    " << productName1 << "    " << price1 << "    " << type1 << endl;
        }
        productFileObj.close();
    }

    void createBill(){   	            	    
  	    ofstream objCreate ("bill.txt", ios::app);
    }

};

class User{
    private:
    string username, password, un, pw;

    public:
    int loginAttempt = 0;
    
    void createAccount(){
        cout << "\nPlease enter your user name: ";
        cin >> username;
        cout << "Please enter your user password: ";
        cin >> password;

        ofstream file;
        file.open("accounts\\" + username + ".txt");
        cout << "You are creating account successfully!!!\n";

        file << username << endl << password;
        file.close();

    }
 
    void login(){
        while (loginAttempt < 5)
        {
            cout << "\nPlease enter your user name: ";
            cin >> username;
            cout << "Please enter your user password: ";
            cin >> password;

            ifstream read("accounts\\" + username + ".txt");
            getline(read, un);
            getline(read, pw);

            if (un == username && pw == password){
			    cout << "Welcome!\n";
                cout << "Thank you for logging in.\n";
                break;
            }
            else
            {
                cout << "Invalid login attempt. Please try again.\n" << '\n';
                loginAttempt++;
            }
            
        }
        if (loginAttempt == 5){
            cout << "Too many login attempts! The program will now close."; 
        }
        
    }
};


//display items Function
void displayItems(int x){

  if(x==1){
    User user;
    user.login();
  }
  if(x==2){
      Product product;
      product.showProduct();
  }
}//________________________________

//display items Function
void displayItems2(int x){

  if(x==1){
    Product product;
    product.showProduct();
  }
  if(x==2){
    Product product;
    product.createProduct();
  }
  if(x==3){
      
  }
  if(x==4){
      
  }
}//________________________________

//Step1 Function
int Step1(){
  int choice;

  cout << "\n   AzCorp Mart    " << endl;
  cout << "\n1 - Login" << endl;
  cout << "2 - Shop Products" << endl;
  cout << "3 - quit program\n" << endl;
  cout << endl;

  cin >> choice;
  return choice;
}

//Step2 Function
int Step2(){
  int choice;

  cout << "\n   AzCorp Mart    " << endl;
  cout << "\n1 - Shop Products" << endl;
  cout << "2 - Create Products" << endl;
  cout << "3 - Edit Products" << endl;
  cout << "4 - Delete Products" << endl;
  cout << "5 - Exit Program\n" << endl;
  cout << endl;

  cin >> choice;
  return choice;
}


int main(){

    int whatStep2Want;
    int whatYouWant;
    whatYouWant = Step1();
    while(whatYouWant !=3){
      switch(whatYouWant){
        case 1:
          displayItems(1);
          whatStep2Want = Step2();
              while(whatStep2Want !=5){
              switch(whatStep2Want){
                case 1:
                  displayItems2(1);
                  break;
                case 2:
                  displayItems2(2);
                  break;
                case 3:
                  displayItems2(3);
                  break; 
                case 4:
                  displayItems2(4);
                  break;   
              } 
              whatStep2Want = Step2();
          break;

        case 2:
          displayItems(2);
          break;
        } 
      whatYouWant = Step1();
    }
  }
}
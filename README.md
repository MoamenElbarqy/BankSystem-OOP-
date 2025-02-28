# 🏦 BankSystem  

**BankSystem** developed using **Object-Oriented Programming (OOP) in C++**.  
This file-based project simulates real-world banking operations with a strong focus on **security, account management, user management, and financial transactions**.  
The system prevents unauthorized access by automatically locking after three consecutive failed login attempts.  
The system ensures that users without the required permissions cannot perform restricted operations.  
##  Notes

Defualt user to login : 

username : User1

password : 1234

All Phone Numbers And Emails are fake 

## 🛠 Installation Steps  

Follow these steps to set up and run the project on your machine manually:  

### 1️⃣ Download the Project  
1. Click on the **"Code"** button at the top of this repository.  
2. Select **"Download ZIP"** to download the project files.  
3. Extract the ZIP file to a folder on your computer.  

### 2️⃣ Ensure You Have a C++ Compiler  

### 3️⃣ Compile the Project  

### 4️⃣ Run the Program  

##  Note  
Ensure Required Files Exist  

The program requires the following text files **in the same directory**:  
- `Currencies.txt`  
- `Users.txt`  
- `LoginRegister.txt`  
- `TransferLog.txt`  
- `DataClients.txt`  

## 📌 Features  
Testing Features -> (https://drive.google.com/file/d/1b_9j9B_1EYfWbmuc04tWoWGSClYgrmi_/view?usp=drive_link)
### 🔹 Client Management  
- View all registered clients.  
- Add, delete, update, and search for clients.  

### 🔹 User Management  
- Manage system users with different access levels.  
- Add, delete, update, and list users.  

### 🔹 Transaction System  
- Deposit and withdraw funds.  
- Transfer money between accounts.  
- View transaction history and total balances.  

### 🔹 Currency Exchange Operations  
- Display a list of currencies from different countries.  
- Search for a specific currency by its code or country name.  
- Use a built-in currency calculator.  
- Update exchange rates (relative to the US dollar).  

### 🔹 Security & Logging  
- **System Will Close After 3 Failed Login Attempts**  
- **Login Activity Tracking:** Stores login details, including the user, login time, and date in text files.  
- **Transaction Logging:** Records money transfers, including sender and receiver details, transfer time and date, and account balances before and after the transaction.  

### 🔹 File-Based Storage  
- All client and user data is stored in text files, ensuring persistent data storage.  

## 📌 User Interface  

### 🔹 Login Menu  

The login menu looks like this:  

~~~
===============================
         Login Screen      
===============================
 Enter Username: ________
 Enter Password: ________
-------------------------------
~~~
## 📌 Main Menu

Once logged in, users are greeted with the Main Menu, which looks like this:
~~~
===================================
          Main Menu Screen
===================================
[1] Show Client List.  
[2] Add New Client.  
[3] Delete Client.  
[4] Update Client Info.  
[5] Find Client. 
[6] Transactions.  
[7] Manage Users.  
[8] Login Register.  
[9] Currency Exchange.
[10] Logout 
===================================
~~~

## 📌Transactions Menue

Transactions Menue looks like this:
~~~
===================================
          Transactions Menue
===================================
[1] Deposit.  
[2] Withdraw.  
[3] Total Balances.  
[4] Transfer.  
[5] Transfer Data. 
[6] Main Menu.  
===================================
~~~
## 📌Currency Exchange Menue

Currency Exchange Menue looks like this:

~~~
===================================
          Currency Exchange Menue
===================================
[1] List Currencies.  
[2] Find Currencuey.  
[3] Update Rate.  
[4] Currency Calculator. 
[5] Main Menu.   
===================================
~~~

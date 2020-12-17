// Change these first two lines according to your computer locations //
#define BODY_LOCATION "C:\\Users\\BIKRANT PANJIYAR\\Desktop\\C++ project\\mailing\\body.html" // Copy the path of body.html here which is in same project folder you will be using
//copy the html code of email body content in body.html by openening it with notepad. Note the double back slash here in path which is required. 
//Note that your any foramt of mail you have in google docs can be downloaded as html.After downloading if there are imgaes then copy and paste image folder
//and body.html outside of zip folder but inside project folder
//download zip folder or clone vckpkg. Watch this video "https://youtu.be/b7SdgK7Y510" for help and to install vcpkg and
//after completion of integration install openssl by typing ".\vcpkg install openssl" in power shell
#include "C:\\Users\\BIKRANT PANJIYAR\\Desktop\\Github\\vcpckg\\vcpkg\\downloads\\tools\\perl\\5.30.0.1\\c\\lib\\gcc\\i686-w64-mingw32\\8.3.0\\include\\stdfix.h"//SEARCH WHERE IS STDFIX.H AND COPY THE PATH HERE

#include <tchar.h>
//#include <Windows.h>
#include <iostream>
#include <conio.h>  // for _getch() and _getche() // Here getche()
#include <cstdlib>   // for system("cls");
#include <fstream>
#include <cstring>
#define size_recipients 1000 

using namespace std;
const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

#include "EASendMailObj.tlh" //
#include <time.h>
#include <string>
using namespace EASendMailObjLib;//contains the classes necessary to construct and send email


class FrontPage
{
protected:
public:
	void showfrontpage()
	{
		system("cls");
		cout << "\t\t\tMass Mailing using C++" << endl;
		cout << "\t\t\t---------------------" << endl;
		cout << "\n\n\n";
		cout << " The act of sending the same email message to a large number of people at the same time is called Mass Mailing with exciting new Features such as:" << endl;
		cout << "1. To attach files." << endl;
		cout << "2. Use html tags in the body section" << endl;
		cout << "3. Able to send to more than 1000 mails at a time" << endl;
		cout << "4. Paste large no. of mails at once on a file and sent mail to each" << endl;
		cout << "5. Use Predefined body.html format" << endl;
		cout << "\n\n\n\n";
		cout << "Project Members:\n";
		cout << "\tVikrant Panjiyar\n";
		cout << "\tBhupendra Chaulagain\n";
		cout << "\tJeevan Koiri\n";
		cout << "\n\n\t\tPress Any Key to Continue";
		getch();
	}
};
class LogIn : public FrontPage
{
protected:
	char your_address[100];
	char your_password[50];
public:
	void showheader()
	{
		// this is the header
		system("cls");
		cout << "\t\t\tMass Mailing using C++" << endl;
		cout << "\t\t\t---------------------" << endl;
		// this is the session
	}
	

	void getaddress()
	{
		cout << "\n\n\n\t\t\tLog In" << endl;
		// Set your sender email address
		cout << "\t\tEmail:";
		cin >> your_address;
	}

	// to make the password * and while typing in the console
	void getpass()
	{
		int i = 0;  // used in the while loop
		char ch = '\0';
		char password[50]; // to store each character enter by the user

		// main loop for implementating password entering
		cout << "\t\tPassword: ";
		while (1)
		{
			ch = _getch();  // getting a character at each iteration

			if (ch != 8 && ch != 13) // 
			{
				cout << "*";
				password[i] = ch;
				i++;
			}
			else if (ch == 8) // if backspace is presssed
			{
				cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
				i--;
			}
			else if (ch == 13) // 13 represents enter
			{
				password[i] = '\0'; // if enter is pressed, last character in match[] becomes null
				break;         // for end of string
			}
			else
			{
				break;
			}
		}
		cout << endl;
		//cout<< endl << password;
		//doing this using the loop ---> your_pass = password;
		for (int i = 0; password[i] != '\0'; i++)
		{
			your_password[i] = password[i];
		}
		your_password[i] = '\0';
	}
};


class Recipients : public LogIn
{
protected:
	int no_of_recipients;
	int list_choice;
	int consoleOrfile;
	char recipients[1000][50];
public:
	void getrecipient()
	{
		system("cls");
		LogIn l;
		l.showheader();
		cout << "How do you want to enter Recipient:" << endl;
		cout << "1. Console Input/Output\n";
		cout << "2. File Input/Output\n";
		cout << "\nEnter your choice:";
		cin >> consoleOrfile;


		if (consoleOrfile == 2)  // two represent file I/O
		{
			while (true)
			{
				// read the RecipientList.txt file and display the content
				system("cls");
				char ch;
				ifstream infile;
				infile.open("RecipientList.txt", ios::in);
				if (infile.fail()) //Error handling while opening a file
				{
					cout << "The File has no Recipient List." << endl;
					goto down_label;
				}
				cout << "\nThe File contains the following recipients:" << endl;
				no_of_recipients = 0;
				while (infile.get(ch))
				{
					if (ch == '\n')
					{
						no_of_recipients++;
					}
					cout << ch;
				}
				infile.close();
			down_label:
				cout << endl << "What do you Want:" << endl;
				cout << "1. Create New Recipient Lists" << endl;
				cout << "2. Delete file" << endl;
				cout << "3. Append List" << endl;
				cout << "4. Search and delete a Recipient" << endl;
				cout << "5. Exit Outside" << endl;
				cout << "Enter Your choice: ";
				cin >> list_choice;

				if (list_choice == 1)
				{
					// code for creating a file and ask to add the list using File IO
					char ch;
					ofstream outfile;
					outfile.open("RecipientList.txt", ios::out);
					cout << "Start writing the Recipients type ` to exit" << endl;
					while ((ch = cin.get()) != '`')
					{
						outfile.put(ch);
					}
					outfile.close();
					cout << "File written!" << endl;
				}
				else if (list_choice == 2)
				{
					remove("RecipientList.txt");
				}
				else if (list_choice == 3)
				{
					// code for opening file in append mode and writing the content of the file
					char ch;
					ofstream out;
					out.open("RecipientList.txt", ios::app);
					cout << "Start writing the Recipient. Type ` to exit" << endl;
					while ((ch = cin.get()) != '`')
					{
						out.put(ch);
					}
					out.close();
					cout << "File written!" << endl;
				}
				else if (list_choice == 4)
				{
					char ch;
					char choiceyn;
					ifstream cinf;
					cinf.open("RecipientList.txt", ios::in);
					char name[50];
					char search_name[50];
					cout << "Enter the name of the recipient you want to search:";
					cin >> search_name;
					bool found;
					while (!cinf.eof())
					{
						cinf >> name;
						if (strcmp(name, search_name) == 0)
						{
							cout << "Found:";
							found = true;
						}
					}
					cinf.close();

					// deleting 
					if (found)
					{
						cout << "Are you sure you want to delete(y/n): ";
						cin >> choiceyn;
						if (choiceyn == 'y')
						{
							cout << "deleting..." << endl;
							/////
							string line;
							ifstream myfile;
							ofstream temp;
							myfile.open("RecipientList.txt");
							temp.open("temp.txt");
							while (getline(myfile, line))
							{
								if (line != search_name)
									temp << line << endl;
							}
							cout << "The record with the name " << search_name << " has been deleted" << endl;
							myfile.close();
							temp.close();
							remove("RecipientList.txt"); // to delete the file directly
							rename("temp.txt", "RecipientList.txt"); // to rename the file 
							///
							cout << "Deleted" << search_name << endl;
						}
					}
					else
					{
						cout << "Not Found\n";
					}
				}
				else if (list_choice == 5)
				{
					cout << "Exiting ........\n";
					break;
				}
				else
				{
					cout << "You typed wrong." << endl;
					system("cls");
				}
			}
		}
		else // if(consoleOrfile == 1 or anything by default)
		{
			int i = 0;
			no_of_recipients = 0;
			cout << "Enter Address of Recipients. Type stop to stop \n";
			while (true)
			{
				cin >> recipients[i];
				if (strcmp(recipients[i], "stop") == 0)
				{

					break;
				}

				i++;
				no_of_recipients++;
			}

		}
	}
	void showrecipient()
	{
		if (consoleOrfile == 1)
		{
			cout << "Recipients List:" << endl;
			for (int i = 0; i <= no_of_recipients; i++)
			{
				cout << recipients[i] << endl;
			}
		}
		else // for file if (consoleOrfile == 2)
		{

			// Creation of ifstream class object to read the file 
			ifstream fin;
			// by default open mode = ios::in mode 
			fin.open("RecipientList.txt");
			int i = 0;
			// Execute a loop until EOF (End of File) 
			while (fin) {

				// Read a Line from File and store it in a variable 

				fin >> recipients[i];
				i++;
			}
			// Close the file 
			fin.close();
		}

	} // end of the function
	void showrecipientVar()
	{
		cout << "\nRecipients List from its Variable:" << endl;
		for (int i = 0; i <= no_of_recipients; i++)
		{
			cout << recipients[i] << endl;
		}
	}
};

// class to deal with the subject entry
class Subject : public Recipients
{
protected:
	char your_subject[100];
	char subject[100];
	char ch;
public:
	void getsubject()
	{
		int j = 0;  // used in the while loop
		char ch = '\0';
		// main loop for implementating your_subject entering
		cout << "Subject: ";
		while (1)
		{
			ch = _getche();  // getting a character at each iteration

			if (ch != 8 && ch != 13)
			{
				your_subject[j] = ch;
				j++;
			}
			if (ch == 8) // if backspace is presssed
			{
				cout << " \b"; // backspace means clearing the screen from the console
				j--;
			}
			else if (ch == 13) // 13 represents enter
			{
				your_subject[j] = '\0'; // if enter is pressed, last character in match[] becomes null
				break;         // for end of string
			}
		}
	}
	void showsubject()
	{
		cout << "Subject:" << your_subject << endl;
	}
};

// for handling the body 
class Body : public Subject
{
protected:
	char your_body[100000];
	char ch;
	int choice_body;
public:

	void showbody()
	{
		if (choice_body == 1)
			cout << "Body:" << your_body << endl;
		else
			cout << "Attached body.html\n Go and edit the body.html in the directory to change the format of the mail.\n";

	}
};

class Attachments : public Body
{
protected:
	int no_of_attachments;
	char your_attachments[100][50];
public:
	//set attachment
	void getSameAttachToAll()
	{
		cout << "\nEnter the number of attachments you want to send:";
		cin >> no_of_attachments;
		for (int i = 0; i < no_of_attachments; i++)
		{
			cout << "Enter name of your attachment:" << endl;
			cin >> your_attachments[i];
		}
	}
};

// Deals with sending the mail to every recipients
class Mails : public Attachments
{
protected:
	int choice_body;
public:

	void send_to_each_email()
	{
		for (int i = 0; i < no_of_recipients; i++)
		{
			mailSenderWithSameAttachmentToAll(recipients[i], your_address, your_password, your_body, your_attachments, no_of_attachments);
		}
	}

	void mailSenderWithSameAttachmentToAll(char recipient[50], char your_address[100], char your_password[50], char your_body[100000], char your_attachments[100][50], int no_of_attachments)
	{

		::CoInitialize(NULL);
		//IMail is object of EaSend Mail necessary to send mails and support CC,Bcc,mutliple attachments, embedded pictures and all
		IMailPtr oSmtp = NULL;
		oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
		oSmtp->LicenseCode = _T("TryIt");//License code is propertie of Imail object
										 // It will turn your literal into a Unicode wide character literal if and only if you are compiling your sources with Unicode support
		oSmtp->FromAddr = _T(your_address);// FromAddr is propertie of EASendMail object


		oSmtp->AddRecipientEx(_T(recipient), 0); //to whom You want to send 
		// Set email body 

		//set attachment
		for (int i = 0; i < no_of_attachments; i++)
		{
			oSmtp->AddAttachment(your_attachments[i]); //Add attachment is method of IMail object
		}


		// Set HTML body format. BodyFormat property must be set to 1 (text/html) to take effect.        
		oSmtp->BodyFormat = 1;
		if (choice_body == 1)
		{
			oSmtp->BodyText = your_body;
		}
		else
		{
			// Set HTML body text
			// google.png will be imported as embedded image in this email     
			oSmtp->ImportMailEx(_T(BODY_LOCATION));
		}
		// Your SMTP server address
		oSmtp->ServerAddr = _T("smtp.gmail.com");

		oSmtp->Subject = _T(your_subject);

		// User and password for ESMTP authentication, if your server doesn't
		// require User authentication, please remove the following codes.
		oSmtp->UserName = _T(your_address);
		oSmtp->Password = _T(your_password);
		// Most mordern SMTP servers require SSL/TLS connection now.
		// ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
		oSmtp->ConnectType = ConnectTryTLS;

		// If your SMTP server uses 587 port for TLS  connection
		oSmtp->ServerPort = 587;

		// If your SMTP server requires SSL/TLS connection on 25/587/465 port
		//oSmtp->ServerPort = 25 or 587 or 465;
			// oSmtp->ConnectType = ConnectSSLAuto;

		cout << "Start to send email ...\r" << endl;

		if (oSmtp->SendMail() == 0)
		{
			cout << "Email was Sent Successfully to " << recipient << endl;
		}
		else
		{
			cout << "Failed to send email with the following error:\n" << (const TCHAR*)oSmtp->GetLastErrDescription();
		}
	}// end of mail sender

	// get body 
	void getbody()
	{
		cout << "\n";
		// main loop for implementating your_subject entering
		cout << "Body: " << endl;
		cout << "\t1. By Typing in the console" << endl;
		cout << "\t2. Using Predefined Format of body.html" << endl;
		cout << "\nEnter Your choice: ";
		cin >> choice_body;

		// Set HTML body format. BodyFormat property must be set to 1 (text/html) to take effect.        
		//oSmtp->BodyFormat = 1;


		if (choice_body == 1)
		{
			int j = 0;  // used in the while loop
			char ch = '\0';
			cout << "\nStart Typing body text type ` to end:" << endl;
			while (1)
			{
				ch = _getche();  // getting a character at each iteration

				if (ch != 8 && ch != 13 && ch != '`')
				{
					your_body[j] = ch;
					j++;
				}
				else if (ch == 8) // if backspace is presssed
				{
					cout << " \b"; // backspace means clearing the screen from the console
					j--;
				}
				else if (ch == 13) // 13 represents enter
				{
					cout << "\n";
					your_body[j] = '<'; // if enter is pressed, last character in match[] becomes null
					j++;
					your_body[j] = 'b';
					j++;
					your_body[j] = 'r';
					j++;
					your_body[j] = '>';    // <br> in html represents a new line
					j++;
				}
				else
				{
					your_body[j] = '\0';
					//oSmtp->BodyText(your_body);
					break; // for end of loop
				}
			} // end of while loop
		} // end of if condition
		else
		{
			//oSmtp->ImportMailEx(_T("G:\\1. Mass Mailing System\\1. code working\\sending_mails_using-_CPP\\body.html"));
			cout << "Attached body.html" << endl;
		}
	}
};

int main()
{

	int choice;
Relogin:
	Mails* ptr = new Mails;
	// Sender Email and Password
	ptr->showfrontpage();
	ptr->showheader(); // clear screen and show our project name at top as header
	// Log In section 

	ptr->getaddress();  // get email of sender
	ptr->getpass();	// get password of sender

	ptr->showheader();  // clear screen and show our project name at top as header

	//ptr->showsession(); // view your logged in information
Resend:

	// subject of the mail 
	ptr->getsubject();
	// body of the mail
	ptr->getbody();

	// attchment of the mail
	ptr->getSameAttachToAll();

	// recipients of the mail
	ptr->getrecipient();
	ptr->showrecipient();
	ptr->showrecipientVar();

	// sending the mail to each mails from the list of recipients
	ptr->send_to_each_email();
	cout << "\n\n\n1. To Login from another email\n2. To send mails to other recipients from same email\n3. To end\n";
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		delete ptr;
		goto Relogin;
	}
	else if (choice == 2)
	{
		goto Resend;
	}
	else
	{
		cout << "\n\t\t____________________________________\n";
		cout << "\t\t\tThank you!!!";
	}


	return 0;

}

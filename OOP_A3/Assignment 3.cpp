#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//functions
void print(int & choice)
{
	cout << "\t\t\t---------------BANK MANAGEMENT SYSTEM----------------" << endl;
	cout << "\t\t\t\t\t1.User CLient" << endl;
	cout << "\t\t\t\t\t2.Company Client" << endl;
	cout << "\t\t\t\t\t3.Banking Employee" << endl;
	cout << "\t\t\t\t\t4.Exit" << endl;
	cout << "\t\t\t-----------------------------------------------------" << endl;
	cout << "Enter your choice:";
	cin >> choice;
	while (choice < 1 || choice>4)
	{
		cout << "Enter a valid choice:";
		cin >> choice;
	}
}
void sign_menu(int& option)
{
	cout << "--------------------------------------" << endl;
	cout << "1. Sign up                  2.Sign in" << endl;
	cout << "\tEnter your choice:";
	cin >> option;
	while (option < 1 || option>2)
	{
		cout << "Enter a valid choice:";
		cin >> option;
	}
	cout << "--------------------------------------" << endl;
}
long long int generate_card_number(long long int& card_num)
{
	unsigned i;
	card_num = rand() % 9 + 1;
	for (i = 0; i < 15; i++)
	{
		card_num *= 10;
		card_num += rand() % 10;
	}
	return card_num;
}

//classes
class Account_type
{
private:
	int max_limit;
public:
	Account_type(int max)
	{
		max_limit = max;
	}
};
class Bronze :public Account_type
{
public:
	Bronze(int max) :Account_type(max)
	{}

};
class Gold :public Account_type
{
public:
	Gold(int max) :Account_type(max)
	{}
};
class Business :public Account_type
{
public:
	Business(int max) :Account_type(max)
	{}
};

class user
{
private:
	int login_id;
	string password;
public:
	user()
	{
		login_id = 0, password = " ";
	}
	void setdata(int l, string p)
	{
		login_id = l, password = p;
	}
	int getid()
	{
		return login_id;
	}
	virtual void print(int& will) = 0;
};
class user_client :public user
{
private:
	string address, name, cnic, phone, username;
	int limit, balance, card_no;
	Account_type* account;
public:
	user_client() :user()
	{
		address = " ", name = " ", cnic = " ", phone = " ", username = " ", limit = 0, balance = 0;
		account = nullptr;
	}
	void setdata(string fid,string fname,string faddress,string fusername,string fp,string flimit,string fbalance)
	{
		user::setdata(stoi(fid), fp);
		name = fname, address = faddress, username = fusername, limit = stoi(flimit), balance = stoi(fbalance);
	}
	virtual void print(int &will)
	{
			system("CLS");
			cout << "\t\t\t--------------------------OPTONS----------------------------" << endl;
			cout << "\t\t\t\t\t1.Deposit amount" << endl;
			cout << "\t\t\t\t\t2.Withdraw amount" << endl;
			cout << "\t\t\t\t\t3.View account balance & transaction history" << endl;
			cout << "\t\t\t\t\t4.Transfer funds" << endl;
			cout << "\t\t\t\t\t5.Log out " << endl;
			cout << "\t\t\t------------------------------------------------------------" << endl;
			cout << "Enter your choice:";
			cin >> will;
			while (will < 1 || will>5)
			{
				cout << "Enter a valid choice:";
				cin >> will;
			}
	}
	void signup(int l)
	{
		string p;
		cout << "Enter full name:";
		cin.ignore();
		getline(cin, name);
		cout << "Enter username:";
		getline(cin, username);
		cout << "Enter address:";
		getline(cin, address);
		cout << "Enter CNIC:";
		getline(cin, cnic);
		while (cnic.length() != 13)
		{
			cout << "Enter valid cnic:";
			getline(cin, cnic);
		}
		cout << "Enter phone number:";
		getline(cin, phone);
		cout << "Enter password:";
		getline(cin, p);
		cout << "Enter Maximum daily limit:";
		cin >> limit;
		while (limit < 0 || limit>500000)
		{
			cout << "Enter a valid limit:";
			cin >> limit;
		}
		cout << "Enter the number of cards:";
		cin >> card_no;
		user::setdata(l, p);
		if (limit <= 100000)
		{
			account = new Bronze(limit);
		}
		else if (limit > 100000 && limit <= 500000)
		{
			account = new Gold(limit);
		}
		ofstream enter;
		enter.open("Pending.txt", ios::app);
		enter << l << "," << name << "," << address << "," << cnic << "," << username << "," << p << "," << limit << ",0," <<card_no<< "\n";
		enter.close();
		cout << "---------------------------------------------" << endl;
		cout << "Your request has been forwarded successfully" << endl;
		cout << "---------------------------------------------" << endl;
	}
	bool signin()
	{
		int s = 0,min=0;
		string** c_info;
		string username, pass,fid,fname,faddress,fcnic,card,fusername,fp,flimit,fbalance,pin;
		cout << "Enter username:";
		cin.ignore();
		getline(cin, username);
		cout << "Enter password:";
		getline(cin, pass);
		ifstream verify;
		verify.open("Users.txt");
		if (verify.fail())
		{
			cout << "User not found!" << endl;
			return false;
		}
		else
		{
			while (!verify.eof())
			{
				getline(verify, fid, ',');
				getline(verify, fname, ',');
				getline(verify, faddress, ',');
				getline(verify, fcnic, ',');
				getline(verify, fusername, ',');
				getline(verify, fp, ',');
				getline(verify, flimit, ',');
				getline(verify, fbalance, ',');
				getline(verify, card, '\n');
				if (limit <= 100000)
				{
					account = new Bronze(limit);
				}
				else if (limit > 100000 && limit <= 500000)
				{
					account = new Gold(limit);
				}
				if (username == fusername && pass == fp)
				{
					setdata(fid, fname, faddress, fusername, fp, flimit, fbalance);
					c_info=loadcards(s);
					for (int i = 0; i < s; i++)
					{
						if (c_info[i][0] == fid)
						{
							min++;
						}
					}
					ofstream oop;
					oop.open("Cards.txt", ios::app);
					if (min == 0||oop.fail())
					{
						
						for (int i = 0; i < stoi(card); i++)
						{
							long long  int picnic;
							generate_card_number(picnic);
							cout << "Card number: " << picnic << endl;
							cout << "Enter the pin of card:";
							cin >> pin;
							oop << fid << "," << picnic << "," << pin << ",0\n";
						
						}
					}	oop.close();
					cout << "-----------------------" << endl;
					cout << "Sign in successfull!";
					cout << "-----------------------" << endl;
					verify.close();
					return true;
				}
			}
			cout << "------------------------" << endl;
			cout << "Sign in unsuccessfull!";
			cout << "------------------------" << endl;
			verify.close();
			return false;
		}
	}
	static string** loaduser(int &c)
	{
		string** data;
		string waste;
		ifstream find;
		find.open("Users.txt");
		while (!find.eof())
		{
			getline(find, waste, '\n');
			c++;
		}
		if (c > 1)
		{
			c -= 1;
		}
		find.close();
		data = new string * [c];
		for (int i = 0; i < c; i++)
		{
			data[i] = new string[9];
		}
		ifstream fill; fill.open("Users.txt");
		for (int i = 0; i < c; i++)
		{
			getline(fill, data[i][0], ',');
			getline(fill, data[i][1], ',');
			getline(fill, data[i][2], ',');
			getline(fill, data[i][3], ',');
			getline(fill, data[i][4], ',');
			getline(fill, data[i][5], ',');
			getline(fill, data[i][6], ',');
			getline(fill, data[i][7], ',');
			getline(fill, data[i][8], '\n');
		}
		fill.close();
		return data;
	}
	static void updateuser(string** data, int c)
	{
		ofstream update;
		update.open("Users.txt");
		for (int i = 0; i < c; i++)
		{
			update << data[i][0] << "," << data[i][1] << "," << data[i][2] << "," << data[i][3] << "," << data[i][4] << "," << data[i][5] << "," << data[i][6] << "," << data[i][7] <<","<< data[i][8] << "\n";
		}
		update.close();
	}
	static string** loadcards(int &c)
	{
		string** data;
		string waste;
		ifstream find;
		find.open("Cards.txt");
		if (find.fail())
		{
			return nullptr;
		}
		while (!find.eof())
		{
			getline(find, waste, '\n');
			c++;
		}
		if (c > 1)
		{
			c -= 1;
		}
		find.close();
		data = new string * [c];
		for (int i = 0; i < c; i++)
		{
			data[i] = new string[4];
		}
		ifstream fill;
		fill.open("Cards.txt");
		for (int i = 0; i < c; i++)
		{
			getline(fill, data[i][0], ',');
			getline(fill, data[i][1], ',');
			getline(fill, data[i][2], ',');
			getline(fill, data[i][3], '\n');
		}
		fill.close();
		return data;
	}
	static void updatecards(string** data, int c)
	{
		ofstream update;
		update.open("Cards.txt");
		for (int i = 0; i < c; i++)
		{
			update << data[i][0] << "," << data[i][1] << "," << data[i][2] << "," << data[i][3] << "\n";
		}
		update.close();
	}
	void depositamount()
	{
		int amount,s=0,c=0,pin,chance=0,x=0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to deposit:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		string** data = loaduser(s);
		cards = loadcards(c);
		for (int i = 0; i < s; i++)
		{
			if (stoi(data[i][0]) == getid())
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either account is blocked!" << endl;
					cout << "------------------------------" << endl;
					return;
				}
				else
				{
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
					P:
					cout << "Enter the pin : ";
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid() && stoll(cards[i][1]) == num && chance < 2)
						{
							if (stoi(cards[i][2]) == pin)
							{
								cards[i][3] = to_string(stoi(cards[i][3]) + amount);
								for (int i = 0; i < s; i++)
								{
									if (stoi(data[i][0]) == getid())
									{

										data[i][7] = to_string(stoi(data[i][7]) + amount);
									}
								}
								x++;
							}
							else
							{
								chance++;
								goto P;
							}
							if (x != 0)
							{
								cout << "---------------------------------" << endl;
								cout << "Amount deposited successfully!" << endl;
								cout << "---------------------------------" << endl;
								updateuser(data, s);
								updatecards(cards, c);
								ofstream write;
								write.open("Transactions.txt", ios::app);
								write << date << "," << getid() << "," << amount << ",Deposit\n";
								write.close();
								return;
							}
						}
						if (chance == 2)
						{
							cout << "-----------------------" << endl;
							cout << "Transaction failed!" << endl;
							cout << "Incorrect pin entered " << endl;
							cout << "-----------------------" << endl;
							ofstream ill;
							ill.open("TBFroozen.txt", ios::app);
							ill << getid() << "\n";
							ill.close();
							for (int i = 0; i < s; i++)
							{
								if (stoi(data[i][0]) == getid())
								{
									data[i][6] = "-1";
								}

							}goto o;
						}
					}
				}
			}
		}
		o:
		if (chance == 2)
		{
			cout << "--------------------------------------" << endl;
			cout << "Account has been closed temporarily or amount is greater than limit!" << endl;
			cout << "--------------------------------------" << endl;
			updateuser(data, s);
			updatecards(cards, c);
		}
	}
	void withdrawamount()
	{
		int amount, s = 0, c = 0, pin, chance = 0, x = 0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to withdraw:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		string** data = loaduser(s);
		cards = loadcards(c);
		for (int i = 0; i < s; i++)
		{
			if (stoi(data[i][0]) == getid())
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either amount is greater than limit or account is blocked!" << endl;
					cout << "------------------------------" << endl;
				}
				else
				{
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
					cout << "Enter the pin : ";
				P:
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid() && stoll(cards[i][1]) == num && chance < 2)
						{
							if (stoi(cards[i][2]) == pin)
							{
								if (stoi(cards[i][3]) < amount)
								{
									cout << "------------------------" << endl;
									cout << "Transaction failed!" << endl;
									cout << "Not enough money in the account" << endl;
									cout << "------------------------" << endl;
									return;
								}
								else
								{
									cards[i][3] = to_string(stoi(cards[i][3]) - amount);
									for (int i = 0; i < s; i++)
									{
										if (stoi(data[i][0]) == getid())
										{
											data[i][7] = to_string(stoi(data[i][7]) - amount);
										}
									}
									x++;
								}
							}
							else
							{
								chance++;
								goto P;
							}
							if (x != 0)
							{
								cout << "---------------------------------" << endl;
								cout << "Amount withdrawn successfully!" << endl;
								cout << "---------------------------------" << endl;
								updateuser(data, s);
								updatecards(cards, c);
								ofstream write;
								write.open("Transactions.txt", ios::app);
								write << date << "," << getid() << "," << amount << ",Withdraw\n";
								write.close();
								return;
							}
						}
						if (chance == 2)
						{
							cout << "-----------------------" << endl;
							cout << "Transaction failed!" << endl;
							cout << "-----------------------" << endl;
							ofstream ill;
							ill.open("TBFroozen.txt", ios::app);
							ill << getid() << "\n";
							ill.close();
							for (int i = 0; i < s; i++)
							{
								if (stoi(data[i][0]) == getid())
								{
									data[i][6] = "-1";
								}

							}goto o;
						}
					}
				}
			}
		}
	o:
		if (chance == 2)
		{
			cout << "---------------------------------------" << endl;
			cout << "Account has been closed temporarily!" << endl;
			cout << "---------------------------------------" << endl;
			updateuser(data, s);
			updatecards(cards, c);
		}
	}
	void transferfunds()
	{
		int amount, s = 0, c = 0, pin, chance = 0, x = 0,rid,good=0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to transfer:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		cout << "Enter the id of recipient account:";
		cin >> rid;
		string** data = loaduser(s);
		cards = loadcards(c);
		for (int i = 0; i < s; i++)
		{
			for (int i = 0; i < s; i++)
			{
				if (stoi(data[i][0]) == rid)
				{
					good++;
				}
			}
			if (good == 0)
			{
				cout << "------------------------------" << endl;
				cout << "Transaction failed!" << endl;
				cout << "Recipient ID does not exist!" << endl;
				cout << "------------------------------" << endl;
				return;
			}
			if (stoi(data[i][0]) == getid())
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either amount is greater than limit or account is blocked!" << endl;
					cout << "------------------------------" << endl;
					return;
				}
				else
				{
					for (int i = 0; i < s; i++)
					{
						if (stoi(data[i][0]) == rid)
						{
							for (int i = 0; i < c; i++)
							{
								if (stoi(cards[i][0]) == rid)
								{
									cards[i][3] = to_string(stoi(cards[i][3]) + amount);
									break;
								}
							}
							data[i][7] = to_string(stoi(data[i][7]) + amount);
						}
					}
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
				P:
					cout << "Enter the pin : ";
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid() && stoll(cards[i][1]) == num && chance < 2)
						{
							if (stoi(cards[i][3]) < amount)
							{
								cout << "------------------------" << endl;
								cout << "Transaction failed!" << endl;
								cout << "Not enough money in the account" << endl;
								cout << "------------------------" << endl;
								return;
							}
							else
							{
								if (stoi(cards[i][2]) == pin)
								{
									cards[i][3] = to_string(stoi(cards[i][3]) - amount);
									for (int i = 0; i < s; i++)
									{
										if (stoi(data[i][0]) == getid())
										{
											data[i][7] = to_string(stoi(data[i][7]) - amount);
										}
									}
									x++;
								}
								else
								{
									chance++;
									goto P;
								}
								if (x != 0)
								{
									cout << "-----------------------------------" << endl;
									cout << "Amount transferred successfully!" << endl;
									cout << "-----------------------------------" << endl;
									updateuser(data, s);
									updatecards(cards, c);
									ofstream write;
									write.open("Transactions.txt", ios::app);
									write << date << "," << getid() << "," << amount << ",Transfer," << rid << "\n";
									write.close();
									return;
								}
							}
							if (chance == 2)
							{
								cout << "------------------------" << endl;
								cout << "Transaction failed!" << endl;
								cout << "Incorrect pin entered " << endl;
								cout << "------------------------" << endl;
								ofstream ill;
								ill.open("TBFroozen.txt", ios::app);
								ill << getid() << "\n";
								ill.close();
								for (int i = 0; i < s; i++)
								{
									if (stoi(data[i][0]) == getid())
									{
										data[i][6] = "-1";
									}

								}goto o;
							}
						}
					}
				}
			}
		}
	o:
		if (chance == 2)
		{
			cout << "---------------------------------------" << endl;
			cout << "Account has been closed temporarily!" << endl;
			cout << "---------------------------------------" << endl;
			updateuser(data, s);
			updatecards(cards, c);
		}
	}
	void viewhistory()
	{
		cout << "------------------------------------------------------------" << endl;
		int s = 0;
		string** user = loaduser(s);
		cout << "Account Balance: ";
		for (int i = 0; i < s; i++)
		{
		if (stoi(user[i][0])==getid())
			cout<< user[i][7]<< endl;
		}
		ifstream loop;
		loop.open("Transactions.txt");
		if (loop.fail())
		{
			cout << "No transactions has been made!" << endl;
		}
		else
		{
			cout << "-------------------TRANSACTION HISTORY--------------------" << endl;
			string random;
			int count = 0;
			while (!loop.eof())
			{
				getline(loop, random, '\n');
				count++;
			}
			if (count > 1)
			{
				count -= 1;
			}
			loop.close();
			string** history = new string * [count];
			for (int i = 0; i < count; i++)
			{
				history[i] = new string[4];
			}
			ifstream learn;
			learn.open("Transactions.txt");
			for (int i = 0; i < count; i++)
			{
				getline(learn, history[i][0], ',');
				getline(learn, history[i][1], ',');
				getline(learn, history[i][2], ',');
				getline(learn, history[i][3], '\n');
			}
			learn.close();
			for (int i = 0; i < count; i++)
			{
				if ((history[i][3] == "Deposit" || history[i][3] == "Withdraw") && stoi(history[i][1]) == getid())
				{
					cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "   Description: " << history[i][3] << endl;
				}
				else if (stoi(history[i][1]) == getid())
				{
					cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "    Description: " << history[i][3] << " :Recipient ID" << endl;

				}

			}
		}
		cout << "--------------------------------------------------------" << endl;
	}
};
class company_client:public user
{
private:
	string name, address, username;
	int tax, limit, balance,card_no;
	Account_type* account;
public:
	company_client() :user()
	{
			name = " ", address = " ", username = " ", tax = 0, limit = 0, balance = 0, account = nullptr;
	}
	void setdata(string fid, string fname, string faddress, string fusername, string fp, string flimit, string fbalance)
	{
		user::setdata(stoi(fid), fp);
		name = fname, address = faddress, username = fusername, limit = stoi(flimit), balance = stoi(fbalance);
	}
	virtual void print(int& will)
	{
		system("CLS");
		cout << "\t\t\t--------------------------OPTONS----------------------------" << endl;
		cout << "\t\t\t\t\t1.Deposit amount" << endl;
		cout << "\t\t\t\t\t2.Withdraw amount" << endl;
		cout << "\t\t\t\t\t3.View account balance & transaction history" << endl;
		cout << "\t\t\t\t\t4.Transfer funds" << endl;
		cout << "\t\t\t\t\t5.Request loan" << endl;
		cout << "\t\t\t\t\t6.Log out " << endl;
		cout << "\t\t\t------------------------------------------------------------" << endl;
		cout << "Enter your choice:";
		cin >> will;
		while (will < 1 || will>6)
		{
			cout << "Enter a valid choice:";
			cin >> will;
		}
	}
	void signup(int l)
	{
		string p;
		cout << "Enter company name:";
		cin.ignore();
		getline(cin, name);
		cout << "Enter company username:";
		getline(cin, username);
		cout << "Enter address:";
		getline(cin, address);
		cout << "Enter tax number:";
		cin >> tax;
		string t = to_string(tax);
		while  (t.length() != 5)
		{
			cout << "Enter valid tax number:";
			cin >> tax;
		}
		cout << "Enter password:";
		cin.ignore();
		getline(cin, p);
		cout << "Enter Maximum daily limit:";
		cin >> limit;
		while (limit < 0 || limit>20000000)
		{
			cout << "Enter a valid limit:";
			cin >> limit;
		}
		cout << "Enter the number of cards:";
		cin >> card_no;
		user::setdata(l, p);
		if (limit <= 100000)
		{
			account = new Bronze(limit);
		}
		else if (limit > 100000 && limit <= 500000)
		{
			account = new Gold(limit);
		}
		else if(limit>500000&&limit<=20000000)
		{
			account = new Business(limit);
		}
		ofstream enter;
		enter.open("Pending.txt", ios::app);
		enter << l << "," << name << "," << address << "," << tax << "," << username << "," << p << "," << limit << ",0," << card_no << "\n";
		enter.close();
		cout << "---------------------------------------------" << endl;
		cout << "Your request has been forwarded successfully" << endl;
		cout << "---------------------------------------------" << endl;

	}
	bool signin()
	{
		int s = 0, min = 0, employee_num, user_id;
		string** c_info;
		string name, pass, fid, fname, faddress, ftax,card,pin, fusername, fp, flimit, fbalance,unique;
		cout << "Enter username:";
		cin.ignore();
		getline(cin, name);
		cout << "Enter password:";
		getline(cin, pass);
		ifstream verify;
		verify.open("Companies.txt");
		if (verify.fail())
		{
			cout << "User not found!" << endl;
			return false;
		}
		else
		{
			while (!verify.eof())
			{
				getline(verify, fid, ',');
				getline(verify, fname, ',');
				getline(verify, faddress, ',');
				getline(verify, ftax, ',');
				getline(verify, fusername, ',');
				getline(verify, fp, ',');
				getline(verify, flimit, ',');
				getline(verify, fbalance, ',');
				getline(verify, card, '\n');
				if (limit <= 100000)
				{
					account = new Bronze(limit);
				}
				else if (limit > 100000 && limit <= 500000)
				{
					account = new Gold(limit);
				}
				else if (limit > 500000 && limit <= 20000000)
				{
					account = new Business(limit);
				}
				if (name == fusername && pass == fp)
				{
					setdata(fid, fname, faddress, fusername, fp, flimit, fbalance);
					ifstream king;
					king.open("Cards.txt");
					if (!king.fail())
					{
						c_info = user_client::loadcards(s);
						for (int i = 0; i < s; i++)
						{
							if (c_info[i][0] == fid)
							{
								min++;
							}
						}
					}
					if (min == 0)
					{
						ofstream oop;
						oop.open("Cards.txt", ios::app);
						for (int i = 0; i < stoi(card); i++)
						{
							long long  int picnic;
							generate_card_number(picnic);
							cout << "Card number: " << picnic << endl;
							cout << "Enter the pin of card:";
							cin >> pin;
							oop << fid << "," << picnic << "," << pin << ",0\n";
							oop.close();
						}
						ofstream wet;
						wet.open("Companies_employees.txt", ios::app);
						cout << "Enter the number of your employees:";
						cin >> employee_num;
						for (int i = 0; i < employee_num; i++)
						{
							cout << "Enter the ID of employee:";
							cin >> user_id;
							ifstream down;
							down.open("Unique.txt");
							down>>unique;
							while (user_id > stoi(unique))
							{
								cout << "Enter current employee ID:";
								cin >> user_id;
							}
							wet << fid << "," << user_id << "\n";
						}
						wet.close();
					}
					cout << "-----------------------" << endl;
					cout << "Sign in successfull!"<<endl;
					cout << "-----------------------" << endl;
					verify.close();
					return true;
				}
			}
			cout << "----------------------" << endl;
			cout << "Sign in unsuccessfull!"<<endl;
			cout << "----------------------" << endl;
			verify.close();
			return false;
		}
	}
	static string** loadclients(int& c)
	{
		string** data;
		string waste;
		ifstream find;
		find.open("Companies.txt");
		while (!find.eof())
		{
			getline(find, waste, '\n');
			c++;
		}
		if (c > 1)
		{
			c -= 1;
		}
		find.close();
		data = new string * [c];
		for (int i = 0; i < c; i++)
		{
			data[i] = new string[9];
		}
		ifstream fill; fill.open("Companies.txt");
		for (int i = 0; i < c; i++)
		{
			getline(fill, data[i][0], ',');
			getline(fill, data[i][1], ',');
			getline(fill, data[i][2], ',');
			getline(fill, data[i][3], ',');
			getline(fill, data[i][4], ',');
			getline(fill, data[i][5], ',');
			getline(fill, data[i][6], ',');
			getline(fill, data[i][7], ',');
			getline(fill, data[i][8], '\n');
		}
		fill.close();
		return data;
	}
	static void updateclients(string** data, int c)
	{
		ofstream update;
		update.open("Companies.txt");
		for (int i = 0; i < c; i++)
		{
			update << data[i][0] << "," << data[i][1] << "," << data[i][2] << "," << data[i][3] << "," << data[i][4] << "," << data[i][5] << "," << data[i][6] << "," << data[i][7] <<","<<data[i][8] << "\n";
		}
		update.close();
	}
	static string** loadcompany_employees(int& c)
	{
		string** data;
		string waste;
		ifstream find;
		find.open("Companies_employees.txt");
		while (!find.eof())
		{
			getline(find, waste, '\n');
			c++;
		}
		if (c > 1)
		{
			c -= 1;
		}
		find.close();
		data = new string * [c];
		for (int i = 0; i < c; i++)
		{
			data[i] = new string[2];
		}
		ifstream fill; fill.open("Companies_employees.txt");
		for (int i = 0; i < c; i++)
		{
			getline(fill, data[i][0], ',');
			getline(fill, data[i][1], '\n');
		}
		fill.close();
		return data;
	}
	void depositamount()
	{
		int amount, s = 0, c = 0, pin, chance = 0, x = 0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to deposit:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		string** data = loadclients(s);
		cards = user_client::loadcards(c);
		for (int i = 0; i < s; i++)
		{
			if (stoi(data[i][0]) == getid())
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either amount is greater than limit  or account is blocked!" << endl;
					cout << "------------------------------" << endl;
					return;
				}
				else
				{
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
				P:
					cout << "Enter the pin : ";
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid() && stoll(cards[i][1]) == num && chance < 2)
						{
							if (stoi(cards[i][2]) == pin)
							{
								cards[i][3] = to_string(stoi(cards[i][3]) + amount);
								for (int i = 0; i < s; i++)
								{
									if (stoi(data[i][0]) == getid())
									{
										data[i][7] = to_string(stoi(data[i][7]) + amount);
									}
								}
								x++;
							}
							else
							{
								chance++;
								goto P;
							}
							if (x != 0)
							{
								cout << "---------------------------------" << endl;
								cout << "Amount deposited successfully!" << endl;
								cout << "---------------------------------" << endl;
								updateclients(data, s);
								user_client::updatecards(cards, c);
								ofstream write;
								write.open("Transactions.txt", ios::app);
								write << date << "," << getid() << "," << amount << ",Deposit\n";
								write.close();
								return;
							}
						}
						if (chance == 2)
						{
							cout << "-----------------------" << endl;
							cout << "Transaction failed!" << endl;
							cout << "-----------------------" << endl;
							ofstream ill;
							ill.open("TBFroozen.txt", ios::app);
							ill << getid() << "\n";
							ill.close();
							for (int i = 0; i < s; i++)
							{
								if (stoi(data[i][0]) == getid())
								{
									data[i][6] = "-1";
								}

							}goto o;
						}
					}
				}
			}
		}
	o:
		if (chance == 2)
		{
			cout << "---------------------------------------" << endl;
			cout << "Account has been closed temporarily!" << endl;
			cout << "---------------------------------------" << endl;
			updateclients(data, s);
			user_client::updatecards(cards, c);
		}
	}
	void withdrawamount()
	{
		int amount, s = 0, c = 0, pin, chance = 0, x = 0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to withdraw:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		string** data = loadclients(s);
		cards = user_client::loadcards(c);
		for (int i = 0; i < s; i++)
		{
			if (stoi(data[i][0]) == getid())
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit) || (amount > balance))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either amount is greater than limit or balance or account is blocked!" << endl;
					cout << "------------------------------" << endl;
					return;
				}
				else
				{
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
					cout << "Enter the pin : ";
				P:
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid() && stoll(cards[i][1]) == num && chance < 2)
						{
							if (stoi(cards[i][2]) == pin)
							{
								if (stoi(cards[i][3]) < amount)
								{
									cout << "----------------------" << endl;
									cout << "Transaction failed!" << endl;
									cout << "Not enough money in the account" << endl;
									cout << "----------------------" << endl;
									return;
								}
								else
								{
									cards[i][3] = to_string(stoi(cards[i][3]) - amount);
									for (int i = 0; i < s; i++)
									{
										if (stoi(data[i][0]) == getid())
										{
											data[i][7] = to_string(stoi(data[i][7]) - amount);
										}
									}
									x++;
								}
							}
							else
							{
								chance++;
								goto P;
							}
							if (x != 0)
							{
								cout << "---------------------------------" << endl;
								cout << "Amount withdrawn successfully!" << endl;
								cout << "---------------------------------" << endl;
								updateclients(data, s);
								user_client::updatecards(cards, c);
								ofstream write;
								write.open("Transactions.txt", ios::app);
								write << date << "," << getid() << "," << amount << ",Withdraw\n";
								write.close();
								return;
							}
						}
						if (chance == 2)
						{
							cout << "----------------------" << endl;
							cout << "Transaction failed!" << endl;
							cout << "----------------------" << endl;
							ofstream ill;
							ill.open("TBFroozen.txt", ios::app);
							ill << getid() << "\n";
							ill.close();
							for (int i = 0; i < s; i++)
							{
								if (stoi(data[i][0]) == getid())
								{
									data[i][6] = "-1";
								}

							}goto o;
						}
					}
				}
			}
		}
	o:
		if (chance == 2)
		{
			cout << "--------------------------------------" << endl;
			cout << "Account has been closed temporarily!" << endl;
			cout << "--------------------------------------" << endl;
			updateclients(data, s);
			user_client::updatecards(cards, c);
		}
	}
	void transferfunds()
	{
		int amount, s = 0, c = 0, pin, chance = 0, x = 0, rid, good = 0,size=0;
		long long int num;
		string** cards;
		string date;
		cout << "Enter the amount you want to transfer:";
		cin >> amount;
		while (amount < 0)
		{
			cout << "Enter amount greater than 0:";
			cin >> amount;
		}
		cout << "Enter date (XX-XX-XXXX):";
		cin >> date;
		cout << "Enter the id of recipient account:";
		cin >> rid;
		string** data = user_client::loaduser(s);
		cards = user_client::loadcards(c);
		string** ce = loadcompany_employees(size);
		for (int i = 0; i < s; i++)
		{
			for (int i = 0; i < size; i++)
			{
				if (stoi(ce[i][1]) == rid)
				{
					good++;
				}
			}	
			if (good == 0)
			{
				cout << "-------------------------------------------" << endl;
				cout << "Transaction Failed!" << endl;
				cout << "The user ID is not is part of the company" << endl;
				cout << "-------------------------------------------" << endl;
				return;
			}
			if (stoi(data[i][0]) == rid)
			{
				if ((stoi(data[i][6]) == -1) || (stoi(data[i][7]) == -1) || (amount > limit) || (amount > balance))
				{
					cout << "------------------------------" << endl;
					cout << "Transaction failed!" << endl;
					cout << "Either amount is greater than limit or balance or account is blocked!" << endl;
					cout << "------------------------------" << endl;
					return;
				}
				else
				{
					for (int i = 0; i < s; i++)
					{
						if (stoi(data[i][0]) == rid)
						{
							for (int i = 0; i < c; i++)
							{
								if (stoi(cards[i][0]) == rid)
								{
									cards[i][3] = to_string(stoi(cards[i][3]) + amount);
									break;
								}
							}
							data[i][7] = to_string(stoi(data[i][7]) + amount);
						}
					}
					for (int i = 0; i < c; i++)
					{
						if (stoi(cards[i][0]) == getid())
						{
							cout << "Card number: " << cards[i][1] << endl;
						}
					}
					cout << "Enter the card number:";
					cin >> num;
				P:
					cout << "Enter the pin : ";
					cin >> pin;
					for (int i = 0; i < c; i++)
					{
						if ((stoi(cards[i][0]) == rid) && (stoll(cards[i][1]) == num) && chance < 2)
						{
							if (stoi(cards[i][3]) < amount)
							{
								cout << "------------------------" << endl;
								cout << "Transaction failed!" << endl;
								cout << "Not enough money in the account" << endl;
								cout << "------------------------" << endl;
								return;
							}
							else
							{
								if (stoi(cards[i][2]) == pin)
								{
									int size = 0;
									string** info = loadclients(size);
									for (int i = 0; i < size; i++)
									{
										if (stoi(info[i][0]) == getid())
										{
											info[i][7] = to_string(stoi(info[i][7]) - amount);
										}
									}
									for (int i = 0; i < c; i++)
									{
										if (stoi(cards[i][0]) == getid())
										{
											cards[i][3] = to_string(stoi(cards[i][3]) - amount);
										}
									}
									updateclients(info, size);
									x++;
								}
								else
								{
									chance++;
									goto P;
								}
								if (x != 0)
								{
									cout << "-----------------------------------" << endl;
									cout << "Amount transferred successfully!" << endl;
									cout << "-----------------------------------" << endl;
									user_client::updateuser(data, s);
									user_client::updatecards(cards, c);
									ofstream write;
									write.open("Transactions.txt", ios::app);
									write << date << "," << getid() << "," << amount << ",Transfer," << rid << "\n";
									write.close();
									return;
								}
							}
							if (chance == 2)
							{
								cout << "----------------------" << endl;
								cout << "Transaction failed!" << endl;
								cout << "----------------------" << endl;
								ofstream ill;
								ill.open("TBFroozen.txt", ios::app);
								ill << getid() << "\n";
								ill.close();
								for (int i = 0; i < s; i++)
								{
									if (stoi(data[i][0]) == getid())
									{
										data[i][6] = "-1";
									}

								}goto o;
							}
						}
					}
				}
			}
		}
	o:
		if (chance == 2)
		{
			cout << "----------------------------------------" << endl;
			cout << "Account has been closed temporarily!" << endl;
			cout << "----------------------------------------" << endl;
			user_client::updateuser(data, s);
			user_client::updatecards(cards, c);
		}
	}
	void viewhistory()
	{
		cout << "------------------------------------------------------------" << endl;
		cout << "Account Balance: ";
		int s = 0;
		string** user = loadclients(s);
		cout << "Account Balance: ";
		for (int i = 0; i < s; i++)
		{
			if (stoi(user[i][0]) == getid())
				cout << user[i][7] << endl;
		}
		ifstream loop;
		loop.open("Transactions.txt");
		if (loop.fail())
		{
			cout << "No transactions has been made!" << endl;
		}
		else
		{
			cout << "-------------------TRANSACTION HISTORY--------------------" << endl;
			string random;
			int count = 0;
			while (!loop.eof())
			{
				getline(loop, random, '\n');
				count++;
			}
			if (count > 1)
			{
				count -= 1;
			}
			loop.close();
			string** history = new string * [count];
			for (int i = 0; i < count; i++)
			{
				history[i] = new string[4];
			}
			ifstream learn;
			learn.open("Transactions.txt");
			for (int i = 0; i < count; i++)
			{
				getline(learn, history[i][0], ',');
				getline(learn, history[i][1], ',');
				getline(learn, history[i][2], ',');
				getline(learn, history[i][3], '\n');
			}
			learn.close();
			for (int i = 0; i < count; i++)
			{
				if ((history[i][3] == "Deposit" || history[i][3] == "Withdraw") && stoi(history[i][1]) == getid())
				{
					cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "   Description: " << history[i][3] << endl;
				}
				else if (stoi(history[i][1]) == getid())
				{
					cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "    Description: " << history[i][3] << " :Recipient ID" << endl;

				}

			}
		}
		cout << "--------------------------------------------------------" << endl;
	}
	void requestloan()
	{
		int amount, check = 0,size=0;
		string temp,top;
		cout << "Enter the amount to request for loan:";
		cin >> amount;
		ifstream read;
		read.open("Loaning.txt");
		if (!read.fail())
		{
			while (!read.eof())
			{
				getline(read, temp, '\n');
				size++;
			}
			read.close();
			if (size > 1)
			{
				size -= 1;
			}
			ifstream get;
			get.open("Loaning.txt");
			for(int i=0;i<size;i++)
			{
				getline(get, temp, ',');
				getline(get, top, '\n');
				if (stoi(temp) == getid())
				{
					check++;
				}
			}
			get.close();
		}
		else if(read.fail()||(check==0))
		{
				ofstream enter;
				enter.open("Loaning.txt", ios::app);
				enter << getid() << "," << amount << "\n";
				enter.close();
				cout << "---------------------------------------------" << endl;
				cout << "Your request has been forwarded successfully!" << endl;
				cout << "---------------------------------------------" << endl;
				read.close();
		}
		if(check!=0)
		{
			cout << "---------------------------------------" << endl;
			cout << "You have already availed loan facility!" << endl;
			cout << "---------------------------------------" << endl;
			read.close();
		}
	}
};
class banking_employee :public user
{
private:

public:
	banking_employee() :user() {}
	void setdata(int l, string pass)
	{
		user::setdata(l, pass);
	}
	void signup(int l)
	{
		string pass,name;
		cout << "Enter username:";
		cin.ignore();
		getline(cin, name);
		cout << "Enter password:";
		cin >> pass;
		user::setdata(l, pass);
		ofstream write;
		write.open("Admin.txt", ios::app);
		write << l << "," <<name<<","<< pass << "\n";
		write.close();
		cout << "----------------------" << endl;
		cout << "Sign up successfull!" << endl;
		cout << "----------------------" << endl;
	}
	bool signin()
	{
		int hint = 0;
		string name, pass, fid, fpass,fname;
		cout << "Enter username:";
		cin >> name;
		cout << "Enter password:";
		cin >> pass;
		ifstream you;
		you.open("Admin.txt");
		if (you.fail())
		{
			cout << "User not found!" << endl;
			return false;
		}
		else
		{
			while (!you.eof())
			{
				getline(you, fid, ',');
				getline(you, fname, ',');
				getline(you, fpass, '\n');
				if (name == fname && pass == fpass)
				{
					setdata(stoi(fid), fpass);
					cout << "---------------------" << endl;
					cout << "Sign in successfull!" << endl;
					cout << "---------------------" << endl;
					you.close();
					return true;
				}
			}
		}
		cout << "----------------------" << endl;
		cout << "Sign in unsuccessfull!" << endl;
		cout << "----------------------" << endl;
		you.close();
		return false;
	}
	virtual void print(int& will)
	{
		system("CLS");
		cout << "\t\t\t--------------------------OPTONS----------------------------" << endl;
		cout << "\t\t\t\t\t1.View all client accounts" << endl;
		cout << "\t\t\t\t\t2.Approve or reject new applications" << endl;
		cout << "\t\t\t\t\t3.Approve or reject loans" << endl;
		cout << "\t\t\t\t\t4.View transaction history of an account" << endl;
		cout << "\t\t\t\t\t5.Freeze an account " << endl;
		cout << "\t\t\t\t\t6.Log out" << endl;
		cout << "\t\t\t------------------------------------------------------------" << endl;
		cout << "Enter your choice:";
		cin >> will;
		while (will < 1 || will>6)
		{
			cout << "Enter a valid choice:";
			cin >> will;
		}
	}
	void allow_creation()
	{
		ifstream temp;
		temp.open("Pending.txt");
		if (temp.fail())
		{
			cout << "----------------------" << endl;
			cout << "No requests found!" << endl;
			cout << "----------------------" << endl;
		}
		else
		{
			int count = 0, hint;
			string file, id, name, user, cnic, lmt, bal, add, pass, card_no, pin, waste;
			while (!temp.eof())
			{
				getline(temp, waste, '\n');
				count++;
			}
			if (count > 1)
			{
				count -= 1;
			}
			temp.close();
			ifstream find;
			find.open("Pending.txt");
			for (int i = 0; i < count; i++)
			{
				getline(find, id, ',');
				getline(find, name, ',');
				getline(find, add, ',');
				getline(find, cnic, ',');
				getline(find, user, ',');
				getline(find, pass, ',');
				getline(find, lmt, ',');
				getline(find, bal, ',');
				getline(find, card_no, '\n');
				ofstream write;
				cout << "--------------------------------------------------------------" << endl;
				cout << "Name:" << name << " Daily limit:" << lmt << endl;
				cout << "----------------------------------------------------------------" << endl;
				cout << "To create account press 0:";
				cin >> hint;
				if (hint == 0)
				{
					if (cnic.length() == 13)
					{
						file = "Users";
					}
					else if (cnic.length() == 5)
					{
						file = "Companies";
					}
					write.open(file + ".txt", ios::app);
					write << id << "," << name << "," << add << "," << cnic << "," << user << "," << pass << "," << lmt << "," << bal<<","<<card_no << "\n";
					write.close();
					cout << "Account creation request accepted!" << endl;
					cout << "-----------------------------------" << endl;
				}
				else
				{
					cout << "Account creation request rejected!" << endl;
					cout << "-----------------------------------" << endl;
				}
			}
		}
		remove("Pending.txt");
		temp.close();
	}
	void viewallaccounts()
	{
		//display user clients data
		ifstream user;
		user.open("Users.txt");
		if (user.fail())
		{
			cout << "No user clients data found!" << endl;
		}
		else
		{
			int s = 0;
			string** data = user_client::loaduser(s);
			cout << "--------------------------------------------User Clients---------------------------------------------" << endl;
			for (int i = 0; i < s; i++)
			{
				cout << "ID:" << data[i][0] << " Name:" << data[i][1] << " Address:" << data[i][2] << " CNIC:" << data[i][3] << " Username:" << data[i][4] << " Password:" << data[i][5] << " Daily limit:" << data[i][6] << " Balance:" << data[i][7] << endl;
			}

		}
		user.close();
		//display company clients data
		ifstream client;
		client.open("Users.txt");
		if (client.fail())
		{
			cout << "No company clients data found!" << endl;
		}
		else
		{
			int s = 0;
			string** data = company_client::loadclients(s);
			cout << "--------------------------------------------Company Clients---------------------------------------------" << endl;
			for (int i = 0; i < s; i++)
			{
				cout << "ID:" << data[i][0] << " Name:" << data[i][1] << " Address:" << data[i][2] << " Tax:" << data[i][3] << " Username:" << data[i][4] << " Password:" << data[i][5] << " Daily limit:" << data[i][6] << " Balance:" << data[i][7] << endl;
			}
		}
		client.close();
		cout << "------------------------------------------------------------------------------------------------------" << endl;
	}
	void approveloans()
	{
		ifstream loan;
		loan.open("Loaning.txt");
		if (loan.fail())
		{
			cout << "No request found!" << endl;
		}
		else
		{
			int count = 0, hint, s = 0, c = 0;;
			string id, amount, waste;
			while (!loan.eof())
			{
				getline(loan, waste, '\n');
				count++;
			}
			loan.close();
			if (count > 1)
			{
				count -= 1;
			}
			string** client = company_client::loadclients(s);
			string** card = user_client::loadcards(c);
			ifstream find;
			find.open("Loaning.txt");
			for (int i = 0; i < count; i++)
			{
				getline(find, id, ',');
				getline(find, amount, '\n');
				cout << "ID: " << id << " Amount:" << amount << endl;
				cout << "To grant loan press 0:";
				cin >> hint;
				if (hint == 0)
				{
					for (int i = 0; i < s; i++)
					{
						if (client[i][0] == id)
						{
							client[i][7] = to_string(stoi(client[i][7]) + stoi(amount));
						}
					}
					for (int i = 0; i < c; i++)
					{
						if (card[i][0] == id)
						{
							card[i][3] = to_string(stoi(card[i][3]) + stoi(amount));
							goto LOAN;
						}
					}
					LOAN:
					cout << "Loan request accepted!" << endl;
					cout << "-----------------------" << endl;
				}
				else
				{
					cout << "Loan request rejected!" << endl;
					cout << "-----------------------" << endl;
				}
			}
			find.close();
			company_client::updateclients(client, s);
			user_client::updatecards(card, c);
			remove("Loaning.txt");
		}
		loan.close();
	}
    void viewspecificaccount()
		{
			string tid;
			cout << "Enter ID to view transaction history:";
			cin >> tid;
			cout << "------------------------------------------------------------" << endl;
			ifstream loop;
			loop.open("Transactions.txt");
			if (loop.fail())
			{
				cout << "No transactions has been made!" << endl;
			}
			else
			{
				cout << "-------------------TRANSACTION HISTORY--------------------" << endl;
				string random;
				int count = 0;
				while (!loop.eof())
				{
					getline(loop, random, '\n');
					count++;
				}
				if (count > 1)
				{
					count -= 1;
				}
				loop.close();
				string** history = new string * [count];
				for (int i = 0; i < count; i++)
				{
					history[i] = new string[4];
				}
				ifstream learn;
				learn.open("Transactions.txt");
				for (int i = 0; i < count; i++)
				{
					getline(learn, history[i][0], ',');
					getline(learn, history[i][1], ',');
					getline(learn, history[i][2], ',');
					getline(learn, history[i][3], '\n');
				}
				learn.close();
				for (int i = 0; i < count; i++)
				{
					if ((history[i][3] == "Deposit" || history[i][3] == "Withdraw") && history[i][1] == tid)
					{
						cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "   Description: " << history[i][3] << endl;
					}
					else if (history[i][1] == tid)
					{
						cout << "ID: " << history[i][1] << "   Date: " << history[i][0] << "   Amount: " << history[i][2] << "    Description: " << history[i][3] << " :Recipient ID" << endl;

					}

				}
			}
			cout << "--------------------------------------------------------" << endl;
		}
    void freezeaccount()
	{
		ifstream freeze;
		freeze.open("TBFroozen.txt");
		if (freeze.fail())
		{
			cout << "---------------------" << endl;
			cout << "No requests found!" << endl;
			cout << "---------------------" << endl;
		}
		else
		{
			string waste,id;
			ofstream get;
			int count = 0;
			ifstream good;
			good.open("TBFroozen.txt");
			while (!good.eof())
			{
				getline(good, waste, '\n');
				count++;
			}
			good.close();
			if (count > 1)
			{
				count -= 1;
			}
			int s=0,u=0;
			string** user = user_client::loaduser(u);
			string** client = company_client::loadclients(s);
			ifstream top;
			top.open("TBFroozen.txt");
			for (int i = 0; i < count; i++)
			{
				getline(top, id, '\n');
				for (int j = 0; j < u; j++)
				{
					if (user[j][0] == id)
					{
						user[j][7] = "-1";
						break;
					}
				}
				for (int k = 0; k < s; k++)
				{
					if (client[k][0] == id)
					{
						client[k][7] = "-1";
						break;
					}
				}
			}
			top.close();
			user_client::updateuser(user, u);
			company_client::updateclients(client, s);
			cout << "----------------------------------" << endl;
			cout << "The accounts have been freezed!"<<endl;
			cout << "----------------------------------" << endl;
		}
		freeze.close();
		remove("TBFroozen.txt");
	}
};

int main()
{
	int option,choice,will,index;
	char ch = ' ';
Start:
	
	system("CLS");
	print(choice);
	ifstream rad;
	//code to assign unique id 
	rad.open("Unique.txt");
	if (rad.fail())
	{
		ofstream enter;
		enter.open("Unique.txt");
		enter << "0\n";
		enter.close();
	}
	else
	{
		rad >> index;
		rad.close();
	}
	if (choice == 1)
	{
		ch = ' ';
		sign_menu(option);
		user_client uc_01;
		if (option == 1)
		{
			uc_01.signup(index++);
			ofstream rad;
			rad.open("Unique.txt");
			rad << index;
			rad.close();
			goto Start;
		}
		else if (option == 2)
		{
			if (uc_01.signin())
			{
				while (ch == ' ' || ch == 'y' || ch == 'Y')
				{
					uc_01.print(will);
					if (will == 1)
					{
						 uc_01.depositamount();
					}
					else if (will == 2)
					{
						uc_01.withdrawamount();
					}
					else if (will == 3)
					{
						uc_01.viewhistory();
					}
					else if (will == 4)
					{
						uc_01.transferfunds();
					}
			        else if (will == 5)
			        {
				      goto Start;
			        }
					cout << "To perform anther function press y:";
					cin >> ch;
				}
			}
			else
			{
				goto Start;
			}
		}
	}
	else if (choice == 2)
	{
		ch = ' ';
		sign_menu(option);
		company_client cc_01;
		if (option == 1)
		{
			cc_01.signup(index++);
			ofstream rad;
			rad.open("Unique.txt");
			rad << index;
			rad.close();
			goto Start;
		}
		else if (option == 2)
		{
			if (cc_01.signin())
			{
				while (ch == ' ' || ch == 'y' || ch == 'Y')
				{
					cc_01.print(will);
					if (will == 1)
					{
						cc_01.depositamount();
					}
					else if (will == 2)
					{
						cc_01.withdrawamount();
					}
					else if (will == 3)
					{
						cc_01.viewhistory();
					}
					else if (will == 4)
					{
					    cc_01.transferfunds();
					}
					else if (will == 5)
					{
						cc_01.requestloan();
					}
					else if (will == 6)
					{
						goto Start;
					}
					cout << "To perform anther function press y:";
					cin >> ch;
				}
			}
			else
			{
				goto Start;
			}
		}
	}
	else if (choice == 3)
	{
		ch = ' ';
		sign_menu(option);
		banking_employee be_01;
		if (option == 1)
		{
			be_01.signup(index++);
			ofstream rad;
			rad.open("Unique.txt");
			rad << index;
			rad.close();
			cout << "Please sign in to continue!" << endl;
			cout << "----------------------------" << endl;
			goto Start;
		}
		else if (option == 2)
		{
			if (be_01.signin())
			{
				while (ch == ' ' || ch == 'y' || ch == 'Y')
				{
					be_01.print(will);
					if (will == 1)
					{
						be_01.viewallaccounts();
					}
					else if (will == 2)
					{
						be_01.allow_creation();
					}
					else if (will == 3)
					{
						be_01.approveloans();
					}
					else if (will == 4)
					{
						be_01.viewspecificaccount();
					}
					else if (will == 5)
					{
						be_01.freezeaccount();
					}
					else if (will == 6)
					{
						goto Start;
					}
					cout << "To perform anther function press y:";
					cin >> ch;
				}
			}
			else
			{
				goto Start;
			}
		}
	}
	else if (choice == 4)
	{
		cout << "--------------------------------" << endl;
		cout << "The program has been terminated!" << endl;
		cout << "--------------------------------" << endl;
	}
}
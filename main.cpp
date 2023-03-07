#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <typeinfo>
using namespace std;

class rabotnik
{
	string name;
	string time;
	int vremja;
public:
	virtual void getdata(string &Name, string Time)
	{
		name = Name;
		time = Time;
	}
	virtual int gettime()
	{
		vremja = stoi(time);
		return vremja;
	}
	virtual void showdata()
	{
		cout << name<<"\t";
	}
};
class director : public rabotnik
{
	int koef = 500;
public:
	void getdata(string& Name, string Time)
	{
		rabotnik::getdata(Name, Time);
	}
	void showdata()
	{
		rabotnik::showdata();
		
		cout << gettime() * koef << "$" << endl;
	}	
};
class programmer : public rabotnik
{
	int koef = 350;
public:
	void getdata(string& Namme, string Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		rabotnik::showdata();

		cout  << gettime() * koef << "$" << endl;
	}
};
class assistant : public rabotnik
{
	int koef = 200;
public:
	void getdata(string& Namme, string Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		rabotnik::showdata();
		cout <<  gettime() * koef<<"$" << endl;
	}
};
bool isDirector(rabotnik* pUknown)
{
	director* pdir;
	if (pdir = dynamic_cast<director*>(pUknown))
		return true;
	else
		return false;
}
bool isProgrammer(rabotnik* pUknown)
{
	programmer* pdir;
	if (pdir = dynamic_cast<programmer*>(pUknown))
		return true;
	else
		return false;
}
bool isAssistant(rabotnik* pUknown)
{
	assistant* pdir;
	if (pdir = dynamic_cast<assistant*>(pUknown))
		return true;
	else
		return false;
}
int main()
{
	setlocale(LC_ALL, "ru");
	string data = "/home/dante/Документы/Task1/employes.dat";
	ifstream fin;
	string str;
	string str2;
	vector <string> slova;
	string slovo;
	string Director = "director";
	string Programmer = "programmer";
	string Assistant = "assistant";
	vector <rabotnik*> rab;
	string vibor;
	char ch;
	int temp = 0;
	fin.open(data);
	int size = -1;
	if (fin.is_open())
	{
		cout << "файл открыт" << endl;
		char ch;
		while (fin.get(ch))
		{
			str += ch;
		}

	}
	else
	{
		cout << "ошибка файл не открылся" << endl;
	}
	fin.close();
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == ';')
		{
			temp++;
		}
	}
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] != '\n')
		{
			str2 += str[i];
		}
	}
	for (int j = 0; j < str2.size(); j++)
	{
		if (str2[j] != ';')
		{
			slovo += str2[j];
		}
		else
		{
			slova.push_back(slovo);
			slovo.clear();
		}
	}
	int k = 0;
	for (int j = 0; j < slova.size(); j++)
		{
			if (slova[j] == Director)
			{
				rab.push_back(new director);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
			if (slova[j] == Programmer)
			{ 
				rab.push_back(new programmer);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
			if (slova[j] == Assistant)
			{
				rab.push_back(new assistant);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
		}	
		do {
			cout << "введите профессию: director/programmer/assistant "; cin >> vibor;
			for (int i = 0; i < rab.size() ; i++)
			{
				if (vibor == "director")
				{
					if (isDirector(rab[i]))
					{
						rab[i]->showdata();
					}
				}
				if (vibor == "programmer")
				{
					if (isProgrammer(rab[i]))
					{
						rab[i]->showdata();
					}
				}
				if (vibor == "assistant")
				{
					if (isAssistant(rab[i]))
					{
						rab[i]->showdata();
					}
				}
			}
			cout << "ввести еще? y/n "; cin >> ch;
	}	while (ch != 'n');
	return 0;
}

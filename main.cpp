#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <typeinfo>
using namespace std;

class rabotnik
{protected:
	string name;
	string time;
	int vremja;
public:
	rabotnik(){}
	rabotnik(string &data,vector <string> &slova)
	{	
		int temp = 0;
		string slovo;
		string str;
		string str2;
		ifstream fin;
		fin.open(data);
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

	};
	virtual void getdata(string &Name, string &Time)
	{
		name = Name;
		time = Time;
	}
	virtual int gettime()
	{
		vremja = stoi(time);
	}
	virtual void showdata(){}
	virtual bool isProf(string&){}

	
	
};
class director : public rabotnik
{
	int koef = 500;
public:
	director(){}
	void getdata(string& Name, string &Time)
	{
		rabotnik::getdata(Name, Time);
	}
	void showdata()
	{
		cout << name<<"\t";
		
		cout << gettime() * koef << "$" << endl;
	}	
	bool isProf(string &str)
	{
		return (str=="director");
	}
};
class programmer : public rabotnik
{
	int koef = 350;
public:
	programmer(){}
	void getdata(string& Namme, string &Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		cout << name<<"\t";

		cout  << gettime() * koef << "$" << endl;
	}
	bool isProf(string &str)
	{
		return (str=="programmer");
	}
};
class assistant : public rabotnik
{
	int koef = 200;
public:
	assistant(){}
	void getdata(string& Namme, string Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		cout << name;
		cout <<"\t"<<gettime() * koef<<"$" << endl;
	}
	bool isProf(string &str)
	{
		return (str=="assistant");
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
void Parsdata(vector<string>&slova,vector <rabotnik*> &rab)
{
	int k = 0;
	for (int j = 0; j < slova.size(); j++)
		{
			if (slova[j] == "director")
			{
				rab.push_back(new director);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
			if (slova[j] == "programmer")
			{ 
				rab.push_back(new programmer);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
			if (slova[j] == "assistant")
			{
				rab.push_back(new assistant);
				rab[k++]->getdata(slova[j + 1], slova[j + 2]);
			}
		}	
}
int main()
{
	setlocale(LC_ALL, "ru");
	string data = "/home/dante/Документы/Task1/employes.dat";
	vector <string> slova;
	vector <rabotnik*> rab;
	string vibor;
	char ch;
	rabotnik ParsSlova(data,slova);
	Parsdata(slova,rab);
		do 
		{
			cout << "введите профессию: director/programmer/assistant "; cin >> vibor;
			for (int i = 0; i < rab.size() ; i++)
			{
				if (vibor == "director")
				{
					if (rab[i]->isProf(vibor))
					{
						rab[i]->showdata();
					}
				}
				if (vibor == "programmer")
				{
					if (rab[i]->isProf(vibor))
					{
						rab[i]->showdata();
					}
				}
				if (vibor == "assistant")
				{
					if (rab[i]->isProf(vibor))
					{
						rab[i]->showdata();
					}
				}
			}
			cout << "ввести еще? y/n "; cin >> ch;
	}	while (ch != 'n');
	return 0;
}

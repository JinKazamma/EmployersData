#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;

class worker
{protected:
	string name;
	string timeOfWork;
	int timetoInt;
public:
	worker(){}
	worker(string &data,vector <string> &ArrForParsedWords)
	{	
		string ParsedWord;
		string strToReadData;
		ifstream fin;
		fin.open(data);
		if (fin.is_open())
		{
			cout << "файл открыт" << endl;
			char ch;
			while (fin.get(ch))
			{
				strToReadData += ch;
			}
		}
		else
		{
			cout << "ошибка файл не открылся" << endl;
		}
		fin.close();
		for (int i = 0; i < strToReadData.size() - 1; i++)
		{
			if (strToReadData[i] != '\n'&&strToReadData[i]!=';')
			{
				ParsedWord += strToReadData[i];
			}
			else
			{
				ArrForParsedWords.push_back(ParsedWord);
				ParsedWord.clear();
			}
		}
	};
	void SetData(const string &Name,const string &Time)
	{
		name = Name;
		timeOfWork = Time;
	}
	int gettime()
	{
		timetoInt = stoi(timeOfWork);
	}
	virtual void showdata(){}
	virtual bool isProf(const string&){}	
};
class director : public worker
{
	int koef = 500;
public:
	director(){}
	void SetData(const string& Name, const string &Time)
	{
		worker::SetData(Name, Time);
	}
	void showdata()
	{
		cout << name<<"\t";
		
		cout << gettime() * koef << "$" << endl;
	}	
	bool isProf(const string &str)
	{
		return (str=="director");
	}
};
class programmer : public worker
{
	int koef = 350;
public:
	programmer(){}
	void SetData(const string& Namme,const string &Timme)
	{
		worker::SetData(Namme, Timme);
	}
	void showdata()
	{
		cout << name<<"\t";

		cout  << gettime() * koef << "$" << endl;
	}
	bool isProf(const string &str)
	{
		return (str=="programmer");
	}
};
class assistant : public worker
{
	int koef = 200;
public:
	assistant(){}
	void SetData(const string& Namme,const string Timme)
	{
		worker::SetData(Namme, Timme);
	}
	void showdata()
	{
		cout << name;
		cout <<"\t"<<gettime() * koef<<"$" << endl;
	}
	bool isProf(const string &str)
	{
		return (str=="assistant");
	}
};
void Parsdata(vector<string>&ArrForParsedWords,vector <worker*> &rab)
{
	int k = 0;
	for (int j = 0; j < ArrForParsedWords.size(); j++)
		{
			if (ArrForParsedWords[j] == "director")
			{
				rab.push_back(new director);
				rab[k++]->SetData(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
			if (ArrForParsedWords[j] == "programmer")
			{ 
				rab.push_back(new programmer);
				rab[k++]->SetData(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
			if (ArrForParsedWords[j] == "assistant")
			{
				rab.push_back(new assistant);
				rab[k++]->SetData(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
		}	
}
int main()
{
	setlocale(LC_ALL, "ru");
	string data = "/home/dante/Документы/Task1/employes.dat";
	vector <string> ArrForParsedWords;
	vector <worker*> rab;
	string EnterProfesion;
	char choice;
	worker Parsing(data,ArrForParsedWords);
	Parsdata(ArrForParsedWords,rab);
		do 
		{
			cout << "введите профессию: director/programmer/assistant "; cin >> EnterProfesion;
			for (int i = 0; i < rab.size() ; i++)
			{
				if (EnterProfesion == "director")
				{
					if (rab[i]->isProf(EnterProfesion))
					{
						rab[i]->showdata();
					}
				}
				if (EnterProfesion == "programmer")
				{
					if (rab[i]->isProf(EnterProfesion))
					{
						rab[i]->showdata();
					}
				}
				if (EnterProfesion == "assistant")
				{
					if (rab[i]->isProf(EnterProfesion))
					{
						rab[i]->showdata();
					}
				}
			}
			cout << "ввести еще? y/n "; cin>>choice;
	}	while (choice != 'n');
	return 0;
}

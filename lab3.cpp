#include<iostream>
#include<fstream>
#include<string.h>
#define size 55

using namespace std;

char buffer[size+1];

class student{
	char usn[15];
	char name[20];
	char sem[5];
	char marks[10];
	public:
		void getData();
		void putData();
		void pack();
		void unPack();
		void insert();
		void display();
		void modify (char *key);
		void search(char *key);
};

void student::getData(){
	cout<<"enter usn,name,sem,marks:\n";
	cin>>usn>>name>>sem>>marks;
}

void student::putData(){
	cout<<usn<<"\t"<<name<<"\t\t"<<sem<<"\t"<<marks<<endl;

}
void student::pack(){
	strcpy(buffer,usn);strcat(buffer,"|");
	strcat(buffer,name);strcat(buffer,"|");
	strcat(buffer,sem);strcat(buffer,"|");
	strcat(buffer,marks);
	strcat(buffer,"\n");
}
void student::unPack(){
	char *p;
	p=strtok(buffer,"|");strcpy(usn,p);
	p=strtok(NULL,"|");strcpy(name,p);
	p=strtok(NULL,"|");strcpy(sem,p);
	p=strtok(NULL,"|");strcpy(marks,p);
}
void student::insert(){
	getData();
	pack();
	ofstream fout("data.txt",ios::app);
	fout<<buffer;
	fout.close();
}
void student::display(){
	ifstream fin("data.txt");
	while(!fin.eof()){
		fin.getline(buffer,size+1,'\n');
		if(fin.fail()) 
		break;
		unPack();
		putData();
		}
	fin.close();	
	
	}
	
	

void student::search(char *key){
	ifstream fin("data.txt");
	int count=0;
	while(!fin.eof()){
	fin.getline(buffer,size+1,'\n');
	if(fin.fail())
	break;
	unPack();
		if(strcmp(usn,key)==0){
		putData();
		count++;
		}
	}
	cout<<"Total records found:"<<count<<endl;
	fin.close();
}

void student::modify(char *key){
	ifstream fin("data.txt");
	ofstream fout("temp.txt");
	int count=0;
	while(!fin.eof()){
		fin.getline(buffer,size+1,'\n');
		if(fin.fail()) break;
			unPack();
		if(strcmp(usn,key)==0){
			getData();
			count++;
		}
		pack();
		fout<<buffer;
	}
	if(count==0)
		cout<<"USN not found."<<endl;
	else
		cout<<"Modified."<<endl;
	fin.close();
	fout.close();
	remove("data.txt");
	rename("temp.txt","data.txt");
}
int main(){
	int choice;
	student s;
	char key[15];
	while(1){
		cout<<"1.Insert\n"
			<<"2.Display\n"
			<<"3.Search\n"
			<<"4.Modify\n"
			<<"5.Exit\n"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			s.insert();
			cout<<"Done!"<<endl;
			break;
		case 2:
			cout<<"The contents are:"<<endl;
			s.display();
			cout<<"Done!"<<endl;
			break;
		case 3:
			cout<<"enter the key USN:";
			cin>>key;
			s.search(key);
			cout<<"Done!"<<endl;
			break;
		case 4:
			cout<<"enter te usn to modify:";
			cin>>key;
			s.modify(key);
			cout<<"Done!"<<endl;
			break;
		default:
			return 0;
		}
	}
}



	








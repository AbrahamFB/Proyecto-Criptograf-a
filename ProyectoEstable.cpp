//Proyecto final ITI 2017
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
class Criptograma
{
private:
char alf[28]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z'};
int aux1,aux2,aux3;
public:
void cifradoCesar(){
	char m[100];
	fflush(stdin);
	cout<<"Ingrese frase a cifrar:";
	cin.getline(m,100);
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 27){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux=(j+3)%27;
					m[i]=alf[aux];
					break;
				}
			}
		}
	}
	cout<<"La frase cifrada es: "<<m<<endl<<endl;
}
void descifradoCesar(){
	char m[100];
	fflush(stdin);
	cout<<"Ingrese frase a descifrar:";
	cin.getline(m,100);
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 32){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					int aux;
					if((j-3)<0){
						aux=27+(j-3);
					}
					else{
						aux=(j-3)%27;
					}
					m[i]=alf[aux];
					break;
				}
			}
		}
	}
	cout<<"La frase descifrada es: "<<m<<endl<<endl;
}
void cifradoVigenere (){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese frase a cifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	int k=0;
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 28){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					 aux1=j;
				}
				if(clave[k%strlen(clave)]==alf[j]){
					 aux2=j;
				}
			}
			aux3=(aux1+aux2)%28;
			m[i]=alf[aux3];
			k++;
		}
	}
	cout<<"El mensaje cifrado es:"<<m<<endl<<endl;
}
void descifradoVigenere(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	int k=0;
	for(int i=0; i<strlen(m);i++){
		if(m[i]!= 28){
			for(int j=0;j<strlen(alf);j++){
				if(m[i]==alf[j]){
					 aux1=j;
				}
				if(clave[k%strlen(clave)]==alf[j]){
					 aux2=j;
				}
			}
			if((aux1-aux2)<0){
				aux3=28+(aux1-aux2);
			}
			else{
				aux3=(aux1-aux2)%28;
			}
			m[i]=alf[aux3];
			k++;
		}
	}
	cout<<"El mensaje descifrado es:"<<m<<endl<<endl;
}

};
int main(){
	Criptograma p;
	int opc,opc2,opc3;
	do{
		cout<<"Menu:"<<endl;
		cout<<"1.- Cifrado del Cesar:"<<endl;
		cout<<"2.- Cifrado de Vigenere"<<endl;
		cout<<"4.- Salir"<<endl;
		cout<<"Ingrese Opcion:";
		cin>>opc;

		switch(opc){
			case 1: system("cls");
					do{
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: p.cifradoCesar(); break;
							case 2: p.descifradoCesar(); break;
						}
					}while(opc2!=3);
					system("cls");
					break;

			case 2: system("cls");
					do{
						cout<<"Menu"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc3;
						switch(opc3){
							case 1: p.cifradoVigenere(); break;
							case 2: p.descifradoVigenere(); break;
						}
					}while(opc3!=3);
					system("cls");
					break;
            case 4: cout<<"Otorguenos el 10 xD"<<endl;
		}
	}while(opc!=4);
	getch();
}

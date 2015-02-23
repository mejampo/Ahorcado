#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
int main(int argc, char** argv){

	bool gano;
	int resp;
	string meter= "";
	vector<string> facil;
	vector<string> medio;
	vector<string> dificil;
	int ganado=0;
	int perdido=0;
	vector<string> hangman;
	hangman.push_back("_______ ");
	hangman.push_back("|      | ");
	hangman.push_back("|      | ");
	hangman.push_back("|     ___ ");
	hangman.push_back("|    |O_O| ");
	hangman.push_back("|     --- ");
	hangman.push_back("|      | ");
	hangman.push_back("|   ---|--- ");
	hangman.push_back("|   |  |   |");
	hangman.push_back("|   |  |   |");
	hangman.push_back("|      |    ");
	hangman.push_back("|     ---- ");
	hangman.push_back("|    |    | ");
	hangman.push_back("|    |    | ");
	hangman.push_back("|   _|    |_ ");
	hangman.push_back("|__________________");

	//LLENA VECTORS CON LAS PALABRAS
   		ifstream fe("FACIL.txt"); 
	   while(!fe.eof()) {
	   	fe >> meter;
   		facil.push_back(meter);
 	 	 }
  		 fe.close();

  		 ifstream fe2("MEDIO.txt"); 
	   while(!fe2.eof()) {
	   	fe2 >> meter;
   		medio.push_back(meter);
 	 	 }
  		 fe.close();

  		 ifstream fe3("DIFICIL.txt"); 
	   while(!fe3.eof()) {
	   	fe3 >> meter;
   		dificil.push_back(meter);
 	 	 }
  		 fe.close();
  	// TERMINA DE ABRIR ARCHIVOS


	do{
		int difi;
		cout<<"*********JUEGO DEL AHORCADO*********"<<endl;
		cout<<"-----EN QUE DIFICULTAD DESEA JUGAR?-----\n1.- FACIL\n2.-MEDIO\n3.-DIFICIL"<<endl;
		cin>>difi;

		while(difi!=1&&difi!=2&&difi!=3){
			cout<<"OPCION ERRONEA!!! INTENTE DE NUEVO\n-----EN QUE DIFICULTAD DESEA JUGAR?-----\n1.- FACIL\n2.-MEDIO\n3.-DIFICIL"<<endl;
			cin>>difi;
		}

		if(difi==1){
			int x=0;
			string word;
			string guess;
			int intentos;
			int errors;
			srand (time(0));
			x= rand()%facil.size()-1;
			word = facil[x];
			intentos= word.length();
			errors=intentos;
			vector<string> espacios;
			cout<<"NIVEL FACIL"<<endl;

			for(int i=0;i<word.length();i++){
				espacios.push_back("_");
			}
			do{
			
			cout<<"TIENE "<<intentos<<" INTENTOS"<<endl;
			cin>>guess;

			if(guess.length()==1){
				for(int i=0;i<=word.length();i++){
					if(word[i]==guess[0]){
						cout<<"HA ENCONTRADO UNA LETRA"<<endl;
						espacios[i]=guess;
					}
				}
			}else if(guess.length()>=1){
				if(word==guess){
					gano=true;
					break;
				}
			}else{
				cout<<"ESA LETRA NO SE ENCUENTRA EN LA PALABRA"<<endl;
				errors--;
			}
				
				if(intentos!=word.length()){
					int lineas = 15/errors;
						for(int i=0;i<=lineas;i++){
								cout<<hangman[i]<<endl;
						}
					}	
					cout<<endl;
					for(int l=0;l<=espacios.size();l++){
							cout<< espacios[l];
					}
					cout<<endl;
				intentos--;
			}while(gano==false&&intentos!=0);
		
		}else if(difi==2){


			int x=0;
			string word;
			string guess;
			int intentos;
			int errors;
			srand (time(0));
			x= rand()%medio.size()-1;
			word = medio[x];
			intentos= word.length();
			errors=intentos;
			vector<string> espacios;
			cout<<"NIVEL MEDIO"<<endl;

			for(int i=0;i<word.length();i++){
				espacios.push_back("_");
			}
			do{
			
			cout<<"TIENE "<<intentos<<" INTENTOS"<<endl;
			cin>>guess;

			if(guess.length()==1){
				for(int i=0;i<=word.length();i++){
					if(word[i]==guess[0]){
						cout<<"HA ENCONTRADO UNA LETRA"<<endl;
						espacios[i]=guess;
					}
				}
			}else if(guess.length()>=1){
				if(word==guess){
					gano=true;
					break;
				}
			}else{
				cout<<"ESA LETRA NO SE ENCUENTRA EN LA PALABRA"<<endl;
				errors--;
			}
				
				if(intentos!=word.length()){
						int lineas = 15/errors;
						for(int i=0;i<=lineas;i++){
								cout<<hangman[i]<<endl;
						}
					}	
					cout<<endl;
					for(int l=0;l<=espacios.size();l++){
							cout<< espacios[l];
					}
					cout<<endl;
				intentos--;
			}while(gano==false&&intentos!=0);

		}else if(difi==3){

			int x=0;
			string word;
			string guess;
			int intentos;
			int errors;
			srand (time(0));
			x= rand()%dificil.size()-1;
			word = dificil[x];
			intentos= word.length();
			errors=intentos;
			vector<string> espacios;
			cout<<"NIVEL FACIL"<<endl;

			for(int i=0;i<word.length();i++){
				espacios.push_back("_");
			}
			do{
			
			cout<<"TIENE "<<intentos<<" INTENTOS"<<endl;
			cin>>guess;

			if(guess.length()==1){
				for(int i=0;i<=word.length();i++){
					if(word[i]==guess[0]){
						cout<<"HA ENCONTRADO UNA LETRA"<<endl;
						espacios[i]=guess;
					}
				}
			}else if(guess.length()>=1){
				if(word==guess){
					gano=true;
					break;
				}
			}else{
				cout<<"ESA LETRA NO SE ENCUENTRA EN LA PALABRA"<<endl;
				errors--;
			}
				
				if(intentos!=word.length()){

						int lineas = 15/errors;
						for(int i=0;i<=lineas;i++){
								cout<<hangman[i]<<endl;
						}
					}	
					cout<<endl;
					for(int l=0;l<=espacios.size();l++){
							cout<< espacios[l];
					}
					cout<<endl;
				intentos--;
			}while(gano==false&&intentos!=0);

		}

				if(gano==true){
					cout<<"FELICIDADES HA GANADO ESTA RONDA"<<endl;
					ganado++;
				}else{
					cout<<"PERDIO ESTA VEZ"<<endl;
					perdido++;
				}
		cout<<"Desea jugar de nuevo? \nSI=1\nNO=0"<<endl;
		cin>>resp;
	}while (resp!=0);

	return 0;
}
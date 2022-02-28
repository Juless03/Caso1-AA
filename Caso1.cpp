/* ITCR. Ing.Computación.
   Análisis de algoritmos. GR 1
   Caso #1. 
   Autora: Juleisy Porras Diaz.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define SIZE 3

using namespace std;

//Compare the triplets
/* Compara los números de 2 arrays. El número mayor se lleva el punto. 
   Recibe los arrays a comparar y devuelve un array con los puntos que tuvo cada uno.
*/

void compareTriplets(int array1[], int array2[]){
   int result[] = {0,0}
   for (int i = 0; i < SIZE; i++){  //este for itera 3 veces
      if(array1[i] > array2[i]){    //4 comparaciones del for y 6 internas
         result[0]++;               //7 veces del ++
      }
      if (array2[i] > array1[i]){
         result[1]++;
      }
   }
   cout << result[0] << " , " << result[1] << endl;
}

void compareTriplets2(int array1[], int array2[]){
   int result[] = {0,0}

   if(array1[0] != array2[0]){         //MEJOR VERSION 3 comparaciones y 11 operaciones 
    int valor = (array1[0] - array2[0]) / abs(array1[0] - array2[0]); 
    result[0] += valor + 1;                   
    result[1] += valor - 1;                   
  }
  if(array1[1] != array2[1]){
    int valor = (array1[1] - array2[1]) / abs(array1[1] - array2[1]);
    result[0]+= valor + 1;       
    result[1]+= valor - 1;
  }
  if(array1[2] != array2[2]){
    int valor = (array1[2] - array2[2]) / abs(array1[2] - array2[2]);
    result[0]+= valor + 1;
    result[1]+= valor - 1;
  }

   result[0] = result[0]/2;      
   result[1] = abs(result[1]/2);

   cout << result[0] << " , " << result[1] << endl;
}

//Time conversion
/* Convierte una hora en formato AM/PM a formato 24 horas. 
   Recibe un string de una hora en formato de 12 horas y devuelve un string 
   de la hora convertida en formato de 24 horas.
*/

string timeConversion(string format12h){       //3 comparaciones 
   string format24h = format12h.substr(2, 6);
   int hours = stoi(format12h.substr(0, 2));

   if(hours == 12){
      if(format12h[8] == 'A')
         hours = 0;
   }else if(format12h[8] == 'P'){
      hours += 12;
   }

   format24h = (hours<10) ? "0" + to_string(hours) + format24h : to_string(hours) + format24h;
   return format24h;
}

string timeConversion2(string format12h){
   string format24h = format12h.substr(2, 6);
   int hours = stoi(format12h.substr(0, 2));
   int mod = ((hours % 12) / hours)   //da 0 si las horas son 12PM, sino da -1 
    
   if (format12h[8] == 'A')          //MEJOR VERSION 1 comparación               
      mod--;     //si son las 12AM, da -1, sino da 0

   hours += (12 * mod);

   format24h = (hours<10) ? "0" + to_string(hours) + format24h : to_string(hours) + format24h;
   return format24h;
}

//Subarray division
/* Determina de cuantas maneras se puede dividir una barra de chocolate, deseando que la 
   longitud coincida con el mes de nacimiento y la suma de cada cuadro de chocolate sea igual
   al día de nacimiento.

   Recibe un entero que son los números en cada cuadro de chocolate, un entero del 
   día de nacimiento y un entero del mes de nacimiento. Devuelve un entero
   que representa la cantidad de formas en que se puede dividir la barra.
*/

int arrayAddition(int chocolate[], int squareNumber){
   int addition = 0;
   for (int i = 0; i < squareNumber; i++)  //este for itera la cantidad de veces indicada en squareNumber
      addition += chocolate[i];
   return addition;
}

int subArrayDiv(int chocolate[], int squareNumber, int birthDay, int birthMonth){
   int start = 0;
   int end = 0;
   int result = 0;
   int newArray[birthMonth];
   int portions = 0;

   for(int i = 0; i < birthMonth; i++ ){       //este for itera varias veces, según lo indique el mes de nacimiento,
      newArray[i] = chocolate[portions];       //una comparación y la cantidad de veces que hay en el for de arrayAddition
      portions += 1;
   }
   end += 1;
   start += 1;
   portions = start;

   if(arrayAddition(newArray,birthMonth) == birthDay) 
      result += 1;

   return result;
}


int subArrayDiv2(int chocolate[], int squareNumber,  int birthDay, int birthMonth){
   int start = 0;
   int result = 0;
   int addition = 0;
   int portions = 1;

   for(int i = 0; i< squareNumber; i++){           //MEJOR VERSION: este for itera varias veces, según lo indique el mes 
      addition += chocolate[i];                    //de nacimiento y hay 3 comparaciones

      if (portions == birthMonth && addition == birthDay){
         result += 1;
         addition -= chocolate[start];
         start += 1;
      }else if(portions == birthMonth){
         addition -= chocolate[start];
         start += 1;
      }else
         portions += 1;
   }

   return result;
}

//The Minion game
/* Determina cuantas subpalabras se pueden formar a partir de una palabra dada.
   Stuart debe hacer palabras que inicien con consonantes y Kevin con vocales. 

   Recibe un string con la palabra inicial. Devuelve un string con el nombre y puntuación del ganador, 
   en caso de que no haya ganador, un string con la palabra "Draw"
*/

void minionGame(string word){
   int score[] = {0,0};

   for(int counter=0 ; counter<word.length() ; counter++){
      score[0]+=((word[counter]=='A'||word[counter]=='E'||word[counter]=='I'||word[counter]=='O'||word[counter]=='U')?
                     word.length()-counter:0);
      score[1]+=((word[counter]!='A'&&word[counter]!='E'&&word[counter]!='I'&&word[counter]!='O'&&word[counter]!='U')?
                     word.length()-counter:0);
   }

   if(score[0] > score[1]){
      cout << "Kevin " << score[0] << endl;
   }
   else if(score[0] < score[1]){
      cout << "Stuart "<< score[1] << endl;
   }
   else{
      cout << "Draw" << endl;
   }
}


//Cipher
/* Decodifica un string con base en desplazamiento y longitud aplicados a la hora de 
   encriptarlo.

  Recibe un string con un mensaje codificado, un entero de la longitud y un entero
   de las veces de desplazamiento. Devuelve un string con el mensaje decodificado.
*/

string cipher(string codMessage, int length, int offset){
   vector<char> result(length);

   result[0] = codMessage[0]-48;

    
   for (int i = 1; i < offset; i++) {
        result[i] = codMessage[i-1] ^ codMessage[i];
   }

    // Calcular los elementos de k en adelante
   char aux;
   for (int i = offset; i < length; i++) {
      aux = '0';
      for (int j = i-(offset-1); j < i; j++) {
         aux = aux ^ result[j];
      }
      result[i] = aux ^ codMessage[i];
   }

    // Armar el string con el resultado
   string decMessage = "";
   for (int i = 0; i < length; i++) {
        decMessage += result[i] + 48;
   }
   
   return decMessage;
}

//Pairs
/* Determina el número de pares de elementos de un array que tienen diferencia igual
   al valor de destino.

   Recibe un array con los elementos y un entero que es el valor de destino. Devuelve un entero que 
   son la cantidad de pares que satisfacen el criterio.
*/

int pairs(vector<int> array1, int destinyValue){

   sort(array1.begin(), array1.end());

   int pointers[] = {1, 0, 0};
   int result = 0;
   int diference = 0;


   while (pointers[0] < array1.size()) {
      diference = array1[pointers[0]] - array1[pointers[2]];

        if (diference == destinyValue) {
            result++;
            pointers[0]++;
            continue;
        }

      pointers[((diference - destinyValue)/abs(diference - destinyValue)) + 1 ]++;
   }

   return result;
}

//Main
int main(){
   int a[] = {5,6,7};
   int b[] = {3,6,10};

   int c[] = {17,28,30};
   int d[] = {99,16,8};

   compareTriplets(a, b);
   compareTriplets2(c, d);

   cout << timeConversion("07:05:45PM") << endl;
   cout << timeConversion2("12:01:00AM") << endl;

   int chocolate[] = {2,2,1,3,2};
   int chocolate1[] = {1,1,1,1,1,1}; 
    
   cout << subArrayDiv(chocolate, 5, 4, 2) << endl;
   cout << subArrayDiv2(chocolate1, 6, 3, 2) << endl;

   minionGame("BANANA");
   minionGame("PEAR");

   cout << cipher("1110100110", 7, 4) << endl;
   cout << cipher("1110001", 6, 2) << endl;

   vector<int> array1 = {1,2,3,4};
   vector<int> array2 = {1,5,3,4,2};

   cout << pairs(array1, 1) << endl;
   cout << pairs(array2, 2) << endl;

   return 0;
}
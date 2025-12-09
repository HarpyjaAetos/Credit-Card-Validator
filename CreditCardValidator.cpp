#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
using namespace std;
/*
Using Luhn's Algorithm as the base of this.
Luhn algorithm:
Starting from the rightmost digit, double every second digit.
If doubling results in a two-digit number, sum its digits.
*/

int Digit(const int CardNumber);
int EvenSum(const string CardNumber);
int OddSum(const string CardNumber);
void Amex(const string CardNumber);
void Visa(const string CardNumber);
void MasterCard(const string CardNumber);
void CvvCheck(int length);

int main(){

bool Working = true;
string CardNumber;
int n;
string Card[]= {"1. American Express", "2. Visa Card", "3. MasterCard"};

do{
cout << "What is Type Of Your Card?\n";
for(int i = 0; i < sizeof(Card)/sizeof(Card[0]);i++){
    cout << Card[i] << '\n';
}
cin >> n;
if(n > 3 || n < 1){
    Working = false;
}
else{
    Working = true;
}
}while(Working == false);

do{

cout << "Enter Your Credit Card Number ( without '-' ): ";
cin >> CardNumber;
int result = EvenSum(CardNumber) + OddSum(CardNumber);

if(result%10 != 0){
    cout << "The Given Credit Card Number Is Not Valid. Please RE-ENTER\n";
    Working = false;
}
else{
    Working = true;
}
}while(Working == false);

if(n == 1){
    Amex(CardNumber);
}
if(n == 2){
    Visa(CardNumber);
}
if(n == 3){
    MasterCard(CardNumber);
}
}
int Digit(const int CardNumber){
    return ((CardNumber%10) + ((CardNumber/10)%10)); //since i have to split if the number becomes 2 digits. example 18 -> 1 and 8 --> 9 
}
int EvenSum(const string CardNumber){
int sum = 0;
for(int i = CardNumber.size() - 2; i >= 0; i-=2){
    sum+= Digit((CardNumber[i] - '0')*2); // - '0' as the Digit function is receiving the charcter in int( ASCII value) so to get the actual number we need to subtract the number by ASCII of '0' or 48.
                                          // *2 as we need to times 2 the only even digits in the number
}
return sum;
}
int OddSum(const string CardNumber){
    int sum = 0;
for(int i = CardNumber.size() - 1; i >= 0; i-=2){
    sum+= Digit((CardNumber[i] - '0')); // - '0' as the Digit function is receiving the charcter in int( ASCII value) so to get the actual number we need to subtract the number by ASCII of '0' or 48.
}
return sum;
}
void Amex(const string CardNumber){
if (CardNumber.size() != 15) {
cout << "Invalid American Express Credit Card Number\n";
return;
}

int firstTwo = stoi(CardNumber.substr(0,2));
if((firstTwo != 34) && (firstTwo != 37)){
cout << "The Entered American Express Number Isnt valid";
return;
}
else{
CvvCheck(4);
}
}
void Visa(const string CardNumber){
if (CardNumber.size() != 16) {
cout << "Invalid Visa Credit Card Number\n";
return;
}
if((CardNumber[0] != '4' )){
cout << "Invalid Visa Credit Card Number";
return;
}
else{
CvvCheck(3);
}
}
void MasterCard(const string CardNumber){
if (CardNumber.size() != 16) {
cout << "Invalid MasterCard Credit Card Number\n";
return;
}

int firstTwo  = stoi(CardNumber.substr(0, 2));
int firstFour = stoi(CardNumber.substr(0, 4));
if((firstTwo < 51 || firstTwo > 55) && (firstFour < 2221 || firstFour > 2720)){
cout << "Invalid MasterCard Credit Card Number";
return;
}
else{
    CvvCheck(3);
}
}
void CvvCheck(int length){
bool Working = true;
string cvv;
do{
cout << "Enter The CVV for the Card: ";
cin >> cvv;

bool digitsOnly = true;
for(char c : cvv){
if(c < '0' || c > '9'){
digitsOnly = false;
break;}
}
if(cvv.size() != length || !digitsOnly){
cout << "Wrong CVV! RE-ENTER!\n";
Working = false;
}
else{
Working = true;
}
}while(!Working);
}
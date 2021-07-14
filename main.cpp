/*
Program takes in a string as input and evaluates it as a a valid password. The password is valid if it has at a minimum 2 numbers,
2 of the following special characters ('!', '@', '#', '$', '%', '&', '*'), and a length of at least 7 characters.
If the password passes the check, output 'Strong', else output 'Weak'.
*/
#include <iostream>
#include <string.h>
using namespace std;

const int IMAX = 28;
const int IMIN = 7;

bool passLength(string password){
    bool result=true;

     if(password.length()){
        if(password.length() < IMIN || password.length() > IMAX )
            {
                result = false;
            }else{
                result = true;
                }

     }

    return result;
}

bool checkString(string pass){
    bool output;
    bool checkNo = false;
    bool checkCharacter = false;
    int num = 0;
    int charact =0;

    for(int i = 0; i < pass.length(); i++){
        checkNo = (pass[i] > 48 && pass[i] < 58 );
        if(checkNo){
            num++;
        }

        checkCharacter = ((pass[i] > 32 && pass[i] < 48) || (pass[i] > 57 && pass[i] < 65) ||(pass[i] > 91 && pass[i] < 97) || (pass[i] > 122 && pass[i] < 127) );
              if(checkCharacter){
                charact++;
                }
            }

        if( num <= 1 ||  charact <= 1)
        {
         output = false;
        }else output = true;

    return output;

}

int main() {
    string pass;
    bool output;

    cout << "Input password:" << endl;
    getline(cin, pass);

    if(pass.length()){
        if(!passLength(pass)){
            output = false;
        }
        else{
            if(checkString(pass)){
                output= true;
            }
            else{
                output = false;
                }

        }
    }

        if(output==true){
            cout << "Strong" << endl;

        }else cout << "Weak" << endl;

    return 0;
}

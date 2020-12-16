#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <vector>
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;

class MModel {

public:
    string* str;
    int* gramArr;
    string* nextChar;
    unsigned int var;
    int randNum, k, size, ctr, z, currentGram;
    string* tempArr;
    std::vector<std::string> tempVec;
    
    vector<string> arr;
    vector<int> ctrArr;
    
     
        MModel(string text, int k)
        {
            text.append("_"); //shows that there is a space in the code
            size = text.length();
            this->k = k;
            str = new string[size];
            gramArr = new int[size];
            nextChar = new string[size];
        
            srand(::time(NULL));
            
            
            //initializes string array given the text
            for(int i = 0; i < text.length(); i++)
            {
                str[i].append(text, i, k);
                string temp = str[i];
            }
            
        
            //Finds frequency of each element
            for(int i=0; i < text.length(); i++)
            {
                //char c;
                string temp = str[i];
                
                int z=0;
                int ctr=0;
                while(z != text.length()-1)
                {
                    if(str[z] == temp)
                    {
                        ctr++;
                        nextChar[i].append(text, z + 2, 1);
                    }
                    z++;
                }
                z=0;
                gramArr[i] = ctr;
                
                //*         Uncomment code to get list of array, occurences and next character array     *//
                //cout << str[i] << "  "  << gramArr[i] <<  "  "  << nextChar[i] << "\n" ;
            }
            
        }

        int kOrder()
        {
            
            for(int i=0; i < size; i++)
            {
                cout << str[i] << "  "  << gramArr[i] << "\n";
                
            }
                
            return 0;
        }

        
        int freq(string kgram)
        {
            //Finds frequency of each element (Fix repetitiveness)
            
            
            
            if(kgram.length() != k)
            {
                cout << "KGram not length of k\n";
            }
            else
            {
                cout << "KGram    Frequency \n";
                ctr=0;
                for(int i=0; i < size; i++)
                {
                
                        if(str[i] == kgram)
                        {
                            ctr++;
                        }
                
                }
                
                cout << kgram << "       " << ctr << "\n";
                
            
            }
            return 0;
        
        }

        int freq(string kgram, char c)
        {
            cout << "KGram    Letter   Frequency \n";
            
            if(kgram.length() != k)
            {
                throw new runtime_error("KGram not length of k");
            }
            else
            {
                cout << "KGram    Letter   Frequency \n";
                ctr=0;
                for(int i = 0; i < size-2; i++)
                {
                    if(str[i] == kgram)
                    {
                        string temp = nextChar[i];
                        var = std::count(temp.begin(), temp.end(), c);
                    }
                }
            }
            
            cout << kgram << "       " << c << "        " << var << "\n";
            return var;
        }

        
        char kRand(string kgram)
        {
            
            
            
            if(kgram.length() != k)
            {
                cout << "KGram not length of k";
            }
            else
            {
                cout << "KGram    Random Char\n";
                srand(::time(NULL));
                for(int i = 0; i < size-2; i++)
                {
                        for(int z = 0; z < nextChar[i].length(); z++)
                        {
                            if(kgram == str[i])
                            {
                                string temp;
                                temp.append(nextChar[i], z, 1);
                                tempVec.push_back(temp);
                                randNum = rand() % nextChar[i].length();
                                

                                cout << str[i] <<  "       "  << tempVec[randNum] << "\n" ;
                                i = size-2;
                            }
                        }
                        tempVec.clear();
                        
                    }
                }
            return 0;
        }

        string generate(string kgram, int L)
        {
            string result;
            int resize = size-2;
            
            srand(::time(NULL));
            
            if(kgram.length() != k)
            {
                cout << "KGram not length of k";
            }
            else
            {
                //initializes the first element that will be tested in loop
                for(int i=0; i < resize; i++)
                {
                    if(str[i] == kgram)
                    {
                        currentGram = i;
                        i = resize;
                        result.append(str[currentGram]);
                    }
                }
                
                /*loops for the amount of time that user inputs and takes the currentGram and
                 and searches for it in string array and changes the char to the most
                 similar char. That next gram is now throw onto a vector and randomizes what
                 character is generated
                */
                
                string temp = str[currentGram];
                for(int i=0; i <= L; i++)
                {
                    temp = str[currentGram];
                    
                    for(int z=0; z < resize; z++)
                    {
                        if(temp == str[z])
                        {
                            randNum = rand() % nextChar[currentGram].length() + 0;
                            
                            
                            for(int t = 0; t < nextChar[currentGram].length(); t++)
                            {
                                string vector = "";
                                vector.append(nextChar[currentGram], t, 1);
                                tempVec.push_back(vector);
                            }

                            result.append(tempVec[randNum]);
                            temp = "";
                            temp.append(result, i+1, 2);
                            tempVec.clear();
                            
                            
                            //finds str that is equal to temp and finds it location and makes currentGram equal to it, if not found then randomizes next str BOOM NO MORE STRING COMPLICATIONS
                            for(int g=0; g <= resize; g++)
                            {
                                if (temp == str[g])
                                {
                                    currentGram =g;
                                    g=resize;
                                }
                                else if (g == resize-1)
                                {
                                    randNum = rand() % resize + 0;
                                    currentGram = randNum;
                                    temp = str[currentGram];
                                    g=resize;
                                }
                            }
                            z = resize;
                    }
                }
           }
        }
            cout << "Generated string: " << result << "\n";
            return result;
        }
};

int main(int argc, const char * argv[]) {
    
    int userInput=0;
    char letter;
    int length;
    string kGram, sentence;
    MModel m1("gagaaagaga", 2);
    
    cout << "Enter in string to be tested in Markov Model\n";
    cin >> sentence;
    cout << "Enter length of k\n";
    cin >> length;
    MModel m2(sentence, length);
    

    cout << "Menu:\n1. Check Frequency\n2. Check Frequecy of given Char\n3. Generate Random character for KGRam\n4. Generate a list of character with entered length\n5. To Print Markov Example\n6. Print MENUEnter -1 to quit\n";
//    cin >> userInput;
    while(userInput != -1)
    {
        cout << "\nEnter input/Enter -1 to quit or 5 for menu\n";
        cin >> userInput;
        switch (userInput) {
            case 1:
                cout << "Enter KGRAM\n";
                cin >> kGram;
                m2.freq(kGram);
                break;
                
            case 2:
                cout << "Enter KGRAM\n";
                cin >> kGram;
                cout << "Enter character\n";
                cin >> letter;
                m2.freq(kGram, letter);
                break;
                
            case 3:
                cout << "Enter KGRAM\n";
                m2.kRand(kGram);
                break;
            
            case 4:
                cout << "Enter KGRAM\n";
                m2.kRand(kGram);
                cout << "Enter desired length of string\n";
                cin >> length;
                m2.generate(kGram, length);
                break;
            case 5:
                cout << "\nExample using (gagaaagaga)\n\n";
                //MModel m1("gagaaagaga", 2);
                cout << "Frequency: \n";
                m1.freq("ga");
                cout << "\nFrequency with given char: \n";
                m1.freq("ga", 'g');
                cout << "\nKOrder: \n";
                m1.kOrder();
                cout << "\nRandom char given KGram: \n";
                m1.kRand("ag");
                cout << "\nGenerated String from Kgram: \n";
                m1.generate("ga", 10);
                break;
            case 6:
                cout << "Menu:\n1. Check Frequency\n2. Check Frequecy of given Char\n3. Generate Random character for KGRam\n4. Generate a list of character with entered length\nEnter -1 to quit\n";
                break;
            default:
                cout << "Menu:\n1. Check Frequency\n2. Check Frequecy of given Char\n3. Generate Random character for KGRam\n4. Generate a list of character with entered length\nEnter -1 to quit\n";
                break;
        }
    }
}



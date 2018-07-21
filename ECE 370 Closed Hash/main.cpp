#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>

using namespace std;

string hashTable[60] = "0";
int stepArray[60] = {0};



void hashCalc( ifstream &inFile){
    //take in single line as string, calculate the hash, return hash table index
    int i,steps;
    int hash_index;
    string last, next;

    //cout<<"State \t\t\tSteps\tHash Index"<<endl;//test code

    for(i=0;i<50;i++){
        //i<50 because there are no more than 50 state names in one file
        inFile>>next;
        steps = 0;

        //make state name 15 char in length using blank spaces
        while(next.size()<15){
            next = next+"_";//used underscore so that the spaces could be seen
        }
        if(last!=next){
            //last,next is so that at the end of the list, we don't repeatedly hash the last line of the file
            //since this loop has to happen 50 times when there might not be 50 entries
            hash_index = ((next[0]*3)%50 + (next[1]*5)%50 + (next[2]*7)%50)%60; //given hash function
            while(hashTable[hash_index]!="0"){
                //linear probing to handle collisions
                hash_index = (hash_index+1)%50;//increment hash until a free space is found
                //record the number of times the rehash had to be done
                steps++;

            }
            hashTable[hash_index] = next;
            stepArray[hash_index] = steps;
            //cout<<hashTable[hash_index]<<"\t\t"<<steps<<"\t"<<hash_index<<endl; //test code
            last = next;


        }
    }

    //check for rehash? Should I do that here?

    return;
}//void hashcalc

void printHash(){
    //this function will use the resulting hash table and step array to print in a certain order
    int index,entryNum;
    string blank = "_______________";
    index = 0;

    while(index<60){
        //will go through the entire array printing the State names and the number of times rehashed
        entryNum = index+1;
        if(hashTable[index]=="0"){
            //if entry is null/blank/empty print blank space
            cout<<entryNum<<" "<<blank<<"\t";
            index++;
        }
        else{
            cout<<entryNum<<" "<<hashTable[index]<<" "<<stepArray[index]<<" \t";
            index++;
        }
        if(entryNum%4 == 0){
                //new line after every 4th entry
            cout<<endl;
        }
    }
}



int main()
{

    ifstream inFile;
    inFile.open("a4.txt");
    string last, next;

    hashCalc(inFile);
    printHash();
/*
    for(i=0;i<50;i++){
        //i<50 because there are no more than 50 state names in one file
        inFile>>next;
        if(last!=next){
                //last, next is so that at the end of the list we don't repeatedly has the last line of the file
                //since this loop has to happen 50 times when there might not be 50 entries
        hash_index = hashCalc(next);
        cout<<next<<"\t"<<hash_index<<endl;
        last = next;
        }

    }
    */
    return 0 ;
}

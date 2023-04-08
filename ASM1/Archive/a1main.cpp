//Mok Hoi Chun Hogan (301447481)
//3rd June, 2022
#include<iostream>
#include<string.h>
#include"Song.cpp"
#include"PlayList.cpp"

using std::cout;
using std::endl;

/**** Big O notation
  PlayList Methods
  Default constructor: O(1), Setting variable values
  Destructor: O(n), calling help function, if the list contains any element, it will traverse through the whole list.
  Copy constructor: O(n), calling help function, if the list contains any element, it will traverse through the whole list.
  Overloaded assignment operator: O(n), calling two helper functions which traverse through the whole list, so O(n) + O(n) = O(n).
  Insert: O(n), the worse case is inserting to the tail, which may traverse to the last node. 
  Remove: O(n), the worse case is removing from the tail, which may traverse to the last node. 
  Get: O(n), the worse case is getting the node the tail, which may traverse to the last node. 
  Swap: O(n), the worse case is swapping the last two node with slicing, which called insert and remove to traverse the list. So the worse is O(n) + O(n) = O(n).
  Size: O(1), getting the size value from private.

  Main Function Commands
  Enter a song: O(n), since we are just calling the insert function, so the big o notation is same as the insert function.
  Remove a song: O(n), since we are just calling the remove function, so the big o notation is same as the remove function.
  Swap two songs: O(n), since we are just calling the swap function, so the big o notation is same as the swap   function.
  Print all the songs: O(n^2), since we are travsing the list printing the values while using the get function, so there are two while loop which looping from the first node to the last node.
****/

int main(){
  cout<<"Menu:"<<endl;
  cout<<"1 - Enter a song in the play list at a given position"<<endl;
  cout<<"2 - Remove a song from the play list at a given position"<<endl;
  cout<<"3 - Swap two songs in the play list"<<endl;
  cout<<"4 - Print all the songs in the play list"<<endl;
  cout<<"5 - Quit"<<endl;
  cout<<endl;
  int num = 0, flag = 0;
  PlayList list;
  while(flag == 0){
    cout<<"Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";
    cin>>num;
    if(num == 1){
      string nm, at;
      int leng = 0;
      unsigned int pos;
      cout<<"Song name: ";
      getline(cin,nm);
      getline(cin,nm);
      cout<<"Artist: ";
      getline(cin,at);
      cout<<"length: ";
      cin>>leng;
      if(list.size() != 0){
        int flag2 = 0;
        while(flag2 == 0){
          cout<<"Position: (1 to "<<list.size()+1<<"): ";
          cin>>pos;
          if(pos >= 1 && pos <= list.size()+1){
            flag2 = 1;
          }
        }
      }
      else{
        int flag2 = 0;
        while(flag2 == 0){
          cout<<"Position: (1): ";
          cin>>pos;
          if(pos == 1){
            flag2 = 1;
          }
        }
      }
      Song song = Song(nm,at,leng);
      list.insert(song, pos);
      cout<<"You entered "<<nm<<" at position "<<pos<<" in the play list."<<endl;
      cout<<endl;
    }
    else if(num == 2 && list.size() > 0){
      unsigned int pos = 0;
      int flag2 = 0;
      if(list.size() == 1){
        while(flag2  == 0){
          cout<<"Position (1): ";
          cin>>pos;
          if(pos == 1){
            flag2 = 1;
          }
        }
        cout<<"You removed "<<list.remove(pos).getName()<<" from the play list."<<endl;
        cout<<endl;
      }
      else{
        while(flag2 == 0){
          cout<<"Position (1 to "<<list.size()<<"): ";
          cin>>pos;
          cout<<endl;
          if(pos <= list.size() && pos >= 1){
            flag2 = 1;
          }
        }
        cout<<"You removed "<<list.remove(pos).getName()<<" from the play list."<<endl;
      }
      cout<<endl;
    }
    else if(num == 3 && list.size() > 1){
      unsigned int pos1, pos2;
      int flag2 = 0;
      while(flag2 == 0){
        cout<<"Swap song at position (1 to "<<list.size()<<"): ";
        cin>>pos1;
        cout<<"with the song at position (1 to "<<list.size()<<"): ";
        cin>>pos2;
        if(pos1 != pos2 && pos1 >= 1 && pos1 <= list.size() && pos2 >= 1 && pos2 <= list.size()){
          list.swap(pos1,pos2);
          cout<<"Your swapped the songs at positions "<<pos1<<" and "<<pos2 <<endl;
          flag2 = 1;
        }
      }
      cout<<endl;
    }
    else if (num == 4 && list.size() > 0){
      unsigned int si = 0;
      while(si != list.size()){
        string nm = list.get(si).getName();
        string art = list.get(si).getArtist();
        int leng = list.get(si).getLength();
        cout<<si+1<<" "<<nm<<" ("<<art<<") "<<leng<<"s"<<endl;
        si++;
      }
      cout<<endl;
    }
    else if (num == 5){
      cout<<"You have chosen to quit the program."<<endl;
      flag = 1; 
    }
  }
  return 0;
}
//Mok Hoi Chun Hogan (301447481)
//3rd June, 2022
#include<iostream>
#include"Song.h"
#include "PlayList.h"

using namespace std;
PlayList::PlayList(){
	head = nullptr;
}

	// PARAM: pl - PlayList to be copied
	// POST: new PlayList is created that is a deep copy of pl*/
void PlayList::copyPlayList(const PlayList& pl){
  head = nullptr;
  PlayListNode* original = pl.head;
  if(original != nullptr){
    head = new PlayListNode(head->song);
    head = head->next;
    PlayListNode* copyNode = head;
    while(original != nullptr){
      PlayListNode* newNode = new PlayListNode(original->song);
      copyNode->next = newNode;
      copyNode = copyNode->next;
      original = original->next;
      }
  }
}

PlayList::PlayList(const PlayList& pl){
	copyPlayList(pl);
}

	//POST: dynamic memory associated with object is deallocated
void PlayList::deletePlayList(){
  while(head != nullptr){
    PlayListNode* temp = head;
    head = head->next;
    delete temp;
  }
}

	
PlayList::~PlayList(){
	deletePlayList();
}

	// PARAM: pl - PlayList to be copied
	// POST: dynamic memory of calling object deallocated (except
	//       under self-assgnment), calling object is set to a
	//       a deep copy of pl
PlayList& PlayList::operator=(const PlayList& pl){
  if(this != &pl){
    deletePlayList();
    copyPlayList(pl);
  }
  return *this;
}

//Three different cases
//First case: If the list is empty
//Second case: if the list is not empty and inserting in the first position
//Thirs case: IF the list is not empty and inserting at last or in the middle of the list
void PlayList::insert(Song sng, unsigned int pos){
	if(head == nullptr && pos == 1){
    	PlayListNode* newNode = new PlayListNode(sng,nullptr);
		head = newNode;
	}
	else if(pos == 1 && head != nullptr){
    	PlayListNode* newNode = new PlayListNode(sng,nullptr);
		newNode->next = head;
		head = newNode;
		PlayListNode* cur = head;
		unsigned int place = 0;
		while(cur != nullptr){
			cur = cur->next;
			place++;
		}
	}
	else{
		PlayListNode* cur = head;
		if(pos != si+1){
			unsigned int place = 0;
			while(place < pos){
				if(place == pos-2){
          			PlayListNode* newNode = new PlayListNode(sng, nullptr);
					newNode->next = cur->next;
					cur->next = newNode;
				}
				place++;
				cur = cur->next;
			}
		}
		else{
			unsigned int place = 1;
			while(place < pos){
				if(place == pos-1){
          			PlayListNode* newNode = new PlayListNode(sng, nullptr);
          			cur->next = newNode;
				}
				place++;
				cur = cur->next;
			}
		}
	}
	si++;
}

//Three different cases
//First case: If the list is empty
//Second case: if the list is not empty and removing in the first position
//Thirs case: IF the list is not empty and removing at last or middle of the list
Song PlayList::remove(unsigned int pos){
	unsigned int place = 0;
	PlayListNode* cur = head;
	if(pos == 1 && si != 1){
		Song result = cur-> song;
		head = head->next;
		delete cur;
		si--;
		return result;
	}
	else if(pos == 1 && si == 1){
		Song result = cur->song;
		head = nullptr;
		delete cur;
		si--;
		return result;
	}
	else if(pos == si){
		Song result = cur->song;
		while(place != pos-1){
			if(place == pos-2){
				PlayListNode* dele_song = cur->next;
				cur->next = nullptr;
				result = dele_song->song;
				delete dele_song;
			}
			else{
				cur = cur->next;
			}
			place++;
		}
		si--;
		return result;	
	}
	else{
		Song result = cur->song;
		while(place != pos-1){
			if(place == pos-2){
				PlayListNode* dele_song = cur->next;
				result = dele_song->song;
				cur->next = cur->next->next;
				delete dele_song;
			}
			else{
				cur = cur->next;
			}
			place++;
		}
		si--;
		return result;
	}
}

//Two different cases
//First case: If pos1 is greater than pos2, then pos1 will be removed first
//Second case: If pos2 is greater than pos1, then pos2 will be removed first
void PlayList::swap(unsigned int pos1, unsigned int pos2){
  	if(pos1 > pos2){
    	Song song1 = remove(pos1);
		Song song2 = remove(pos2);
		insert(song1, pos2);
		insert(song2, pos1);
	}
	else{
		Song song1 = remove(pos2);
		Song song2 = remove(pos1);
		insert(song1, pos1);
		insert(song2, pos2);
	}
}

//Tranver to the giving position and return the song
Song PlayList::get(unsigned int pos) const{
	PlayListNode* cur = head;
	PlayListNode* return_value = cur;
	unsigned int place = -1;
	while(place!= pos){
		place++;
		return_value = cur;
		cur = cur->next;
	}
	return return_value->song;
}

//Return the size of the list which we set in the private
unsigned int PlayList::size()const{
  return si;
}
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:public Cache{
    public:
    LRUCache(int _cp) {
        cp = _cp +2;
        head = new Node(-1,-1);
        tail = new Node(-2,-1);
        mp[-1] = head;
        mp[-2] = tail;
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    }
    
    void set(int key,int value) {
        Node *temp = new Node(key, value);
        
        if(mp.find(key)==mp.end()) {
            //cout<<"not contained"<<endl;
            //the key is not contained within the map
            if(mp.size()==cp) {
               //cout<<"map is crowded"<<endl;
                //Remove the last
                mp.erase(tail->prev->key);
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
            }
            mp[key] = temp;
        } else {
            //recover the element from the map, then rearrange
            temp = mp[key];
            //remember to update the value, maybe its different
            temp->value = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;    
        }
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        return mp[key]->value;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


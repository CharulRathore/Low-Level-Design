//******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

enum Status {
  ACTIVE,
  EXPIRED
};

struct Code {
    int val;
    string created_date;
    string end_date; 
    Order* order;
    Status status;
    
    bool isValid();
};

class Block {
private:
    Order* order;
    
public:
    void setOrder(Order* order);
    void setEmpty();
};

class Locker {
private:
    Location loc;
    stirng id;
    unordered_set<Block*> free_blocks;
    unordered_map<Code*, Block*> code_block_map;
    
public:
    void setPackage(Code* code) {
        Block* block = free_blocks.begin();
        free_blocks.erase(block);
        block->setOrder(code->order);
        code_block_map[code] = block;
    }
    
    Block* getBlockCode* code) {
        if (!code->isValid()) {
            return;
        } 
        
        if (code_block_map.find(code) == code_block_map.end())
            return; //error
        
        Block* block = code_block_map[code];
        code_block_map.erase(code);
        block->setEmpty();
        free_blocks.insert(block);
        return block;
    }
    
    void checkValidCodes();
};

class Search {
public:
    virtual Locker* findLocker(LockerSystem* lockersystem, Location loc) = 0;
};

class SearchNearestLocker : public Search {
public:
    Locker* findLocker(LockerSystem* lockersystem, Location loc);
};

class Customer {
private:
    string name;
    string id;
    string details;
    Search searchObj;
    
public:
    Locker* selectLocker();
    void pickPackage(Locker* locker, Code* code) {
        locker->getBlock(code);
    }
};

class Notif {
public:
    virtual void sendNotification(User* user) = 0;
};

class Email :: public Notif {
private:
    static Email* inst;
    Email() {}
    
public:
    static Email* getInstance() {
        if (inst==NULL) 
            inst = new Email();
        return inst;
    }
};

class Phone :: public Notif {
private:
    static Phone* inst;
    Email() {}
    
public:
    static Phone* getInstance() {
        if (inst==NULL) 
            inst = new Phone();
        return inst;
    }
};

Email* Email::inst = NULL;
Phone* Phone::inst = NULL;

class NotifFactory {
public:
    static Notif* getInstance(string type) {
        if (type == "email") {
            return Email::getInstance();
        } else if (type == "phone") {
            return Phone::getInstance();
        }
        return NULL;
    }
};

class System {
private:
    NotifFactory* notiffactory;
    vector<Locker*> lockers;
    
public:
    void assignLocker(Locker* locker, Order* order) {
        Code* code = new Code();
        locker->setPackage(code);
        for (pref : preferences) {
            Notif* notif = NotifFactory::getInstance(pref);
            notif->sendNotification(order->user());
        }
    }
};

int main()
{
    return 0;
}

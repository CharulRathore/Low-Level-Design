/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

enum Roomtype {
    Standard,
    Double,
    King
};

enum Status {
    Reserved,
    Assigned,
    Available,
    Out_of_service
};

class Search {
private:
    vector<string> filters;
public:
    bool apply_filter(string & filter);
    vector<Room> searchRooms(Hotel* hotel, string start_date, string end_date);
    Room getReservedRooms(Hotel* hotel);
};  

class Payment {
public:
    string type;
    virtual bool pay() = 0;
};

class CreditCard : public Payment {
public:
    bool pay();
};

class DebitCard : public Payment {
public:
    bool pay();
};

class Cash : public Payment {
public:
    bool pay();
};

class PayFactory() {
public:
    Payment* getPayObject(string type) {
        if (type == "CreditCard")
            return new CreditCard();
        else if (type == "DebitCard")
            return new DebitCard();
        return new Cash();
    } 
};

class Booking {
private:
    PayFactory paymentFactory;
public:
    bool bookRoom(Hotel& hotel, Room& room, string start_date, string end_date, string payment_type);
};  

class Person {
public:
    string name;
    string email;
    string phone;
    string type;
    Person(string t) : type(t) {} 
};

class Service {
protected:
    string desc;
    double price;
public:
    virtual double getPrice() = 0;
};

class ParkingService : public Service {
private:
    double price;
public:
    double getPrice(); 
};

class ServiceDecorator : public Service {
protected:
    ServiceType type;
    Service* base_service;
    void setType(SeviceType t) {
	type = t;
    }  
  
public:
    ServiceDecorator(Service* s) : base_service(s) {};   
}	

class Valet : public ServiceDecorator {
public:
    Valet(Service* s) : ServiceDecorator(s) {
	setType(ServiceType::Parking);
    }
  
    double getPrice() {
	return base_service.getPrice() + this->price;
    }  
};

class Roombooking {
private:
    PayFactory paymentFactory;
public:
    vector<Service*> services;
    Room* room;
    string start_date;
    string end_date;
    Guest* guest;
    double roomBasePrice;
    double amount_paid;
    double remaining_amt;

    void add_service() {
	
    }    
    void calculateRemainingAmt();
    bool payBalance(remaining_amt, string payment_type);
    bool creditBalance(credit_amt);
};

class Guest : public Person {
public:
    Guest() : Person("guest") {};
    Search searchObj;
    Booking bookObj;
    vector<Roombooking> bookings;
    
    bool checkIn(Roombooking);
    bool checkOut(Roombooking);
};

class Receptionist : public Person {
public:
    Receptionist() : Person("receptionist") {};
    Search searchObj;
    Booking bookObj;
};

class HouseKeeper : public Person {
public:
    HouseKeeper() : Person("housekeeper") {};
};

class HouseKeepingLog {
public:
    HouseKeeper keeper;
    string date;
    string desc;
};

class Room {
public:
    string id;
    Roomtype type;
    Status status;
    vector<HouseKeepingLog> logs; 
}

class Hotel {
public:
    string name;
    string id;
    Location loc;
    unordered_map<Roomtype, vector<Room>> rooms;
    unordered_map<string, unordered_map<Roomtype, unordered_set<Room>>> available_rooms;
};



int main()
{
    std::cout<<"Hello World";

    return 0;
}





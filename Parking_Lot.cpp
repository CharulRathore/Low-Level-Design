/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Search {
protected:
    Entry entry;
    virtual vector<ParkingSpot> findParkingSpots(ParkingLot* lot, Entry e, int spots, ParkingSpotType type) = 0;
};

class SearchAny : public Search {
public:
    vector<ParkingSpot> findParkingSpots(ParkingLot* lot, Entry e, int spots, ParkingSpotType type);
};

class SearchNearest : public Search {
public:
    vector<ParkingSpot> findParkingSpots(ParkingLot* lot, Entry e, int spots, ParkingSpotType type);
};

enum Vechicle_Mode {
    Normal.
    Disabled
};

class Vechicle {
protected:
    string license;
    string color;
    Vechicle_Mode mode;
    Search* searcObj;
      
public:
    Vechicle(Vehicle_Mode m)  : mode(m) {
        if (mode == Normal)
            searchObj = new SearchAny();
        else 
            searchObj = new SearchNearest();
    } 
    virtual void park_vechicle(ParkingLot* lot) = 0;
};

class Bus : public Vehicle {
private:
    int spots;
    ParkingSpotType type;
    
public:
    Bus(Vechicle_Mode m) : Vechicle(m) {};
    void park_vechicle();
};

enum ParkingSpotType {
  Bike,
  Compact,
  Large
};

class ParkingSpot {
private:
    string id;
    int x;
    int y;
    Vehicle* vehicle;
    ParkingRow row;
    ParkingSpotType type;
    
public:
    bool isEmpty();
    bool park_vehicle(Vechile* vechicle);
};


class ParkingRow {
private:
    string id;
    unordered_map<ParkingSpotType, vector<ParkingSpot>> parking_spots;
    
public:
    vector<ParkingSpot> getParkingSpots(ParkingSpotType type, int spots);
    void addParkingSpot(ParkingSpotType type);
};

class ParkingLot {
private:
    vector<unique_ptr<ParkingRow>> parking_rows;
    Location loc;
    
public:
    ParkingLot() {}
    ~ParkingLot() {}
    vector<ParkingSpot> getParkingRows();
    void addParkingRow();
    void deleteParkingRow();
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}

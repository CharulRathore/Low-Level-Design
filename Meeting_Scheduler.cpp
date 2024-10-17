/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class User;

class Meeting {
private:
    User* host;
    vector<User*> participants;
    string details;
    vector<int> interval;
    string date;
    MeetingRoom* room;
    
public:
    Meeting* next;
    Meeting* prev

    Meeting() {
        next = NULL;
        prev  =NULL;
    }
    
    void showMeetingDetails();
};

class Search {
public:
    MeetingRoom* findMeetingRoom(Scheduler* scheduler, string date, vector<int> interval) {
        vector<MeetingRoom*> meetingRooms = scheduler->getAllMeetingRooms();
        for (auto room : meetingRooms) {
            if (room->canScheduleMeeting(date, interval))
                return room;
        }
        return NULL;
    }
};

class User {
private:
    string name;
    string details;
    Search searchObj;
    
public:
    MeetingRoom* bookMeeting(Scheduler* scheduler, vector<User> users, string date, vector<int> interval) {
        MeetingRoom* room = searchObj.findMeetingRoom(scheduler, date, interval);
        if (!room)
            return NULL;
        Meeting* meet = new Meeting();
        room->addMeeting(meet);
        return room;
    }    
    
    bool cancelMeeting(Meeting* meeting);
    bool updateMeeting(Meeting* meeting);
};

class MeetingRoom {
private:
    unordered_map<string, map<int, Meeting*>> date_meetings_map;

public:
    bool canScheduleMeeting(string date, vector<int> interval) {
        if (date_meetings_map.find(date) == date_meeting_map.end())
            return true;
        map<int, int> meetings_map = date_meetings_map[date];
        Meeting* tail = date_meeting_list_head_map[date];
            
        auto it = meetings_map.upper_bound(interval[0]);
        if (it == meetings_map.begin() && it->first >= interval[1])
            return true;
        else if (it == meetings_map.end() && prev(it)->second->end_time() <= interval[0])
            return true;
        else if (interval[0] >= prev(it)->second->end_time() && interval[1] <= it->first)
            return true;
        return false;
    }
    
    void addMeeting(Meeting* meeting) {
        date_meetings_map[meeting->date()].insert({meeting->start_time(), meeting});
        return;
    }
    
    void deleteMeeting(Meeting* meeting);
};

class Notif {
public:
    virtual void sendNotification() = 0;
};


class Email : public Notif {
private:
    static unique_ptr<Email> inst;
    Email() {}

public:
    static Email* getInstance() {
	if (!inst)
	    inst = make_unique<Email>();
	return inst.get();
    }

    void sendNotification();    
};

class Phone : public Notif {
private:
    static unique_ptr<Phone> inst;
    Phone() {}

public:
    static Phone* getInstance() {
	if (!inst)
	    inst = make_unique<Phone>();
	return inst.get();
    }

    void sendNotification();    
};

unique_ptr<Email> Email::inst = nullptr;
unique_ptr<Phone> Phone::inst = nullptr;

class NotifFactory {
public:
    static Notif* getInstance(string type) {
	if (type == "email") {
	    return Email::getInstance();
	} else if (type == "phone") {
	    return Phone::getInstance();
	}
    }
};

class Scheduler {
private:
    static unique_ptr<Scheduler> inst;
    Scheduler() {}
    vector<MeetingRoom*> rooms;

public:
    static Scheduler* getInstance() {
        if (!inst) 
            inst = make_unique<Scheduler>();              
        return inst.get();
    }
    
    vector<MeetingRoom*> getAllMeetingRooms();
    MeetingRoom* bookMeeting(string date, )
}

unique_ptr<Scheduler> Scheduler::inst = nullptr;

int main()
{
    Scheduler* meeting_scheduler = Scheduler::getInstance();      // use smart ptr so that when meeting_scheduler goes out of scope, it gets automatically cleaned up
    return 0;
}

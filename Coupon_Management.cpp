/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class Person {
protected:
    string name;
    string id;
    string details;
};

class Rule {
private:
    string description;

public:
    virtual bool isStatisfied() = 0;
};

class AgeGreater100 : public Rule {
private:
    int age;
    void getUserAge();
    
public:
    bool isSatisifed() {
        getUserAge();
        return age > 100;
    }
}; 

class Coupon {
private:
    int coupon_id;
    vector<Rule*> rules;
    User* user;
    Status status;
public:
    bool can_apply_coupon();
};

class Voucher {
protected:
    stirng voucher_id;
    User* user;
    Status status;

public:
    virtual bool isValid() = 0;    
};

class Unassigned : public Voucher {
public:
    Uanssigned() {
        user = NULL;
    }
    bool isValid();
};

class Preassigned : public Voucher {
public:
    Preassigned(User * u1) {
        user = u1;
    }
    bool isValid();
};

class Admin : public Person {
private:
    VoucherFactory* vfactory;
public:
    Admin() {vfactory = new VoucherFactory();}
    pair<int, Coupon> create_coupons(vector<Rule> rules, int num, int amt);
    pair<int, Voucher> create_vouchers(VoucherType type, int num, int amt);
};

class SystemManager {
private:
    Admin* admin;
    unordered_map<Voucher*, int> avail_vouchers;
    unordered_map<Coupon*, int> avail_coupons;
    
public:
    void showAllCoupons();
    void showAllVouchers();
    bool assignCoupon(Coupon* c);
    bool assignVoucher(Voucher* v);
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}

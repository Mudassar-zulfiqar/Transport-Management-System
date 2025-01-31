#include<iostream>
using namespace std;


class Name {
private:
    char* fName;
    char* lName;

public:
    Name(const char* fN = nullptr, const char* lN = nullptr)
    {
        fName = nullptr;
        lName = nullptr;

        if (fN != nullptr)
        {
            int len = 0;
            while (fN[len] != '\0') len++;
            fName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fName[i] = fN[i];
            }
            fName[len] = '\0';
        }

        if (lN != nullptr)
        {
            int len = 0;
            while (lN[len] != '\0') len++;
            lName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                lName[i] = lN[i];
            }
            lName[len] = '\0';
        }
    }

    
    Name(const Name& other)
    {
        fName = nullptr;
        lName = nullptr;

        if (other.fName != nullptr)
        {
            int len = 0;
            while (other.fName[len] != '\0') len++;
            fName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fName[i] = other.fName[i];
            }
            fName[len] = '\0';
        }

        if (other.lName != nullptr)
        {
            int len = 0;
            while (other.lName[len] != '\0') len++;
            lName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                lName[i] = other.lName[i];
            }
            lName[len] = '\0';
        }
    }

    
    Name& operator=(const Name& other)
    {
        if (this == &other) return *this;

        if (fName)
            delete[] fName;
        if (lName)
            delete[] lName;

        fName = nullptr;
        lName = nullptr;

        if (other.fName != nullptr)
        {
            int len = 0;
            while (other.fName[len] != '\0') len++;
            fName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fName[i] = other.fName[i];
            }
            fName[len] = '\0';
        }

        if (other.lName != nullptr)
        {
            int len = 0;
            while (other.lName[len] != '\0') len++;
            lName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                lName[i] = other.lName[i];
            }
            lName[len] = '\0';
        }

        return *this;
    }

    
    ~Name() {
        if (fName)
            delete[] fName;
        if (lName) 
            delete[] lName;
    }

    
    void setFirstName(char* fN)
    {
        if (fName) delete[] fName;

        if (fN != nullptr)
        {
            int len = 0;
            while (fN[len] != '\0') len++;
            fName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fName[i] = fN[i];
            }
            fName[len] = '\0';
        }
    }

    void setLastName(char* lN)
    {
        if (lName) delete[] lName;

        if (lN != nullptr) {
            int len = 0;
            while (lN[len] != '\0') len++;
            lName = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                lName[i] = lN[i];
            }
            lName[len] = '\0';
        }
    }

    char* getFirstName() const 
    {
        return fName; 
    }
    char* getLastName() const 
    {
        return lName;
    }

   
    friend ostream& operator<<(ostream& out, const Name& n)
    {
        out << n.fName << " " << n.lName;
        return out;
    }
};


class Date
{
private:
    int day, month, year;

public:
   
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    
    void setDay(int d) 
    {
        day = (d > 0 && d <= 31) ? d : 1; 
    }
    void setMonth(int m) 
    {
        month = (m > 0 && m <= 12) ? m : 1; 
    }
    void setYear(int y) 
    {
        year = (y > 0) ? y : 2000; 
    }

   
    int getDay() const 
    {
        return day; 
    }
    int getMonth() const 
    {
        return month; 
    }
    int getYear() const 
    {
        return year; 
    }

    
    friend ostream& operator<<(ostream& out, const Date& d)
    {
        out << d.day << "/" << d.month << "/" << d.year;
        return out;
    }

    
    ~Date() {}
};


class mTime 
{
private:
    int hour, min, sec;

public:
    
    mTime(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    
    void setHour(int h) 
    {
        if (h >= 0 && h < 24) 
        {
            hour = h;
        }
        else {
            hour = 0;
        }
    }

    void setMinute(int m)
    {
        if (m >= 0 && m < 60) 
        {
            min = m;
        }
        else {
            min = 0;
        }
    }

    void setSecond(int s) 
    {
        if (s >= 0 && s < 60) 
        {
            sec = s;
        }
        else 
        {
            sec = 0;
        }
    }

    
    int getHour() const 
    {
        return hour; 
    }
    int getMinute() const 
    {
        return min; 
    }
    int getSecond() const
    {
        return sec; 
    }

    
    friend ostream& operator<<(ostream& out, const mTime& t)
    {
        out << t.hour << ":" << t.min << ":" << t.sec;
        return out;
    }

    
    ~mTime() {}
};




class Service
{
protected:
    char* source;
    char* destination;
    float distance;
    Date bookingDate;
    mTime bookingTime;
    bool status;
    float fuelrate;
    int cId;
    int dId;
    int vId;

public:
    
    Service(const char* src = nullptr, const char* dest = nullptr, float dist = 0.0, Date date = Date(),
        mTime time = mTime(), bool stat = false, float fuel = 0.0,
        int custId = -1, int drvId = -1, int vehId = -1)
        : distance(dist), bookingDate(date), bookingTime(time), status(stat), fuelrate(fuel),
        cId(custId), dId(drvId), vId(vehId) 
    {
        source = nullptr;
        destination = nullptr;

        if (src != nullptr)
        {
            int len = 0;
            while (src[len] != '\0') len++;
            source = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                source[i] = src[i];
            }
            source[len] = '\0';
        }

        if (dest != nullptr)
        {
            int len = 0;
            while (dest[len] != '\0') len++;
            destination = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                destination[i] = dest[i];
            }
            destination[len] = '\0';
        }
    }

    
    ~Service()
    {
        if (source) delete[] source;
        if (destination) delete[] destination;
    }

    
    Service(const Service& other)
        : distance(other.distance), bookingDate(other.bookingDate), bookingTime(other.bookingTime),
        status(other.status), fuelrate(other.fuelrate), cId(other.cId),
        dId(other.dId), vId(other.vId)
    {
        source = nullptr;
        destination = nullptr;

        if (other.source != nullptr)
        {
            int len = 0;
            while (other.source[len] != '\0') len++;
            source = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                source[i] = other.source[i];
            }
            source[len] = '\0';
        }

        if (other.destination != nullptr)
        {
            int len = 0;
            while (other.destination[len] != '\0') len++;
            destination = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                destination[i] = other.destination[i];
            }
            destination[len] = '\0';
        }
    }

   
    Service& operator=(const Service& other)
    {
        if (this == &other)
            return *this;

        if (source) 
            delete[] source;
        if (destination)
            delete[] destination;

        source = nullptr;
        destination = nullptr;

        distance = other.distance;
        bookingDate = other.bookingDate;
        bookingTime = other.bookingTime;
        status = other.status;
        fuelrate = other.fuelrate;
        cId = other.cId;
        dId = other.dId;
        vId = other.vId;

        if (other.source != nullptr)
        {
            int len = 0;
            while (other.source[len] != '\0') len++;
            source = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                source[i] = other.source[i];
            }
            source[len] = '\0';
        }

        if (other.destination != nullptr)
        {
            int len = 0;
            while (other.destination[len] != '\0') len++;
            destination = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                destination[i] = other.destination[i];
            }
            destination[len] = '\0';
        }

        return *this;
    }

    
    void setSource(char* src)
    {
        if (source) delete[] source;
        if (src != nullptr)
        {
            int len = 0;
            while (src[len] != '\0') len++;
            source = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                source[i] = src[i];
            }
            source[len] = '\0';
        }
    }
    char* getSource() const 
    {
        return source; 
    }

    void setDestination(char* dest)
    {
        if (destination)
            delete[] destination;
        if (dest != nullptr) 
        {
            int len = 0;
            while (dest[len] != '\0') len++;
            destination = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                destination[i] = dest[i];
            }
            destination[len] = '\0';
        }
    }
    char* getDestination() const
    { 
        return destination;
    }

    void setDistance(float dist)
    { 
        distance = dist;
    }
    float getDistance() const 
    {
        return distance;
    }

    void setStatus(bool stat) 
    {
        status = stat;
    }
    bool getStatus() const
    { 
        return status;
    }

    void setFuelRate(float rate) 
    {
        fuelrate = rate; 
    }
    float getFuelRate() const
    { 
        return fuelrate;
    }

    void setCustomerId(int id) 
    {
        cId = id; 
    }
    int getCustomerId() const 
    {
        return cId; 
    }

    void setDriverId(int id) 
    {
        dId = id;
    }
    int getDriverId() const
    { 
        return dId;
    }

    void setVehicleId(int id)
    { 
        vId = id;
    }
    int getVehicleId() const
    {
        return vId;
    }

   
    void displayService() const
    {
        cout << "Source: " << (source ? source : "N/A") << endl;
        cout << "Destination: " << (destination ? destination : "N/A") << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Booking Date: " << bookingDate << endl;
        cout << "Booking Time: " << bookingTime << endl;
        cout << "Status: " << (status ? "Complete" : "Pending") << endl;
        cout << "Fuel Rate: " << fuelrate << " per km" << endl;
        cout << "Customer ID: " << cId << ", Driver ID: " << dId << ", Vehicle ID: " << vId << endl;
    }
};

class Ride : public Service
{
private:
    int noOfPassengers;
    char* rideType;
    float driverRanking;
    float vehicleRanking;

public:
    
    Ride(char* src = nullptr, char* dest = nullptr, float dist = 0.0, Date date = Date(),
        mTime time = mTime(), bool stat = false, float fuel = 0.0, int custId = -1,
        int drvId = -1, int vehId = -1, int passengers = 0, char* type = nullptr,
        float drvRank = 0.0, float vehRank = 0.0)
        : Service(src, dest, dist, date, time, stat, fuel, custId, drvId, vehId),
        noOfPassengers(passengers), driverRanking(drvRank), vehicleRanking(vehRank)
    {
        rideType = nullptr;
        if (type != nullptr)
        {
            int len = 0;
            while (type[len] != '\0') len++;
            rideType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                rideType[i] = type[i];
            }
            rideType[len] = '\0';
        }
    }

   
    ~Ride() {
        if (rideType) delete[] rideType;
    }

    
    void setRideType(char* type)
    {
        if (rideType) delete[] rideType;
        if (type != nullptr) {
            int len = 0;
            while (type[len] != '\0') len++;
            rideType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                rideType[i] = type[i];
            }
            rideType[len] = '\0';
        }
    }
    char* getRideType() const
    {
        return rideType; 
    }

    void setPassengers(int passengers)
    {
        noOfPassengers = passengers;
    }
    int getPassengers() const 
    {
        return noOfPassengers; 
    }

    void setDriverRanking(float rank)
    {
        driverRanking = rank; 
    }
    float getDriverRanking() const
    {
        return driverRanking;
    }

    void setVehicleRanking(float rank) 
    {
        vehicleRanking = rank;
    }
    float getVehicleRanking() const
    {
        return vehicleRanking;
    }

    
    void displayRide() const
    {
        displayService();
        cout << "Ride Type: " << (rideType ? rideType : "N/A") << endl;
        cout << "Passengers: " << noOfPassengers << endl;
        cout << "Driver Ranking: " << driverRanking << endl;
        cout << "Vehicle Ranking: " << vehicleRanking << endl;
    }
};


class Delivery : public Service
{
private:
    float goodsWeight;
    char* goodsType;

public:
   
    Delivery(char* src = nullptr, char* dest = nullptr, float dist = 0.0, Date date = Date(),
        mTime time = mTime(), bool stat = false, float fuel = 0.0, int custId = -1,
        int drvId = -1, int vehId = -1, float weight = 0.0, char* type = nullptr)
        : Service(src, dest, dist, date, time, stat, fuel, custId, drvId, vehId),
        goodsWeight(weight)
    {
        goodsType = nullptr;
        if (type != nullptr)
        {
            int len = 0;
            while (type[len] != '\0') len++;
            goodsType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                goodsType[i] = type[i];
            }
            goodsType[len] = '\0';
        }
    }

   
    ~Delivery()
    {
        if (goodsType) delete[] goodsType;
    }

    
    void setGoodsWeight(float weight) 
    {
        goodsWeight = weight;
    }
    float getGoodsWeight() const
    {
        return goodsWeight;
    }


    void setGoodsType(char* type) 
    {
        if (goodsType) delete[] goodsType;
        if (type != nullptr)
        {
            int len = 0;
            while (type[len] != '\0') len++;
            goodsType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                goodsType[i] = type[i];
            }
            goodsType[len] = '\0';
        }
    }
    char* getGoodsType() const 
    {
        return goodsType;
    }

    
    void displayDelivery() const
    {
        displayService();
        cout << "Goods Type: " << (goodsType ? goodsType : "N/A") << endl;
        cout << "Goods Weight: " << goodsWeight << " kg" << endl;
    }
};



class Feature
{
private:
    int fId;
    char* description;
    float cost;

public:
    
    Feature(int id = 0, char* desc = nullptr, float c = 0.0) : fId(id), cost(c)
    {
        description = nullptr;
        if (desc != nullptr) 
        {
            
            int len = 0;
            while (desc[len] != '\0') len++;
            description = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                description[i] = desc[i];
            }
            description[len] = '\0';
        }
    }

    ~Feature()
    {
        if (description) delete[] description;
    }

    
    void setDescription(char* desc)
    {
        if (description) delete[] description;
        if (desc != nullptr) {
            int len = 0;
            while (desc[len] != '\0') len++;
            description = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                description[i] = desc[i];
            }
            description[len] = '\0';
        }
    }

    char* getDescription() const 
    {
        return description;
    }

    void setCost(float c) 
    {
        cost = c; 
    }
    float getCost() const 
    {
        return cost;
    }

    void setFId(int id)
    { 
        fId = id;
    }
    int getFId() const
    {
        return fId;
    }

    
    void displayFeature() const
    {
        cout << "Feature ID: " << fId << "\nDescription: " << (description ? description : "N/A")
            << "\nCost: " << cost << endl;
    }
};


class Person
{
protected:
    Name pName;
    Date DOB;
    int age;
    int Nid;

public:
    
    Person(const char* fName = nullptr, const char* lName = nullptr, Date dob = Date(), int id = 0)
        : pName(fName, lName), DOB(dob), Nid(id)
    {
        age = calculateAge(dob);
    }

    
    Person(const Person& other) : pName(other.pName), DOB(other.DOB), age(other.age), Nid(other.Nid) {}

    
    Person& operator=(const Person& other)
    {
        if (this == &other) return *this;

        pName = other.pName;
        DOB = other.DOB;
        age = other.age;
        Nid = other.Nid;

        return *this;
    }

    
    virtual ~Person() {}

    int calculateAge(Date dob)
    {
        int currentYear = 2024; 
        return currentYear - dob.getYear();
    }

    
    void setName(char* fName, char* lName) 
    {
        pName = Name(fName, lName);
    }
    Name getName() const 
    {
        return pName;
    }

    void setDOB(Date dob)
    {
        DOB = dob;
        age = calculateAge(dob);
    }
    Date getDOB() const 
    {
        return DOB;
    }

    void setNid(int id) 
    {
        Nid = id;
    }
    int getNid() const 
    {
        return Nid;
    }

    int getAge() const 
    {
        return age; 
    }

    
    friend ostream& operator<<(ostream& out, const Person& person)
    {
        out << "Name: " << person.pName << "\nDOB: " << person.DOB << "\nAge: " << person.age
            << "\nNational ID: " << person.Nid;
        return out;
    }
};


class Customer : public Person
{
private:
    int cId;
    Service** bookingHistory;
    int historySize;
    int historyCapacity;

public:
    
    Customer(const char* fName = nullptr, const char* lName = nullptr, Date dob = Date(), int nid = 0, int id = 0)
        : Person(fName, lName, dob, nid), cId(id), bookingHistory(nullptr), historySize(0), historyCapacity(5)
    {
        bookingHistory = new Service * [historyCapacity];
        for (int i = 0; i < historyCapacity; ++i)
        {
            bookingHistory[i] = nullptr;
        }
    }

   
    ~Customer()
    {
        for (int i = 0; i < historySize; ++i)
        {
            if (bookingHistory[i]) delete bookingHistory[i];
        }
        delete[] bookingHistory;
    }

   
    void addService(Service* service)
    {
        if (historySize >= historyCapacity)
        {

            Service** newHistory = new Service * [historyCapacity * 2];
            for (int i = 0; i < historyCapacity; ++i)
            {
                newHistory[i] = bookingHistory[i];
            }
            for (int i = historyCapacity; i < historyCapacity * 2; ++i)
            {
                newHistory[i] = nullptr;
            }
            delete[] bookingHistory;
            bookingHistory = newHistory;
            historyCapacity *= 2;
        }
        bookingHistory[historySize++] = service;
    }

   
    void displayBookingHistory() const
    {
        cout << "Booking History for Customer ID " << cId << ":\n";
        for (int i = 0; i < historySize; ++i)
        {
            if (bookingHistory[i]) bookingHistory[i]->displayService();
        }
    }

   
    void setCustomerId(int id) 
    {
        cId = id; 
    }
    int getCustomerId() const 
    {
        return cId;
    }

    friend ostream& operator<<(ostream& out, const Customer& customer)
    {
        out << static_cast<const Person&>(customer); // Call Person's output
        out << "\nCustomer ID: " << customer.cId << "\nBooking History:\n";
        for (int i = 0; i < customer.historySize; ++i)
        {
            if (customer.bookingHistory[i]) customer.bookingHistory[i]->displayService();
        }
        return out;
    }
};


class Driver : public Person
{
private:
    int dId;
    char** LicensesList;
    int noOfLicenses;
    float overallRanking;
    float salary;
    int experience;
    int status;
    Service** serviceHistory;
    int serviceCount;
    int serviceCapacity;

public:
    
    Driver(const char* fName = nullptr, const char* lName = nullptr, Date dob = Date(), int nid = 0, int id = 0,
        float sal = 0, int exp = 0)
        : Person(fName, lName, dob, nid), dId(id), overallRanking(0), salary(sal),
        experience(exp), status(1), serviceCount(0), serviceCapacity(5) {
        LicensesList = nullptr;
        noOfLicenses = 0;
        serviceHistory = new Service * [serviceCapacity];
        for (int i = 0; i < serviceCapacity; ++i)
        {
            serviceHistory[i] = nullptr;
        }
    }

   
    ~Driver() {
        if (LicensesList)
        {
            for (int i = 0; i < noOfLicenses; ++i)
            {
                delete[] LicensesList[i];
            }
            delete[] LicensesList;
        }
        for (int i = 0; i < serviceCount; ++i)
        {
            if (serviceHistory[i]) delete serviceHistory[i];
        }
        delete[] serviceHistory;
    }

    
    void addLicense(char* license)
    {
        char** newLicenses = new char* [noOfLicenses + 1];
        for (int i = 0; i < noOfLicenses; ++i) 
        {
            newLicenses[i] = LicensesList[i];
        }
        newLicenses[noOfLicenses] = new char[100];  // Assuming the license string is <= 100 characters
        int i = 0;
        while (license[i] != '\0')
        {
            newLicenses[noOfLicenses][i] = license[i];
            i++;
        }
        newLicenses[noOfLicenses][i] = '\0';

        delete[] LicensesList;
        LicensesList = newLicenses;
        noOfLicenses++;
    }

   
    void displayLicenses() const
    {
        cout << "Licenses for Driver ID " << dId << ":\n";
        for (int i = 0; i < noOfLicenses; ++i) 
        {
            cout << LicensesList[i] << endl;
        }
    }

    
    void setDriverId(int id) 
    {
        dId = id; 
    }
    int getDriverId() const 
    {
        return dId; 
    }

    void setRanking(float rank) 
    {
        overallRanking = rank;
    }
    float getRanking() const 
    {
        return overallRanking;
    }

    void setSalary(float sal) 
    {
        salary = sal; 
    }
    float getSalary() const 
    {
        return salary; 
    }

    void setExperience(int exp) 
    {
        experience = exp; 
    }
    int getExperience() const 
    {
        return experience; 
    }

    void setStatus(int stat) 
    {
        status = stat;
    }
    int getStatus() const 
    {
        return status; 
    }

    
    friend ostream& operator<<(ostream& out, const Driver& driver)
    {
        out << static_cast<const Person&>(driver);
        out << "\nDriver ID: " << driver.dId << "\nRanking: " << driver.overallRanking
            << "\nSalary: " << driver.salary << "\nExperience: " << driver.experience
            << " years\nStatus: " << (driver.status == 1 ? "Free" : (driver.status == 2 ? "Booked" : "Canceled"))
            << "\nLicenses:\n";
        for (int i = 0; i < driver.noOfLicenses; ++i) 
        {
            out << driver.LicensesList[i] << endl;
        }
        return out;
    }
};

class Vehicle
{
private:
    int vId;
    int registrationNo;
    float avgMileage;
    char* licenseType;
    bool status;
    char* fuelType;
    float overallRanking;
    Date manufacturingDate;
    Feature* features;
    Service** serviceHistory;
    int serviceCount;
    int serviceCapacity;

public:

    Vehicle(int id = 0, int regNo = 0, float mileage = 0.0, const char* licType = nullptr,
        bool stat = false, const char* fuel = nullptr, float rank = 0.0, Date manuDate = Date())
        : vId(id), registrationNo(regNo), avgMileage(mileage), licenseType(nullptr),
        status(stat), fuelType(nullptr), overallRanking(rank), manufacturingDate(manuDate),
        serviceCount(0), serviceCapacity(5)
    {
        if (licType != nullptr)
        {
            int len = 0;
            while (licType[len] != '\0') len++;
            licenseType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                licenseType[i] = licType[i];
            }
            licenseType[len] = '\0';
        }

        if (fuel != nullptr)
        {
            int len = 0;
            while (fuel[len] != '\0') len++;
            fuelType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fuelType[i] = fuel[i];
            }
            fuelType[len] = '\0';
        }

        serviceHistory = new Service * [serviceCapacity];
        for (int i = 0; i < serviceCapacity; ++i)
        {
            serviceHistory[i] = nullptr;
        }
    }

  
    ~Vehicle() 
    {
        if (licenseType) delete[] licenseType;
        if (fuelType) delete[] fuelType;
        for (int i = 0; i < serviceCount; ++i)
        {
            if (serviceHistory[i]) delete serviceHistory[i];
        }
        delete[] serviceHistory;
    }

  
    void setLicenseType(char* type)
    {
        if (licenseType) delete[] licenseType;
        if (type != nullptr) {
            int len = 0;
            while (type[len] != '\0') len++;
            licenseType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                licenseType[i] = type[i];
            }
            licenseType[len] = '\0';
        }
    }

    char* getLicenseType() const 
    {
        return licenseType; 
    }

    void setFuelType(char* fuel)
    {
        if (fuelType) delete[] fuelType;
        if (fuel != nullptr) {
            int len = 0;
            while (fuel[len] != '\0') len++;
            fuelType = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                fuelType[i] = fuel[i];
            }
            fuelType[len] = '\0';
        }
    }

    char* getFuelType() const 
    {
        return fuelType; 
    }

    void setAvgMileage(float mileage) 
    {
        avgMileage = mileage; 
    }
    float getAvgMileage() const 
    {
        return avgMileage;
    }

    void setOverallRanking(float rank) 
    {
        overallRanking = rank; 
    }
    float getOverallRanking() const 
    {
        return overallRanking; 
    }

    void setStatus(bool stat) 
    {
        status = stat; 
    }
    bool getStatus() const 
    {
        return status; 
    }

    void setManufacturingDate(Date date) 
    {
        manufacturingDate = date; 
    }
    Date getManufacturingDate() const 
    {
        return manufacturingDate;
    }

    void addService(Service* service)
    {
        if (serviceCount >= serviceCapacity)
        {
            Service** newHistory = new Service * [serviceCapacity * 2];
            for (int i = 0; i < serviceCapacity; ++i)
            {
                newHistory[i] = serviceHistory[i];
            }
            delete[] serviceHistory;
            serviceHistory = newHistory;
            serviceCapacity *= 2;
        }
        serviceHistory[serviceCount++] = service;
    }

    void displayVehicleDetails() const
    {
        cout << "Vehicle ID: " << vId << "\nRegistration No: " << registrationNo
            << "\nMileage: " << avgMileage << " km/l\nLicense Type: " << licenseType
            << "\nStatus: " << (status ? "Booked" : "Available") << "\nFuel Type: " << fuelType
            << "\nOverall Ranking: " << overallRanking << "\nManufacturing Date: " << manufacturingDate << endl;
        cout << "Features: " << endl;
        if (features) features->displayFeature();
        cout << "Service History: " << endl;
        for (int i = 0; i < serviceCount; ++i)
        {
            if (serviceHistory[i]) serviceHistory[i]->displayService();
        }
    }

    void addFeature(Feature* feature)
    {
        features = feature;
    }
};
class TMS
{
private:
    Customer* customers[15];
    Driver* drivers[10];
    Vehicle* vehicles[20];
    Service* services[50];

    int customerCount;
    int driverCount;
    int vehicleCount;
    int serviceCount;

public:
   
    TMS() : customerCount(0), driverCount(0), vehicleCount(0), serviceCount(0) {}

    void addCustomer(const char* fName, const char* lName, Date dob, int nid)
    {
        if (customerCount < 15)
        {
            int id = customerCount + 1;
            customers[customerCount] = new Customer(fName, lName, dob, nid, id);
            customerCount++;
            cout << "Customer added with ID: " << id << endl;
        }
        else
        {
            cout << "Customer limit reached!" << endl;
        }
    }

    void addDriver(const char* fName, const char* lName, Date dob, int nid, int salary, int exp)
    {
        if (driverCount < 10)
        {
            int id = driverCount + 1;
            drivers[driverCount] = new Driver(fName, lName, dob, nid, id, salary, exp);
            driverCount++;
            cout << "Driver added with ID: " << id << endl;
        }
        else
        {
            cout << "Driver limit reached!" << endl;
        }
    }

    
    void addVehicle(int regNo, float mileage, const char* licenseType, bool status,
        const char* fuelType, float ranking, Date manufacturingDate)
    {
        if (vehicleCount < 20)
        {
            int id = vehicleCount + 1;
            vehicles[vehicleCount] = new Vehicle(id, regNo, mileage, licenseType,
                status, fuelType, ranking, manufacturingDate);
            vehicleCount++;
            cout << "Vehicle added with ID: " << id << endl;
        }
        else
        {
            cout << "Vehicle limit reached!" << endl;
        }
    }

    
    void addService(const char* src, const char* dest, float dist, Date date, mTime time,
        bool status, float fuelRate, int customerId, int driverId, int vehicleId)
    {
        if (serviceCount < 50)
        {
            int id = serviceCount + 1;
            services[serviceCount] = new Service(src, dest, dist, date, time,
                status, fuelRate, customerId, driverId, vehicleId);
            serviceCount++;
            cout << "Service added with ID: " << id << endl;
        }
        else
        {
            cout << "Service limit reached!" << endl;
        }
    }

    
    void printAllCustomers() const
    {
        cout << "All Customers:\n";
        for (int i = 0; i < customerCount; i++)
        {
            cout << *customers[i] << endl;
        }
    }

    void printAllDrivers() const
    {
        cout << "All Drivers:\n";
        for (int i = 0; i < driverCount; i++)
        {
            cout << *drivers[i] << endl;
        }
    }

    
    void printAllVehicles() const
    {
        cout << "All Vehicles:\n";
        for (int i = 0; i < vehicleCount; i++)
        {
            vehicles[i]->displayVehicleDetails();
        }
    }

    
    void printVehicleServiceHistory(int vehicleId) const
    {
        cout << "Service History for Vehicle ID " << vehicleId << ":\n";
        for (int i = 0; i < serviceCount; i++) 
        {
            if (services[i]->getVehicleId() == vehicleId)
            {
                services[i]->displayService();
            }
        }
    }

    void printCustomerServiceHistory(int customerId) const
    {
        cout << "Service History for Customer ID " << customerId << ":\n";
        for (int i = 0; i < serviceCount; i++) 
        {
            if (services[i]->getCustomerId() == customerId)
            {
                services[i]->displayService();
            }
        }
    }

    void printDriverServiceHistory(int driverId) const
    {
        cout << "Service History for Driver ID " << driverId << ":\n";
        for (int i = 0; i < serviceCount; i++) 
        {
            if (services[i]->getDriverId() == driverId)
            {
                services[i]->displayService();
            }
        }
    }

    void cancelService(int serviceId)
    {
        for (int i = 0; i < serviceCount; i++)
        {
            if (services[i] && services[i]->getCustomerId() == serviceId)
            {
                cout << "Service ID " << serviceId << " is canceled. A 5% charge will be applied." << endl;
                // Perform cancellation actions here...
                delete services[i];
                services[i] = nullptr;
                return;
            }
        }
        cout << "Service ID " << serviceId << " not found!" << endl;
    }

    void completeService(int serviceId)
    {
        for (int i = 0; i < serviceCount; i++)
        {
            if (services[i] && services[i]->getCustomerId() == serviceId)
            {
                cout << "Service ID " << serviceId << " completed." << endl;
                services[i]->setStatus(true);
                return;
            }
        }
        cout << "Service ID " << serviceId << " not found!" << endl;
    }
};

int main()
{
    TMS tms;


    tms.addCustomer("Saleem", "Ahmad", Date(10, 10, 1990), 123456);
    tms.addCustomer("Kareem", "Iqbal", Date(12, 11, 1985), 654321);


    tms.addDriver("Ali", "Khan", Date(1, 1, 1980), 1001, 20000, 5);
    tms.addDriver("Ahmed", "Shah", Date(5, 5, 1990), 1002, 25000, 8);


    tms.addVehicle(1234, 15.5, "LTV", true, "Petrol", 4.5, Date(15, 2, 2015));
    tms.addVehicle(5678, 12.3, "HTV", false, "Diesel", 4.0, Date(10, 7, 2012));


    tms.addService("Karachi", "Lahore", 1000.0, Date(25, 12, 2023), mTime(10, 30, 0), false, 10.0, 1, 1, 1);
    tms.addService("Karachi", "Hyderabad", 150.0, Date(26, 12, 2023), mTime(11, 0, 0), true, 7.5, 2, 2, 2);


    tms.printAllCustomers();
    tms.printAllDrivers();
    tms.printAllVehicles();


    tms.printVehicleServiceHistory(1);
    tms.printCustomerServiceHistory(1);
    tms.printDriverServiceHistory(1);


    tms.cancelService(1);


    tms.completeService(2);

    return 0;
}
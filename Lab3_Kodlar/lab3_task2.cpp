#include<bits/stdc++.h>
using namespace std;
struct PassengerNode
{
    string name;
    int age;
    PassengerNode *next = nullptr;

    PassengerNode(string pName, int pAge)
    {
        name = pName;
        age = pAge;
    }
};

class BusQueue
{
public:
    PassengerNode *seniorFront = nullptr;
    PassengerNode *seniorRear = nullptr;

    PassengerNode *regularFront = nullptr;
    PassengerNode *regularRear = nullptr;
    void addPassenger(string name, int age)
    {
        PassengerNode *newNode = new PassengerNode(name, age);

        if (age > 65)
        {
            if (seniorRear == nullptr)
            {
                seniorFront = seniorRear = newNode;
            }
            else
            {
                seniorRear->next = newNode;
                seniorRear = newNode;
            }
            cout << name << " (" << age << " yas) - Yaslilar (prioritetli) novbesine elave olundu." << endl;
        }
        else
        {
            if (regularRear == nullptr)
            {
                regularFront = regularRear = newNode;
            }
            else
            {
                regularRear->next = newNode;
                regularRear = newNode;
            }
            cout << name << " (" << age << " yas) - Adi novbeye elave olundu." << endl;
        }
    }

    void boardBus()
    {
        if (seniorFront != nullptr)
        {
            PassengerNode *temp = seniorFront;
            cout << "Avtobusa mindi (Prioritetli): " << temp->name << " (" << temp->age << " yas)" << endl;

            seniorFront = seniorFront->next;
            if (seniorFront == nullptr)
            {
                seniorRear = nullptr;
            }
            delete temp;
        }
        else if (regularFront != nullptr)
        {
            PassengerNode *temp = regularFront;
            cout << "Avtobusa mindi (Adi): " << temp->name << " (" << temp->age << " yas)" << endl;

            regularFront = regularFront->next;
            if (regularFront == nullptr)
            {
                regularRear = nullptr;
            }
            delete temp;
        }
        else
        {
            cout << "Dayanacaqda avtobusa minecek hec bir sernisin yoxdur!" << endl;
        }
    }

    void displayQueue()
    {
        cout << "\n================ DAYANACAQ NOVBESI ================" << endl;

        cout << "[ Yaslilar Novbesi (Prioritetli) ]:" << endl;
        if (seniorFront == nullptr)
        {
            cout << "  (Bosdur)" << endl;
        }
        else
        {
            PassengerNode *curr = seniorFront;
            int pos = 1;
            while (curr != nullptr)
            {
                cout << "  " << pos++ << ". " << curr->name << " (" << curr->age << " yas)" << endl;
                curr = curr->next;
            }
        }

        cout << "[ Adi Novbe ]:" << endl;
        if (regularFront == nullptr)
        {
            cout << "  (Bosdur)" << endl;
        }
        else
        {
            PassengerNode *curr = regularFront;
            int pos = 1;
            while (curr != nullptr)
            {
                cout << "  " << pos++ << ". " << curr->name << " (" << curr->age << " yas)" << endl;
                curr = curr->next;
            }
        }
        cout << "====================================================" << endl;
    }

};

int main()
{
    BusQueue bus;

    bus.addPassenger("Anar", 25);
    bus.addPassenger("Hesen dayi", 70);
    bus.addPassenger("Nigar", 30);
    bus.addPassenger("Fatma xala", 68);
    bus.addPassenger("Elmir", 19);

    bus.displayQueue();

    bus.boardBus();
    bus.boardBus();

    bus.displayQueue();

    bus.boardBus();
    bus.boardBus();
    bus.boardBus();
    bus.boardBus();

    return 0;
}
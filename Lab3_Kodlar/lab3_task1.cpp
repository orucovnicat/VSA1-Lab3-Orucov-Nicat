#include <bits/stdc++.h>
using namespace std;
struct CustomerNode
{
    string name;
    string medicine;
    CustomerNode *next = nullptr;

    CustomerNode(string custName, string medName)
    {
        name = custName;
        medicine = medName;
    }
};

class PharmacyQueue
{
public:
    CustomerNode *frontNode = nullptr;
    CustomerNode *rearNode = nullptr;
    int count = 0;
    void addCustomer(string name, string medicine)
    {
        CustomerNode *newNode = new CustomerNode(name, medicine);

        if (rearNode == nullptr)
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
        cout << name << " (" << medicine << ") novbeye elave olundu." << endl;
    }

    void serveCustomer()
    {
        if (isEmpty())
        {
            cout << "Novbe bosdur, xidmet gosterilecek musteri yoxdur!" << endl;
            return;
        }
        CustomerNode *temp = frontNode;
        cout << "Xidmet gosterildi: " << temp->name
             << " adli musteriye '" << temp->medicine
             << "' dermani verildi ve novbeden cixarildi." << endl;

        frontNode = frontNode->next;

        if (frontNode == nullptr)
        {
            rearNode = nullptr;
        }

        delete temp;
        count--;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Aptek novbesi hazirda bosdur." << endl;
            return;
        }

        cout << endl
             << "Aptek Novbesi" << endl;
        CustomerNode *current = frontNode;
        int queuePosition = 1;

        while (current != nullptr)
        {
            cout << queuePosition << ". Musteri: " << current->name
                 << " | Teleb olunan derman: " << current->medicine << endl;
            current = current->next;
            queuePosition++;
        }
        cout << "-----------------------" << endl;
    }

    bool isEmpty()
    {
        return frontNode == nullptr;
    }
};

int main()
{
    PharmacyQueue aptek;

    aptek.addCustomer("Samir", "Paracetamol");
    aptek.addCustomer("Orxan", "Parol");
    aptek.addCustomer("Rufan", "Valerian");

    aptek.displayQueue();

    aptek.serveCustomer();

    aptek.displayQueue();

    return 0;
}
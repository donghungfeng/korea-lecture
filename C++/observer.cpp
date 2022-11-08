#include <iostream>
using namespace std;

class IObserver;
class ISubject
{
public:
    virtual void registerObserver(IObserver* o) = 0;
    virtual void removeObserver(IObserver* o) = 0;
    virtual void notifyObservers() = 0;
};

class IObserver
{
public:
    virtual void update(string operation, string record) = 0;
};
class Database : public ISubject
{
private:
    vector<IObserver*> mObservers;
public:
    Database() {}

    void registerObserver(IObserver* o) {
        mObservers.push_back(o);
    }

    void removeObserver(IObserver* o) {
        auto observer = find(mObservers.begin(), mObservers.end(), o);
        if (observer != mObservers.end()) {
            mObservers.erase(observer, observer + 1); // remove observer from mObservers
        }
    }

    void notifyObservers(){
        for (auto& : mObservers) {
            o->update(mOperation, mRecord); 
        }
    }
    void editRecord(string operation, string record) {
        mOperation = operation;
        mRecord = record;
        notifyObservers();
    }
};

class Client : public IObserver
{
public:
    Client() {}

    void update(string operation, string record) {
        cout << "Client: " << operation << " opeation was performed on " << record << endl;
    }
};

class Developer : public IObserver
{
public:
    Developer() {}

    void update(string operation, string record) {
        cout << "Developer: " << operation << " opeation was performed on " << record << endl;
    }
};

class Boss : public IObserver
{
public:
    Boss() {}

    void update(string operation, string record) {
        cout << "Boss: " << operation << " opeation was performed on " << record << endl;
    }
};

int main()
{    
    Database database;
    Developer dev;
    Client client;
    Boss boss;
    db.registerObserver(&dev);
    db.registerObserver(&client);
    db.registerObserver(&boss);
    return 0;
}

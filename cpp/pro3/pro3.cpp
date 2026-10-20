
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer, model;
    int year;

    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
    }

    void setDetails(int id, string maker, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = maker;
        model = mod;
        year = yr;
    }

    int getVehicleID() const
    {
        return vehicleID;
    }

    string getManufacturer() const
    {
        return manufacturer;
    }

    string getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    virtual void display() const
    {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

int Vehicle::totalVehicles = 0;


class Car : virtual public Vehicle
{
protected:
    string fuelType;

public:
    Car()
    {
        fuelType = "Petrol";
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    string getFuelType() const
    {
        return fuelType;
    }

    void display() const override
    {
        cout << "\nType: Car";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType << endl;
    }
};


class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar()
    {
        batteryCapacity = 0;
    }

    void setBatteryCapacity(int battery)
    {
        batteryCapacity = battery;
    }

    void display() const override
    {
        cout << "\nType: Electric Car";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
        cout << "\nBattery Capacity: "
             << batteryCapacity << " kWh\n";
    }
};


class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar()
    {
        topSpeed = 0;
    }

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    void display() const override
    {
        cout << "\nType: Sports Car";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
        cout << "\nBattery Capacity: "
             << batteryCapacity << " kWh";
        cout << "\nTop Speed: " << topSpeed << " km/h\n";
    }
};


class Sedan : public Car
{
public:
    void display() const override
    {
        cout << "\nType: Sedan";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType << endl;
    }
};


class SUV : public Car
{
public:
    void display() const override
    {
        cout << "\nType: SUV";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType << endl;
    }
};


class Aircraft : virtual public Vehicle
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    void setFlightRange(int range)
    {
        flightRange = range;
    }

    int getFlightRange() const
    {
        return flightRange;
    }

    void display() const override
    {
        cout << "\nType: Aircraft";
        Vehicle::display();
        cout << "\nFlight Range: " << flightRange << " km\n";
    }
};


class FlyingCar : public Car, public Aircraft
{
public:
    void display() const override
    {
        cout << "\nType: Flying Car";
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
        cout << "\nFlight Range: " << flightRange << " km\n";
    }
};


class VehicleRegistry
{
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;

        for (int i = 0; i < 100; i++)
        {
            vehicles[i] = NULL;
        }
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }

    void addVehicle()
    {
        if (count >= 100)
        {
            cout << "\nRegistry is full!\n";
            return;
        }

        int type, id, year;

        string maker, model;

        cout << "\n--- Select Vehicle Type ---";
        cout << "\n1. Car";
        cout << "\n2. Electric Car";
        cout << "\n3. Sports Car";
        cout << "\n4. Sedan";
        cout << "\n5. SUV";
        cout << "\n6. Aircraft";
        cout << "\n7. Flying Car";
        cout << "\nEnter type: ";
        cin >> type;

        if (type < 1 || type > 7)
        {
            cout << "\nInvalid vehicle type!\n";
            return;
        }

        cout << "Enter Vehicle ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle ID already exists!\n";
                return;
            }
        }

        cout << "Enter Manufacturer: ";
        getline(cin >> ws, maker);

        cout << "Enter Model: ";
        getline(cin, model);

        cout << "Enter Year: ";
        cin >> year;

        Vehicle* v = NULL;

        switch (type)
        {
            case 1:
                v = new Car();
                break;

            case 2:
                v = new ElectricCar();
                break;

            case 3:
                v = new SportsCar();
                break;

            case 4:
                v = new Sedan();
                break;

            case 5:
                v = new SUV();
                break;

            case 6:
                v = new Aircraft();
                break;

            case 7:
                v = new FlyingCar();
                break;
        }

        v->setDetails(id, maker, model, year);

        if (type == 1 || type == 4 || type == 5)
        {
            string fuel;

            cout << "Enter Fuel Type: ";
            getline(cin >> ws, fuel);

            Car* c = dynamic_cast<Car*>(v);

            if (c != NULL)
            {
                c->setFuelType(fuel);
            }
        }
        else if (type == 2)
        {
            string fuel;
            int battery;

            cout << "Enter Fuel Type: ";
            getline(cin >> ws, fuel);

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            ElectricCar* e = dynamic_cast<ElectricCar*>(v);

            if (e != NULL)
            {
                e->setFuelType(fuel);
                e->setBatteryCapacity(battery);
            }
        }
        else if (type == 3)
        {
            string fuel;
            int battery, speed;

            cout << "Enter Fuel Type: ";
            getline(cin >> ws, fuel);

            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;

            cout << "Enter Top Speed (km/h): ";
            cin >> speed;

            SportsCar* s = dynamic_cast<SportsCar*>(v);

            if (s != NULL)
            {
                s->setFuelType(fuel);
                s->setBatteryCapacity(battery);
                s->setTopSpeed(speed);
            }
        }
        else if (type == 6)
        {
            int range;

            cout << "Enter Flight Range (km): ";
            cin >> range;

            Aircraft* a = dynamic_cast<Aircraft*>(v);

            if (a != NULL)
            {
                a->setFlightRange(range);
            }
        }
        else if (type == 7)
        {
            string fuel;
            int range;

            cout << "Enter Fuel Type: ";
            getline(cin >> ws, fuel);

            cout << "Enter Flight Range (km): ";
            cin >> range;

            FlyingCar* f = dynamic_cast<FlyingCar*>(v);

            if (f != NULL)
            {
                f->setFuelType(fuel);
                f->setFlightRange(range);
            }
        }

        vehicles[count] = v;
        count++;

        cout << "\nVehicle added successfully!\n";
    }

    void displayVehicles() const
    {
        if (count == 0)
        {
            cout << "\nNo vehicles found!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n========== Vehicle "
                 << i + 1 << " ==========\n";

            vehicles[i]->display();
        }
    }

    void searchVehicle() const
    {
        int id;

        cout << "\nEnter Vehicle ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found!\n";
                vehicles[i]->display();
                return;
            }
        }

        cout << "\nVehicle not found!\n";
    }
};


int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Show Total Vehicles Created";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registry.addVehicle();
                break;

            case 2:
                registry.displayVehicles();
                break;

            case 3:
                registry.searchVehicle();
                break;

            case 4:
                cout << "\nTotal Vehicles Created: "
                     << Vehicle::getTotalVehicles() << endl;
                break;

            case 5:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}


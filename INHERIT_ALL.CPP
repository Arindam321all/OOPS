#include <bits/stdc++.h>
using namespace std;

/*
    HIERARCHY OVERVIEW (matches the UML diagram)
    ---------------------------------------------
    Employee (base class)
        |-- SalesManager
        |       |-- BusinessDevelopmentManager  (multiple inheritance below)
        |-- MarketingManager
        |       |-- BusinessDevelopmentManager  (multiple inheritance below)
        |-- Executive
        |       |-- CEO
        |-- Developer
        |-- HRManager
                |-- HRDirector

    ProjectManager (independent base class)
        |-- TechLead  (multiple inheritance below)
    TeamLead (independent base class)
        |-- TechLead  (multiple inheritance below)

    Types of inheritance demonstrated:
      - Single inheritance:      SalesManager, MarketingManager, Executive,
                                  Developer, HRManager  (each from Employee)
      - Multilevel inheritance:  CEO <- Executive <- Employee
                                  HRDirector <- HRManager <- Employee
      - Multiple inheritance:    BusinessDevelopmentManager <- SalesManager + MarketingManager
                                  TechLead <- ProjectManager + TeamLead
*/

// ---------------------------------------------------------
// Base Class: Employee
// ---------------------------------------------------------
class Employee {
protected:
    string name;
    int employeeId;
public:
    Employee(string name, int employeeId) : name(name), employeeId(employeeId) {}
    void display() {
        cout << "[Employee] Name: " << name << " | ID: " << employeeId << endl;
    }
};

// ---------------------------------------------------------
// Single inheritance: direct children of Employee
// ---------------------------------------------------------
class SalesManager : public Employee {
public:
    SalesManager(string name, int id) : Employee(name, id) {}
    void boostSales() {
        cout << name << " is boosting sales." << endl;
    }
};

class MarketingManager : public Employee {
public:
    MarketingManager(string name, int id) : Employee(name, id) {}
    void createMarketingStrategy() {
        cout << name << " is creating a marketing strategy." << endl;
    }
};

class Executive : public Employee {
public:
    Executive(string name, int id) : Employee(name, id) {}
    void makeExeDecision() {
        cout << name << " is making an executive decision." << endl;
    }
};

class Developer : public Employee {
private:
    string progLanguage;
public:
    Developer(string name, int id, string lang) : Employee(name, id), progLanguage(lang) {}
    void show() {
        cout << name << " codes in " << progLanguage << "." << endl;
    }
};

class HRManager : public Employee {
public:
    HRManager(string name, int id) : Employee(name, id) {}
    void handleHRDuties() {
        cout << name << " is handling HR duties." << endl;
    }
};

// ---------------------------------------------------------
// Multilevel inheritance
// ---------------------------------------------------------
class CEO : public Executive {
public:
    CEO(string name, int id) : Executive(name, id) {}
    void leadCompany() {
        cout << name << " is leading the company." << endl;
    }
};

class HRDirector : public HRManager {
public:
    HRDirector(string name, int id) : HRManager(name, id) {}
    void manageHRDep() {
        cout << name << " is managing the entire HR department." << endl;
    }
};

// ---------------------------------------------------------
// Multiple inheritance: BusinessDevelopmentManager
// (inherits from BOTH SalesManager and MarketingManager)
// ---------------------------------------------------------
class BusinessDevelopmentManager : public SalesManager, public MarketingManager {
public:
    // Note: base classes SalesManager & MarketingManager each carry their own
    // copy of Employee's members (the "diamond problem"), so we re-pass
    // name/id to both parents' constructors.
    BusinessDevelopmentManager(string name, int id)
        : SalesManager(name, id), MarketingManager(name, id) {}

    void coordinateBusinessDev() {
        // "name" is ambiguous here because both SalesManager and MarketingManager
        // each carry their own separate copy of Employee's "name" (diamond problem).
        // Must explicitly say which one to use:
        cout << SalesManager::name << " is coordinating business development." << endl;
    }
};

// ---------------------------------------------------------
// Independent base classes (not derived from Employee)
// ---------------------------------------------------------
class ProjectManager {
protected:
    int projectManaged;
public:
    ProjectManager(int projectManaged) : projectManaged(projectManaged) {}
    void manageProject() {
        cout << "Managing " << projectManaged << " project(s)." << endl;
    }
};

class TeamLead {
protected:
    int teamSize;
public:
    TeamLead(int teamSize) : teamSize(teamSize) {}
    void leadTeam() {
        cout << "Leading a team of " << teamSize << " people." << endl;
    }
};

// ---------------------------------------------------------
// Multiple inheritance: TechLead
// (inherits from BOTH ProjectManager and TeamLead)
// ---------------------------------------------------------
class TechLead : public ProjectManager, public TeamLead {
public:
    TechLead(int projectManaged, int teamSize)
        : ProjectManager(projectManaged), TeamLead(teamSize) {}

    void displayInfo() {
        cout << "TechLead handles " << projectManaged
             << " project(s) and leads a team of " << teamSize << "." << endl;
    }
};

// ---------------------------------------------------------
// Demo
// ---------------------------------------------------------
int main() {
    cout << "--- Single Inheritance ---" << endl;
    SalesManager sm("Ravi", 101);
    sm.display();
    sm.boostSales();

    Developer dev("Anita", 102, "C++");
    dev.display();
    dev.show();

    cout << "\n--- Multilevel Inheritance ---" << endl;
    CEO ceo("Vikram", 103);
    ceo.display();          // from Employee
    ceo.makeExeDecision();  // from Executive
    ceo.leadCompany();      // from CEO

    HRDirector hrd("Sneha", 104);
    hrd.display();
    hrd.handleHRDuties();
    hrd.manageHRDep();

    cout << "\n--- Multiple Inheritance (BusinessDevelopmentManager) ---" << endl;
    BusinessDevelopmentManager bdm("Karan", 105);
    bdm.boostSales();               // from SalesManager
    bdm.createMarketingStrategy();  // from MarketingManager
    bdm.coordinateBusinessDev();    // its own method
    // Note: bdm.display() would be AMBIGUOUS (two copies of Employee exist)
    // Must disambiguate explicitly:
    bdm.SalesManager::display();
    bdm.MarketingManager::display();

    cout << "\n--- Multiple Inheritance (TechLead) ---" << endl;
    TechLead tl(3, 8);
    tl.manageProject();  // from ProjectManager
    tl.leadTeam();        // from TeamLead
    tl.displayInfo();     // its own method

    return 0;
}
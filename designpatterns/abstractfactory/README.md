## Abstract Factory Pattern

### Intent

Abstract factory is a creational design pattern that allows to produce families of related objects without specifying their concrete classes.

## Problem:

Consider a scenario where we need to create objects of the same family.

for example, we have a Tesla car and we need to purchase cold tire, we cannot buy Hundai or Ford tire for our Tesla car. We need Tesla comparible tire.

Abstract factory pattern helps to solve this issue.

## Implementation

```
#include <iostream>
#include <string>

using namespace std;


class ITire {
public:
    virtual void make_tire() = 0;
};


class TeslaTire : public ITire
{
public:
    void make_tire();
};

void TeslaTire::make_tire() {
    cout << "Tesla Tire" << endl;
}

class FordTire : public ITire {
public:
    void make_tire();

};

void FordTire::make_tire()
{
    cout << "Ford Tire" << endl;
}

class IHeadLight {
public:
    virtual void make_headlight() = 0;
};

class TeslaHeadlight : public IHeadLight
{
public:
    void make_headlight();
};

void TeslaHeadlight::make_headlight() {
    cout << "Tesla Headlight" << endl;
}

class FordHeadlight : public IHeadLight {
public:
    void make_headlight();
};

void FordHeadlight::make_headlight() {
    cout << "Ford Headlight" << endl;
}

class IAbstractFactory {
public:
    virtual IHeadLight* make_headlight() = 0;
    virtual ITire* make_tire() = 0;
};

class TeslaFactory : public IAbstractFactory {
public:
    IHeadLight* make_headlight();
    ITire* make_tire();
};

IHeadLight* TeslaFactory::make_headlight() {
    IHeadLight* pHeadlight = new TeslaHeadlight();
    pHeadlight->make_headlight();
    return pHeadlight;
}

ITire* TeslaFactory::make_tire()
{
    ITire* pTire = new TeslaTire();
    pTire->make_tire();
    return pTire;
}


class FordFactory : public IAbstractFactory {
public:
    IHeadLight* make_headlight();
    ITire* make_tire();
};

IHeadLight* FordFactory::make_headlight() {
    IHeadLight* pHeadlight = new FordHeadlight();
    pHeadlight->make_headlight();
    return pHeadlight;
}

ITire* FordFactory::make_tire()
{
    ITire* pTire = new FordTire();
    pTire->make_tire();
    return pTire;
}

enum Compnaies {
    TESLA = 0,
    FORD = 1
};

class AbstractFactory {
public:
    static IAbstractFactory* GetCompanyObjects(Compnaies company);
};

IAbstractFactory* AbstractFactory::GetCompanyObjects(Compnaies company)
{
    IAbstractFactory* pAbsFactory = NULL;

    switch (company)
    {
    case TESLA:
        pAbsFactory = new TeslaFactory();
        break;
    case FORD:
        pAbsFactory = new FordFactory();
        break;
    default:
        break;
    }

    return pAbsFactory;
}


int main()
{
    std::cout << "Abstract Factory Implementation\n";

    auto pTesla = AbstractFactory::GetCompanyObjects(Compnaies::TESLA);
    pTesla->make_tire();
    pTesla->make_headlight();


    auto pFord = AbstractFactory::GetCompanyObjects(Compnaies::FORD);
    pFord->make_tire();
    pFord->make_headlight();

}
```

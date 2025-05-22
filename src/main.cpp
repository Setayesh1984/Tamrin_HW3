
#include <iostream>
#include <memory>       //unique_ptr and shared_ptr
#include <limits>
#include <algorithm>    //cin
#include <cctype>       //isalpha
#include "usd.hpp"
#include "eur.hpp"
#include "irr.hpp"
#include "bankaccount.hpp"
#include "shoppingcart.hpp"
#include "fruit.hpp"
#include "snack.hpp"
#include "seasoning.hpp"
#include "item.hpp"
#include "vegetables.hpp"
#include "drinks.hpp"


// shared_ptr-->shei mored estefade az barname ha

// unique_ptr-->mored estafade 1 barname





void getValidPositiveDouble(const std::string& prompt, double& value) 
{
    while (true) 
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < 0) //fail:adad,harf na
        {
            std::cout << "vorodi namotabar! adad mosbat vared konid.\n";
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    }
}




void getValidString(const std::string& prompt, std::string& input) 
{
    while (true) 
    {
        std::cout << prompt;
        //ws:hazf fasele,voroodi  input:zakhiresazi ozv getline
        std::getline(std::cin >> std::ws, input); 


        //barresi hame char -->all of
        if (std::all_of(input.begin(), input.end(), [](char c){ return std::isalpha(c) || std::isspace(c); })) break;

        std::cout << "vorodi namotabar! lotfan harf vared konid.\n";
    }
}





int main() 
{
    std::string name, accNumber;
    double transferLimit;
    int currencyChoice;

    std::cout << "Welcome to Bank & Shopping System \n";

    getValidString("Enter your name: ", name);
    getValidString("Enter your bank account name: ", accNumber);
    getValidPositiveDouble("Enter your transfer limit: ", transferLimit);
    if (transferLimit <= 0) 
    {
        std::cout << "transfer limit namotabar! meghdar pishfarz (1000) set shod.\n";
        transferLimit = 1000;
    }
    


    std::cout << "Choose currency:\n1. USD\n2. EUR\n3. IRR\n>> ";
    while (!(std::cin >> currencyChoice) || currencyChoice < 1 || currencyChoice > 3) 
    {
        std::cout << "vorodi namotabar! bayad adad bein 1 ta 3 bashad.\n>> ";
        std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    std::unique_ptr<Currency> startingCurrency;  //unique-Ptr delete nadare

    if (currencyChoice == 1) startingCurrency = std::make_unique<USD>(0);
    else if (currencyChoice == 2) startingCurrency = std::make_unique<EUR>(0);
    else startingCurrency = std::make_unique<IRR>(0);

    BankAccount account(transferLimit);

    double initAmount;
    getValidPositiveDouble("Enter initial deposit: ", initAmount);
    startingCurrency->setValue(initAmount);
    account.deposit(*startingCurrency);    //despite->avalei be hesab banki*pointercurrency

    std::cout << "hesab ba movafaghiat sakhte shod!\n";
    account.printBalance();

    CartEntry cart;
    char addMore;
    do 
    {
        std::string itemChoiceStr;
        std::cout << "\nChoose item to add:\n1. Fruit\n2. Snack\n3. Seasoning\n4. Vegetables\n5. Drink\n>> ";
        std::getline(std::cin >> std::ws, itemChoiceStr);  //hazf space
        std::transform(itemChoiceStr.begin(), itemChoiceStr.end(), itemChoiceStr.begin(), ::tolower);

        int itemChoice = 0;
        if (itemChoiceStr == "1" || itemChoiceStr == "fruit") itemChoice = 1;
        else if (itemChoiceStr == "2" || itemChoiceStr == "snack") itemChoice = 2;
        else if (itemChoiceStr == "3" || itemChoiceStr == "seasoning") itemChoice = 3;
        else if (itemChoiceStr == "4" || itemChoiceStr == "vegetables" || itemChoiceStr == "vegetable") itemChoice = 4;
        else if (itemChoiceStr == "5" || itemChoiceStr == "drink" || itemChoiceStr == "drinks") itemChoice = 5;
        else 
        
        {
            std::cout << "vorodi namotabar!\n";
            continue;
        }

        double price, quantity;
        getValidPositiveDouble("Price: ", price);
        getValidPositiveDouble("Quantity: ", quantity);
        Currency priceCurrency(price, startingCurrency->getConversionRate());

        std::shared_ptr<Item> item;
        switch (itemChoice) 
        {
            case 1: 
            {
                std::string fruitOption;
                std::cout << "choose fruit:\n1) toot\n2) khiyar\n3) mooz\n4) sib\n5) aloocheh\n6) porteghal\n>> ";
                std::getline(std::cin >> std::ws, fruitOption);
                std::transform(fruitOption.begin(), fruitOption.end(), fruitOption.begin(), ::tolower);
                std::string fruitType;
                if (fruitOption == "1" || fruitOption == "toot") fruitType = "toot";
                else if (fruitOption == "2" || fruitOption == "khiyar") fruitType = "khiyar";
                else if (fruitOption == "3" || fruitOption == "mooz") fruitType = "mooz";
                else if (fruitOption == "4" || fruitOption == "sib") fruitType = "sib";
                else if (fruitOption == "5" || fruitOption == "aloocheh") fruitType = "aloocheh";
                else if (fruitOption == "6" || fruitOption == "porteghal") fruitType = "porteghal";
                else fruitType = "fruit";
                item = std::make_shared<Fruit>(fruitType, priceCurrency, quantity, fruitType , Unit::Kg);
                break;
            }
            case 2: 
            {
                std::string snackOption;
                std::cout << "choose snack type:\n1. pitzayi\n2. gosht\n3. sosis\n4. morgh\n>> ";
                std::getline(std::cin >> std::ws, snackOption);
                std::transform(snackOption.begin(), snackOption.end(), snackOption.begin(), ::tolower);
                std::string snackType;
                if (snackOption == "1" || snackOption == "pitzayi") snackType = "pitzayi";
                else if (snackOption == "2" || snackOption == "gosht") snackType = "gosht";
                else if (snackOption == "3" || snackOption == "sosis") snackType = "sosis";
                else if (snackOption == "4" || snackOption == "morgh") snackType = "morgh";
                else snackType = "snack";
                double calDouble;
                getValidPositiveDouble("Snack calories: ", calDouble);
                int cal = static_cast<int>(calDouble);

                item = std::make_shared<Snack>(snackType, priceCurrency, quantity, cal , Unit::Package);
                //item = std::shared_ptr<Item>(new Snack(snackType, priceCurrency, quantity, cal, Unit::Package));

                break;
            }



            case 3: 
            {
                std::string seasoningOption;
                std::cout << "choose seasoning type:\n1. sos\n2. torshijaat\n3. adwijat\n>> ";
                std::getline(std::cin >> std::ws, seasoningOption);
                std::transform(seasoningOption.begin(), seasoningOption.end(), seasoningOption.begin(), ::tolower);
                std::string flavor;
                if (seasoningOption == "1" || seasoningOption == "sos") flavor = "sos";
                else if (seasoningOption == "2" || seasoningOption == "torshijaat") flavor = "torshijaat";
                else if (seasoningOption == "3" || seasoningOption == "adwijat") flavor = "adwijat";
                else flavor = "seasoning";
                item = std::make_shared<Seasoning>(flavor, priceCurrency, quantity, flavor , Unit::g);
                break;
            }



            case 4: 
            {
                std::string vegOption;
                std::cout << "choose vegetable type:\n1. jaafari\n2. tareh\n3. havij va torobcheh\n>> ";
                std::getline(std::cin >> std::ws, vegOption);
                std::transform(vegOption.begin(), vegOption.end(), vegOption.begin(), ::tolower);
                std::string color;
                if (vegOption == "1" || vegOption == "jaafari") color = "jaafari";
                else if (vegOption == "2" || vegOption == "tareh") color = "tareh";
                else if (vegOption == "3" || vegOption == "havij va torobcheh") color = "havij va torobcheh";
                else color = "vegetable";
                item = std::make_shared<Vegetables>(color, priceCurrency, quantity, color , Unit::Kg);
                break;
            }



            case 5: 
            {
                std::string drinkOption;
                std::cout << "choose drink:\n1. ab\n2. doogh\n3. noshabe\n4. delester\n5. abmive\n>> ";
                std::getline(std::cin >> std::ws, drinkOption);
                std::transform(drinkOption.begin(), drinkOption.end(), drinkOption.begin(), ::tolower);
                bool isCold = true;
                if (drinkOption == "1" || drinkOption == "ab") isCold = true;
                else if (drinkOption == "2" || drinkOption == "doogh") isCold = true;
                else if (drinkOption == "3" || drinkOption == "noshabe") isCold = true;
                else if (drinkOption == "4" || drinkOption == "delester") isCold = true;
                else if (drinkOption == "5" || drinkOption == "abmive") isCold = false;
                item = std::make_shared<Drinks>(drinkOption, priceCurrency, quantity, isCold , Unit::bottle);
                break;
            }
        }

        cart.addItem(item); //add to sabadKharid
        std::cout << "add item dige? (y/n): ";
        std::cin >> addMore;
        ++(*item);  //add cala be anbar

    } 
    
    
    
    
    while (addMore == 'y' || addMore == 'Y');

    //gift
    if (cart.getItems().size() >= 5) 
    {
        Currency freePrice(0.0, startingCurrency->getConversionRate());
        auto gift = std::make_shared<Snack>("gift-snack", freePrice, 1, 0, Unit::Package);
        cart.addItem(gift);
        std::cout << "gift snack ba gheymat 0 be sabad ezafe shod!" << std::endl;
    }



    std::cout << "sabade shoma:\n";
    cart.printItems();

    Currency total = cart.calculateTotal();
    std::cout << "mablagh pardakht: ";
    total.print();

    std::cout << "\n aya mikhahid pardakht ra anjam dahid? (y/n): ";
    char pay;
    std::cin >> pay;
    if (pay == 'y' || pay == 'Y') 
    {
        if (cart.checkout(account)) 
        {
        for (const auto& it : cart.getItems()) 
        {
            --(*it); 
        }
        
        std::cout << "pardakht movafagh bud!\n";
        std::cout << " stock jadid ba'd az pardakht:\n";
        cart.printItems();

    }
    
    else
    
    {
        std::cout << "pardakht namovafagh! mojodi ya had ra check konid.\n";
    }
} 
    std::cout << "mojodi nahayi hesab: ";
    account.printBalance();
    std::cout << "mamnoon az estefade az system ma!\n";
    return 0;
}

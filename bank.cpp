#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;


bool isValidCardNumber(const string& cardNumber) {
    int nDigits = cardNumber.length();
    int sum = 0;
    bool isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {
        int d = cardNumber[i] - '0';
        if (isSecond)
            d = d * 2;
        sum += d / 10;
        sum += d % 10;
        isSecond = !isSecond;
    }
    return (sum % 10 == 0);
}


string getBankName(const string& cardNumber) {
    map<string, string> bankMap = {
        {"603799", "MELI"},
        {"589210", "SADERAT"},
        {"627648", "TOSEE SADERAT"},
        {"627961", "SANAT O MADAN"},
        {"603770", "KESHAVARZI"},
        {"628023", "MASKAN"},
        {"627760", "POST BANK"},
        {"502908", "TOSEE TAVON"},
        {"627412", "EGHTESAD NOVIN"},
        {"622106", "PARSIAN"},
        {"502229", "PASARGAD"},
        {"627488", "KARAFARIN"},
        {"621986", "SAMAN"},
        {"639346", "SINA"},
        {"639607", "SARMAYEH"},
        {"636214", "AYANDEH"},
        {"505785", "IRAN ZAMIN"},
        {"636949", "HEKMAT IRANIAN"},
        {"628157", "ETEBARI TOSEE"},
        {"505416", "GARDESHGARI"},
        {"606373", "QARZOL HASANE MEHR IRAN"},
        {"628175", "MEHR IRAN"},
        {"639370", "MEHR EGHTESAD"},
        {"627381", "ANSAR"},
        {"639194", "SARMAYEG"},
        {"603769", "SHABAKE PAYE KASHI"}
    };

    string bankCode = cardNumber.substr(0, 6);
    if (bankMap.find(bankCode) != bankMap.end()) {
        return bankMap[bankCode];
    }
    return "UNKNOWN";
}

int main() {
    string cardNumber;

    cout << "Enter a 16-digit card number: ";
    cin >> cardNumber;

    
    if (cardNumber.length() != 16 || !regex_match(cardNumber, regex("[0-9]+"))) {
        cout << "Invalid card number format." << endl;
        return 1;
    }

    
    if (!isValidCardNumber(cardNumber)) {
        cout << "Invalid card number." << endl;
        return 1;
    }


    string bankName = getBankName(cardNumber);


    cout << "CARD: " << cardNumber.substr(0, 4) << "-" << cardNumber.substr(4, 4) << "-" << cardNumber.substr(8, 4) << "-" << cardNumber.substr(12, 4) << endl;
    cout << "BANK: " << bankName << endl;

    return 0;
}

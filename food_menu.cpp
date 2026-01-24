#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "\t\t\t FOOD MENU" << endl;
    cout << "\t\t\t------------" << endl;

    string user, js, sh, wr, tc;
    int mc = 0, ch = 0, pm1 = 0;
    char pm = 'n';
    char wraps, tacos, juices, shakes;
    double drinkPrice = 0, mainCoursePrice = 0, totalBill = 0;
    ofstream file;

    file.open("food_order.txt", ios::app);
    if (!file)
    {
        cerr << "Unable to open food_order.txt for writing." << endl;
        return 1;
    }

    cout << "enter your name: ";
    // getline(cin, user);
    file << "Customer Name: " << user << endl;
    if (user.empty())
    {
        getline(cin, user);
    }

    cout << "\n";
    cout << "Welcome to Taco Bell " << user << "!" << endl;
    cout << "\t\t\t MENU " << endl;

    cout << "what would you like to have?" << endl;
    cout << "juices or shakes (press 1 for juices and 2 for shakes): ";
    if (!(cin >> ch))
        return 0;
    if (ch == 1)
    {
        cout << "JUICES MENU" << endl;
        cout << "------------" << endl;
        int juices = 0;
        cout << "1. Pineapple lime";
        juices = 159;
        cout << ":" << juices << "/-" << endl;
        cout << "2. Cranberry crush";
        juices = 189;
        cout << ":" << juices << "/-" << endl;
        cout << "3. Mango peach";
        juices = 179;
        cout << ":" << juices << "/-" << endl;
        cout << "4. Dragonfruit berry";
        juices = 199;
        cout << ":" << juices << "/-" << endl;
        cout << "which juice would you like to have?: ";
        cin >> ws;
        getline(cin, js);
        file << "Juice: " << js << endl;
        drinkPrice = juices;
    }
    else if (ch == 2)
    {
        cout << "SHAKES MENU" << endl;
        cout << "-----------" << endl;
        int shakes = 0;
        cout << "1. Sweet vanilla";
        shakes = 149;
        cout << ":" << shakes << "/-" << endl;
        cout << "2. Mexican chocolate";
        shakes = 169;
        cout << ":" << shakes << "/-" << endl;
        cout << "3. Dulce de leche";
        shakes = 199;
        cout << ":" << shakes << "/-" << endl;
        cout << "4. Wild strawberry";
        shakes = 159;
        cout << ":" << shakes << "/-" << endl;
        cout << "which shake would you like to have?: ";
        cin >> ws;
        getline(cin, sh);
        file << "Shake: " << sh << endl;
        drinkPrice = shakes;
    }

    else
    {
        cout << "Invalid selection for drinks." << endl;
    }

    cout << "would you like to continue your order with main course?\n";
    cout << "press 'y' for yes and 'n' for no: ";
    cin >> pm;
    file << "Main course (y/n): " << pm << endl;

    if (pm == 'y' || pm == 'Y')
    {
        cout << "please enter your choice <3 " << endl;
        cout << "Wrap or Taco (press 1 for wraps and 2 for taco): ";
        cin >> mc;

        if (mc == 1)
        {
            cout << "WRAP" << endl;
            cout << "-----" << endl;
            int wraps = 0;
            cout << "1. Spicy paneer";
            wraps = 199;
            cout << ":" << wraps << "/-" << endl;
            cout << "2. Crispy chicken";
            wraps = 249;
            cout << ":" << wraps << "/-" << endl;
            cout << "3. Crispy potato";
            wraps = 179;
            cout << ":" << wraps << "/-" << endl;
            cout << "4. Hot bean";
            wraps = 159;
            cout << ":" << wraps << "/-" << endl;
            cout << "which wrap would you like to have? ";
            cin >> ws;
            getline(cin, wr);
            file << "Wrap: " << wr << endl;
            mainCoursePrice = wraps;
        }
        else if (mc == 2)
        {
            cout << "TACO" << endl;
            cout << "-----" << endl;
            int tacos = 0;
            cout << "1. Soft shell taco";
            tacos = 129;
            cout << ":" << tacos << "/-" << endl;
            cout << "2. Crunchy taco";
            tacos = 149;
            cout << ":" << tacos << "/-" << endl;
            cout << "3. Naked taco";
            tacos = 159;
            cout << ":" << tacos << "/-" << endl;
            cout << "4. Cheesy lava taco";
            tacos = 179;
            cout << ":" << tacos << "/-" << endl;
            cout << "which taco would you like to have? ";
            cin >> ws;
            getline(cin, tc);
            file << "Taco: " << tc << endl;
            mainCoursePrice = tacos;
        }
        else
        {
            cout << "invalid input for main course selection" << endl;
        }
    }

    if (ch != 1 && ch != 2 && mc != 1 && mc != 2)
    {
        cout << "No items were selected. Exiting order process." << endl;
        file.close();
        return 0;
    }

    // Display billing gateway
    cout << "\n";
    cout << "\t\t\t BILLING GATEWAY" << endl;
    cout << "\t\t\t=================" << endl;

    // Add drink to bill
    if (ch == 1)
    {
        cout << js << " (Juice)" << "\t\t" << drinkPrice << "/-" << endl;
        file << "Juice Price: " << drinkPrice << endl;
        totalBill += drinkPrice;
    }
    else if (ch == 2)
    {
        cout << sh << " (Shake)" << "\t\t" << drinkPrice << "/-" << endl;
        file << "Shake Price: " << drinkPrice << endl;
        totalBill += drinkPrice;
    }
    else if (ch != 1 && ch != 2)
    {
        cout << "No drinks were selected." << endl;
    }

    // Add main course to bill
    if (mc == 1)
    {
        cout << wr << " (Wrap)" << "\t\t" << mainCoursePrice << "/-" << endl;
        file << "Wrap Price: " << mainCoursePrice << endl;
        totalBill += mainCoursePrice;
    }
    else if (mc == 2)
    {
        cout << tc << " (Taco)" << "\t\t" << mainCoursePrice << "/-" << endl;
        file << "Taco Price: " << mainCoursePrice << endl;
        totalBill += mainCoursePrice;
    }
    else if (mc != 1 && mc != 2)
    {
        cout << "No main course was selected." << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "TOTAL BILL: " << totalBill << "/-" << endl;
    file << "Total Bill: " << totalBill << endl;
    cout << "-----------------------------" << endl;

    cout << "\n";
    cout << "\t\t\t PAYMENT GATEWAY" << endl;
    cout << "\t\t\t=================" << endl;
    cout << "please select the payment method" << endl;
    cout << "UPI/cash (press 1 for upi and 2 for cash): ";
    cin >> pm1;

    if (pm1 == 1)
    {
        cout << "\nOpening UPI QR Code..." << endl;
        string upiLink =
            "upi://pay?"
            "pa=bhawyagugdodia@fam&"
            "pn=TacoBell&"
            "am=" +
            to_string((int)totalBill) +
            "&cu=INR";

        string qrURL = "https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=" + upiLink;
        system(("start " + qrURL).c_str());
        cout << "Please scan the QR code to complete payment." << endl;
        cout << "Amount to pay: " << totalBill << "/-" << endl;
        file << "Payment Method: UPI" << endl;
        file << "Amount Paid: " << totalBill << endl;
    }

    else if (pm1 == 2)
    {
        cout << "please pay on the counter." << endl;
        cout << "Amount to pay: " << totalBill << "/-" << endl;
        cout << "-----------------------------" << endl;
        file << "Payment Method: Cash" << endl;
        file << "Amount to Pay: " << totalBill << endl;
    }

    else
    {
        cout << "invalid input" << endl;
        file << "Payment: invalid" << endl;
    }
    
    cout << "thank you for choosing Taco Bell!" << endl;

    file.close();

    return 0;
}
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Account
{
    // structur account
    string username;
    string password;
    double balance;
};

int main()
{
    map<string, Account> accounts;
    string username, password;
    int pilihan;

    while (true)
    {
        cout << "|===============================================|" << endl;
        cout << "|         Selamat datang di Bank HanzYiz        |" << endl;
        cout << "|===============================================|" << endl;
        cout << "|        1. Buat Account                        |" << endl;
        cout << "|        2. Login ke Akun                       |" << endl;
        cout << "|        3. exit                                |" << endl;
        cout << "|===============================================|" << endl;
        cout << "\n silah kan pilih menu (1/2/3) : ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            Account newAccount;
            cout << "Masukan Username : ";
            cin >> newAccount.username;
            cout << endl;
            cout << "Masukan password : ";
            cin >> newAccount.password;
            // mendeklarasi bahwa accout itu balance 0
            newAccount.balance = 0;
            accounts[newAccount.username] = newAccount;
            cout << "Akun berhasil di buat !!" << endl;
            cout << "Silahkan login " << username << "!" << endl;
            cout << "\n";
        }

        else if (pilihan == 3)
        {
            cout << "Terimakasih telah menggunakan jasa bank HanzYiz" << endl;
            cout << "\n";
            break;
        }

        if (pilihan == 2)
        {
            // memasukan informasi account
            cout << "masukan username anda : ";
            cin >> username;
            cout << endl;
            cout << "masukan password anda : ";
            cin >> password;

            if (accounts.find(username) != accounts.end() && accounts[username].password == password)
            {
                cout << "Selamat datang, " << username << "!" << endl;

                while (true)
                {
                    int pilih;
                    cout << "\n"
                         << endl;
                    cout << "|==================================|" << endl;
                    cout << "|        Menu Bank HanzYiz         |" << endl;
                    cout << "|==================================|" << endl;
                    cout << "|         1. Deposit               |" << endl;
                    cout << "|         2. Transfer              |" << endl;
                    cout << "|         3. Withdraw              |" << endl;
                    cout << "|         4. Info account          |" << endl;
                    cout << "|         5. Log out               |" << endl;
                    cout << "|==================================|" << endl;
                    cout << " Masukan pilihan anda (1/2/3/4/5) : ";
                    cin >> pilih;
                    cout << endl;
                    if (pilih == 1)
                    {
                        double deposit;
                        cout << endl;
                        cout << "Masukan Deposit Rp. ";
                        cin >> deposit;
                        accounts[username].balance += deposit;
                    }
                    else if (pilih == 2)
                    {
                        string namaakun;
                        double transfer;
                        cout << endl;
                        cout << "Masukan UserName pengguna : ";
                        cin >> namaakun;
                        cout << "Masukan Nominal transfer anda : ";
                        cin >> transfer;
                        if (transfer <= accounts[namaakun].balance)
                        {
                            accounts[username].balance -= transfer;
                            accounts[namaakun].balance += transfer;
                            cout << "Transfer sukses " << endl;
                            cout << "Saldo anda tersisa : " << accounts[username].balance << endl;
                        }
                        else
                        {
                            cout << "Gagal transfer, saldo tidak mencukupi." << endl;
                        }
                    
                    }

                    else if (pilih == 3)
                    {
                        double withdraw;
                        cout << "Masukan jumlah withdraw anda : ";
                        cin >> withdraw;
                        if (withdraw <= accounts[username].balance)
                        {
                            accounts[username].balance -= withdraw;
                            cout << "Berhasil withdraw " << endl;
                            cout << "Saldo anda tersisa : " << accounts[username].balance << endl;
                            cout << "\n";
                        }
                        else
                        {
                            cout << "Gagal withdraw, saldo tidak mencukupi." << endl;
                        }
                    }
                    else if (pilih == 4)
                    {
                        cout << "Nama rekening : " << accounts[username].username << endl;
                        cout << "Jumlah saldo  : " << accounts[username].balance << endl;
                        cout << "\n";
                    }
                    else if (pilih == 5)
                    {
                        cout << "melakukan log out" << endl;
                        cout << "Terimakasih telah menggunakan jasa bank HanzYiz" << endl;
                        cout << "\n";
                        break;
                    }
                    else{
                        cout<<"Maaf menu yang Anda masukkan salah. Silahkan ulangi lagi.\n";
                    }
                  }
        }
        else{
            cout << "Username atau password salah. Ulangi kembali dengan benar\n";
        }
    }
    else {
        cout << "Maaf menu yang anda masukan salah. silahkan ulangi lagi.\n";
    }
}
}

 
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

// Базовый класс User
class User {
protected:
    string username;
    string email;

    // Общая проверка email
    bool isValidEmail(const string& email) const {
        return email.find('@') != string::npos && 
               email.find('.') != string::npos &&
               email.size() > 5;
    }

public:
    User(const string& uname, const string& em) : username(uname), email(em) {
        if (uname.empty()) {
            throw invalid_argument("Username cannot be empty");
        }
        if (!isValidEmail(em)) {
            throw invalid_argument("Invalid email format");
        }
    }

    virtual ~User() {}

    virtual void updateProfile(const string& newUsername, const string& newEmail) {
        if (newUsername.empty()) {
            throw invalid_argument("Username cannot be empty");
        }
        if (!isValidEmail(newEmail)) {
            throw invalid_argument("Invalid email format");
        }

        username = newUsername;
        email = newEmail;
    }

    virtual void printProfile() const {
        cout << "Username: " << username << "\nEmail: " << email << endl;
    }

    virtual string getUserType() const = 0;
};

// Класс RegularUser (обычный пользователь)
class RegularUser : public User {
private:
    string fullName;
    int age;

public:
    RegularUser(const string& uname, const string& em, 
                const string& fname, int a) 
        : User(uname, em), fullName(fname), age(a) 
    {
        if (fname.empty()) {
            throw invalid_argument("Full name cannot be empty");
        }
        if (age < 13 || age > 120) {
            throw invalid_argument("Age must be between 13 and 120");
        }
    }

    void updateProfile(const string& newUsername, const string& newEmail) override {
        User::updateProfile(newUsername, newEmail);
        cout << "Regular user profile updated successfully" << endl;
    }

    void updateProfile(const string& newUsername, const string& newEmail,
                      const string& newFullName, int newAge) 
    {
        if (newFullName.empty()) {
            throw invalid_argument("Full name cannot be empty");
        }
        if (newAge < 13 || newAge > 120) {
            throw invalid_argument("Age must be between 13 and 120");
        }

        User::updateProfile(newUsername, newEmail);
        fullName = newFullName;
        age = newAge;
    }

    void printProfile() const override {
        User::printProfile();
        cout << "Full Name: " << fullName << "\nAge: " << age << endl;
    }

    string getUserType() const override {
        return "Regular User";
    }
};

// Класс AdminUser (администратор)
class AdminUser : public User {
private:
    string department;
    int accessLevel;

public:
    AdminUser(const string& uname, const string& em,
              const string& dept, int accessLvl)
        : User(uname, em), department(dept), accessLevel(accessLvl)
    {
        if (dept.empty()) {
            throw invalid_argument("Department cannot be empty");
        }
        if (accessLvl < 1 || accessLvl > 5) {
            throw invalid_argument("Access level must be between 1 and 5");
        }
    }

    void updateProfile(const string& newUsername, const string& newEmail) override {
        if (username != newUsername) {
            throw runtime_error("Admin username cannot be changed");
        }

        User::updateProfile(newUsername, newEmail);
        cout << "Admin profile updated successfully" << endl;
    }

    void updateProfile(const string& newEmail, const string& newDept, int newAccessLvl) {
        if (newDept.empty()) {
            throw invalid_argument("Department cannot be empty");
        }
        if (newAccessLvl < 1 || newAccessLvl > 5) {
            throw invalid_argument("Access level must be between 1 and 5");
        }

        User::updateProfile(username, newEmail);
        department = newDept;
        accessLevel = newAccessLvl;
    }

    void printProfile() const override {
        User::printProfile();
        cout << "Department: " << department 
             << "\nAccess Level: " << accessLevel << endl;
    }

    string getUserType() const override {
        return "Admin User";
    }
};

// Функция для тестирования обновления профиля
void testProfileUpdate(User* user, const string& newUsername, const string& newEmail) {
    cout << "\nTesting profile update for " << user->getUserType() << ":" << endl;
    user->printProfile();

    try {
        cout << "\nAttempting to update to:\nUsername: " << newUsername 
             << "\nEmail: " << newEmail << endl;
        user->updateProfile(newUsername, newEmail);
        cout << "Profile after update:" << endl;
        user->printProfile();
    } 
    catch (const exception& e) {
        cerr << "Update failed: " << e.what() << endl;
    }
}

int main() {
    try {
        // Создаем пользователей
        RegularUser regular("johndoe", "john@example.com", "John Doe", 30);
        AdminUser admin("admin", "admin@company.com", "IT", 3);

        // Тестируем обновление профилей
        testProfileUpdate(&regular, "newjohndoe", "newjohn@example.com");
        testProfileUpdate(&admin, "newadmin", "newadmin@company.com"); // Должно вызвать ошибку
        
        // Тестируем специальные методы обновления
        cout << "\nTesting extended update for RegularUser:" << endl;
        RegularUser* regularPtr = &regular;
        regularPtr->updateProfile("johndoe", "john.doe@example.com", "John H. Doe", 31);
        regularPtr->printProfile();

        cout << "\nTesting extended update for AdminUser:" << endl;
        AdminUser* adminPtr = &admin;
        adminPtr->updateProfile("admin@newcompany.com", "Security", 4);
        adminPtr->printProfile();

        // Попытка создать пользователя с недопустимыми данными
        try {
            RegularUser invalidUser("", "invalid", "", 0);
        } 
        catch (const exception& e) {
            cout << "\nFailed to create user: " << e.what() << endl;
        }

    } 
    catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
#include <string>
#include <iostream>
class User {
protected:
    std::string username;
    std::string password;

public:
    User(const std::string& _username, const std::string& _password);

    virtual bool authenticate(const std::string& _username, const std::string& _password) const;
    std::string getUsername() const;

    void saveToFile(std::ostream& os) const;
    
    static User* loadFromFile(std::istream& is);
};

class AdminUser: public User {
public:
    AdminUser(const std::string& _username, const std::string& _password);
    bool authenticate(const std::string& _username, const std::string& _password) const override;
};


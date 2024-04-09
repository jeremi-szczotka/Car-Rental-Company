#include "User.h"
#include <vector>

class AuthenticationSystem {
private:

public:
    std::vector<User*> users;
    void addUser(User* user);
    User* login(const std::string& username, const std::string& password);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};


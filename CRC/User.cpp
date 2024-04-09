#include "User.h"

User::User(const std::string& _username, const std::string& _password) : username(_username), password(_password) {}

bool User::authenticate(const std::string& _username, const std::string& _password) const {
    return username == _username && password == _password;
}

std::string User::getUsername() const {
    return username;
}

AdminUser::AdminUser(const std::string& _username, const std::string& _password) : User(_username, _password) {}

bool AdminUser::authenticate(const std::string& _username, const std::string& _password) const {
    return true;
}
void User::saveToFile(std::ostream& os) const {
    os << username << " " << password << std::endl;
}

User* User::loadFromFile(std::istream& is) {
    std::string username, password;
    if (is >> username >> password) {
        return new User(username, password);
    }
    return nullptr;
}
#ifndef NODE_HPP
#define NODE_HPP

#include <QString>
#include <string>

class Node
{
public:
    Node(const std::string&);

    inline QString Name() { return m_name; };
private:
    QString m_name;
};

#endif // NODE_HPP

#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>

class Log {

    std::string m_date;
	std::string m_time;
	std::string m_description;

public:
    Log(const std::string&, const std::string&, const std::string&);

    const std::string& get_date() const;
	const std::string& get_time() const;
	const std::string& get_description() const;

	bool operator==(const Log&) const;

	friend std::ostream& operator<<(std::ostream&, const Log&);
};

std::ostream& operator<<(std::ostream&, const Log&);

#endif
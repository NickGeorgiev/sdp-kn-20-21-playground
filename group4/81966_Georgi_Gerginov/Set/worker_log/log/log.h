#ifndef LOG_H
#define LOG_H
#include "../comparable/comparable.h"
#include <iostream>
#include <string>

class Log : public Comparable {

    std::string m_date;
	std::string m_time;
	std::string m_description;

public:
    Log(const std::string&, const std::string&, const std::string&);

	const short int compareTo(Comparable*) const override;
	const std::string get_date() const override;
	
	bool operator==(const Log&) const;

	friend std::ostream& operator<<(std::ostream&, const Log&);
};

std::ostream& operator<<(std::ostream&, const Log&);

#endif

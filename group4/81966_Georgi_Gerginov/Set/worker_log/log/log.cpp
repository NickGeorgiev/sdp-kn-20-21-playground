#include "log.h"

Log::Log(const std::string& date, const std::string& time, const std::string& description) : m_date{date}, m_time{time}, m_description{description} {}

const short int Log::compareTo(Comparable* other) const {
    Log* pt_to_log{dynamic_cast<Log*>(other)};

    if(m_date < pt_to_log -> m_date) {
        return -1;
    } else if(m_date == pt_to_log -> m_date) {
        return 0;
    } else {
    	return 1;
	}
}

const std::string Log::get_date() const {
	return m_date;
}

bool Log::operator==(const Log& other) const {
	return m_date == other.m_date;
}

std::ostream& operator<<(std::ostream& out, const Log& log) {
	out << log.m_date << " " << log.m_time << " " << log.m_description;
	return out;
}

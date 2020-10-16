#include "log.h"

Log::Log(const std::string& date, const std::string& time, const std::string& description) : m_date{date}, m_time{time}, m_description{description} {}

const std::string& Log::get_date() const {
	return m_date;
}

const std::string& Log::get_time() const {
	return m_time;
}

const std::string& Log::get_description() const {
	return m_description;
}

bool Log::operator==(const Log& other) const {
	return m_date == other.m_date && m_time == other.m_time;
}

std::ostream& operator<<(std::ostream& out, const Log& log) {
	out << log.m_date << " " << log.m_time << " " << log.m_description;
	return out;
}
#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "../dev_task_types.h"
#include <string>

class Programmer {
public:
	enum class Role {
		junior,
		middle,
		senior
	};

private:
	std::string m_name;
	Type m_spec;
	unsigned short int m_workhours;
	Role m_role;
	bool m_is_available;

public:
	Programmer(const std::string&, const Type&, const unsigned short int&, const Role&);

	void make_unavailable();

	const Type get_specialization() const;
	const unsigned short int get_workhours() const;
	const unsigned short int get_role_multiplier() const;
	bool is_available() const;

	bool operator==(const Programmer&) const;

	friend std::ostream& operator<<(std::ostream&, const Programmer&);
};

std::ostream& operator<<(std::ostream&, const Programmer&);

#endif
